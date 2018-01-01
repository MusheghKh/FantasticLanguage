//
// Created by max on 12/29/17.
//

#include "BinaryExpression.h"
#include "../lib/NumberValue.h"
#include "../lib/StringValue.h"

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

BinaryExpression::BinaryExpression(const char operationIn, const Expression *expr1In, const Expression *expr2In)
        : operation(operationIn), expr1(expr1In), expr2(expr2In) {
}

const Value *BinaryExpression::eval() const {
    const Value *v1 = expr1->eval();
    const Value *v2 = expr2->eval();
    if (dynamic_cast<const StringValue *>(v1)) {
        const string s1 = v1->asString();
        switch (operation) {
            case '*': {
                const auto iterations = (int) v2->asNumber();
                stringstream ss;
                for (int i = 0; i < iterations; ++i) {
                    ss << s1;
                }
                return new StringValue(ss.str());
            }
            case '+':
                return new StringValue(s1 + v2->asString());
            default:
                throw std::runtime_error("Wrong operation with string");
        }
    }
    const double n1 = v1->asNumber();
    const double n2 = v2->asNumber();
    switch (operation) {
        case '-':
            return new NumberValue(n1 - n2);
        case '*':
            return new NumberValue(n1 * n2);
        case '/':
            return new NumberValue(n1 / n2);
        case '+':
        default:
            return new NumberValue(n1 + n2);
    }
}

const std::string BinaryExpression::toString() const {
    return '[' + expr1->toString() + ' ' + operation + ' ' + expr2->toString() + ']';
}