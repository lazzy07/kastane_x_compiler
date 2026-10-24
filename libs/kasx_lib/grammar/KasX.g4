grammar KasX;

/*
* File name: KasX.g4
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 01:49:32
* ------
*/

prog
  : definition* EOF                # Program
;       

definition
  : type_declaration               
  | entity_declaration             
  | fluent_declaration             
  | initial_state_declaration      
  | action_definition              
  | trigger_definition             
  | utility_definition             
  ;

/* 
  Declare types: 
    type location;
    type character : location;
*/ 
type_declaration
  : TYPE_DEFINITION_KEYWORD IDENTIFIER (COLON types_list)? DEFINITION_SEPARATOR # TypeDeclaration
  ;


type_name
  : IDENTIFIER
  | ENTITY_DEFINITION_KEYWORD
  ;

/*
    Types list (Helper grammar):
      location, character
*/
types_list
  : (type_name (COMMA type_name)*)?                                             # TypesList
  ;

/* 
  Declare Entities
    entity Tom : character, location;
*/
entity_declaration
  : ENTITY_DEFINITION_KEYWORD IDENTIFIER COLON types_list DEFINITION_SEPARATOR  # EntityDeclaration
  ;

/*
  Declare properties:
    property path(from : place, to : place) : boolean;
    property alive(character : character) : boolean;
*/
fluent_declaration
  : FLUENT_DEFINITION_KEYWORD function_header COLON data_type DEFINITION_SEPARATOR # FluentDeclaration
  ;

/* 
  Parameter list interpretation (Helper)
    from : place, to : place
*/
param_list
  : (param (COMMA param)*)?                                                        # ParamList
  ;

/*
  Parameter interpretation (Helper)
    from : place
    to : place
*/
param
  : IDENTIFIER (COLON data_type)?
  ;

/* 
  Action interpretation
*/
action_definition
  : ACTION_DEFINITION_KEYWORD function_header START_CUR_BRACES action_body END_CUR_BRACES DEFINITION_SEPARATOR        # ActionDecl
  ;

/* 
  Action/Property header interpretation
    path(from : place, to : place)
    walk(c: character, from: place, to: place)
*/
function_header
  : IDENTIFIER OPEN_BRACKET param_list CLOSE_BRACKET  # FunctionHeader
  ;

action_body
  : precondition_block?
   effect_block?
   consenting_list?
   observing_fun? 
  ;

precondition_block
  : PRECONDITION_KEYWORD COLON conditions_list DEFINITION_SEPARATOR
  ;

effect_block
  : EFFECT_KEYWORD COLON conditions_list DEFINITION_SEPARATOR
  ;

consenting_list
  : CONSENTING_KEYWORD COLON identifiers_list DEFINITION_SEPARATOR
  ;

observing_fun
  : OBSERVING_KEYWORD OPEN_BRACKET IDENTIFIER COLON data_type CLOSE_BRACKET COLON conditions_list DEFINITION_SEPARATOR
  ;

initial_state_declaration
  : arithmetic_expression DEFINITION_SEPARATOR                                # InitialStateDecl
  ;

trigger_definition
  : TRIGGER_DEFINITION_KEYWORD function_header START_CUR_BRACES trigger_body END_CUR_BRACES DEFINITION_SEPARATOR  #TriggerDecl
  ;

trigger_body
  : precondition_block
    effect_block
  ;

utility_definition
  : UTILITY_DEFINITION_KEYWORD OPEN_BRACKET (IDENTIFIER)? CLOSE_BRACKET COLON arithmetic_expression DEFINITION_SEPARATOR  #UtilityDecl
  ;


identifiers_list
  : (IDENTIFIER (COMMA IDENTIFIER)*)?
  ;

conditions_list
  : arithmetic_expression
  ;

belives_expression
  : KEYWORD_BELIEVES OPEN_BRACKET IDENTIFIER COMMA arithmetic_expression CLOSE_BRACKET
  ;

exists_clause
  : EXISTENTIAL_QUANTIFICATION_KEYWORD OPEN_BRACKET param CLOSE_BRACKET
  ;

/*
  Operator precedence, the same as Sabre's (edu.uky.cs.nil.sabre.io.DefaultParser). From the loosest to the tightest:
    &
    |
    !, if/elseif/else, forall, exists   prefix forms, they cover everything after them up to the next '&' or '|'
    =                                    right associative
    ==, !=, >=, <=, >, <                 each one is a separate level, in this order, all right associative
    :                                    type constraint
    sum                                  covers the arithmetic after it
    *, /, +, -                           each one is a separate level, in this order, all right associative
  ANTLR reads the alternatives below from the tightest to the loosest.

  Sabre's arithmetic is not the usual mathematical one: f() + g() * h() is (f() + g()) * h() and f() - g() - h() is
  f() - (g() - h()). Sabre has no unary minus (-1 is a number), so the unary '-' below binds tightest and only stands for
  negative numbers.
*/
arithmetic_expression
  : SUBTRACTION_KEYWORD arithmetic_expression                                                          # ExprNegation
  | OPEN_BRACKET arithmetic_expression CLOSE_BRACKET                                                   # ExprInBracket
  | <assoc = right> arithmetic_expression op = SUBTRACTION_KEYWORD arithmetic_expression               # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = ADDITION_KEYWORD arithmetic_expression                  # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = DIVISION_KEYWORD arithmetic_expression                  # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = MULTIPLICATION_KEYWORD arithmetic_expression            # ExprBinaryOp
  | sum_function arithmetic_expression                                                                 # ExprSum
  | arithmetic_expression op = COLON arithmetic_expression                                             # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = LESS_THAN_KEYWORD arithmetic_expression                 # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = GREATER_THAN_KEYWORD arithmetic_expression              # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = LESS_THAN_OR_EQUAL_TO_KEYWORD arithmetic_expression     # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = GREATER_THAN_OR_EQUAL_TO_KEYWORD arithmetic_expression  # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = NOT_EQUAL_TO_KEYWORD arithmetic_expression              # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = EQUAL_TO_KEYWORD arithmetic_expression                  # ExprBinaryOp
  | <assoc = right> arithmetic_expression op = ASSIGNMENT_KEYWORD arithmetic_expression                # ExprBinaryOp
  | forall_function arithmetic_expression                                                              # ExprForAll
  | exists_clause arithmetic_expression                                                                # ExprExists
  | if_else_block arithmetic_expression                                                                # ExprIfElse
  | NEGATION_KEYWORD arithmetic_expression                                                             # ExprNot
  | arithmetic_expression op = DISJUNCTION_KEYWORD arithmetic_expression                               # ExprBinaryOp
  | arithmetic_expression op = CONJUNCTION_KEYWORD arithmetic_expression                               # ExprBinaryOp
  | belives_expression                                                                                 # ExprBelives
  | fluent                                                                                             # ExprFluent
  | boolean_data                                                                                       # ExprBoolean
  | IDENTIFIER                                                                                         # ExprIdentifier
  | NUMBER                                                                                             # ExprNumber
  | UNKNOWN_KEYWORD                                                                                    # ExprUnknown
  | NULL_CLAUSE_KEYWORD                                                                                # ExprNullClause
  ;

inheritance_expression
  : arithmetic_expression COLON arithmetic_expression             # ExprInheritance
  ;

forall_function
  : UNIVERSAL_QUANTIFICATION_KEYWORD OPEN_BRACKET IDENTIFIER COLON IDENTIFIER CLOSE_BRACKET
  ;

sum_function
  : SUM_KEYWORD OPEN_BRACKET IDENTIFIER COLON IDENTIFIER CLOSE_BRACKET
  ;

fluent
  : IDENTIFIER OPEN_BRACKET argument_list? CLOSE_BRACKET        # FluentVal
  ;

argument_list
  : IDENTIFIER (COMMA IDENTIFIER)*                              # ArgumentList
  ;

/*
  Everything of a conditional except its last branch (the last branch is the arithmetic_expression after it in ExprIfElse,
  so it gets the conditional's precedence). Branches followed by elseif/else are complete expressions.
*/
if_else_block
    : CONDITIONAL_FIRST_BRANCH_KEYWORD OPEN_BRACKET arithmetic_expression CLOSE_BRACKET
    (conditions_list CONDITIONAL_MIDDLE_BRANCH_KEYWORD OPEN_BRACKET arithmetic_expression CLOSE_BRACKET)*
    (conditions_list CONDITIONAL_LAST_BRANCH_KEYWORD)?
    ;

boolean_data
  : TRUE_KEYWORD                          # TrueValue
  | FALSE_KEYWORD                         # FalseValue
  ;

/*
  Supported Data types interpretation:
    ?
    number
    boolean
    character (Interpreted as an Identifier)
*/
data_type
  : UNKNOWN_KEYWORD
  | NUMBER_KEYWORD
  | BOOLEAN_KEYWORD
  | ENTITY_DEFINITION_KEYWORD
  | IDENTIFIER
  | NUMBER
  ;



// Ignore single-line comments
LINE_COMMENT: '//' ~[\r\n]* -> skip;

// Ignore multi-line comments
BLOCK_COMMENT: '/*' .*? '*/' -> skip;

// Whitespace
WS: [ \t\r\n]+ -> skip;

/* Tokens */
TYPE_DEFINITION_KEYWORD : 'type';
ENTITY_DEFINITION_KEYWORD: 'entity';
FLUENT_DEFINITION_KEYWORD: 'property';
ACTION_DEFINITION_KEYWORD: 'action';
TRIGGER_DEFINITION_KEYWORD: 'trigger';
KEYWORD_BELIEVES: 'believes';
UTILITY_DEFINITION_KEYWORD: 'utility';
EXISTENTIAL_QUANTIFICATION_KEYWORD: 'exists';
// TODO: Implement
CONDITIONAL_EFFECT_KEYWORD: 'when';
UNIVERSAL_QUANTIFICATION_KEYWORD: 'forall';
//TODO: Implement
PRODUCT_KEYWORD: 'product';
SUM_KEYWORD: 'sum';
//TODO: Implement
GOAL_KEYWORD: 'goal';

/* Data type declarations */
NUMBER_KEYWORD: 'number';
BOOLEAN_KEYWORD: 'boolean';

/* Function Keywords */
PRECONDITION_KEYWORD: 'precondition';
EFFECT_KEYWORD: 'effect';
CONSENTING_KEYWORD: 'consenting';
OBSERVING_KEYWORD: 'observing';

/* Flow controller keywords */
CONDITIONAL_FIRST_BRANCH_KEYWORD: 'if';
CONDITIONAL_LAST_BRANCH_KEYWORD: 'else';
CONDITIONAL_MIDDLE_BRANCH_KEYWORD: 'elseif';

/* Identifiers and numbers */
NUMBER: [0-9]+;
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
UNKNOWN_KEYWORD: '?';
FALSE_KEYWORD: 'False';
TRUE_KEYWORD: 'True';
NULL_CLAUSE_KEYWORD: 'nil';

/* Operators */
EQUAL_TO_KEYWORD: '==';
NOT_EQUAL_TO_KEYWORD: '!=';
GREATER_THAN_OR_EQUAL_TO_KEYWORD: '>=';
LESS_THAN_OR_EQUAL_TO_KEYWORD: '<=';

ASSIGNMENT_KEYWORD: '=';
NEGATION_KEYWORD: '!';
DISJUNCTION_KEYWORD: '|';
CONJUNCTION_KEYWORD: '&';
GREATER_THAN_KEYWORD: '>';
LESS_THAN_KEYWORD: '<';

MULTIPLICATION_KEYWORD: '*';
DIVISION_KEYWORD: '/';
ADDITION_KEYWORD: '+';
SUBTRACTION_KEYWORD: '-';

// Punctuation
OPEN_BRACKET: '(';
CLOSE_BRACKET: ')';
START_CUR_BRACES: '{';
END_CUR_BRACES: '}';

DEFINITION_SEPARATOR: ';';
COLON: ':';
COMMA: ',';

// Catch-all for unexpected characters
ERROR_CHAR: . ;
