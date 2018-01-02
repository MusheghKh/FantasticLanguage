//
// Created by max on 1/2/18.
//

#ifndef OWNCPP_ASTEXPRESSION_H
#define OWNCPP_ASTEXPRESSION_H

#include <string>
#include <sstream>

#include "../lib/Value.h"
#include "../../include/lib/Storage.h"

using namespace std;
using namespace storage;

namespace ast
{
    class Expression
    {
    public:

        virtual ~Expression() = 0;

        virtual const Value * eval() const = 0;

        virtual const string toString() const = 0;
    };

    class BinaryExpression : public Expression
    {
    public:

        BinaryExpression(char operationIn, const Expression* expr1In, const Expression* expr2In);

        ~BinaryExpression() override;

        const Value * eval() const override;

        const string toString() const override;

    private:

        const Expression* expr1;
        const Expression *expr2;
        const char operation;
    };

    class ConditionalExpression : public Expression
    {
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

        const string toString() const override;

    private:

        static const string getOperatorAsString(Operator operationIn) ;

        const Expression *expr1, *expr2;
        const Operator operation;
    };

    class UnaryExpression : public Expression
    {
    public:

        UnaryExpression(char operationIn, const Expression* exprIn);

        ~UnaryExpression() override {
            delete expr;
        }

        const Value * eval() const override;

        const string toString() const override {
            return "" + operation + expr->toString();
        }

    private:

        const Expression* expr;
        const char operation;
    };

    class ValueExpression : public Expression
    {
    public:
        explicit ValueExpression(double valueIn);

        explicit ValueExpression(const string & valueIn);

        ~ValueExpression() override;

        const Value *eval() const override;

        const string toString() const override;

    private:
        const Value * value;
    };

    class VariableExpression : public Expression
    {
    public:

        explicit VariableExpression(string string);

        ~VariableExpression() override = default;;

        const Value * eval() const override;

        const string toString() const override;

    private:
        const string name;
    };
}

#endif //OWNCPP_ASTEXPRESSION_H
