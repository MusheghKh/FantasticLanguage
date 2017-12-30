//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_NUMBEREXPRESSION_H
#define OWNCPP_NUMBEREXPRESSION_H

#include "Expression.h"

#include <string>
#include <iostream>

class NumberExpression: public Expression {
public:

    explicit NumberExpression(double valueIn);

    ~NumberExpression() override {
        std::cout << "destruct NumberExpression : " << toString() << std::endl;
    };

    double eval() override {
        return value;
    }

    const std::string toString() override {
        return std::to_string(value);
    }

private:

    double value;
};


#endif //OWNCPP_NUMBEREXPRESSION_H
