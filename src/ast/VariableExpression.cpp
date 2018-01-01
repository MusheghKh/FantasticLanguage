//
// Created by max on 12/31/17.
//

#include "VariableExpression.h"
#include "../lib/Variables.h"

using std::string;

VariableExpression::VariableExpression(string nameIn) : name(std::move(nameIn)) {
}

const Value * VariableExpression::eval() const {
    if (!Variables::instance().exist(name)){
        throw std::runtime_error("Constant does not exists");
    }
    return Variables::instance().get(name);
}

const string VariableExpression::toString() const {
    return name;
}