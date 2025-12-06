#include "ProgramVisitor.hpp"

#include "../core/Domain.hpp"
#include "KasXParser.h"
// Fixer added
#include <Log.hpp>
#include <any>
#include <kasx/Types.hpp>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "../data_structures/expressions/Fluent.hpp"
#include "../data_structures/expressions/data_types/IdentifierPointer.hpp"
#include "../data_structures/expressions/data_types/NullValue.hpp"
#include "../data_structures/expressions/data_types/NumberValue.hpp"
#include "../data_structures/expressions/data_types/UnknownValue.hpp"
#include "../data_structures/expressions/operations/BinaryOperation.hpp"
#include "../data_structures/expressions/operations/BinaryOperationTypes.hpp"
#include "../trace/Range.hpp"

KasX::Compiler::Visitor::ProgramVisitor::ProgramVisitor(KasX::Compiler::Core::Domain* domain)
    : Core::TraceableClass("Visitor"), KasXBaseVisitor(), m_Domain(domain) {
  CORE_TRACE("Program Visitor Initialized");
}

KasX::Compiler::Visitor::ProgramVisitor::~ProgramVisitor() { CORE_TRACE("Program Visitor Terminated"); }

void KasX::Compiler::Visitor::ProgramVisitor::printStartVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("\n[Visitor] ----- Started visit - type: {}", type);
    return;
  }
  CLI_TRACE("\n[Visitor] ----- Started visit - type: {}, id: '{}'", type, identifier);
}

void KasX::Compiler::Visitor::ProgramVisitor::printEndVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("[Visitor] ----- Ended visit - type: {}\n", type);
    return;
  }
  CLI_TRACE("[Visitor] ----- Ended visit - type: {}, id: '{}'\n", type, identifier);
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypeDeclarationNoParents(
    KasXParser::TypeDeclarationNoParentsContext* ctx) {
  std::string typeIdentifier = ctx->IDENTIFIER()->toString();
  printStartVisit("type-declaration (no parents)", typeIdentifier);

  antlr4::Token* token = ctx->IDENTIFIER()->getSymbol();
  linetrace_data line = token->getLine();
  linetrace_data column = token->getCharPositionInLine() + 1;
  linetrace_data end = column + typeIdentifier.length();

  KasX::Compiler::Trace::Range range;
  range.start.line = line;
  range.end.line = line;
  range.start.character = column;
  range.end.character = end;

  m_Domain->getGlobalScope()->initNewType(typeIdentifier, range);
  printEndVisit("type-declaration (no parents)", typeIdentifier);
  return nullptr;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypesList(KasXParser::TypesListContext* ctx) {
  std::vector<std::string> out;
  std::vector<KasXParser::Type_nameContext*> items = ctx->type_name();  // vector<Type_nameContext*>
  out.reserve(items.size());
  for (auto* item : items) out.emplace_back(item->getText());  // or visit(t).as<std::string>()
  return out;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypeDeclarationWithParents(
    KasXParser::TypeDeclarationWithParentsContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  auto parents = std::any_cast<std::vector<std::string>>(visit(ctx->types_list()));
  printStartVisit("type-declaration (with parents)", name);

  antlr4::Token* token = ctx->IDENTIFIER()->getSymbol();
  size_t line = token->getLine();
  size_t column = token->getCharPositionInLine() + 1;

  linetrace_data end = column + name.length();

  KasX::Compiler::Trace::Range range;
  range.start.line = line;
  range.end.line = line;
  range.start.character = column;
  range.end.character = end;

  m_Domain->getGlobalScope()->initNewType(name, range, parents);
  printEndVisit("type-declaration (with parents)", name);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitEntityDeclaration(KasXParser::EntityDeclarationContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  printStartVisit("entity-declaration", name);
  auto parents = std::any_cast<std::vector<std::string>>(visit(ctx->types_list()));

  antlr4::Token* token = ctx->IDENTIFIER()->getSymbol();
  size_t line = token->getLine();
  size_t column = token->getCharPositionInLine() + 1;

  linetrace_data end = column + name.length();

  KasX::Compiler::Trace::Range range;
  range.start.line = line;
  range.end.line = line;
  range.start.character = column;
  range.end.character = end;

  m_Domain->getCurrentScope()->initNewEntity(name, range, parents);
  // m_Domain->InitNewEntity(name, {line, column}, parents);
  printEndVisit("entity-declaration", name);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFluentDeclaration(KasXParser::FluentDeclarationContext* ctx) {
  printStartVisit("fluent-declaration", "");
  auto funcHeader = std::any_cast<std::pair<std::string, ParamList>>(visit(ctx->function_header()));

  std::string name = funcHeader.first;
  ParamList params = funcHeader.second;
  const std::string dataType = ctx->data_type()->getText();

  KasX::Compiler::Trace::Range range;

  m_Domain->getGlobalScope()->initNewFluent(name, range, params, dataType);
  printEndVisit("fluent-declaration", name);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithoutDataType(KasXParser::ParamWithoutDataTypeContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();

  TracePrint("Visiting parameter '{}' without a datatype", name);

  return Param{name, ""};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithDataType(KasXParser::ParamWithDataTypeContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  const std::string dataType = ctx->data_type()->getText();

  TracePrint("Visiting parameter '{}' with datatype: '{}'", name, dataType);

  return Param{name, dataType};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamList(KasXParser::ParamListContext* ctx) {
  const auto noOfElems = ctx->param().size();

  TracePrint("Visiting the parameter list with {} elements", noOfElems);

  ParamList out;
  out.reserve(noOfElems);

  for (auto* pctx : ctx->param()) {
    auto param = std::any_cast<Param>(visit(pctx));
    out.push_back(std::move(param));
  }

  return out;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFunctionHeader(KasXParser::FunctionHeaderContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  TracePrint("Visiting Function header: '{}'", name);
  ParamList params;

  if (auto* paramList = ctx->param_list()) {              // guard: list is optional
    params = std::any_cast<ParamList>(visit(paramList));  // visit to get the value
  }

  return std::pair<std::string, ParamList>(name, std::move(params));
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprIdentifier(KasXParser::ExprIdentifierContext* ctx) {
  TracePrint("Visiting Identifier expression");
  auto identifierStr = ctx->IDENTIFIER()->getText();
  auto* identifierDeclaration = this->m_Domain->getCurrentScope()->getDefinition(identifierStr);

  if (identifierDeclaration == nullptr) {
    // username - lazzy07 TODO: Handle the error
    CLI_ERROR("Declaration: {} could not be found!", identifierStr);
    return nullptr;
  }
  TracePrint("Identifier: {} found", identifierStr);

  DataStructures::Expression* identifierPointer = new DataStructures::IdentifierPointer(identifierDeclaration->id);

  return identifierPointer;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNumber(KasXParser::ExprNumberContext* ctx) {
  TracePrint("Visiting Number expression");
  std::string numberStr = ctx->NUMBER()->getText();

  number_value number = 0.0F;
  // Convert the string version of the number to number_value format
  try {
    number_value number = std::stof(numberStr);
    TracePrint("Number '{}' succesfully converted into number_value format", number);
  } catch (const std::invalid_argument& e) {
    // username - lazzy07 TODO: Handle the error
    CLI_ERROR("Invalid number argument: '{}'", numberStr);
  } catch (const std::out_of_range& e) {
    // username - lazzy07 TODO: Handle the error
    CLI_ERROR("Value '{}' is out of range of the number type (number_value), please increase it and recompile", numberStr);
  }

  TracePrint("Number value: '{}'", number);
  DataStructures::Expression* expression = new DataStructures::NumberValue(number);

  return expression;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprUnknown(KasXParser::ExprUnknownContext* ctx) {
  TracePrint("Visiting Unknown expression");
  DataStructures::UnknownValue unknownVal;
  TracePrint("Returning unknown value");
  return unknownVal;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNullClause(KasXParser::ExprNullClauseContext* ctx) {
  TracePrint("Visiting Null clause expression");
  DataStructures::Expression* nullValue = new DataStructures::NullValue();
  TracePrint("Returning unknown value");
  return nullValue;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNot(KasXParser::ExprNotContext* ctx) {
  TracePrint("Visiting Not expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNegation(KasXParser::ExprNegationContext* ctx) {
  TracePrint("Visiting Negation expression");
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprInheritance(KasXParser::ExprInheritanceContext* ctx) {
  TracePrint("Visiting Inheritance expression");
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitInitialStateDecl(KasXParser::InitialStateDeclContext* ctx) {
  printStartVisit("initial-state", "");
  visit(ctx->arithmetic_expression());
  printEndVisit("initial-state", "");
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFluentVal(KasXParser::FluentValContext* ctx) {
  TracePrint("Visiting Fluent");
  auto fluentStr = ctx->IDENTIFIER()->getText();
  auto arguments = std::any_cast<std::vector<std::string>>(visit(ctx->argument_list()));

  Core::Scope* scope = m_Domain->getCurrentScope();

  DataStructures::Expression* fluent = new DataStructures::Fluent();
  // Checking if the args mentioned in the fluent exists
  for (auto argument : arguments) {
    auto* parameter = scope->getDefinition(argument);

    if (parameter == nullptr) {
      // username - lazzy07 TODO: Handle the error
      CLI_ERROR("Fluent argument: '{}' is missing", argument);
      return nullptr;
    }
    // Since the parameter exists in the domain, add it to the paramenter list of the fluent.
    static_cast<DataStructures::Fluent*>(fluent)->parameters.push_back(parameter->id);

    TracePrint("Fluent argument: '{}' id: '{}'", argument, parameter->id);
  }
  TracePrint("All the arguments of the fluent: '{}' found as definitions in the domain", fluentStr);
  fluent->name = fluentStr;

  return fluent;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitArgumentList(KasXParser::ArgumentListContext* ctx) {
  TracePrint("Visting Argument List (Identifiers)");
  std::vector<std::string> arguments;

  for (auto* identifier : ctx->IDENTIFIER()) {
    arguments.push_back(identifier->getText());
  }

  return arguments;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprBinaryOp(KasXParser::ExprBinaryOpContext* ctx) {
  TracePrint("Visiting Binary Operation");
  auto operationType = std::any_cast<DataStructures::BINARY_OPERATION_TYPES>(visit(ctx->binary_op()));

  auto* binaryOperation = new DataStructures::BinaryOperation(operationType);

  TracePrint("Binary operation type: {}", binaryOperation->name);

  auto left = visit(ctx->arithmetic_expression(0));
  auto* leftExpression = std::any_cast<DataStructures::Expression*>(left);
  TracePrint("Visiting the left expression done: {}", leftExpression->name);

  auto right = visit(ctx->arithmetic_expression(1));
  auto* rightExpression = std::any_cast<DataStructures::Expression*>(right);
  TracePrint("Visiting the right expression done: {}", rightExpression->name);

  binaryOperation->left = std::unique_ptr<DataStructures::Expression>(leftExpression);
  binaryOperation->right = std::unique_ptr<DataStructures::Expression>(rightExpression);

  TracePrint("Binary operation created - {} {} {}", binaryOperation->left->name, binaryOperation->name,
             binaryOperation->right->name);

  return binaryOperation;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitBinary_op(KasXParser::Binary_opContext* ctx) {
  TracePrint("Visiting binary operation type");
  auto type = ctx->op->getType();

  namespace DS = KasX::Compiler::DataStructures;

  switch (type) {
    case KasXParser::SUBTRACTION_KEYWORD:
      return DS::SUBSTRACTION;
    case KasXParser::ADDITION_KEYWORD:
      return DS::ADDITION;
    case KasXParser::DIVISION_KEYWORD:
      return DS::DIVISION;
    case KasXParser::MULTIPLICATION_KEYWORD:
      return DS::MULTIPLICATION;
    case KasXParser::LESS_THAN_KEYWORD:
      return DS::LESS_THAN;
    case KasXParser::GREATER_THAN_KEYWORD:
      return DS::GREATER_THAN;
    case KasXParser::LESS_THAN_OR_EQUAL_TO_KEYWORD:
      return DS::LESS_THAN_OR_EQUAL;
    case KasXParser::GREATER_THAN_OR_EQUAL_TO_KEYWORD:
      return DS::GREATER_THAN_OR_EQUAL;
    case KasXParser::NOT_EQUAL_TO_KEYWORD:
      return DS::NOT_EQUAL;
    case KasXParser::EQUAL_TO_KEYWORD:
      return DS::EQUAL_TO;
    case KasXParser::ASSIGNMENT_KEYWORD:
      return DS::ASSIGNMENT;
    case KasXParser::DISJUNCTION_KEYWORD:
      return DS::DISJUNCTION;
    case KasXParser::CONJUNCTION_KEYWORD:
      return DS::CONJUNCTION;
    case KasXParser::COLON:
      return DS::INHERITANCE;
    default:
      CLI_ERROR("Unknown binary operator token type");
  }

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitActionDecl(KasXParser::ActionDeclContext* ctx) {
  printStartVisit("action-declaration", "");

  auto funcHeader = std::any_cast<std::pair<std::string, ParamList>>(visit(ctx->function_header()));
  auto actionName = funcHeader.first;

  m_Domain->createActionScope(actionName);

  printEndVisit("action-declaration", actionName);

  return 0;
}
