//
// Created by max on 1/1/18.
//

#include <iostream>
#include "ForStatement.h"

using std::cout;
using std::endl;

ForStatement::ForStatement(const Statement *initializationIn, const Expression *terminationIn, const Statement *incrementIn,
                           const Statement *bodyIn)
        : initialization(initializationIn), termination(terminationIn), increment(incrementIn), body(bodyIn) {
}


ForStatement::~ForStatement() {
    delete initialization;
    delete termination;
    delete increment;
    delete body;
    cout << "destruct ForStatement" << endl;
}

void ForStatement::execute() const {
    for (initialization->execute(); termination->eval()->asNumber() != 0 ; increment->execute()) {
        body->execute();
    }
}

std::string ForStatement::toString() const {
    return "for " + increment->toString() + ", " + termination->toString() + ", " + increment->toString() + ' ' + body->toString();
}
