//
// Created by max on 1/2/18.
//

#include "../../include/ast/AstExpression.h"

using namespace ast;

Expression::~Expression() = default;

BinaryExpression::BinaryExpression(const char operationIn, const Expression *expr1In, const Expression *expr2In)
        : operation(operationIn), expr1(expr1In), expr2(expr2In) {
}

BinaryExpression::~BinaryExpression()  {
    delete expr1;
    delete expr2;
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
                throw runtime_error("Wrong operation with string");
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

const string BinaryExpression::toString() const {
    return '[' + expr1->toString() + ' ' + operation + ' ' + expr2->toString() + ']';
}

ConditionalExpression::ConditionalExpression(Operator operationIn, const Expression *expr1In, const Expression *expr2In)
        : operation(operationIn), expr1(expr1In), expr2(expr2In) {
}

ConditionalExpression::~ConditionalExpression() {
    delete expr1;
    delete expr2;
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
            throw runtime_error("Invalid conditional : " + v1->asString() + getOperatorAsString(operation) + v2->asString());
    }
    return new NumberValue(result);
}

const string ConditionalExpression::toString() const {
    return expr1->toString() + ' ' + getOperatorAsString(operation) + ' ' + expr2->toString();
}

const string ConditionalExpression::getOperatorAsString(Operator operationIn) {
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

UnaryExpression::UnaryExpression(const char operationIn, const Expression *exprIn)
        : operation(operationIn), expr(exprIn){
}

const Value * UnaryExpression::eval() const {
    switch (operation) {
        case '-':
            return new NumberValue(-expr->eval()->asNumber());
        case '+':
        default:
            return expr->eval();
    }
}

ValueExpression::ValueExpression(double valueIn) {
    value = new NumberValue(valueIn);
}

ValueExpression::ValueExpression(const string &valueIn) {
    value = new StringValue(valueIn);
}


ValueExpression::~ValueExpression() {
    delete value;
}

const Value *ValueExpression::eval() const {
    return value;
}

const string ValueExpression::toString() const {
    return value->toString();
}

VariableExpression::VariableExpression(string nameIn) : name(move(nameIn)) {
}

const Value * VariableExpression::eval() const {
    if (!Variables::instance()->exist(name)){
        throw runtime_error("Variable does not exists");
    }
    return Variables::instance()->get(name);
}

const string VariableExpression::toString() const {
    return name;
}