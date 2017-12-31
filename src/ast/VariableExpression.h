//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_CONSTANTEXPRESSION_H
#define OWNCPP_CONSTANTEXPRESSION_H

#include <iostream>
#include "Expression.h"

class ConstantExpression : public Expression{
public:

    explicit ConstantExpression(const std::string& string);

    ~ConstantExpression() override{
        std::cout << "destruct ConstantExpression" << std::endl;
    };

    double eval() override;

    const std::string toString() override;

private:
    const std::string name;
};


#endif //OWNCPP_CONSTANTEXPRESSION_H
