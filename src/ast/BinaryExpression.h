//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_BINARYEXPRESSION_H
#define OWNCPP_BINARYEXPRESSION_H

#include <iostream>
#include "Expression.h"

class BinaryExpression : public Expression{
public:

    BinaryExpression(char operationIn, Expression* expr1In, Expression* expr2In);

    ~BinaryExpression() override {
        delete expr1;
        delete expr2;
        std::cout << "destruct BinaryExpression : " << operation << std::endl;
    }

    double eval() override;

    const std::string toString() override;

private:

    Expression* expr1;
    Expression *expr2;
    char operation;
};


#endif //OWNCPP_BINARYEXPRESSION_H
