//
// Created by max on 12/29/17.
//

#include "UnaryExpression.h"
#include "../lib/NumberValue.h"

UnaryExpression::UnaryExpression(const char operationIn, const Expression *exprIn)
        : operation(operationIn), expr(exprIn){
}

const Value * UnaryExpression::eval() const {
    switch (operation) {
        case '-':
            return new NumberValue(-expr->eval()->asNumber());
        case '+':
        default:
            return expr->eval();
    }
}