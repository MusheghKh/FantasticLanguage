//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_BINARYEXPRESSION_H
#define OWNCPP_BINARYEXPRESSION_H

#include <iostream>
#include "Expression.h"

class BinaryExpression : public Expression{
public:

    BinaryExpression(const char operationIn, const Expression* expr1In, const Expression* expr2In);

    ~BinaryExpression() override {
        delete expr1;
        delete expr2;
        std::cout << "destruct BinaryExpression : " << operation << std::endl;
    }

    const Value * eval() const override;

    const std::string toString() const override;

private:

    const Expression* expr1;
    const Expression *expr2;
    const char operation;
};


#endif //OWNCPP_BINARYEXPRESSION_H
