//
// Created by max on 12/31/17.
//

#include "AssignmentStatement.h"
#include "../lib/Variables.h"

AssignmentStatement::AssignmentStatement(const std::string &variableIn, Expression *exprIn)
        : variable(variableIn), expr(exprIn){

}

void AssignmentStatement::execute() {
    const double result = expr->eval();
    Variables::instance().set(variable, result);
}

std::string AssignmentStatement::toString() {
    return variable + " = " + expr->toString();
}