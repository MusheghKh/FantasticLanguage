//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_UNARYEXPRESSION_H
#define OWNCPP_UNARYEXPRESSION_H

#include "Expression.h"

#include <string>
#include <iostream>

class UnaryExpression : public Expression{
public:

    UnaryExpression(char operationIn, Expression* exprIn);

    ~UnaryExpression() override {
        delete expr;
        std::cout << "destruct UnaryExpression : " << operation << std::endl;
    }

    double eval() override;

    const std::string toString() override {
        return "" + operation + expr->toString();
    }

private:

    Expression* expr;
    char operation;
};


#endif //OWNCPP_UNARYEXPRESSION_H
