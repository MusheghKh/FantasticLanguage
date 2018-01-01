//
// Created by max on 1/1/18.
//

#include <iostream>
#include "BreakStatement.h"

using std::cout;
using std::endl;

BreakStatement::BreakStatement() : runtime_error("break") {}

BreakStatement::~BreakStatement() {
    cout << "destruct BreakStatement" << endl;
}

void BreakStatement::execute() const {
    throw *this;
}

std::string BreakStatement::toString() const {
    return "break";
}
