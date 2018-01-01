//
// Created by max on 12/31/17.
//

#include <iostream>
#include "ValueExpression.h"
#include "../lib/NumberValue.h"
#include "../lib/StringValue.h"

using std::cout;
using std::endl;

ValueExpression::ValueExpression(double valueIn) {
    value = new NumberValue(valueIn);
}

ValueExpression::ValueExpression(const std::string &valueIn) {
    value = new StringValue(valueIn);
}


ValueExpression::~ValueExpression() {
    delete value;
    cout << "destruct ValueExpression" << endl;
}

const Value *ValueExpression::eval() const {
    return value;
}

const std::string ValueExpression::toString() const {
    return value->toString();
}
