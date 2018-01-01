//
// Created by max on 1/1/18.
//

#include <iostream>
#include <sstream>
#include "BlockStatement.h"

using std::cout;
using std::endl;
using std::stringstream;

BlockStatement::~BlockStatement() {
    for (auto s = statements.begin(); s < statements.end(); ++s) {
        delete *s;
    }
    cout << "destruct BlockStatement" << endl;
}

void BlockStatement::add(const Statement* statement) {
    statements.push_back(statement);
}

void BlockStatement::execute() const {
    for (auto s = statements.begin(); s < statements.end(); ++s) {
        (*s)->execute();
    }
}

std::string BlockStatement::toString() const {
    stringstream ss;
    for (auto s = statements.begin(); s < statements.end(); ++s) {
        ss << (*s)->toString() << endl;
    }
    return ss.str();
}
