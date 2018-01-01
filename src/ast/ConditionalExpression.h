//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_CONDITIONALEXPRESSION_H
#define OWNCPP_CONDITIONALEXPRESSION_H


#include "Expression.h"

class ConditionalExpression : public Expression{
public:
    ConditionalExpression(char operationIn, const Expression *expr1In, const Expression *expr2In);

    ~ConditionalExpression() override;

    const Value *eval() const override;

    const std::string toString() const override;

private:

    const Expression *expr1, *expr2;
    const char operation;
};


#endif //OWNCPP_CONDITIONALEXPRESSION_H
