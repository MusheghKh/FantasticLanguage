//
// Created by max on 12/29/17.
//

#include "BinaryExpression.h"

double BinaryExpression::eval() {
    switch (operation) {
        case '-':
            return expr1->eval() - expr2->eval();
        case '*':
            return expr1->eval() * expr2->eval();
        case '/':
            return expr1->eval() / expr2->eval();
        case '+':
        default:
            return expr1->eval() + expr2->eval();
    }
}

const std::string BinaryExpression::toString() {
    return '[' + expr1->toString() + ' ' + operation + ' ' + expr2->toString() + ']';
}

BinaryExpression::BinaryExpression(char operationIn, Expression *expr1In, Expression *expr2In)
        : operation(operationIn), expr1(expr1In), expr2(expr2In) {
}
