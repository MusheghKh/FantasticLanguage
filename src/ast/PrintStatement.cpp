//
// Created by max on 12/31/17.
//

#include "PrintStatement.h"
#include "../common_utils.h"

#include <iostream>

using std::cout;
using std::endl;

PrintStatement::PrintStatement(const Expression *exprIn) : expr(exprIn) {}

PrintStatement::~PrintStatement() {
    delete expr;
    cout << "destruct PrintStatement" << endl;
}

void PrintStatement::execute() const {
    cout << expr->eval()->asString();
}

std::string PrintStatement::toString() const {
    return makeRawSpecialChars("print " + expr->toString());
}