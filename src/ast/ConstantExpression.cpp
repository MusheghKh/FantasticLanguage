//
// Created by max on 12/31/17.
//

#include "ConstantExpression.h"
#include "../lib/Constants.h"

#include <string>

using std::string;

ConstantExpression::ConstantExpression(const string& nameIn) : name(nameIn) {}

double ConstantExpression::eval() {
    if (!Constants::instance().constantExists(name)){
        throw std::runtime_error("Constant does not exists");
    }
    return Constants::instance().getConstant(name);
}

const string ConstantExpression::toString() {
    return name;
}