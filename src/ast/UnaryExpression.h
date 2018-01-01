//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_UNARYEXPRESSION_H
#define OWNCPP_UNARYEXPRESSION_H

#include "Expression.h"
#include "../lib/Value.h"

#include <string>
#include <iostream>

class UnaryExpression : public Expression{
public:

    UnaryExpression(char operationIn, const Expression* exprIn);

    ~UnaryExpression() override {
        delete expr;
        std::cout << "destruct UnaryExpression : " << operation << std::endl;
    }

    const Value * eval() const override;

    const std::string toString() const override {
        return "" + operation + expr->toString();
    }

private:

    const Expression* expr;
    const char operation;
};


#endif //OWNCPP_UNARYEXPRESSION_H
