//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_CONDITIONALEXPRESSION_H
#define OWNCPP_CONDITIONALEXPRESSION_H


#include "Expression.h"

class ConditionalExpression : public Expression{
public:

    enum Operator{
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,

        EQUALS,
        NOT_EQUALS,

        LT,
        LTEQ,
        GT,
        GTEQ,

        AND,
        OR
    };

    ConditionalExpression(Operator operationIn, const Expression *expr1In, const Expression *expr2In);

    ~ConditionalExpression() override;

    const Value *eval() const override;

    const std::string toString() const override;

private:

    static const std::string getOperatorAsString(Operator operationIn) ;

    const Expression *expr1, *expr2;
    const Operator operation;
};


#endif //OWNCPP_CONDITIONALEXPRESSION_H
