//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_ASSIGNMENTSTATEMENT_H
#define OWNCPP_ASSIGNMENTSTATEMENT_H


#include <iostream>
#include "Statement.h"
#include "Expression.h"

class AssignmentStatement : public Statement{
public:

    AssignmentStatement(const std::string& variableIn, Expression* exprIn);

    ~AssignmentStatement() override{
        delete expr;
        std::cout << "destruct AssignmentStatement : " << variable << std::endl;
    }

    void execute() override;

    std::string toString() override;

private:

    const std::string variable;
    Expression* expr;
};


#endif //OWNCPP_ASSIGNMENTSTATEMENT_H
