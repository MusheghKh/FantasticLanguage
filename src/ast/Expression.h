//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_EXPRESSION_H
#define OWNCPP_EXPRESSION_H

#include <string>

class Expression {
public:

    virtual ~Expression() = 0;

    virtual double eval() = 0;

    virtual const std::string toString() = 0;
};

#endif //OWNCPP_EXPRESSION_H