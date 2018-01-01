//
// Created by max on 1/1/18.
//

#include <iostream>
#include "ConditionalExpression.h"
#include "../lib/StringValue.h"
#include "../lib/NumberValue.h"

using std::string;
using std::cout;
using std::endl;

ConditionalExpression::ConditionalExpression(const char operationIn, const Expression *expr1In, const Expression *expr2In)
        : operation(operationIn), expr1(expr1In), expr2(expr2In) {
}

ConditionalExpression::~ConditionalExpression() {
    delete expr1;
    delete expr2;
    cout << "destruct ConditionalExpression : " << operation << endl;
}

const Value *ConditionalExpression::eval() const {
    const Value *v1 = expr1->eval();
    const Value *v2 = expr2->eval();
    if (dynamic_cast<const StringValue*>(v1)){
        const string &s1 = v1->asString();
        const string &s2 = v2->asString();
        switch (operation){
            case '<':
                return new NumberValue(s1 < s2);
            case '>':
                return new NumberValue(s1 > s2);
            case '=':
                return new NumberValue(s1 == s2);
            default:
                throw std::runtime_error("Invalid conditional : " + s1 + operation + s2);
        }
    }

    switch (operation){
        case '<':
            return new NumberValue(v1->asNumber() < v2->asNumber());
        case '>':
            return new NumberValue(v1->asNumber() > v2->asNumber());
        case '=':
            return new NumberValue(v1->asNumber() == v2->asNumber());
        default:
            throw std::runtime_error("Invalid conditional : " + v1->asString() + operation + v2->asString());
    }
}

const std::string ConditionalExpression::toString() const {
    return expr1->toString() + ' ' + operation + ' ' + expr2->toString();
}