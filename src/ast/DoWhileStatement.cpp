//
// Created by max on 1/2/18.
//

#include <iostream>
#include "DoWhileStatement.h"
#include "BreakStatement.h"
#include "ContinueStatement.h"

using std::cout;
using std::endl;

DoWhileStatement::DoWhileStatement(const Expression *condition, const Statement *body)
        : condition(condition), body(body) {
}

DoWhileStatement::~DoWhileStatement() {
    delete condition;
    delete body;
    cout << "destruct DoWhileStatement" << endl;
}

void DoWhileStatement::execute() const {
    do{
        try {
            body->execute();
        }catch (BreakStatement &bs){
            break;
        }catch (ContinueStatement &cs){}
    }while (condition->eval()->asNumber() != 0);
}

std::string DoWhileStatement::toString() const {
    return "do " + body->toString() + " while " + condition->toString();
}
