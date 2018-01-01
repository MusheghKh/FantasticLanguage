//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_WHILESTATEMENT_H
#define OWNCPP_WHILESTATEMENT_H


#include "Statement.h"
#include "Expression.h"

class WhileStatement : public Statement{
public:
    WhileStatement(const Expression *conditionIn, const Statement *bodyIn);

    ~WhileStatement() override;

    void execute() const override;

    std::string toString() const override;

private:

    const Expression *condition;
    const Statement *body;
};


#endif //OWNCPP_WHILESTATEMENT_H
