/*
* File name: ProgramVisitor.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 15:12:03
// Date modified: 2026-08-29 21:56:48
* ------
*/

#include <any>
#include <kasx/data_structures/declarations/FluentDeclaration.hpp>
#include <kasx/data_structures/declarations/helpers/Parameter.hpp>
#include <kasx/debug/DomainFileTrace.hpp>
#include <kasx/visitors/ProgramVisitor.hpp>
#include <memory>
#include <string>
#include <vector>

#include "KasXParser.h"
#include "Log.hpp"
#include "Token.h"
#include "kasx/Domain.hpp"
#include "kasx/core/scopes/Scope.hpp"
#include "kasx/core/services/IDHandler.hpp"
#include "kasx/data_structures/expressions/Believes.hpp"
#include "kasx/data_structures/expressions/Expression.hpp"
#include "kasx/data_structures/expressions/Fluent.hpp"
#include "kasx/data_structures/expressions/data_types/Number.hpp"
#include "kasx/data_structures/expressions/operations/BinaryOperation.hpp"
#include "kasx/data_structures/expressions/operations/ForAllOperation.hpp"
#include "kasx/data_structures/expressions/operations/UnaryOperation.hpp"

namespace KasX::Compiler::Visitors {
using std::string;

ProgramVisitor::ProgramVisitor(Core::Domain* domain) : m_Domain(domain) { CORE_TRACE("ProgramVisitor Initialized"); }

ProgramVisitor::~ProgramVisitor() { CORE_TRACE("ProgramVisitor Terminated"); }

std::any ProgramVisitor::visitTypeDeclaration(KasXParser::TypeDeclarationContext* ctx) {
  std::string typeDeclarationName = ctx->IDENTIFIER()->getText();

  ProgramVisitor::PrintStartVisit("Type-Declaration", typeDeclarationName);
  // Setting trace data
  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  CLI_TRACE("File trace: {}", trace.toString());
  auto* tlContext = ctx->types_list();
  auto parents =
      (tlContext != nullptr) ? std::any_cast<std::vector<std::string>>(visit(tlContext)) : std::vector<std::string>{"entity"};

  // When function arrives here, there is at least one parent associated to the type (entity type or other user-defined type)
  this->m_Domain->getGlobalScope()->createTypeDeclaration(typeDeclarationName, parents, trace);

  ProgramVisitor::PrintEndVisit("Type-Declaration", typeDeclarationName);

  return 0;
}

Debug::DomainFileTrace ProgramVisitor::getTraceData(antlr4::Token* startToken, antlr4::Token* endToken) {
  Debug::DomainFileTrace::TraceData start{startToken->getLine(), startToken->getCharPositionInLine()};

  Debug::DomainFileTrace::TraceData end{endToken->getLine(),
                                        endToken->getCharPositionInLine() + static_cast<int>(endToken->getText().size() - 1)};

  // Debug Trace created to trace bugs with the domain file.
  Debug::DomainFileTrace trace{start, end};

  return trace;
}

std::any ProgramVisitor::visitTypesList(KasXParser::TypesListContext* ctx) {
  CLI_TRACE("Accessing types list");
  std::vector<std::string> out;
  std::vector<KasXParser::Type_nameContext*> items = ctx->type_name();
  out.reserve(items.size());

  for (auto* item : items) {
    out.emplace_back(item->getText());
  }
  CLI_TRACE("Types list access done");
  return out;
}

void ProgramVisitor::PrintStartVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("\n[Visitor] ----- Started visit - type: {}", type);
    return;
  }
  CLI_TRACE("\n[Visitor] ----- Started visit - type: {}, id: '{}'", type, identifier);
}

void ProgramVisitor::PrintEndVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("[Visitor] ----- Ended visit - type: {}\n", type);
    return;
  }
  CLI_TRACE("[Visitor] ----- Ended visit - type: {}, id: '{}'\n", type, identifier);
}

void ProgramVisitor::EditParentsData(const string& typeDeclarationName, std::vector<std::string>& parents) {
  if (parents.size() > 0) {
    CLI_TRACE("Type-Declaration '{}' has parents defined", typeDeclarationName);
  } else {
    parents.emplace_back("entity");  // Add 'entity' as a parent since there is no parent.
    CLI_TRACE("Type-Declaration '{}' does not have any parents defined, defaults to 'entity' type", typeDeclarationName);
  }
}

std::any ProgramVisitor::visitEntityDeclaration(KasXParser::EntityDeclarationContext* ctx) {
  const std::string& entityName = ctx->IDENTIFIER()->toString();

  PrintStartVisit("Entity-Declaration", entityName);

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  auto* tlContext = ctx->types_list();
  auto types =
      (tlContext != nullptr) ? std::any_cast<std::vector<std::string>>(visit(tlContext)) : std::vector<std::string>{"entity"};

  m_Domain->getGlobalScope()->createEntityDeclaration(entityName, types, trace);

  CLI_TRACE("File trace: {}", trace.toString());
  PrintEndVisit("Entity-Declaration", entityName);

  return 0;
}

std::any ProgramVisitor::visitFluentDeclaration(KasXParser::FluentDeclarationContext* ctx) {
  PrintStartVisit("Fluent-Declaration", "");
  auto functionHeader = std::any_cast<DataStructures::Declarations::Helpers::FunctionHeader>(visit(ctx->function_header()));
  const std::string& fluentName = functionHeader.name;
  CLI_TRACE("Fluent name identified : {}", fluentName);

  const std::string& dataTypeStr = ctx->data_type()->getText();

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  m_Domain->getGlobalScope()->createFluentDeclaration(fluentName, functionHeader, dataTypeStr, trace);

  PrintEndVisit("Fluent-Declaration", fluentName);
  return 0;
}

std::any ProgramVisitor::visitFunctionHeader(KasXParser::FunctionHeaderContext* ctx) {
  const std::string& functionName = ctx->IDENTIFIER()->toString();

  CLI_TRACE("Accessing function header: {}", functionName);
  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto functionHeader = DataStructures::Declarations::Helpers::FunctionHeader(functionName, trace);
  functionHeader.parameters =
      std::any_cast<std::vector<DataStructures::Declarations::Helpers::Parameter>>(visit(ctx->param_list()));
  CLI_TRACE("Accessing function header done");

  return functionHeader;
}

std::any ProgramVisitor::visitParamList(KasXParser::ParamListContext* ctx) {
  CLI_TRACE("Accessing param list");
  std::vector<DataStructures::Declarations::Helpers::Parameter> out;
  std::vector<KasXParser::ParamContext*> items = ctx->param();
  out.reserve(items.size());

  for (KasXParser::ParamContext* item : items) {
    auto param = std::any_cast<DataStructures::Declarations::Helpers::Parameter>(visit(item));
    out.push_back(param);
  }

  CLI_TRACE("Param list access done");

  return out;
}

std::any ProgramVisitor::visitParam(KasXParser::ParamContext* ctx) {
  const std::string& paramName = ctx->IDENTIFIER()->toString();
  CLI_TRACE("Visiting param: {}", paramName);

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto param = DataStructures::Declarations::Helpers::Parameter(paramName, trace);

  auto* const paramType = ctx->data_type();

  if (paramType == nullptr) {
    param.isTypeDeclaration = false;
    CLI_TRACE("Param {} has been identified as an entity", paramName);
    auto* entityType = m_Domain->getGlobalScope()->getEntityDeclaration(paramName);

    if (entityType == nullptr) {
      // TODO: lazzy07 - Handle error
      CLI_ERROR("Entity type: {} not declared in the global scope", paramName);
    } else {
      param.entityType = entityType;
      CLI_TRACE("Entity type found in the global scope: {} and added to the param: {}", entityType->name, param.name);
    }
  } else {
    param.isTypeDeclaration = true;
    const std::string& dataTypeStr = paramType->getText();
    auto* dataType = m_Domain->getGlobalScope()->getTypeDeclaration(dataTypeStr);

    if (dataType == nullptr) {
      // TODO: lazzy07 - Handle error
      CLI_ERROR("Could not find the data type: {} in the global scope for param: {}", dataTypeStr, param.name);
    } else {
      param.dataType = dataType;
      CLI_TRACE("Param {} has been identified as data type: {}", param.name, param.dataType->name);
    }
  }

  CLI_TRACE("Visiting param: {} done", param.name);

  return param;
}

std::any ProgramVisitor::visitInitialStateDecl(KasXParser::InitialStateDeclContext* ctx) {
  PrintStartVisit("InitialState-Declaration", "");

  auto anyResult = visit(ctx->arithmetic_expression());
  auto* expression = std::any_cast<DataStructures::Expressions::ExpressionPtr>(&anyResult);

  if (expression == nullptr || *expression == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Initial-State expression could not be resolved");
    PrintEndVisit("InitialState-Declaration", "");
    return nullptr;
  }

  m_Domain->getGlobalScope()->addInitialStateExpression(*expression);

  PrintEndVisit("InitialState-Declaration", (*expression)->name);
  return nullptr;
}

std::any ProgramVisitor::visitExprNot(KasXParser::ExprNotContext* ctx) {
  auto anyResult = visit(ctx->unary_not_expression()->arithmetic_expression());
  auto* expression = std::any_cast<DataStructures::Expressions::ExpressionPtr>(&anyResult);

  if (expression == nullptr || *expression == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Expression to '!' operator cannot be null");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  // Anything that isn't inherently a number or a bare identifier can be a boolean value: a fluent (eg: !alive(Aladdin)), a
  // binary operation's result (eg: !(a == b)), another negation, or a belief about one of those (eg: !believes(Nazis,
  // dangerous(Ark))).
  auto negatedType = (*expression)->expressionType;
  if (negatedType == DataStructures::Expressions::EXPRESSION_TYPES::NUMBER_OPERATION ||
      negatedType == DataStructures::Expressions::EXPRESSION_TYPES::IDENTIFIER) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Expression '!' only acccepts boolean values");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto operation = std::make_shared<DataStructures::Expressions::UnaryOpearation>(
      DataStructures::Expressions::UNARY_OPERATION_TYPES::UNARY_NOT, "Unary Not", *expression, trace);
  return DataStructures::Expressions::ExpressionPtr(operation);
}

std::any ProgramVisitor::visitExprNegation(KasXParser::ExprNegationContext* ctx) {
  auto anyResult = visit(ctx->negation_expression()->arithmetic_expression());
  auto* expression = std::any_cast<DataStructures::Expressions::ExpressionPtr>(&anyResult);

  if (expression == nullptr || *expression == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Expression to '-' operator cannot be null");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  if ((*expression)->expressionType != DataStructures::Expressions::EXPRESSION_TYPES::NUMBER_OPERATION) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Expression '-' only acccepts number values");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto operation = std::make_shared<DataStructures::Expressions::UnaryOpearation>(
      DataStructures::Expressions::UNARY_OPERATION_TYPES::UNARY_NEGATION, "Unary Negation", *expression, trace);
  return DataStructures::Expressions::ExpressionPtr(operation);
}

std::any ProgramVisitor::visitExprInBracket(KasXParser::ExprInBracketContext* ctx) {
  auto anyResult = visit(ctx->arithmetic_expression());
  auto* expression = std::any_cast<DataStructures::Expressions::ExpressionPtr>(&anyResult);

  if (expression == nullptr || *expression == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Expression inside brackets cannot be null");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  return *expression;
}

DataStructures::Expressions::BINARY_OPERATION_TYPES ProgramVisitor::getBinaryOperationType(KasXParser::Binary_opContext* ctx) {
  using DataStructures::Expressions::BINARY_OPERATION_TYPES;

  switch (ctx->op->getType()) {
    case KasXParser::SUBTRACTION_KEYWORD:
      return BINARY_OPERATION_TYPES::SUBSTRACTION;
    case KasXParser::ADDITION_KEYWORD:
      return BINARY_OPERATION_TYPES::ADDITION;
    case KasXParser::DIVISION_KEYWORD:
      return BINARY_OPERATION_TYPES::DIVISION;
    case KasXParser::MULTIPLICATION_KEYWORD:
      return BINARY_OPERATION_TYPES::MULTIPLICATION;
    case KasXParser::LESS_THAN_KEYWORD:
      return BINARY_OPERATION_TYPES::LESS_THAN;
    case KasXParser::GREATER_THAN_KEYWORD:
      return BINARY_OPERATION_TYPES::GREATER_THAN;
    case KasXParser::LESS_THAN_OR_EQUAL_TO_KEYWORD:
      return BINARY_OPERATION_TYPES::LESS_THAN_OR_EQUAL;
    case KasXParser::GREATER_THAN_OR_EQUAL_TO_KEYWORD:
      return BINARY_OPERATION_TYPES::GREATER_THAN_OR_EQUAL;
    case KasXParser::NOT_EQUAL_TO_KEYWORD:
      return BINARY_OPERATION_TYPES::NOT_EQUAL;
    case KasXParser::EQUAL_TO_KEYWORD:
      return BINARY_OPERATION_TYPES::EQUAL_TO;
    case KasXParser::ASSIGNMENT_KEYWORD:
      return BINARY_OPERATION_TYPES::ASSIGNMENT;
    case KasXParser::DISJUNCTION_KEYWORD:
      return BINARY_OPERATION_TYPES::DISJUNCTION;
    case KasXParser::CONJUNCTION_KEYWORD:
      return BINARY_OPERATION_TYPES::CONJUNCTION;
    case KasXParser::COLON:
      return BINARY_OPERATION_TYPES::INHERITANCE;
    default:
      // TODO: lazzy07 - Handle error
      CLI_ERROR("Unknown binary operator: {}", ctx->getText());
      return BINARY_OPERATION_TYPES::EQUAL_TO;
  }
}

std::any ProgramVisitor::visitExprBinaryOp(KasXParser::ExprBinaryOpContext* ctx) {
  auto leftResult = visit(ctx->arithmetic_expression(0));
  auto rightResult = visit(ctx->arithmetic_expression(1));

  auto* leftExpression = std::any_cast<DataStructures::Expressions::ExpressionPtr>(&leftResult);
  auto* rightExpression = std::any_cast<DataStructures::Expressions::ExpressionPtr>(&rightResult);

  if (leftExpression == nullptr || *leftExpression == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Left side of a binary operation cannot be null");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  if (rightExpression == nullptr || *rightExpression == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Right side of a binary operation cannot be null");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto operationType = getBinaryOperationType(ctx->binary_op());
  std::string operationName = (*leftExpression)->name + " " + ctx->binary_op()->getText() + " " + (*rightExpression)->name;

  auto operation = std::make_shared<DataStructures::Expressions::BinaryOperation>(operationType, operationName, *leftExpression,
                                                                                  *rightExpression, trace);

  return DataStructures::Expressions::ExpressionPtr(operation);
}

std::any ProgramVisitor::visitFluentVal(KasXParser::FluentValContext* ctx) {
  const std::string& fluentName = ctx->IDENTIFIER()->getText();
  CLI_TRACE("Visiting fluent: {}", fluentName);

  std::vector<std::string> arguments;
  auto* argListCtx = ctx->argument_list();
  if (argListCtx != nullptr) {
    arguments = std::any_cast<std::vector<std::string>>(visit(argListCtx));
  }

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto fluent = std::make_shared<DataStructures::Expressions::Fluent>(fluentName, arguments, trace);
  auto* groundedFluent = m_Domain->getGlobalScope()->getGroundedFluentByName(fluent->name);

  if (groundedFluent == nullptr) {
    CLI_ERROR("Grounded fluent is not available in the global scope: {}", fluent->name);
    return nullptr;
  }

  CLI_TRACE("Grounded fluent found: {}", fluent->name);
  fluent->groundedFluent = groundedFluent;

  CLI_TRACE("Visiting fluent: {} done", fluentName);
  return DataStructures::Expressions::ExpressionPtr(fluent);
}

std::any ProgramVisitor::visitArgumentList(KasXParser::ArgumentListContext* ctx) {
  CLI_TRACE("Accessing argument list");
  std::vector<std::string> out;
  std::vector<antlr4::tree::TerminalNode*> items = ctx->IDENTIFIER();
  out.reserve(items.size());

  for (auto* item : items) {
    out.emplace_back(item->getText());
  }
  CLI_TRACE("Argument list access done");
  return out;
}

std::any ProgramVisitor::visitExprFluent(KasXParser::ExprFluentContext* ctx) { return visit(ctx->fluent()); }

std::any ProgramVisitor::visitExprIdentifier(KasXParser::ExprIdentifierContext* ctx) {
  const std::string& identifierName = ctx->IDENTIFIER()->getText();
  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  auto identifier = std::make_shared<DataStructures::Expressions::Expression>(
      true, DataStructures::Expressions::EXPRESSION_TYPES::IDENTIFIER, identifierName, trace);

  return DataStructures::Expressions::ExpressionPtr(identifier);
}

std::any ProgramVisitor::visitExprNumber(KasXParser::ExprNumberContext* ctx) {
  const std::string& numberText = ctx->NUMBER()->getText();
  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  auto number = std::make_shared<DataStructures::Expressions::DataTypes::Number>(std::stof(numberText), numberText, trace);

  return DataStructures::Expressions::ExpressionPtr(number);
}

std::any ProgramVisitor::visitExprUnknown(KasXParser::ExprUnknownContext* ctx) {
  const std::string& unknownText = ctx->UNKNOWN_KEYWORD()->getText();
  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  auto unknown = std::make_shared<DataStructures::Expressions::Expression>(
      true, DataStructures::Expressions::EXPRESSION_TYPES::UNKNOWN_VALUE, unknownText, trace);

  return DataStructures::Expressions::ExpressionPtr(unknown);
}

std::any ProgramVisitor::visitExprBelives(KasXParser::ExprBelivesContext* ctx) { return visit(ctx->belives_expression()); }

bool ProgramVisitor::typeInheritsFrom(DataStructures::Declarations::TypeDeclaration* type, const std::string& typeName) {
  if (type == nullptr) {
    return false;
  }

  if (type->name == typeName) {
    return true;
  }

  for (auto* parent : type->parents) {
    if (typeInheritsFrom(parent, typeName)) {
      return true;
    }
  }

  return false;
}

bool ProgramVisitor::entityIsOfType(DataStructures::Declarations::EntityDeclaration* entity, const std::string& typeName) {
  for (auto* type : entity->types) {
    if (typeInheritsFrom(type, typeName)) {
      return true;
    }
  }

  return false;
}

std::any ProgramVisitor::visitBelives_expression(KasXParser::Belives_expressionContext* ctx) {
  // Mirrors Sabre's Epistemic(Parameter character, Expression argument): the first argument must resolve to a declared
  // entity of type 'character', the second can be any logical expression (a fluent, a comparison/assignment involving one,
  // or even another believes expression for nested beliefs).
  const std::string& characterName = ctx->IDENTIFIER()->getText();
  CLI_TRACE("Visiting believes expression for: {}", characterName);

  auto* characterEntity = m_Domain->getGlobalScope()->getEntityDeclaration(characterName);

  if (characterEntity == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("First argument '{}' of a 'believes' statement is not a declared entity", characterName);
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  if (!entityIsOfType(characterEntity, "character")) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("First argument '{}' of a 'believes' statement must be a 'character'", characterName);
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  auto anyResult = visit(ctx->arithmetic_expression());
  auto* argumentExpression = std::any_cast<DataStructures::Expressions::ExpressionPtr>(&anyResult);

  if (argumentExpression == nullptr || *argumentExpression == nullptr) {
    // TODO: lazzy07 - Handle error
    CLI_ERROR("Argument expression of a 'believes' statement cannot be null");
    return DataStructures::Expressions::ExpressionPtr(nullptr);
  }

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto believes = std::make_shared<DataStructures::Expressions::Believes>(characterName, *argumentExpression, trace);

  CLI_TRACE("Visiting believes expression for: {} done", characterName);
  return DataStructures::Expressions::ExpressionPtr(believes);
}

std::any ProgramVisitor::visitExprForAll(KasXParser::ExprForAllContext* ctx) {
  CLI_TRACE("Visiting for-all expression started");

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto forAll = std::make_shared<DataStructures::Expressions::ForAllOperation>(trace);

  CLI_TRACE("Visiting for-all expression done");
  return DataStructures::Expressions::ExpressionPtr(forAll);
}
}  // namespace KasX::Compiler::Visitors
