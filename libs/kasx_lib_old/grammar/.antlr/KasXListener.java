// Generated from /home/lazzy07/projects/kastane_x/compiler/libs/kasx_lib/grammar/KasX.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link KasXParser}.
 */
public interface KasXListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by the {@code Program}
	 * labeled alternative in {@link KasXParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProgram(KasXParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Program}
	 * labeled alternative in {@link KasXParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProgram(KasXParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#definition}.
	 * @param ctx the parse tree
	 */
	void enterDefinition(KasXParser.DefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#definition}.
	 * @param ctx the parse tree
	 */
	void exitDefinition(KasXParser.DefinitionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TypeDeclarationNoParents}
	 * labeled alternative in {@link KasXParser#type_declaration}.
	 * @param ctx the parse tree
	 */
	void enterTypeDeclarationNoParents(KasXParser.TypeDeclarationNoParentsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TypeDeclarationNoParents}
	 * labeled alternative in {@link KasXParser#type_declaration}.
	 * @param ctx the parse tree
	 */
	void exitTypeDeclarationNoParents(KasXParser.TypeDeclarationNoParentsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TypeDeclarationWithParents}
	 * labeled alternative in {@link KasXParser#type_declaration}.
	 * @param ctx the parse tree
	 */
	void enterTypeDeclarationWithParents(KasXParser.TypeDeclarationWithParentsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TypeDeclarationWithParents}
	 * labeled alternative in {@link KasXParser#type_declaration}.
	 * @param ctx the parse tree
	 */
	void exitTypeDeclarationWithParents(KasXParser.TypeDeclarationWithParentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#type_name}.
	 * @param ctx the parse tree
	 */
	void enterType_name(KasXParser.Type_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#type_name}.
	 * @param ctx the parse tree
	 */
	void exitType_name(KasXParser.Type_nameContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TypesList}
	 * labeled alternative in {@link KasXParser#types_list}.
	 * @param ctx the parse tree
	 */
	void enterTypesList(KasXParser.TypesListContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TypesList}
	 * labeled alternative in {@link KasXParser#types_list}.
	 * @param ctx the parse tree
	 */
	void exitTypesList(KasXParser.TypesListContext ctx);
	/**
	 * Enter a parse tree produced by the {@code EntityDeclaration}
	 * labeled alternative in {@link KasXParser#entity_declaration}.
	 * @param ctx the parse tree
	 */
	void enterEntityDeclaration(KasXParser.EntityDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code EntityDeclaration}
	 * labeled alternative in {@link KasXParser#entity_declaration}.
	 * @param ctx the parse tree
	 */
	void exitEntityDeclaration(KasXParser.EntityDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FluentDeclaration}
	 * labeled alternative in {@link KasXParser#fluent_declaration}.
	 * @param ctx the parse tree
	 */
	void enterFluentDeclaration(KasXParser.FluentDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FluentDeclaration}
	 * labeled alternative in {@link KasXParser#fluent_declaration}.
	 * @param ctx the parse tree
	 */
	void exitFluentDeclaration(KasXParser.FluentDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParamList}
	 * labeled alternative in {@link KasXParser#param_list}.
	 * @param ctx the parse tree
	 */
	void enterParamList(KasXParser.ParamListContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParamList}
	 * labeled alternative in {@link KasXParser#param_list}.
	 * @param ctx the parse tree
	 */
	void exitParamList(KasXParser.ParamListContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParamWithDataType}
	 * labeled alternative in {@link KasXParser#param}.
	 * @param ctx the parse tree
	 */
	void enterParamWithDataType(KasXParser.ParamWithDataTypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParamWithDataType}
	 * labeled alternative in {@link KasXParser#param}.
	 * @param ctx the parse tree
	 */
	void exitParamWithDataType(KasXParser.ParamWithDataTypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ParamWithoutDataType}
	 * labeled alternative in {@link KasXParser#param}.
	 * @param ctx the parse tree
	 */
	void enterParamWithoutDataType(KasXParser.ParamWithoutDataTypeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ParamWithoutDataType}
	 * labeled alternative in {@link KasXParser#param}.
	 * @param ctx the parse tree
	 */
	void exitParamWithoutDataType(KasXParser.ParamWithoutDataTypeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ActionDecl}
	 * labeled alternative in {@link KasXParser#action_definition}.
	 * @param ctx the parse tree
	 */
	void enterActionDecl(KasXParser.ActionDeclContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ActionDecl}
	 * labeled alternative in {@link KasXParser#action_definition}.
	 * @param ctx the parse tree
	 */
	void exitActionDecl(KasXParser.ActionDeclContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FunctionHeader}
	 * labeled alternative in {@link KasXParser#function_header}.
	 * @param ctx the parse tree
	 */
	void enterFunctionHeader(KasXParser.FunctionHeaderContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FunctionHeader}
	 * labeled alternative in {@link KasXParser#function_header}.
	 * @param ctx the parse tree
	 */
	void exitFunctionHeader(KasXParser.FunctionHeaderContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#action_body}.
	 * @param ctx the parse tree
	 */
	void enterAction_body(KasXParser.Action_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#action_body}.
	 * @param ctx the parse tree
	 */
	void exitAction_body(KasXParser.Action_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#precondition_block}.
	 * @param ctx the parse tree
	 */
	void enterPrecondition_block(KasXParser.Precondition_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#precondition_block}.
	 * @param ctx the parse tree
	 */
	void exitPrecondition_block(KasXParser.Precondition_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#effect_block}.
	 * @param ctx the parse tree
	 */
	void enterEffect_block(KasXParser.Effect_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#effect_block}.
	 * @param ctx the parse tree
	 */
	void exitEffect_block(KasXParser.Effect_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#consenting_list}.
	 * @param ctx the parse tree
	 */
	void enterConsenting_list(KasXParser.Consenting_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#consenting_list}.
	 * @param ctx the parse tree
	 */
	void exitConsenting_list(KasXParser.Consenting_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#observing_fun}.
	 * @param ctx the parse tree
	 */
	void enterObserving_fun(KasXParser.Observing_funContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#observing_fun}.
	 * @param ctx the parse tree
	 */
	void exitObserving_fun(KasXParser.Observing_funContext ctx);
	/**
	 * Enter a parse tree produced by the {@code InitialStateDecl}
	 * labeled alternative in {@link KasXParser#initial_state_declaration}.
	 * @param ctx the parse tree
	 */
	void enterInitialStateDecl(KasXParser.InitialStateDeclContext ctx);
	/**
	 * Exit a parse tree produced by the {@code InitialStateDecl}
	 * labeled alternative in {@link KasXParser#initial_state_declaration}.
	 * @param ctx the parse tree
	 */
	void exitInitialStateDecl(KasXParser.InitialStateDeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#trigger_definition}.
	 * @param ctx the parse tree
	 */
	void enterTrigger_definition(KasXParser.Trigger_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#trigger_definition}.
	 * @param ctx the parse tree
	 */
	void exitTrigger_definition(KasXParser.Trigger_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#trigger_body}.
	 * @param ctx the parse tree
	 */
	void enterTrigger_body(KasXParser.Trigger_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#trigger_body}.
	 * @param ctx the parse tree
	 */
	void exitTrigger_body(KasXParser.Trigger_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#utility_definition}.
	 * @param ctx the parse tree
	 */
	void enterUtility_definition(KasXParser.Utility_definitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#utility_definition}.
	 * @param ctx the parse tree
	 */
	void exitUtility_definition(KasXParser.Utility_definitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void enterIdentifiers_list(KasXParser.Identifiers_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#identifiers_list}.
	 * @param ctx the parse tree
	 */
	void exitIdentifiers_list(KasXParser.Identifiers_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#conditions_list}.
	 * @param ctx the parse tree
	 */
	void enterConditions_list(KasXParser.Conditions_listContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#conditions_list}.
	 * @param ctx the parse tree
	 */
	void exitConditions_list(KasXParser.Conditions_listContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#belives_expression}.
	 * @param ctx the parse tree
	 */
	void enterBelives_expression(KasXParser.Belives_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#belives_expression}.
	 * @param ctx the parse tree
	 */
	void exitBelives_expression(KasXParser.Belives_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#exists_clause}.
	 * @param ctx the parse tree
	 */
	void enterExists_clause(KasXParser.Exists_clauseContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#exists_clause}.
	 * @param ctx the parse tree
	 */
	void exitExists_clause(KasXParser.Exists_clauseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprForAll}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprForAll(KasXParser.ExprForAllContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprForAll}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprForAll(KasXParser.ExprForAllContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprIdentifier}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprIdentifier(KasXParser.ExprIdentifierContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprIdentifier}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprIdentifier(KasXParser.ExprIdentifierContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprSum}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprSum(KasXParser.ExprSumContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprSum}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprSum(KasXParser.ExprSumContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprExists}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprExists(KasXParser.ExprExistsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprExists}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprExists(KasXParser.ExprExistsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprBoolean}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprBoolean(KasXParser.ExprBooleanContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprBoolean}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprBoolean(KasXParser.ExprBooleanContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprInBracket}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprInBracket(KasXParser.ExprInBracketContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprInBracket}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprInBracket(KasXParser.ExprInBracketContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprNegation}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprNegation(KasXParser.ExprNegationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprNegation}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprNegation(KasXParser.ExprNegationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprNot}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprNot(KasXParser.ExprNotContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprNot}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprNot(KasXParser.ExprNotContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprBelives}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprBelives(KasXParser.ExprBelivesContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprBelives}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprBelives(KasXParser.ExprBelivesContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprIfElse}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprIfElse(KasXParser.ExprIfElseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprIfElse}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprIfElse(KasXParser.ExprIfElseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprUnknown}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprUnknown(KasXParser.ExprUnknownContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprUnknown}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprUnknown(KasXParser.ExprUnknownContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprFluent}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprFluent(KasXParser.ExprFluentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprFluent}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprFluent(KasXParser.ExprFluentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprNullClause}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprNullClause(KasXParser.ExprNullClauseContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprNullClause}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprNullClause(KasXParser.ExprNullClauseContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprNumber}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprNumber(KasXParser.ExprNumberContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprNumber}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprNumber(KasXParser.ExprNumberContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprBinaryOp}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprBinaryOp(KasXParser.ExprBinaryOpContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprBinaryOp}
	 * labeled alternative in {@link KasXParser#arithmetic_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprBinaryOp(KasXParser.ExprBinaryOpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ExprInheritance}
	 * labeled alternative in {@link KasXParser#inheritance_expression}.
	 * @param ctx the parse tree
	 */
	void enterExprInheritance(KasXParser.ExprInheritanceContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ExprInheritance}
	 * labeled alternative in {@link KasXParser#inheritance_expression}.
	 * @param ctx the parse tree
	 */
	void exitExprInheritance(KasXParser.ExprInheritanceContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#forall_function}.
	 * @param ctx the parse tree
	 */
	void enterForall_function(KasXParser.Forall_functionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#forall_function}.
	 * @param ctx the parse tree
	 */
	void exitForall_function(KasXParser.Forall_functionContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#sum_function}.
	 * @param ctx the parse tree
	 */
	void enterSum_function(KasXParser.Sum_functionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#sum_function}.
	 * @param ctx the parse tree
	 */
	void exitSum_function(KasXParser.Sum_functionContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#unary_not_expression}.
	 * @param ctx the parse tree
	 */
	void enterUnary_not_expression(KasXParser.Unary_not_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#unary_not_expression}.
	 * @param ctx the parse tree
	 */
	void exitUnary_not_expression(KasXParser.Unary_not_expressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#negation_expression}.
	 * @param ctx the parse tree
	 */
	void enterNegation_expression(KasXParser.Negation_expressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#negation_expression}.
	 * @param ctx the parse tree
	 */
	void exitNegation_expression(KasXParser.Negation_expressionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FluentVal}
	 * labeled alternative in {@link KasXParser#fluent}.
	 * @param ctx the parse tree
	 */
	void enterFluentVal(KasXParser.FluentValContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FluentVal}
	 * labeled alternative in {@link KasXParser#fluent}.
	 * @param ctx the parse tree
	 */
	void exitFluentVal(KasXParser.FluentValContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ArgumentList}
	 * labeled alternative in {@link KasXParser#argument_list}.
	 * @param ctx the parse tree
	 */
	void enterArgumentList(KasXParser.ArgumentListContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ArgumentList}
	 * labeled alternative in {@link KasXParser#argument_list}.
	 * @param ctx the parse tree
	 */
	void exitArgumentList(KasXParser.ArgumentListContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#if_else_block}.
	 * @param ctx the parse tree
	 */
	void enterIf_else_block(KasXParser.If_else_blockContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#if_else_block}.
	 * @param ctx the parse tree
	 */
	void exitIf_else_block(KasXParser.If_else_blockContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#binary_op}.
	 * @param ctx the parse tree
	 */
	void enterBinary_op(KasXParser.Binary_opContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#binary_op}.
	 * @param ctx the parse tree
	 */
	void exitBinary_op(KasXParser.Binary_opContext ctx);
	/**
	 * Enter a parse tree produced by the {@code TrueValue}
	 * labeled alternative in {@link KasXParser#boolean_data}.
	 * @param ctx the parse tree
	 */
	void enterTrueValue(KasXParser.TrueValueContext ctx);
	/**
	 * Exit a parse tree produced by the {@code TrueValue}
	 * labeled alternative in {@link KasXParser#boolean_data}.
	 * @param ctx the parse tree
	 */
	void exitTrueValue(KasXParser.TrueValueContext ctx);
	/**
	 * Enter a parse tree produced by the {@code FalseValue}
	 * labeled alternative in {@link KasXParser#boolean_data}.
	 * @param ctx the parse tree
	 */
	void enterFalseValue(KasXParser.FalseValueContext ctx);
	/**
	 * Exit a parse tree produced by the {@code FalseValue}
	 * labeled alternative in {@link KasXParser#boolean_data}.
	 * @param ctx the parse tree
	 */
	void exitFalseValue(KasXParser.FalseValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link KasXParser#data_type}.
	 * @param ctx the parse tree
	 */
	void enterData_type(KasXParser.Data_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link KasXParser#data_type}.
	 * @param ctx the parse tree
	 */
	void exitData_type(KasXParser.Data_typeContext ctx);
}