//
// Created by max on 12/31/17.
//

#include "VariableExpression.h"
#include "../lib/Variables.h"

#include <string>

using std::string;

VariableExpression::VariableExpression(const string& nameIn) : name(nameIn) {
    std::cout << "const" << std::endl;
}

double VariableExpression::eval() {
    if (!Variables::instance().exist(name)){
        throw std::runtime_error("Constant does not exists");
    }
    return Variables::instance().get(name);
}

const string VariableExpression::toString() {
    return name;
}