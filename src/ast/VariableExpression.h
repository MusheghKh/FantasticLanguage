//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_CONSTANTEXPRESSION_H
#define OWNCPP_CONSTANTEXPRESSION_H

#include <iostream>
#include "Expression.h"
#include "../lib/Value.h"

class VariableExpression : public Expression{
public:

    explicit VariableExpression(std::string string);

    ~VariableExpression() override{
        std::cout << "destruct VariableExpression : " << name << std::endl;
    };

    const Value * eval() const override;

    const std::string toString() const override;

private:
    const std::string name;
};


#endif //OWNCPP_CONSTANTEXPRESSION_H
