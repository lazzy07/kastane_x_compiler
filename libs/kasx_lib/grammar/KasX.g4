grammar KasX;

prog: statement* EOF;

statement
  : type_declaration
  | entity_declaration
  | property_declaration
  | initial_state_declaration
  | action_definition
  | trigger_definition
  | utility_function
  ;

/* 
  Declare types: 
    type location;
    type character : location;
*/ 
type_declaration
  : KEYWORD_TYPE IDENTIFIER SEMICOLON
  | KEYWORD_TYPE IDENTIFIER COLON IDENTIFIER SEMICOLON
  ;

/*
    Types list (Helper grammar):
      location, character
*/
types_list
  : (IDENTIFIER (COMMA IDENTIFIER)*)?
  ;

/* 
  Declare Entities
    entity Tom : character, location;
*/
entity_declaration
  : KEYWORD_ENTITY IDENTIFIER COLON types_list SEMICOLON
  ;

/*
  Declare properties:
    property path(from : place, to : place) : boolean;
    property alive(character : character) : boolean;
*/
property_declaration
  : KEYWORD_PROPERTY function_header COLON data_type SEMICOLON
  ;

/* 
  Parameter list interpretation (Helper)
    from : place, to : place
*/
param_list
  : (param (COMMA param)*)?
  ;

/*
  Parameter interpretation (Helper)
    from : place
    to : place
*/
param
  : IDENTIFIER COLON data_type
  | IDENTIFIER
  ;

/* 
  Action interpretation
*/
action_definition
  : KEYWORD_ACTION function_header START_CUR_BRACES action_body END_CUR_BRACES SEMICOLON
  ;

/* 
  Action/Property header interpretation
    path(from : place, to : place)
    walk(c: character, from: place, to: place)
*/
function_header
  : IDENTIFIER START_BRACKET param_list END_BRACKET
  ;

action_body
  : precondition_block?
   effect_block?
   consenting_list?
   observing_fun? 
  ;

precondition_block
  : FUN_KEYWORD_PRECONDITION COLON conditions_list SEMICOLON
  ;

effect_block
  : FUN_KEYWORD_EFFECT COLON conditions_list SEMICOLON
  ;

consenting_list
  : FUN_KEYWORD_CONSENTING COLON identifiers_list SEMICOLON
  ;

observing_fun
  : FUN_KEYWORD_OBSERVING START_BRACKET IDENTIFIER COLON data_type END_BRACKET COLON conditions_list SEMICOLON
  ;

initial_state_declaration
  : IDENTIFIER START_BRACKET types_list END_BRACKET SEMICOLON
  | IDENTIFIER START_BRACKET types_list END_BRACKET OP_BINARY_ASSIGN data_type SEMICOLON
  ;

trigger_definition
  : KEYWORD_TRIGGER function_header START_CUR_BRACES trigger_body END_CUR_BRACES SEMICOLON
  ;

trigger_body
  : precondition_block
    effect_block
  ;

utility_function
  : KEYWORD_UTILITY START_BRACKET (IDENTIFIER)? END_BRACKET COLON boolean_expression SEMICOLON
  ;


identifiers_list
  : (IDENTIFIER (COMMA IDENTIFIER)*)?
  ;

conditions_list
  : boolean_expression
  | fluent;

belives_predicate
  : KEYWORD_BELIEVES START_BRACKET IDENTIFIER COMMA boolean_expression END_BRACKET
  ;

exists_clause
  : KEYWORD_EXISTS START_BRACKET param END_BRACKET boolean_expression
  ;

boolean_expression
  : OP_UNARY_NOT boolean_expression
  | OP_BINARY_MINUS boolean_expression
  | START_BRACKET boolean_expression END_BRACKET
  | boolean_expression binary_op boolean_expression
  | KEYWORD_BELIEVES START_BRACKET IDENTIFIER COMMA 
  | belives_predicate
  | fluent
  | if_else_block
  | exists_clause
  | IDENTIFIER
  | NUMBER
  | VALUE_UNKNOWN
  ;

fluent
  : IDENTIFIER START_BRACKET argument_list END_BRACKET
  ;

argument_list
  : IDENTIFIER (COMMA IDENTIFIER)*
  ;

if_else_block
    : KEYWORD_IF START_BRACKET boolean_expression END_BRACKET 
    conditions_list 
    (KEYWORD_ELSE conditions_list)? 
    SEMICOLON?
    ;

binary_op
  : OP_BINARY_MINUS
  | OP_BINARY_PLUS
  | OP_BINARY_DIV
  | OP_BINARY_MULTI
  | OP_BINARY_LESS
  | OP_BINARY_GREATER
  | OP_BINARY_LESS_EQ
  | OP_BINARY_GREATER_EQ
  | OP_BINARY_NOT_EQUAL
  | OP_BINARY_EQUAL
  | OP_BINARY_ASSIGN
  | OP_BINARY_OR
  | OP_BINARY_AND
  ;

/*
  Supported Data types interpretation:
    ?
    number
    boolean
    character (Interpreted as an Identifier)
*/
data_type
  : VALUE_UNKNOWN
  | DATATYPE_NUMBER
  | DATATYPE_BOOLEAN
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
KEYWORD_TYPE : 'type';
KEYWORD_ENTITY: 'entity';
KEYWORD_PROPERTY: 'property';
KEYWORD_ACTION: 'action';
KEYWORD_TRIGGER: 'trigger';
KEYWORD_BELIEVES: 'believes';
KEYWORD_UTILITY: 'utility';
KEYWORD_EXISTS: 'exists';

/* Data type declarations */
DATATYPE_NUMBER: 'number';
DATATYPE_BOOLEAN: 'boolean';

/* Function Keywords */
FUN_KEYWORD_PRECONDITION: 'precondition';
FUN_KEYWORD_EFFECT: 'effect';
FUN_KEYWORD_CONSENTING: 'consenting';
FUN_KEYWORD_OBSERVING: 'observing';

/* Flow controller keywords */
KEYWORD_IF: 'if';
KEYWORD_ELSE: 'else';

/* Identifiers and numbers */
NUMBER: [0-9]+;
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
VALUE_UNKNOWN: '?';

/* Operators */
OP_BINARY_EQUAL: '==';
OP_BINARY_NOT_EQUAL: '!=';
OP_BINARY_GREATER_EQ: '>=';
OP_BINARY_LESS_EQ: '<=';

OP_BINARY_ASSIGN: '=';
OP_UNARY_NOT: '!';
OP_BINARY_OR: '|';
OP_BINARY_AND: '&';
OP_BINARY_GREATER: '>';
OP_BINARY_LESS: '<';

OP_BINARY_MULTI: '*';
OP_BINARY_DIV: '/';
OP_BINARY_PLUS: '+';
OP_BINARY_MINUS: '-';

// Punctuation
START_BRACKET: '(';
END_BRACKET: ')';
START_CUR_BRACES: '{';
END_CUR_BRACES: '}';

SEMICOLON: ';';
COLON: ':';
COMMA: ',';

// Catch-all for unexpected characters
ERROR_CHAR: . ;