//
// Created by max on 12/29/17.
//

#include "UnaryExpression.h"

double UnaryExpression::eval() {
    switch (operation) {
        case '-':
            return -expr->eval();
        case '+':
        default:
            return expr->eval();
    }
}

UnaryExpression::UnaryExpression(char operationIn, Expression *exprIn)
        : operation(operationIn), expr(exprIn){
}
