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

ConditionalExpression::ConditionalExpression(Operator operationIn, const Expression *expr1In, const Expression *expr2In)
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

    double n1, n2;
    if (dynamic_cast<const StringValue*>(v1)){
        n1 = v1->asString().compare(v2->asString());
        n2 = 0;
    } else{
        n1 = v1->asNumber();
        n2 = v2->asNumber();
    }

    bool result;
    switch (operation){
        case LT: result = n1 < n2; break;
        case LTEQ: result = n1 <= n2; break;
        case GT: result = n1 > n2; break;
        case GTEQ: result = n1 >= n2; break;
        case NOT_EQUALS: result = n1 != n2; break;
        case AND: result = (n1 != 0) && (n2 != 0); break;
        case OR: result = (n1 != 0) || (n2 != 0); break;
        case EQUALS: result = n1 == n2; break;
        default:
            throw std::runtime_error("Invalid conditional : " + v1->asString() + getOperatorAsString(operation) + v2->asString());
    }
    return new NumberValue(result);
}

const std::string ConditionalExpression::toString() const {
    return expr1->toString() + ' ' + getOperatorAsString(operation) + ' ' + expr2->toString();
}

const std::string ConditionalExpression::getOperatorAsString(Operator operationIn) {
    switch (operationIn){
        case PLUS: return "+";
        case MINUS: return "-";
        case MULTIPLY: return "*";
        case DIVIDE: return "/";
        case EQUALS: return "==";
        case NOT_EQUALS: return "!=";
        case LT: return "<";
        case LTEQ: return "<=";
        case GT: return ">";
        case GTEQ: return ">=";
        case AND: return "&&";
        case OR: return "||";
        default:
            return "Unknown Operator";
    }
}
