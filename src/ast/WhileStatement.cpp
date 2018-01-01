//
// Created by max on 1/1/18.
//

#include <iostream>
#include "WhileStatement.h"

using std::cout;
using std::endl;

WhileStatement::WhileStatement(const Expression *conditionIn, const Statement *bodyIn)
        : condition(conditionIn), body(bodyIn) {}


WhileStatement::~WhileStatement() {
    delete condition;
    delete body;
    cout << "destruct WhileStatement" << endl;
}

void WhileStatement::execute() const {
    while (condition->eval()->asNumber() != 0){
        body->execute();
    }
}

std::string WhileStatement::toString() const {
    return "while " + condition->toString() + ' ' + body->toString();
}