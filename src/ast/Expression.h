//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_EXPRESSION_H
#define OWNCPP_EXPRESSION_H

#include <string>
#include "../lib/Value.h"

class Expression {
public:

    virtual ~Expression() = 0;

    virtual const Value * eval() const = 0;

    virtual const std::string toString() const = 0;
};

#endif //OWNCPP_EXPRESSION_H
