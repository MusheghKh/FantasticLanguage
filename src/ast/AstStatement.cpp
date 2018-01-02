//
// Created by max on 1/2/18.
//

#include "../../include/ast/AstStatement.h"

using namespace ast;

Statement::~Statement() = default;

PrintStatement::PrintStatement(const Expression *exprIn) : expr(exprIn) {}

PrintStatement::~PrintStatement() {
    delete expr;
}

void PrintStatement::execute() const {
    cout << expr->eval()->asString();
}

std::string PrintStatement::toString() const {
    return makeRawSpecialChars("print " + expr->toString());
}

AssignmentStatement::AssignmentStatement(std::string variableIn, const Expression *exprIn)
        : variable(std::move(variableIn)), expr(exprIn){
}

void AssignmentStatement::execute() const {
    const Value * result = expr->eval();
    Variables::instance()->set(variable, result);
}

std::string AssignmentStatement::toString() const {
    return makeRawSpecialChars(variable + " = " + expr->toString());
}

AssignmentStatement::~AssignmentStatement() {
    delete expr;
}

IfStatement::IfStatement(const Expression *exprIn, const Statement *ifStatementIn, const Statement *elseStatementIn)
        : expr(exprIn), ifStatement(ifStatementIn), elseStatement(elseStatementIn) {
}

IfStatement::IfStatement(const Expression *exprIn, const Statement *ifStatementIn)
        : expr(exprIn), ifStatement(ifStatementIn){
}


IfStatement::~IfStatement() {
    delete expr;
    delete ifStatement;
    delete elseStatement;
}

void IfStatement::execute() const {
    const double result = expr->eval()->asNumber();
    if (result != 0){
        ifStatement->execute();
    } else if(elseStatement != nullptr){
        elseStatement->execute();
    }
}

std::string IfStatement::toString() const {
    stringstream ss;
    ss << "if" << expr->toString() << ' ' << ifStatement->toString();
    if (elseStatement != nullptr){
        ss << "\nelse" << elseStatement->toString();
    }
    return ss.str();
}

BlockStatement::~BlockStatement() {
    for (auto s = statements.begin(); s < statements.end(); ++s) {
        delete *s;
    }
}

void BlockStatement::add(const Statement* statement) {
    statements.push_back(statement);
}

void BlockStatement::execute() const {
    for (auto s = statements.begin(); s < statements.end(); ++s) {
        (*s)->execute();
    }
}

std::string BlockStatement::toString() const {
    stringstream ss;
    for (auto s = statements.begin(); s < statements.end(); ++s) {
        ss << (*s)->toString() << endl;
    }
    return ss.str();
}

WhileStatement::WhileStatement(const Expression *conditionIn, const Statement *bodyIn)
        : condition(conditionIn), body(bodyIn) {}


WhileStatement::~WhileStatement() {
    delete condition;
    delete body;
}

void WhileStatement::execute() const {
    while (condition->eval()->asNumber() != 0){
        try {
            body->execute();
        }catch (BreakStatement &bs){
            break;
        }catch (ContinueStatement &cs){}
    }
}

std::string WhileStatement::toString() const {
    return "while " + condition->toString() + ' ' + body->toString();
}

DoWhileStatement::DoWhileStatement(const Expression *condition, const Statement *body)
        : condition(condition), body(body) {
}

DoWhileStatement::~DoWhileStatement() {
    delete condition;
    delete body;
}

void DoWhileStatement::execute() const {
    do{
        try {
            body->execute();
        }catch (BreakStatement &bs){
            break;
        }catch (ContinueStatement &cs){}
    }while (condition->eval()->asNumber() != 0);
}

std::string DoWhileStatement::toString() const {
    return "do " + body->toString() + " while " + condition->toString();
}

ForStatement::ForStatement(const Statement *initializationIn, const Expression *terminationIn, const Statement *incrementIn,
                           const Statement *bodyIn)
        : initialization(initializationIn), termination(terminationIn), increment(incrementIn), body(bodyIn) {
}


ForStatement::~ForStatement() {
    delete initialization;
    delete termination;
    delete increment;
    delete body;
}

void ForStatement::execute() const {
    for (initialization->execute(); termination->eval()->asNumber() != 0 ; increment->execute()) {
        try {
            body->execute();
        }catch (BreakStatement &bs){
            break;
        }catch (ContinueStatement &cs){}
    }
}

std::string ForStatement::toString() const {
    return "for " + increment->toString() + ", " + termination->toString() + ", " + increment->toString() + ' ' + body->toString();
}

BreakStatement::BreakStatement() : runtime_error("break") {}

void BreakStatement::execute() const {
    throw *this;
}

std::string BreakStatement::toString() const {
    return "break";
}

ContinueStatement::ContinueStatement() : runtime_error("continue") {}

void ContinueStatement::execute() const {
    throw *this;
}

std::string ContinueStatement::toString() const {
    return "continue";
}
