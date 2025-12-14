// Generated from /home/lazzy07/projects/kastane_x/compiler/libs/kasx_lib/grammar/KasX.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class KasXParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		LINE_COMMENT=1, BLOCK_COMMENT=2, WS=3, TYPE_DEFINITION_KEYWORD=4, ENTITY_DEFINITION_KEYWORD=5, 
		FLUENT_DEFINITION_KEYWORD=6, ACTION_DEFINITION_KEYWORD=7, TRIGGER_DEFINITION_KEYWORD=8, 
		KEYWORD_BELIEVES=9, UTILITY_DEFINITION_KEYWORD=10, EXISTENTIAL_QUANTIFICATION_KEYWORD=11, 
		CONDITIONAL_EFFECT_KEYWORD=12, UNIVERSAL_QUANTIFICATION_KEYWORD=13, PRODUCT_KEYWORD=14, 
		SUM_KEYWORD=15, GOAL_KEYWORD=16, NUMBER_KEYWORD=17, BOOLEAN_KEYWORD=18, 
		PRECONDITION_KEYWORD=19, EFFECT_KEYWORD=20, CONSENTING_KEYWORD=21, OBSERVING_KEYWORD=22, 
		CONDITIONAL_FIRST_BRANCH_KEYWORD=23, CONDITIONAL_LAST_BRANCH_KEYWORD=24, 
		CONDITIONAL_MIDDLE_BRANCH_KEYWORD=25, NUMBER=26, IDENTIFIER=27, UNKNOWN_KEYWORD=28, 
		FALSE_KEYWORD=29, TRUE_KEYWORD=30, NULL_CLAUSE_KEYWORD=31, EQUAL_TO_KEYWORD=32, 
		NOT_EQUAL_TO_KEYWORD=33, GREATER_THAN_OR_EQUAL_TO_KEYWORD=34, LESS_THAN_OR_EQUAL_TO_KEYWORD=35, 
		ASSIGNMENT_KEYWORD=36, NEGATION_KEYWORD=37, DISJUNCTION_KEYWORD=38, CONJUNCTION_KEYWORD=39, 
		GREATER_THAN_KEYWORD=40, LESS_THAN_KEYWORD=41, MULTIPLICATION_KEYWORD=42, 
		DIVISION_KEYWORD=43, ADDITION_KEYWORD=44, SUBTRACTION_KEYWORD=45, OPEN_BRACKET=46, 
		CLOSE_BRACKET=47, START_CUR_BRACES=48, END_CUR_BRACES=49, DEFINITION_SEPARATOR=50, 
		COLON=51, COMMA=52, ERROR_CHAR=53;
	public static final int
		RULE_prog = 0, RULE_definition = 1, RULE_type_declaration = 2, RULE_type_name = 3, 
		RULE_types_list = 4, RULE_entity_declaration = 5, RULE_fluent_declaration = 6, 
		RULE_param_list = 7, RULE_param = 8, RULE_action_definition = 9, RULE_function_header = 10, 
		RULE_action_body = 11, RULE_precondition_block = 12, RULE_effect_block = 13, 
		RULE_consenting_list = 14, RULE_observing_fun = 15, RULE_initial_state_declaration = 16, 
		RULE_trigger_definition = 17, RULE_trigger_body = 18, RULE_utility_definition = 19, 
		RULE_identifiers_list = 20, RULE_conditions_list = 21, RULE_belives_expression = 22, 
		RULE_exists_clause = 23, RULE_arithmetic_expression = 24, RULE_inheritance_expression = 25, 
		RULE_forall_function = 26, RULE_sum_function = 27, RULE_unary_not_expression = 28, 
		RULE_negation_expression = 29, RULE_fluent = 30, RULE_argument_list = 31, 
		RULE_if_else_block = 32, RULE_binary_op = 33, RULE_boolean_data = 34, 
		RULE_data_type = 35;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "definition", "type_declaration", "type_name", "types_list", 
			"entity_declaration", "fluent_declaration", "param_list", "param", "action_definition", 
			"function_header", "action_body", "precondition_block", "effect_block", 
			"consenting_list", "observing_fun", "initial_state_declaration", "trigger_definition", 
			"trigger_body", "utility_definition", "identifiers_list", "conditions_list", 
			"belives_expression", "exists_clause", "arithmetic_expression", "inheritance_expression", 
			"forall_function", "sum_function", "unary_not_expression", "negation_expression", 
			"fluent", "argument_list", "if_else_block", "binary_op", "boolean_data", 
			"data_type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'type'", "'entity'", "'property'", "'action'", 
			"'trigger'", "'believes'", "'utility'", "'exists'", "'when'", "'forall'", 
			"'product'", "'sum'", "'goal'", "'number'", "'boolean'", "'precondition'", 
			"'effect'", "'consenting'", "'observing'", "'if'", "'else'", "'elseif'", 
			null, null, "'?'", "'False'", "'True'", "'nil'", "'=='", "'!='", "'>='", 
			"'<='", "'='", "'!'", "'|'", "'&'", "'>'", "'<'", "'*'", "'/'", "'+'", 
			"'-'", "'('", "')'", "'{'", "'}'", "';'", "':'", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "LINE_COMMENT", "BLOCK_COMMENT", "WS", "TYPE_DEFINITION_KEYWORD", 
			"ENTITY_DEFINITION_KEYWORD", "FLUENT_DEFINITION_KEYWORD", "ACTION_DEFINITION_KEYWORD", 
			"TRIGGER_DEFINITION_KEYWORD", "KEYWORD_BELIEVES", "UTILITY_DEFINITION_KEYWORD", 
			"EXISTENTIAL_QUANTIFICATION_KEYWORD", "CONDITIONAL_EFFECT_KEYWORD", "UNIVERSAL_QUANTIFICATION_KEYWORD", 
			"PRODUCT_KEYWORD", "SUM_KEYWORD", "GOAL_KEYWORD", "NUMBER_KEYWORD", "BOOLEAN_KEYWORD", 
			"PRECONDITION_KEYWORD", "EFFECT_KEYWORD", "CONSENTING_KEYWORD", "OBSERVING_KEYWORD", 
			"CONDITIONAL_FIRST_BRANCH_KEYWORD", "CONDITIONAL_LAST_BRANCH_KEYWORD", 
			"CONDITIONAL_MIDDLE_BRANCH_KEYWORD", "NUMBER", "IDENTIFIER", "UNKNOWN_KEYWORD", 
			"FALSE_KEYWORD", "TRUE_KEYWORD", "NULL_CLAUSE_KEYWORD", "EQUAL_TO_KEYWORD", 
			"NOT_EQUAL_TO_KEYWORD", "GREATER_THAN_OR_EQUAL_TO_KEYWORD", "LESS_THAN_OR_EQUAL_TO_KEYWORD", 
			"ASSIGNMENT_KEYWORD", "NEGATION_KEYWORD", "DISJUNCTION_KEYWORD", "CONJUNCTION_KEYWORD", 
			"GREATER_THAN_KEYWORD", "LESS_THAN_KEYWORD", "MULTIPLICATION_KEYWORD", 
			"DIVISION_KEYWORD", "ADDITION_KEYWORD", "SUBTRACTION_KEYWORD", "OPEN_BRACKET", 
			"CLOSE_BRACKET", "START_CUR_BRACES", "END_CUR_BRACES", "DEFINITION_SEPARATOR", 
			"COLON", "COMMA", "ERROR_CHAR"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "KasX.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public KasXParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgContext extends ParserRuleContext {
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	 
		public ProgContext() { }
		public void copyFrom(ProgContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ProgContext {
		public TerminalNode EOF() { return getToken(KasXParser.EOF, 0); }
		public List<DefinitionContext> definition() {
			return getRuleContexts(DefinitionContext.class);
		}
		public DefinitionContext definition(int i) {
			return getRuleContext(DefinitionContext.class,i);
		}
		public ProgramContext(ProgContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterProgram(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitProgram(this);
		}
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		int _la;
		try {
			_localctx = new ProgramContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(75);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 105694791512048L) != 0)) {
				{
				{
				setState(72);
				definition();
				}
				}
				setState(77);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(78);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class DefinitionContext extends ParserRuleContext {
		public Type_declarationContext type_declaration() {
			return getRuleContext(Type_declarationContext.class,0);
		}
		public Entity_declarationContext entity_declaration() {
			return getRuleContext(Entity_declarationContext.class,0);
		}
		public Fluent_declarationContext fluent_declaration() {
			return getRuleContext(Fluent_declarationContext.class,0);
		}
		public Initial_state_declarationContext initial_state_declaration() {
			return getRuleContext(Initial_state_declarationContext.class,0);
		}
		public Action_definitionContext action_definition() {
			return getRuleContext(Action_definitionContext.class,0);
		}
		public Trigger_definitionContext trigger_definition() {
			return getRuleContext(Trigger_definitionContext.class,0);
		}
		public Utility_definitionContext utility_definition() {
			return getRuleContext(Utility_definitionContext.class,0);
		}
		public DefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_definition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitDefinition(this);
		}
	}

	public final DefinitionContext definition() throws RecognitionException {
		DefinitionContext _localctx = new DefinitionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_definition);
		try {
			setState(87);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TYPE_DEFINITION_KEYWORD:
				enterOuterAlt(_localctx, 1);
				{
				setState(80);
				type_declaration();
				}
				break;
			case ENTITY_DEFINITION_KEYWORD:
				enterOuterAlt(_localctx, 2);
				{
				setState(81);
				entity_declaration();
				}
				break;
			case FLUENT_DEFINITION_KEYWORD:
				enterOuterAlt(_localctx, 3);
				{
				setState(82);
				fluent_declaration();
				}
				break;
			case KEYWORD_BELIEVES:
			case EXISTENTIAL_QUANTIFICATION_KEYWORD:
			case UNIVERSAL_QUANTIFICATION_KEYWORD:
			case SUM_KEYWORD:
			case CONDITIONAL_FIRST_BRANCH_KEYWORD:
			case NUMBER:
			case IDENTIFIER:
			case UNKNOWN_KEYWORD:
			case FALSE_KEYWORD:
			case TRUE_KEYWORD:
			case NULL_CLAUSE_KEYWORD:
			case NEGATION_KEYWORD:
			case SUBTRACTION_KEYWORD:
			case OPEN_BRACKET:
				enterOuterAlt(_localctx, 4);
				{
				setState(83);
				initial_state_declaration();
				}
				break;
			case ACTION_DEFINITION_KEYWORD:
				enterOuterAlt(_localctx, 5);
				{
				setState(84);
				action_definition();
				}
				break;
			case TRIGGER_DEFINITION_KEYWORD:
				enterOuterAlt(_localctx, 6);
				{
				setState(85);
				trigger_definition();
				}
				break;
			case UTILITY_DEFINITION_KEYWORD:
				enterOuterAlt(_localctx, 7);
				{
				setState(86);
				utility_definition();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_declarationContext extends ParserRuleContext {
		public Type_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_declaration; }
	 
		public Type_declarationContext() { }
		public void copyFrom(Type_declarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeDeclarationNoParentsContext extends Type_declarationContext {
		public TerminalNode TYPE_DEFINITION_KEYWORD() { return getToken(KasXParser.TYPE_DEFINITION_KEYWORD, 0); }
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public TypeDeclarationNoParentsContext(Type_declarationContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterTypeDeclarationNoParents(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitTypeDeclarationNoParents(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeDeclarationWithParentsContext extends Type_declarationContext {
		public TerminalNode TYPE_DEFINITION_KEYWORD() { return getToken(KasXParser.TYPE_DEFINITION_KEYWORD, 0); }
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Types_listContext types_list() {
			return getRuleContext(Types_listContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public TypeDeclarationWithParentsContext(Type_declarationContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterTypeDeclarationWithParents(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitTypeDeclarationWithParents(this);
		}
	}

	public final Type_declarationContext type_declaration() throws RecognitionException {
		Type_declarationContext _localctx = new Type_declarationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_type_declaration);
		try {
			setState(98);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				_localctx = new TypeDeclarationNoParentsContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(89);
				match(TYPE_DEFINITION_KEYWORD);
				setState(90);
				match(IDENTIFIER);
				setState(91);
				match(DEFINITION_SEPARATOR);
				}
				break;
			case 2:
				_localctx = new TypeDeclarationWithParentsContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(92);
				match(TYPE_DEFINITION_KEYWORD);
				setState(93);
				match(IDENTIFIER);
				setState(94);
				match(COLON);
				setState(95);
				types_list();
				setState(96);
				match(DEFINITION_SEPARATOR);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Type_nameContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode ENTITY_DEFINITION_KEYWORD() { return getToken(KasXParser.ENTITY_DEFINITION_KEYWORD, 0); }
		public Type_nameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_name; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterType_name(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitType_name(this);
		}
	}

	public final Type_nameContext type_name() throws RecognitionException {
		Type_nameContext _localctx = new Type_nameContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_type_name);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(100);
			_la = _input.LA(1);
			if ( !(_la==ENTITY_DEFINITION_KEYWORD || _la==IDENTIFIER) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Types_listContext extends ParserRuleContext {
		public Types_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_types_list; }
	 
		public Types_listContext() { }
		public void copyFrom(Types_listContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypesListContext extends Types_listContext {
		public List<Type_nameContext> type_name() {
			return getRuleContexts(Type_nameContext.class);
		}
		public Type_nameContext type_name(int i) {
			return getRuleContext(Type_nameContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(KasXParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(KasXParser.COMMA, i);
		}
		public TypesListContext(Types_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterTypesList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitTypesList(this);
		}
	}

	public final Types_listContext types_list() throws RecognitionException {
		Types_listContext _localctx = new Types_listContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_types_list);
		int _la;
		try {
			_localctx = new TypesListContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(110);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ENTITY_DEFINITION_KEYWORD || _la==IDENTIFIER) {
				{
				setState(102);
				type_name();
				setState(107);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(103);
					match(COMMA);
					setState(104);
					type_name();
					}
					}
					setState(109);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Entity_declarationContext extends ParserRuleContext {
		public Entity_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_entity_declaration; }
	 
		public Entity_declarationContext() { }
		public void copyFrom(Entity_declarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EntityDeclarationContext extends Entity_declarationContext {
		public TerminalNode ENTITY_DEFINITION_KEYWORD() { return getToken(KasXParser.ENTITY_DEFINITION_KEYWORD, 0); }
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Types_listContext types_list() {
			return getRuleContext(Types_listContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public EntityDeclarationContext(Entity_declarationContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterEntityDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitEntityDeclaration(this);
		}
	}

	public final Entity_declarationContext entity_declaration() throws RecognitionException {
		Entity_declarationContext _localctx = new Entity_declarationContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_entity_declaration);
		try {
			_localctx = new EntityDeclarationContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(112);
			match(ENTITY_DEFINITION_KEYWORD);
			setState(113);
			match(IDENTIFIER);
			setState(114);
			match(COLON);
			setState(115);
			types_list();
			setState(116);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Fluent_declarationContext extends ParserRuleContext {
		public Fluent_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fluent_declaration; }
	 
		public Fluent_declarationContext() { }
		public void copyFrom(Fluent_declarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FluentDeclarationContext extends Fluent_declarationContext {
		public TerminalNode FLUENT_DEFINITION_KEYWORD() { return getToken(KasXParser.FLUENT_DEFINITION_KEYWORD, 0); }
		public Function_headerContext function_header() {
			return getRuleContext(Function_headerContext.class,0);
		}
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Data_typeContext data_type() {
			return getRuleContext(Data_typeContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public FluentDeclarationContext(Fluent_declarationContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterFluentDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitFluentDeclaration(this);
		}
	}

	public final Fluent_declarationContext fluent_declaration() throws RecognitionException {
		Fluent_declarationContext _localctx = new Fluent_declarationContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_fluent_declaration);
		try {
			_localctx = new FluentDeclarationContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(118);
			match(FLUENT_DEFINITION_KEYWORD);
			setState(119);
			function_header();
			setState(120);
			match(COLON);
			setState(121);
			data_type();
			setState(122);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Param_listContext extends ParserRuleContext {
		public Param_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_param_list; }
	 
		public Param_listContext() { }
		public void copyFrom(Param_listContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParamListContext extends Param_listContext {
		public List<ParamContext> param() {
			return getRuleContexts(ParamContext.class);
		}
		public ParamContext param(int i) {
			return getRuleContext(ParamContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(KasXParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(KasXParser.COMMA, i);
		}
		public ParamListContext(Param_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterParamList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitParamList(this);
		}
	}

	public final Param_listContext param_list() throws RecognitionException {
		Param_listContext _localctx = new Param_listContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_param_list);
		int _la;
		try {
			_localctx = new ParamListContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(132);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENTIFIER) {
				{
				setState(124);
				param();
				setState(129);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(125);
					match(COMMA);
					setState(126);
					param();
					}
					}
					setState(131);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ParamContext extends ParserRuleContext {
		public ParamContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_param; }
	 
		public ParamContext() { }
		public void copyFrom(ParamContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParamWithoutDataTypeContext extends ParamContext {
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public ParamWithoutDataTypeContext(ParamContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterParamWithoutDataType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitParamWithoutDataType(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParamWithDataTypeContext extends ParamContext {
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Data_typeContext data_type() {
			return getRuleContext(Data_typeContext.class,0);
		}
		public ParamWithDataTypeContext(ParamContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterParamWithDataType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitParamWithDataType(this);
		}
	}

	public final ParamContext param() throws RecognitionException {
		ParamContext _localctx = new ParamContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_param);
		try {
			setState(138);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				_localctx = new ParamWithDataTypeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(134);
				match(IDENTIFIER);
				setState(135);
				match(COLON);
				setState(136);
				data_type();
				}
				break;
			case 2:
				_localctx = new ParamWithoutDataTypeContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(137);
				match(IDENTIFIER);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Action_definitionContext extends ParserRuleContext {
		public Action_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_action_definition; }
	 
		public Action_definitionContext() { }
		public void copyFrom(Action_definitionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ActionDeclContext extends Action_definitionContext {
		public TerminalNode ACTION_DEFINITION_KEYWORD() { return getToken(KasXParser.ACTION_DEFINITION_KEYWORD, 0); }
		public Function_headerContext function_header() {
			return getRuleContext(Function_headerContext.class,0);
		}
		public TerminalNode START_CUR_BRACES() { return getToken(KasXParser.START_CUR_BRACES, 0); }
		public Action_bodyContext action_body() {
			return getRuleContext(Action_bodyContext.class,0);
		}
		public TerminalNode END_CUR_BRACES() { return getToken(KasXParser.END_CUR_BRACES, 0); }
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public ActionDeclContext(Action_definitionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterActionDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitActionDecl(this);
		}
	}

	public final Action_definitionContext action_definition() throws RecognitionException {
		Action_definitionContext _localctx = new Action_definitionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_action_definition);
		try {
			_localctx = new ActionDeclContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(140);
			match(ACTION_DEFINITION_KEYWORD);
			setState(141);
			function_header();
			setState(142);
			match(START_CUR_BRACES);
			setState(143);
			action_body();
			setState(144);
			match(END_CUR_BRACES);
			setState(145);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Function_headerContext extends ParserRuleContext {
		public Function_headerContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function_header; }
	 
		public Function_headerContext() { }
		public void copyFrom(Function_headerContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionHeaderContext extends Function_headerContext {
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public Param_listContext param_list() {
			return getRuleContext(Param_listContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public FunctionHeaderContext(Function_headerContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterFunctionHeader(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitFunctionHeader(this);
		}
	}

	public final Function_headerContext function_header() throws RecognitionException {
		Function_headerContext _localctx = new Function_headerContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_function_header);
		try {
			_localctx = new FunctionHeaderContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(147);
			match(IDENTIFIER);
			setState(148);
			match(OPEN_BRACKET);
			setState(149);
			param_list();
			setState(150);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Action_bodyContext extends ParserRuleContext {
		public Precondition_blockContext precondition_block() {
			return getRuleContext(Precondition_blockContext.class,0);
		}
		public Effect_blockContext effect_block() {
			return getRuleContext(Effect_blockContext.class,0);
		}
		public Consenting_listContext consenting_list() {
			return getRuleContext(Consenting_listContext.class,0);
		}
		public Observing_funContext observing_fun() {
			return getRuleContext(Observing_funContext.class,0);
		}
		public Action_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_action_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterAction_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitAction_body(this);
		}
	}

	public final Action_bodyContext action_body() throws RecognitionException {
		Action_bodyContext _localctx = new Action_bodyContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_action_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==PRECONDITION_KEYWORD) {
				{
				setState(152);
				precondition_block();
				}
			}

			setState(156);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EFFECT_KEYWORD) {
				{
				setState(155);
				effect_block();
				}
			}

			setState(159);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==CONSENTING_KEYWORD) {
				{
				setState(158);
				consenting_list();
				}
			}

			setState(162);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==OBSERVING_KEYWORD) {
				{
				setState(161);
				observing_fun();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Precondition_blockContext extends ParserRuleContext {
		public TerminalNode PRECONDITION_KEYWORD() { return getToken(KasXParser.PRECONDITION_KEYWORD, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Conditions_listContext conditions_list() {
			return getRuleContext(Conditions_listContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public Precondition_blockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_precondition_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterPrecondition_block(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitPrecondition_block(this);
		}
	}

	public final Precondition_blockContext precondition_block() throws RecognitionException {
		Precondition_blockContext _localctx = new Precondition_blockContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_precondition_block);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(164);
			match(PRECONDITION_KEYWORD);
			setState(165);
			match(COLON);
			setState(166);
			conditions_list();
			setState(167);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Effect_blockContext extends ParserRuleContext {
		public TerminalNode EFFECT_KEYWORD() { return getToken(KasXParser.EFFECT_KEYWORD, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Conditions_listContext conditions_list() {
			return getRuleContext(Conditions_listContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public Effect_blockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_effect_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterEffect_block(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitEffect_block(this);
		}
	}

	public final Effect_blockContext effect_block() throws RecognitionException {
		Effect_blockContext _localctx = new Effect_blockContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_effect_block);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(169);
			match(EFFECT_KEYWORD);
			setState(170);
			match(COLON);
			setState(171);
			conditions_list();
			setState(172);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Consenting_listContext extends ParserRuleContext {
		public TerminalNode CONSENTING_KEYWORD() { return getToken(KasXParser.CONSENTING_KEYWORD, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Identifiers_listContext identifiers_list() {
			return getRuleContext(Identifiers_listContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public Consenting_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_consenting_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterConsenting_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitConsenting_list(this);
		}
	}

	public final Consenting_listContext consenting_list() throws RecognitionException {
		Consenting_listContext _localctx = new Consenting_listContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_consenting_list);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(174);
			match(CONSENTING_KEYWORD);
			setState(175);
			match(COLON);
			setState(176);
			identifiers_list();
			setState(177);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Observing_funContext extends ParserRuleContext {
		public TerminalNode OBSERVING_KEYWORD() { return getToken(KasXParser.OBSERVING_KEYWORD, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public List<TerminalNode> COLON() { return getTokens(KasXParser.COLON); }
		public TerminalNode COLON(int i) {
			return getToken(KasXParser.COLON, i);
		}
		public Data_typeContext data_type() {
			return getRuleContext(Data_typeContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public Conditions_listContext conditions_list() {
			return getRuleContext(Conditions_listContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public Observing_funContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_observing_fun; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterObserving_fun(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitObserving_fun(this);
		}
	}

	public final Observing_funContext observing_fun() throws RecognitionException {
		Observing_funContext _localctx = new Observing_funContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_observing_fun);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(179);
			match(OBSERVING_KEYWORD);
			setState(180);
			match(OPEN_BRACKET);
			setState(181);
			match(IDENTIFIER);
			setState(182);
			match(COLON);
			setState(183);
			data_type();
			setState(184);
			match(CLOSE_BRACKET);
			setState(185);
			match(COLON);
			setState(186);
			conditions_list();
			setState(187);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Initial_state_declarationContext extends ParserRuleContext {
		public Initial_state_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initial_state_declaration; }
	 
		public Initial_state_declarationContext() { }
		public void copyFrom(Initial_state_declarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class InitialStateDeclContext extends Initial_state_declarationContext {
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public InitialStateDeclContext(Initial_state_declarationContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterInitialStateDecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitInitialStateDecl(this);
		}
	}

	public final Initial_state_declarationContext initial_state_declaration() throws RecognitionException {
		Initial_state_declarationContext _localctx = new Initial_state_declarationContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_initial_state_declaration);
		try {
			_localctx = new InitialStateDeclContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(189);
			arithmetic_expression(0);
			setState(190);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Trigger_definitionContext extends ParserRuleContext {
		public TerminalNode TRIGGER_DEFINITION_KEYWORD() { return getToken(KasXParser.TRIGGER_DEFINITION_KEYWORD, 0); }
		public Function_headerContext function_header() {
			return getRuleContext(Function_headerContext.class,0);
		}
		public TerminalNode START_CUR_BRACES() { return getToken(KasXParser.START_CUR_BRACES, 0); }
		public Trigger_bodyContext trigger_body() {
			return getRuleContext(Trigger_bodyContext.class,0);
		}
		public TerminalNode END_CUR_BRACES() { return getToken(KasXParser.END_CUR_BRACES, 0); }
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public Trigger_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_trigger_definition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterTrigger_definition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitTrigger_definition(this);
		}
	}

	public final Trigger_definitionContext trigger_definition() throws RecognitionException {
		Trigger_definitionContext _localctx = new Trigger_definitionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_trigger_definition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(192);
			match(TRIGGER_DEFINITION_KEYWORD);
			setState(193);
			function_header();
			setState(194);
			match(START_CUR_BRACES);
			setState(195);
			trigger_body();
			setState(196);
			match(END_CUR_BRACES);
			setState(197);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Trigger_bodyContext extends ParserRuleContext {
		public Precondition_blockContext precondition_block() {
			return getRuleContext(Precondition_blockContext.class,0);
		}
		public Effect_blockContext effect_block() {
			return getRuleContext(Effect_blockContext.class,0);
		}
		public Trigger_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_trigger_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterTrigger_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitTrigger_body(this);
		}
	}

	public final Trigger_bodyContext trigger_body() throws RecognitionException {
		Trigger_bodyContext _localctx = new Trigger_bodyContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_trigger_body);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(199);
			precondition_block();
			setState(200);
			effect_block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Utility_definitionContext extends ParserRuleContext {
		public TerminalNode UTILITY_DEFINITION_KEYWORD() { return getToken(KasXParser.UTILITY_DEFINITION_KEYWORD, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public Utility_definitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_utility_definition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterUtility_definition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitUtility_definition(this);
		}
	}

	public final Utility_definitionContext utility_definition() throws RecognitionException {
		Utility_definitionContext _localctx = new Utility_definitionContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_utility_definition);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			match(UTILITY_DEFINITION_KEYWORD);
			setState(203);
			match(OPEN_BRACKET);
			setState(205);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENTIFIER) {
				{
				setState(204);
				match(IDENTIFIER);
				}
			}

			setState(207);
			match(CLOSE_BRACKET);
			setState(208);
			match(COLON);
			setState(209);
			arithmetic_expression(0);
			setState(210);
			match(DEFINITION_SEPARATOR);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Identifiers_listContext extends ParserRuleContext {
		public List<TerminalNode> IDENTIFIER() { return getTokens(KasXParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(KasXParser.IDENTIFIER, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(KasXParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(KasXParser.COMMA, i);
		}
		public Identifiers_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifiers_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterIdentifiers_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitIdentifiers_list(this);
		}
	}

	public final Identifiers_listContext identifiers_list() throws RecognitionException {
		Identifiers_listContext _localctx = new Identifiers_listContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_identifiers_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENTIFIER) {
				{
				setState(212);
				match(IDENTIFIER);
				setState(217);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(213);
					match(COMMA);
					setState(214);
					match(IDENTIFIER);
					}
					}
					setState(219);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Conditions_listContext extends ParserRuleContext {
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public FluentContext fluent() {
			return getRuleContext(FluentContext.class,0);
		}
		public Conditions_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditions_list; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterConditions_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitConditions_list(this);
		}
	}

	public final Conditions_listContext conditions_list() throws RecognitionException {
		Conditions_listContext _localctx = new Conditions_listContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_conditions_list);
		try {
			setState(224);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(222);
				arithmetic_expression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(223);
				fluent();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Belives_expressionContext extends ParserRuleContext {
		public TerminalNode KEYWORD_BELIEVES() { return getToken(KasXParser.KEYWORD_BELIEVES, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode COMMA() { return getToken(KasXParser.COMMA, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public Belives_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_belives_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterBelives_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitBelives_expression(this);
		}
	}

	public final Belives_expressionContext belives_expression() throws RecognitionException {
		Belives_expressionContext _localctx = new Belives_expressionContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_belives_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(226);
			match(KEYWORD_BELIEVES);
			setState(227);
			match(OPEN_BRACKET);
			setState(228);
			match(IDENTIFIER);
			setState(229);
			match(COMMA);
			setState(230);
			arithmetic_expression(0);
			setState(231);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Exists_clauseContext extends ParserRuleContext {
		public TerminalNode EXISTENTIAL_QUANTIFICATION_KEYWORD() { return getToken(KasXParser.EXISTENTIAL_QUANTIFICATION_KEYWORD, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public ParamContext param() {
			return getRuleContext(ParamContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public Exists_clauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exists_clause; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExists_clause(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExists_clause(this);
		}
	}

	public final Exists_clauseContext exists_clause() throws RecognitionException {
		Exists_clauseContext _localctx = new Exists_clauseContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_exists_clause);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(233);
			match(EXISTENTIAL_QUANTIFICATION_KEYWORD);
			setState(234);
			match(OPEN_BRACKET);
			setState(235);
			param();
			setState(236);
			match(CLOSE_BRACKET);
			setState(237);
			arithmetic_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Arithmetic_expressionContext extends ParserRuleContext {
		public Arithmetic_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arithmetic_expression; }
	 
		public Arithmetic_expressionContext() { }
		public void copyFrom(Arithmetic_expressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprForAllContext extends Arithmetic_expressionContext {
		public Forall_functionContext forall_function() {
			return getRuleContext(Forall_functionContext.class,0);
		}
		public ExprForAllContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprForAll(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprForAll(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprIdentifierContext extends Arithmetic_expressionContext {
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public ExprIdentifierContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprIdentifier(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprIdentifier(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprSumContext extends Arithmetic_expressionContext {
		public Sum_functionContext sum_function() {
			return getRuleContext(Sum_functionContext.class,0);
		}
		public ExprSumContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprSum(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprSum(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprExistsContext extends Arithmetic_expressionContext {
		public Exists_clauseContext exists_clause() {
			return getRuleContext(Exists_clauseContext.class,0);
		}
		public ExprExistsContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprExists(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprExists(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprBooleanContext extends Arithmetic_expressionContext {
		public Boolean_dataContext boolean_data() {
			return getRuleContext(Boolean_dataContext.class,0);
		}
		public ExprBooleanContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprBoolean(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprBoolean(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprInBracketContext extends Arithmetic_expressionContext {
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public ExprInBracketContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprInBracket(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprInBracket(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprNegationContext extends Arithmetic_expressionContext {
		public Negation_expressionContext negation_expression() {
			return getRuleContext(Negation_expressionContext.class,0);
		}
		public ExprNegationContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprNegation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprNegation(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprNotContext extends Arithmetic_expressionContext {
		public Unary_not_expressionContext unary_not_expression() {
			return getRuleContext(Unary_not_expressionContext.class,0);
		}
		public ExprNotContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprNot(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprNot(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprBelivesContext extends Arithmetic_expressionContext {
		public Belives_expressionContext belives_expression() {
			return getRuleContext(Belives_expressionContext.class,0);
		}
		public ExprBelivesContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprBelives(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprBelives(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprIfElseContext extends Arithmetic_expressionContext {
		public If_else_blockContext if_else_block() {
			return getRuleContext(If_else_blockContext.class,0);
		}
		public ExprIfElseContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprIfElse(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprIfElse(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprUnknownContext extends Arithmetic_expressionContext {
		public TerminalNode UNKNOWN_KEYWORD() { return getToken(KasXParser.UNKNOWN_KEYWORD, 0); }
		public ExprUnknownContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprUnknown(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprUnknown(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprFluentContext extends Arithmetic_expressionContext {
		public FluentContext fluent() {
			return getRuleContext(FluentContext.class,0);
		}
		public ExprFluentContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprFluent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprFluent(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprNullClauseContext extends Arithmetic_expressionContext {
		public TerminalNode NULL_CLAUSE_KEYWORD() { return getToken(KasXParser.NULL_CLAUSE_KEYWORD, 0); }
		public ExprNullClauseContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprNullClause(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprNullClause(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprNumberContext extends Arithmetic_expressionContext {
		public TerminalNode NUMBER() { return getToken(KasXParser.NUMBER, 0); }
		public ExprNumberContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprNumber(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprNumber(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprBinaryOpContext extends Arithmetic_expressionContext {
		public List<Arithmetic_expressionContext> arithmetic_expression() {
			return getRuleContexts(Arithmetic_expressionContext.class);
		}
		public Arithmetic_expressionContext arithmetic_expression(int i) {
			return getRuleContext(Arithmetic_expressionContext.class,i);
		}
		public Binary_opContext binary_op() {
			return getRuleContext(Binary_opContext.class,0);
		}
		public ExprBinaryOpContext(Arithmetic_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprBinaryOp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprBinaryOp(this);
		}
	}

	public final Arithmetic_expressionContext arithmetic_expression() throws RecognitionException {
		return arithmetic_expression(0);
	}

	private Arithmetic_expressionContext arithmetic_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Arithmetic_expressionContext _localctx = new Arithmetic_expressionContext(_ctx, _parentState);
		Arithmetic_expressionContext _prevctx = _localctx;
		int _startState = 48;
		enterRecursionRule(_localctx, 48, RULE_arithmetic_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(257);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				{
				_localctx = new ExprNotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(240);
				unary_not_expression();
				}
				break;
			case 2:
				{
				_localctx = new ExprNegationContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(241);
				negation_expression();
				}
				break;
			case 3:
				{
				_localctx = new ExprInBracketContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(242);
				match(OPEN_BRACKET);
				setState(243);
				arithmetic_expression(0);
				setState(244);
				match(CLOSE_BRACKET);
				}
				break;
			case 4:
				{
				_localctx = new ExprBelivesContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(246);
				belives_expression();
				}
				break;
			case 5:
				{
				_localctx = new ExprFluentContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(247);
				fluent();
				}
				break;
			case 6:
				{
				_localctx = new ExprIfElseContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(248);
				if_else_block();
				}
				break;
			case 7:
				{
				_localctx = new ExprExistsContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(249);
				exists_clause();
				}
				break;
			case 8:
				{
				_localctx = new ExprSumContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(250);
				sum_function();
				}
				break;
			case 9:
				{
				_localctx = new ExprForAllContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(251);
				forall_function();
				}
				break;
			case 10:
				{
				_localctx = new ExprBooleanContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(252);
				boolean_data();
				}
				break;
			case 11:
				{
				_localctx = new ExprIdentifierContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(253);
				match(IDENTIFIER);
				}
				break;
			case 12:
				{
				_localctx = new ExprNumberContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(254);
				match(NUMBER);
				}
				break;
			case 13:
				{
				_localctx = new ExprUnknownContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(255);
				match(UNKNOWN_KEYWORD);
				}
				break;
			case 14:
				{
				_localctx = new ExprNullClauseContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(256);
				match(NULL_CLAUSE_KEYWORD);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(265);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ExprBinaryOpContext(new Arithmetic_expressionContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_arithmetic_expression);
					setState(259);
					if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
					setState(260);
					binary_op();
					setState(261);
					arithmetic_expression(13);
					}
					} 
				}
				setState(267);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,17,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Inheritance_expressionContext extends ParserRuleContext {
		public Inheritance_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inheritance_expression; }
	 
		public Inheritance_expressionContext() { }
		public void copyFrom(Inheritance_expressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprInheritanceContext extends Inheritance_expressionContext {
		public List<Arithmetic_expressionContext> arithmetic_expression() {
			return getRuleContexts(Arithmetic_expressionContext.class);
		}
		public Arithmetic_expressionContext arithmetic_expression(int i) {
			return getRuleContext(Arithmetic_expressionContext.class,i);
		}
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public ExprInheritanceContext(Inheritance_expressionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterExprInheritance(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitExprInheritance(this);
		}
	}

	public final Inheritance_expressionContext inheritance_expression() throws RecognitionException {
		Inheritance_expressionContext _localctx = new Inheritance_expressionContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_inheritance_expression);
		try {
			_localctx = new ExprInheritanceContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(268);
			arithmetic_expression(0);
			setState(269);
			match(COLON);
			setState(270);
			arithmetic_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Forall_functionContext extends ParserRuleContext {
		public TerminalNode UNIVERSAL_QUANTIFICATION_KEYWORD() { return getToken(KasXParser.UNIVERSAL_QUANTIFICATION_KEYWORD, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public List<TerminalNode> IDENTIFIER() { return getTokens(KasXParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(KasXParser.IDENTIFIER, i);
		}
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public Forall_functionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forall_function; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterForall_function(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitForall_function(this);
		}
	}

	public final Forall_functionContext forall_function() throws RecognitionException {
		Forall_functionContext _localctx = new Forall_functionContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_forall_function);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(272);
			match(UNIVERSAL_QUANTIFICATION_KEYWORD);
			setState(273);
			match(OPEN_BRACKET);
			setState(274);
			match(IDENTIFIER);
			setState(275);
			match(COLON);
			setState(276);
			match(IDENTIFIER);
			setState(277);
			match(CLOSE_BRACKET);
			setState(278);
			arithmetic_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Sum_functionContext extends ParserRuleContext {
		public TerminalNode SUM_KEYWORD() { return getToken(KasXParser.SUM_KEYWORD, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public List<TerminalNode> IDENTIFIER() { return getTokens(KasXParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(KasXParser.IDENTIFIER, i);
		}
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public Sum_functionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sum_function; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterSum_function(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitSum_function(this);
		}
	}

	public final Sum_functionContext sum_function() throws RecognitionException {
		Sum_functionContext _localctx = new Sum_functionContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_sum_function);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(280);
			match(SUM_KEYWORD);
			setState(281);
			match(OPEN_BRACKET);
			setState(282);
			match(IDENTIFIER);
			setState(283);
			match(COLON);
			setState(284);
			match(IDENTIFIER);
			setState(285);
			match(CLOSE_BRACKET);
			setState(286);
			arithmetic_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Unary_not_expressionContext extends ParserRuleContext {
		public TerminalNode NEGATION_KEYWORD() { return getToken(KasXParser.NEGATION_KEYWORD, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public Unary_not_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary_not_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterUnary_not_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitUnary_not_expression(this);
		}
	}

	public final Unary_not_expressionContext unary_not_expression() throws RecognitionException {
		Unary_not_expressionContext _localctx = new Unary_not_expressionContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_unary_not_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(288);
			match(NEGATION_KEYWORD);
			setState(289);
			arithmetic_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Negation_expressionContext extends ParserRuleContext {
		public TerminalNode SUBTRACTION_KEYWORD() { return getToken(KasXParser.SUBTRACTION_KEYWORD, 0); }
		public Arithmetic_expressionContext arithmetic_expression() {
			return getRuleContext(Arithmetic_expressionContext.class,0);
		}
		public Negation_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_negation_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterNegation_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitNegation_expression(this);
		}
	}

	public final Negation_expressionContext negation_expression() throws RecognitionException {
		Negation_expressionContext _localctx = new Negation_expressionContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_negation_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(291);
			match(SUBTRACTION_KEYWORD);
			setState(292);
			arithmetic_expression(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FluentContext extends ParserRuleContext {
		public FluentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fluent; }
	 
		public FluentContext() { }
		public void copyFrom(FluentContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FluentValContext extends FluentContext {
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(KasXParser.OPEN_BRACKET, 0); }
		public TerminalNode CLOSE_BRACKET() { return getToken(KasXParser.CLOSE_BRACKET, 0); }
		public Argument_listContext argument_list() {
			return getRuleContext(Argument_listContext.class,0);
		}
		public FluentValContext(FluentContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterFluentVal(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitFluentVal(this);
		}
	}

	public final FluentContext fluent() throws RecognitionException {
		FluentContext _localctx = new FluentContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_fluent);
		int _la;
		try {
			_localctx = new FluentValContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(294);
			match(IDENTIFIER);
			setState(295);
			match(OPEN_BRACKET);
			setState(297);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENTIFIER) {
				{
				setState(296);
				argument_list();
				}
			}

			setState(299);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Argument_listContext extends ParserRuleContext {
		public Argument_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argument_list; }
	 
		public Argument_listContext() { }
		public void copyFrom(Argument_listContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArgumentListContext extends Argument_listContext {
		public List<TerminalNode> IDENTIFIER() { return getTokens(KasXParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(KasXParser.IDENTIFIER, i);
		}
		public List<TerminalNode> COMMA() { return getTokens(KasXParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(KasXParser.COMMA, i);
		}
		public ArgumentListContext(Argument_listContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterArgumentList(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitArgumentList(this);
		}
	}

	public final Argument_listContext argument_list() throws RecognitionException {
		Argument_listContext _localctx = new Argument_listContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_argument_list);
		int _la;
		try {
			_localctx = new ArgumentListContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(301);
			match(IDENTIFIER);
			setState(306);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(302);
				match(COMMA);
				setState(303);
				match(IDENTIFIER);
				}
				}
				setState(308);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class If_else_blockContext extends ParserRuleContext {
		public TerminalNode CONDITIONAL_FIRST_BRANCH_KEYWORD() { return getToken(KasXParser.CONDITIONAL_FIRST_BRANCH_KEYWORD, 0); }
		public List<TerminalNode> OPEN_BRACKET() { return getTokens(KasXParser.OPEN_BRACKET); }
		public TerminalNode OPEN_BRACKET(int i) {
			return getToken(KasXParser.OPEN_BRACKET, i);
		}
		public List<Arithmetic_expressionContext> arithmetic_expression() {
			return getRuleContexts(Arithmetic_expressionContext.class);
		}
		public Arithmetic_expressionContext arithmetic_expression(int i) {
			return getRuleContext(Arithmetic_expressionContext.class,i);
		}
		public List<TerminalNode> CLOSE_BRACKET() { return getTokens(KasXParser.CLOSE_BRACKET); }
		public TerminalNode CLOSE_BRACKET(int i) {
			return getToken(KasXParser.CLOSE_BRACKET, i);
		}
		public List<Conditions_listContext> conditions_list() {
			return getRuleContexts(Conditions_listContext.class);
		}
		public Conditions_listContext conditions_list(int i) {
			return getRuleContext(Conditions_listContext.class,i);
		}
		public List<TerminalNode> CONDITIONAL_MIDDLE_BRANCH_KEYWORD() { return getTokens(KasXParser.CONDITIONAL_MIDDLE_BRANCH_KEYWORD); }
		public TerminalNode CONDITIONAL_MIDDLE_BRANCH_KEYWORD(int i) {
			return getToken(KasXParser.CONDITIONAL_MIDDLE_BRANCH_KEYWORD, i);
		}
		public TerminalNode CONDITIONAL_LAST_BRANCH_KEYWORD() { return getToken(KasXParser.CONDITIONAL_LAST_BRANCH_KEYWORD, 0); }
		public TerminalNode DEFINITION_SEPARATOR() { return getToken(KasXParser.DEFINITION_SEPARATOR, 0); }
		public If_else_blockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_if_else_block; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterIf_else_block(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitIf_else_block(this);
		}
	}

	public final If_else_blockContext if_else_block() throws RecognitionException {
		If_else_blockContext _localctx = new If_else_blockContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_if_else_block);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(309);
			match(CONDITIONAL_FIRST_BRANCH_KEYWORD);
			setState(310);
			match(OPEN_BRACKET);
			setState(311);
			arithmetic_expression(0);
			setState(312);
			match(CLOSE_BRACKET);
			setState(313);
			conditions_list();
			setState(322);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(314);
					match(CONDITIONAL_MIDDLE_BRANCH_KEYWORD);
					setState(315);
					match(OPEN_BRACKET);
					setState(316);
					arithmetic_expression(0);
					setState(317);
					match(CLOSE_BRACKET);
					setState(318);
					conditions_list();
					}
					} 
				}
				setState(324);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,20,_ctx);
			}
			setState(327);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,21,_ctx) ) {
			case 1:
				{
				setState(325);
				match(CONDITIONAL_LAST_BRANCH_KEYWORD);
				setState(326);
				conditions_list();
				}
				break;
			}
			setState(330);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				{
				setState(329);
				match(DEFINITION_SEPARATOR);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Binary_opContext extends ParserRuleContext {
		public Token op;
		public TerminalNode SUBTRACTION_KEYWORD() { return getToken(KasXParser.SUBTRACTION_KEYWORD, 0); }
		public TerminalNode ADDITION_KEYWORD() { return getToken(KasXParser.ADDITION_KEYWORD, 0); }
		public TerminalNode DIVISION_KEYWORD() { return getToken(KasXParser.DIVISION_KEYWORD, 0); }
		public TerminalNode MULTIPLICATION_KEYWORD() { return getToken(KasXParser.MULTIPLICATION_KEYWORD, 0); }
		public TerminalNode LESS_THAN_KEYWORD() { return getToken(KasXParser.LESS_THAN_KEYWORD, 0); }
		public TerminalNode GREATER_THAN_KEYWORD() { return getToken(KasXParser.GREATER_THAN_KEYWORD, 0); }
		public TerminalNode LESS_THAN_OR_EQUAL_TO_KEYWORD() { return getToken(KasXParser.LESS_THAN_OR_EQUAL_TO_KEYWORD, 0); }
		public TerminalNode GREATER_THAN_OR_EQUAL_TO_KEYWORD() { return getToken(KasXParser.GREATER_THAN_OR_EQUAL_TO_KEYWORD, 0); }
		public TerminalNode NOT_EQUAL_TO_KEYWORD() { return getToken(KasXParser.NOT_EQUAL_TO_KEYWORD, 0); }
		public TerminalNode EQUAL_TO_KEYWORD() { return getToken(KasXParser.EQUAL_TO_KEYWORD, 0); }
		public TerminalNode ASSIGNMENT_KEYWORD() { return getToken(KasXParser.ASSIGNMENT_KEYWORD, 0); }
		public TerminalNode DISJUNCTION_KEYWORD() { return getToken(KasXParser.DISJUNCTION_KEYWORD, 0); }
		public TerminalNode CONJUNCTION_KEYWORD() { return getToken(KasXParser.CONJUNCTION_KEYWORD, 0); }
		public TerminalNode COLON() { return getToken(KasXParser.COLON, 0); }
		public Binary_opContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_binary_op; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterBinary_op(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitBinary_op(this);
		}
	}

	public final Binary_opContext binary_op() throws RecognitionException {
		Binary_opContext _localctx = new Binary_opContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_binary_op);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(332);
			((Binary_opContext)_localctx).op = _input.LT(1);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 2322026823942144L) != 0)) ) {
				((Binary_opContext)_localctx).op = (Token)_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Boolean_dataContext extends ParserRuleContext {
		public Boolean_dataContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolean_data; }
	 
		public Boolean_dataContext() { }
		public void copyFrom(Boolean_dataContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TrueValueContext extends Boolean_dataContext {
		public TerminalNode TRUE_KEYWORD() { return getToken(KasXParser.TRUE_KEYWORD, 0); }
		public TrueValueContext(Boolean_dataContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterTrueValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitTrueValue(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FalseValueContext extends Boolean_dataContext {
		public TerminalNode FALSE_KEYWORD() { return getToken(KasXParser.FALSE_KEYWORD, 0); }
		public FalseValueContext(Boolean_dataContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterFalseValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitFalseValue(this);
		}
	}

	public final Boolean_dataContext boolean_data() throws RecognitionException {
		Boolean_dataContext _localctx = new Boolean_dataContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_boolean_data);
		try {
			setState(336);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE_KEYWORD:
				_localctx = new TrueValueContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(334);
				match(TRUE_KEYWORD);
				}
				break;
			case FALSE_KEYWORD:
				_localctx = new FalseValueContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(335);
				match(FALSE_KEYWORD);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Data_typeContext extends ParserRuleContext {
		public TerminalNode UNKNOWN_KEYWORD() { return getToken(KasXParser.UNKNOWN_KEYWORD, 0); }
		public TerminalNode NUMBER_KEYWORD() { return getToken(KasXParser.NUMBER_KEYWORD, 0); }
		public TerminalNode BOOLEAN_KEYWORD() { return getToken(KasXParser.BOOLEAN_KEYWORD, 0); }
		public TerminalNode ENTITY_DEFINITION_KEYWORD() { return getToken(KasXParser.ENTITY_DEFINITION_KEYWORD, 0); }
		public TerminalNode IDENTIFIER() { return getToken(KasXParser.IDENTIFIER, 0); }
		public TerminalNode NUMBER() { return getToken(KasXParser.NUMBER, 0); }
		public Data_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_data_type; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).enterData_type(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof KasXListener ) ((KasXListener)listener).exitData_type(this);
		}
	}

	public final Data_typeContext data_type() throws RecognitionException {
		Data_typeContext _localctx = new Data_typeContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_data_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(338);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 470155296L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 24:
			return arithmetic_expression_sempred((Arithmetic_expressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean arithmetic_expression_sempred(Arithmetic_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 12);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u00015\u0155\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002\u001e\u0007\u001e"+
		"\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007!\u0002\"\u0007\"\u0002"+
		"#\u0007#\u0001\u0000\u0005\u0000J\b\u0000\n\u0000\f\u0000M\t\u0000\u0001"+
		"\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0003\u0001X\b\u0001\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0003\u0002c\b\u0002\u0001\u0003\u0001\u0003\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0005\u0004j\b\u0004\n\u0004\f\u0004m\t"+
		"\u0004\u0003\u0004o\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0005"+
		"\u0007\u0080\b\u0007\n\u0007\f\u0007\u0083\t\u0007\u0003\u0007\u0085\b"+
		"\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0003\b\u008b\b\b\u0001\t\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\u000b\u0003\u000b\u009a\b\u000b\u0001\u000b\u0003\u000b"+
		"\u009d\b\u000b\u0001\u000b\u0003\u000b\u00a0\b\u000b\u0001\u000b\u0003"+
		"\u000b\u00a3\b\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\f\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0003\u0013\u00ce\b\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014"+
		"\u0001\u0014\u0005\u0014\u00d8\b\u0014\n\u0014\f\u0014\u00db\t\u0014\u0003"+
		"\u0014\u00dd\b\u0014\u0001\u0015\u0001\u0015\u0003\u0015\u00e1\b\u0015"+
		"\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016\u0001\u0016"+
		"\u0001\u0016\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017\u0001\u0017"+
		"\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0003\u0018\u0102\b\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0005\u0018\u0108\b\u0018\n\u0018\f\u0018\u010b\t\u0018\u0001"+
		"\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u001a\u0001\u001a\u0001"+
		"\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001a\u0001"+
		"\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001\u001b\u0001"+
		"\u001b\u0001\u001b\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001"+
		"\u001d\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0003\u001e\u012a"+
		"\b\u001e\u0001\u001e\u0001\u001e\u0001\u001f\u0001\u001f\u0001\u001f\u0005"+
		"\u001f\u0131\b\u001f\n\u001f\f\u001f\u0134\t\u001f\u0001 \u0001 \u0001"+
		" \u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0001 \u0005 \u0141"+
		"\b \n \f \u0144\t \u0001 \u0001 \u0003 \u0148\b \u0001 \u0003 \u014b\b"+
		" \u0001!\u0001!\u0001\"\u0001\"\u0003\"\u0151\b\"\u0001#\u0001#\u0001"+
		"#\u0000\u00010$\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014"+
		"\u0016\u0018\u001a\u001c\u001e \"$&(*,.02468:<>@BDF\u0000\u0003\u0002"+
		"\u0000\u0005\u0005\u001b\u001b\u0003\u0000 $&-33\u0003\u0000\u0005\u0005"+
		"\u0011\u0012\u001a\u001c\u0159\u0000K\u0001\u0000\u0000\u0000\u0002W\u0001"+
		"\u0000\u0000\u0000\u0004b\u0001\u0000\u0000\u0000\u0006d\u0001\u0000\u0000"+
		"\u0000\bn\u0001\u0000\u0000\u0000\np\u0001\u0000\u0000\u0000\fv\u0001"+
		"\u0000\u0000\u0000\u000e\u0084\u0001\u0000\u0000\u0000\u0010\u008a\u0001"+
		"\u0000\u0000\u0000\u0012\u008c\u0001\u0000\u0000\u0000\u0014\u0093\u0001"+
		"\u0000\u0000\u0000\u0016\u0099\u0001\u0000\u0000\u0000\u0018\u00a4\u0001"+
		"\u0000\u0000\u0000\u001a\u00a9\u0001\u0000\u0000\u0000\u001c\u00ae\u0001"+
		"\u0000\u0000\u0000\u001e\u00b3\u0001\u0000\u0000\u0000 \u00bd\u0001\u0000"+
		"\u0000\u0000\"\u00c0\u0001\u0000\u0000\u0000$\u00c7\u0001\u0000\u0000"+
		"\u0000&\u00ca\u0001\u0000\u0000\u0000(\u00dc\u0001\u0000\u0000\u0000*"+
		"\u00e0\u0001\u0000\u0000\u0000,\u00e2\u0001\u0000\u0000\u0000.\u00e9\u0001"+
		"\u0000\u0000\u00000\u0101\u0001\u0000\u0000\u00002\u010c\u0001\u0000\u0000"+
		"\u00004\u0110\u0001\u0000\u0000\u00006\u0118\u0001\u0000\u0000\u00008"+
		"\u0120\u0001\u0000\u0000\u0000:\u0123\u0001\u0000\u0000\u0000<\u0126\u0001"+
		"\u0000\u0000\u0000>\u012d\u0001\u0000\u0000\u0000@\u0135\u0001\u0000\u0000"+
		"\u0000B\u014c\u0001\u0000\u0000\u0000D\u0150\u0001\u0000\u0000\u0000F"+
		"\u0152\u0001\u0000\u0000\u0000HJ\u0003\u0002\u0001\u0000IH\u0001\u0000"+
		"\u0000\u0000JM\u0001\u0000\u0000\u0000KI\u0001\u0000\u0000\u0000KL\u0001"+
		"\u0000\u0000\u0000LN\u0001\u0000\u0000\u0000MK\u0001\u0000\u0000\u0000"+
		"NO\u0005\u0000\u0000\u0001O\u0001\u0001\u0000\u0000\u0000PX\u0003\u0004"+
		"\u0002\u0000QX\u0003\n\u0005\u0000RX\u0003\f\u0006\u0000SX\u0003 \u0010"+
		"\u0000TX\u0003\u0012\t\u0000UX\u0003\"\u0011\u0000VX\u0003&\u0013\u0000"+
		"WP\u0001\u0000\u0000\u0000WQ\u0001\u0000\u0000\u0000WR\u0001\u0000\u0000"+
		"\u0000WS\u0001\u0000\u0000\u0000WT\u0001\u0000\u0000\u0000WU\u0001\u0000"+
		"\u0000\u0000WV\u0001\u0000\u0000\u0000X\u0003\u0001\u0000\u0000\u0000"+
		"YZ\u0005\u0004\u0000\u0000Z[\u0005\u001b\u0000\u0000[c\u00052\u0000\u0000"+
		"\\]\u0005\u0004\u0000\u0000]^\u0005\u001b\u0000\u0000^_\u00053\u0000\u0000"+
		"_`\u0003\b\u0004\u0000`a\u00052\u0000\u0000ac\u0001\u0000\u0000\u0000"+
		"bY\u0001\u0000\u0000\u0000b\\\u0001\u0000\u0000\u0000c\u0005\u0001\u0000"+
		"\u0000\u0000de\u0007\u0000\u0000\u0000e\u0007\u0001\u0000\u0000\u0000"+
		"fk\u0003\u0006\u0003\u0000gh\u00054\u0000\u0000hj\u0003\u0006\u0003\u0000"+
		"ig\u0001\u0000\u0000\u0000jm\u0001\u0000\u0000\u0000ki\u0001\u0000\u0000"+
		"\u0000kl\u0001\u0000\u0000\u0000lo\u0001\u0000\u0000\u0000mk\u0001\u0000"+
		"\u0000\u0000nf\u0001\u0000\u0000\u0000no\u0001\u0000\u0000\u0000o\t\u0001"+
		"\u0000\u0000\u0000pq\u0005\u0005\u0000\u0000qr\u0005\u001b\u0000\u0000"+
		"rs\u00053\u0000\u0000st\u0003\b\u0004\u0000tu\u00052\u0000\u0000u\u000b"+
		"\u0001\u0000\u0000\u0000vw\u0005\u0006\u0000\u0000wx\u0003\u0014\n\u0000"+
		"xy\u00053\u0000\u0000yz\u0003F#\u0000z{\u00052\u0000\u0000{\r\u0001\u0000"+
		"\u0000\u0000|\u0081\u0003\u0010\b\u0000}~\u00054\u0000\u0000~\u0080\u0003"+
		"\u0010\b\u0000\u007f}\u0001\u0000\u0000\u0000\u0080\u0083\u0001\u0000"+
		"\u0000\u0000\u0081\u007f\u0001\u0000\u0000\u0000\u0081\u0082\u0001\u0000"+
		"\u0000\u0000\u0082\u0085\u0001\u0000\u0000\u0000\u0083\u0081\u0001\u0000"+
		"\u0000\u0000\u0084|\u0001\u0000\u0000\u0000\u0084\u0085\u0001\u0000\u0000"+
		"\u0000\u0085\u000f\u0001\u0000\u0000\u0000\u0086\u0087\u0005\u001b\u0000"+
		"\u0000\u0087\u0088\u00053\u0000\u0000\u0088\u008b\u0003F#\u0000\u0089"+
		"\u008b\u0005\u001b\u0000\u0000\u008a\u0086\u0001\u0000\u0000\u0000\u008a"+
		"\u0089\u0001\u0000\u0000\u0000\u008b\u0011\u0001\u0000\u0000\u0000\u008c"+
		"\u008d\u0005\u0007\u0000\u0000\u008d\u008e\u0003\u0014\n\u0000\u008e\u008f"+
		"\u00050\u0000\u0000\u008f\u0090\u0003\u0016\u000b\u0000\u0090\u0091\u0005"+
		"1\u0000\u0000\u0091\u0092\u00052\u0000\u0000\u0092\u0013\u0001\u0000\u0000"+
		"\u0000\u0093\u0094\u0005\u001b\u0000\u0000\u0094\u0095\u0005.\u0000\u0000"+
		"\u0095\u0096\u0003\u000e\u0007\u0000\u0096\u0097\u0005/\u0000\u0000\u0097"+
		"\u0015\u0001\u0000\u0000\u0000\u0098\u009a\u0003\u0018\f\u0000\u0099\u0098"+
		"\u0001\u0000\u0000\u0000\u0099\u009a\u0001\u0000\u0000\u0000\u009a\u009c"+
		"\u0001\u0000\u0000\u0000\u009b\u009d\u0003\u001a\r\u0000\u009c\u009b\u0001"+
		"\u0000\u0000\u0000\u009c\u009d\u0001\u0000\u0000\u0000\u009d\u009f\u0001"+
		"\u0000\u0000\u0000\u009e\u00a0\u0003\u001c\u000e\u0000\u009f\u009e\u0001"+
		"\u0000\u0000\u0000\u009f\u00a0\u0001\u0000\u0000\u0000\u00a0\u00a2\u0001"+
		"\u0000\u0000\u0000\u00a1\u00a3\u0003\u001e\u000f\u0000\u00a2\u00a1\u0001"+
		"\u0000\u0000\u0000\u00a2\u00a3\u0001\u0000\u0000\u0000\u00a3\u0017\u0001"+
		"\u0000\u0000\u0000\u00a4\u00a5\u0005\u0013\u0000\u0000\u00a5\u00a6\u0005"+
		"3\u0000\u0000\u00a6\u00a7\u0003*\u0015\u0000\u00a7\u00a8\u00052\u0000"+
		"\u0000\u00a8\u0019\u0001\u0000\u0000\u0000\u00a9\u00aa\u0005\u0014\u0000"+
		"\u0000\u00aa\u00ab\u00053\u0000\u0000\u00ab\u00ac\u0003*\u0015\u0000\u00ac"+
		"\u00ad\u00052\u0000\u0000\u00ad\u001b\u0001\u0000\u0000\u0000\u00ae\u00af"+
		"\u0005\u0015\u0000\u0000\u00af\u00b0\u00053\u0000\u0000\u00b0\u00b1\u0003"+
		"(\u0014\u0000\u00b1\u00b2\u00052\u0000\u0000\u00b2\u001d\u0001\u0000\u0000"+
		"\u0000\u00b3\u00b4\u0005\u0016\u0000\u0000\u00b4\u00b5\u0005.\u0000\u0000"+
		"\u00b5\u00b6\u0005\u001b\u0000\u0000\u00b6\u00b7\u00053\u0000\u0000\u00b7"+
		"\u00b8\u0003F#\u0000\u00b8\u00b9\u0005/\u0000\u0000\u00b9\u00ba\u0005"+
		"3\u0000\u0000\u00ba\u00bb\u0003*\u0015\u0000\u00bb\u00bc\u00052\u0000"+
		"\u0000\u00bc\u001f\u0001\u0000\u0000\u0000\u00bd\u00be\u00030\u0018\u0000"+
		"\u00be\u00bf\u00052\u0000\u0000\u00bf!\u0001\u0000\u0000\u0000\u00c0\u00c1"+
		"\u0005\b\u0000\u0000\u00c1\u00c2\u0003\u0014\n\u0000\u00c2\u00c3\u0005"+
		"0\u0000\u0000\u00c3\u00c4\u0003$\u0012\u0000\u00c4\u00c5\u00051\u0000"+
		"\u0000\u00c5\u00c6\u00052\u0000\u0000\u00c6#\u0001\u0000\u0000\u0000\u00c7"+
		"\u00c8\u0003\u0018\f\u0000\u00c8\u00c9\u0003\u001a\r\u0000\u00c9%\u0001"+
		"\u0000\u0000\u0000\u00ca\u00cb\u0005\n\u0000\u0000\u00cb\u00cd\u0005."+
		"\u0000\u0000\u00cc\u00ce\u0005\u001b\u0000\u0000\u00cd\u00cc\u0001\u0000"+
		"\u0000\u0000\u00cd\u00ce\u0001\u0000\u0000\u0000\u00ce\u00cf\u0001\u0000"+
		"\u0000\u0000\u00cf\u00d0\u0005/\u0000\u0000\u00d0\u00d1\u00053\u0000\u0000"+
		"\u00d1\u00d2\u00030\u0018\u0000\u00d2\u00d3\u00052\u0000\u0000\u00d3\'"+
		"\u0001\u0000\u0000\u0000\u00d4\u00d9\u0005\u001b\u0000\u0000\u00d5\u00d6"+
		"\u00054\u0000\u0000\u00d6\u00d8\u0005\u001b\u0000\u0000\u00d7\u00d5\u0001"+
		"\u0000\u0000\u0000\u00d8\u00db\u0001\u0000\u0000\u0000\u00d9\u00d7\u0001"+
		"\u0000\u0000\u0000\u00d9\u00da\u0001\u0000\u0000\u0000\u00da\u00dd\u0001"+
		"\u0000\u0000\u0000\u00db\u00d9\u0001\u0000\u0000\u0000\u00dc\u00d4\u0001"+
		"\u0000\u0000\u0000\u00dc\u00dd\u0001\u0000\u0000\u0000\u00dd)\u0001\u0000"+
		"\u0000\u0000\u00de\u00e1\u00030\u0018\u0000\u00df\u00e1\u0003<\u001e\u0000"+
		"\u00e0\u00de\u0001\u0000\u0000\u0000\u00e0\u00df\u0001\u0000\u0000\u0000"+
		"\u00e1+\u0001\u0000\u0000\u0000\u00e2\u00e3\u0005\t\u0000\u0000\u00e3"+
		"\u00e4\u0005.\u0000\u0000\u00e4\u00e5\u0005\u001b\u0000\u0000\u00e5\u00e6"+
		"\u00054\u0000\u0000\u00e6\u00e7\u00030\u0018\u0000\u00e7\u00e8\u0005/"+
		"\u0000\u0000\u00e8-\u0001\u0000\u0000\u0000\u00e9\u00ea\u0005\u000b\u0000"+
		"\u0000\u00ea\u00eb\u0005.\u0000\u0000\u00eb\u00ec\u0003\u0010\b\u0000"+
		"\u00ec\u00ed\u0005/\u0000\u0000\u00ed\u00ee\u00030\u0018\u0000\u00ee/"+
		"\u0001\u0000\u0000\u0000\u00ef\u00f0\u0006\u0018\uffff\uffff\u0000\u00f0"+
		"\u0102\u00038\u001c\u0000\u00f1\u0102\u0003:\u001d\u0000\u00f2\u00f3\u0005"+
		".\u0000\u0000\u00f3\u00f4\u00030\u0018\u0000\u00f4\u00f5\u0005/\u0000"+
		"\u0000\u00f5\u0102\u0001\u0000\u0000\u0000\u00f6\u0102\u0003,\u0016\u0000"+
		"\u00f7\u0102\u0003<\u001e\u0000\u00f8\u0102\u0003@ \u0000\u00f9\u0102"+
		"\u0003.\u0017\u0000\u00fa\u0102\u00036\u001b\u0000\u00fb\u0102\u00034"+
		"\u001a\u0000\u00fc\u0102\u0003D\"\u0000\u00fd\u0102\u0005\u001b\u0000"+
		"\u0000\u00fe\u0102\u0005\u001a\u0000\u0000\u00ff\u0102\u0005\u001c\u0000"+
		"\u0000\u0100\u0102\u0005\u001f\u0000\u0000\u0101\u00ef\u0001\u0000\u0000"+
		"\u0000\u0101\u00f1\u0001\u0000\u0000\u0000\u0101\u00f2\u0001\u0000\u0000"+
		"\u0000\u0101\u00f6\u0001\u0000\u0000\u0000\u0101\u00f7\u0001\u0000\u0000"+
		"\u0000\u0101\u00f8\u0001\u0000\u0000\u0000\u0101\u00f9\u0001\u0000\u0000"+
		"\u0000\u0101\u00fa\u0001\u0000\u0000\u0000\u0101\u00fb\u0001\u0000\u0000"+
		"\u0000\u0101\u00fc\u0001\u0000\u0000\u0000\u0101\u00fd\u0001\u0000\u0000"+
		"\u0000\u0101\u00fe\u0001\u0000\u0000\u0000\u0101\u00ff\u0001\u0000\u0000"+
		"\u0000\u0101\u0100\u0001\u0000\u0000\u0000\u0102\u0109\u0001\u0000\u0000"+
		"\u0000\u0103\u0104\n\f\u0000\u0000\u0104\u0105\u0003B!\u0000\u0105\u0106"+
		"\u00030\u0018\r\u0106\u0108\u0001\u0000\u0000\u0000\u0107\u0103\u0001"+
		"\u0000\u0000\u0000\u0108\u010b\u0001\u0000\u0000\u0000\u0109\u0107\u0001"+
		"\u0000\u0000\u0000\u0109\u010a\u0001\u0000\u0000\u0000\u010a1\u0001\u0000"+
		"\u0000\u0000\u010b\u0109\u0001\u0000\u0000\u0000\u010c\u010d\u00030\u0018"+
		"\u0000\u010d\u010e\u00053\u0000\u0000\u010e\u010f\u00030\u0018\u0000\u010f"+
		"3\u0001\u0000\u0000\u0000\u0110\u0111\u0005\r\u0000\u0000\u0111\u0112"+
		"\u0005.\u0000\u0000\u0112\u0113\u0005\u001b\u0000\u0000\u0113\u0114\u0005"+
		"3\u0000\u0000\u0114\u0115\u0005\u001b\u0000\u0000\u0115\u0116\u0005/\u0000"+
		"\u0000\u0116\u0117\u00030\u0018\u0000\u01175\u0001\u0000\u0000\u0000\u0118"+
		"\u0119\u0005\u000f\u0000\u0000\u0119\u011a\u0005.\u0000\u0000\u011a\u011b"+
		"\u0005\u001b\u0000\u0000\u011b\u011c\u00053\u0000\u0000\u011c\u011d\u0005"+
		"\u001b\u0000\u0000\u011d\u011e\u0005/\u0000\u0000\u011e\u011f\u00030\u0018"+
		"\u0000\u011f7\u0001\u0000\u0000\u0000\u0120\u0121\u0005%\u0000\u0000\u0121"+
		"\u0122\u00030\u0018\u0000\u01229\u0001\u0000\u0000\u0000\u0123\u0124\u0005"+
		"-\u0000\u0000\u0124\u0125\u00030\u0018\u0000\u0125;\u0001\u0000\u0000"+
		"\u0000\u0126\u0127\u0005\u001b\u0000\u0000\u0127\u0129\u0005.\u0000\u0000"+
		"\u0128\u012a\u0003>\u001f\u0000\u0129\u0128\u0001\u0000\u0000\u0000\u0129"+
		"\u012a\u0001\u0000\u0000\u0000\u012a\u012b\u0001\u0000\u0000\u0000\u012b"+
		"\u012c\u0005/\u0000\u0000\u012c=\u0001\u0000\u0000\u0000\u012d\u0132\u0005"+
		"\u001b\u0000\u0000\u012e\u012f\u00054\u0000\u0000\u012f\u0131\u0005\u001b"+
		"\u0000\u0000\u0130\u012e\u0001\u0000\u0000\u0000\u0131\u0134\u0001\u0000"+
		"\u0000\u0000\u0132\u0130\u0001\u0000\u0000\u0000\u0132\u0133\u0001\u0000"+
		"\u0000\u0000\u0133?\u0001\u0000\u0000\u0000\u0134\u0132\u0001\u0000\u0000"+
		"\u0000\u0135\u0136\u0005\u0017\u0000\u0000\u0136\u0137\u0005.\u0000\u0000"+
		"\u0137\u0138\u00030\u0018\u0000\u0138\u0139\u0005/\u0000\u0000\u0139\u0142"+
		"\u0003*\u0015\u0000\u013a\u013b\u0005\u0019\u0000\u0000\u013b\u013c\u0005"+
		".\u0000\u0000\u013c\u013d\u00030\u0018\u0000\u013d\u013e\u0005/\u0000"+
		"\u0000\u013e\u013f\u0003*\u0015\u0000\u013f\u0141\u0001\u0000\u0000\u0000"+
		"\u0140\u013a\u0001\u0000\u0000\u0000\u0141\u0144\u0001\u0000\u0000\u0000"+
		"\u0142\u0140\u0001\u0000\u0000\u0000\u0142\u0143\u0001\u0000\u0000\u0000"+
		"\u0143\u0147\u0001\u0000\u0000\u0000\u0144\u0142\u0001\u0000\u0000\u0000"+
		"\u0145\u0146\u0005\u0018\u0000\u0000\u0146\u0148\u0003*\u0015\u0000\u0147"+
		"\u0145\u0001\u0000\u0000\u0000\u0147\u0148\u0001\u0000\u0000\u0000\u0148"+
		"\u014a\u0001\u0000\u0000\u0000\u0149\u014b\u00052\u0000\u0000\u014a\u0149"+
		"\u0001\u0000\u0000\u0000\u014a\u014b\u0001\u0000\u0000\u0000\u014bA\u0001"+
		"\u0000\u0000\u0000\u014c\u014d\u0007\u0001\u0000\u0000\u014dC\u0001\u0000"+
		"\u0000\u0000\u014e\u0151\u0005\u001e\u0000\u0000\u014f\u0151\u0005\u001d"+
		"\u0000\u0000\u0150\u014e\u0001\u0000\u0000\u0000\u0150\u014f\u0001\u0000"+
		"\u0000\u0000\u0151E\u0001\u0000\u0000\u0000\u0152\u0153\u0007\u0002\u0000"+
		"\u0000\u0153G\u0001\u0000\u0000\u0000\u0018KWbkn\u0081\u0084\u008a\u0099"+
		"\u009c\u009f\u00a2\u00cd\u00d9\u00dc\u00e0\u0101\u0109\u0129\u0132\u0142"+
		"\u0147\u014a\u0150";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}