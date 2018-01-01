//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_VALUEEXPRESSION_H
#define OWNCPP_VALUEEXPRESSION_H


#include "Expression.h"
#include "../lib/Value.h"

class ValueExpression : public Expression{
public:
    explicit ValueExpression(double valueIn);

    explicit ValueExpression(const std::string & valueIn);

    ~ValueExpression() override;

    const Value *eval() const override;

    const std::string toString() const override;

private:
    const Value * value;
};


#endif //OWNCPP_VALUEEXPRESSION_H
