//
// Created by max on 12/31/17.
//

#include "AssignmentStatement.h"
#include "../lib/Variables.h"
#include "../common_utils.h"

AssignmentStatement::AssignmentStatement(std::string variableIn, const Expression *exprIn)
        : variable(std::move(variableIn)), expr(exprIn){

}

void AssignmentStatement::execute() const {
    const Value * result = expr->eval();
    Variables::instance().set(variable, result);
}

std::string AssignmentStatement::toString() const {
    return makeRawSpecialChars(variable + " = " + expr->toString());
}