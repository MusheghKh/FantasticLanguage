//
// Created by max on 1/2/18.
//

#ifndef OWNCPP_DOWHILESTATEMENT_H
#define OWNCPP_DOWHILESTATEMENT_H


#include "Statement.h"
#include "Expression.h"

class DoWhileStatement : public Statement{
public:
    DoWhileStatement(const Expression *condition, const Statement *body);

    ~DoWhileStatement() override;

    void execute() const override;

    std::string toString() const override;

private:
    const Expression *condition;
    const Statement *body;
};


#endif //OWNCPP_DOWHILESTATEMENT_H
