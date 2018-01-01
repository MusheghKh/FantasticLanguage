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

    AssignmentStatement(std::string variableIn, const Expression* exprIn);

    ~AssignmentStatement() override{
        delete expr;
        std::cout << "destruct AssignmentStatement : " << variable << std::endl;
    }

    void execute() const override;

    std::string toString() const override;

private:

    const std::string variable;
    const Expression* expr;
};


#endif //OWNCPP_ASSIGNMENTSTATEMENT_H
