//
// Created by max on 1/1/18.
//

#include <iostream>
#include <sstream>
#include "IfStatement.h"

using std::cout;
using std::endl;
using std::stringstream;

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
    cout << "destruct IfStatement" << endl;
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