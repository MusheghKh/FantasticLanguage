//
// Created by max on 1/1/18.
//

#include <iostream>
#include "ContinueStatement.h"

using std::cout;
using std::endl;

ContinueStatement::ContinueStatement() : runtime_error("continue") {}

ContinueStatement::~ContinueStatement() {
    cout << "destruct ContinueStatement" << endl;
}

void ContinueStatement::execute() const {
    throw *this;
}

std::string ContinueStatement::toString() const {
    return "continue";
}
