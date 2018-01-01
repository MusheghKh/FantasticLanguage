//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_FORSTATEMENT_H
#define OWNCPP_FORSTATEMENT_H


#include "Statement.h"
#include "Expression.h"

class ForStatement : public Statement{
public:
    ForStatement(const Statement *initializationIn, const Expression *terminationIn, const Statement *incrementIn,
                 const Statement *bodyIn);

    ~ForStatement() override;

    void execute() const override;

    std::string toString() const override;

private:
    const Statement *initialization;
    const Expression *termination;
    const Statement *increment;
    const Statement *body;
};


#endif //OWNCPP_FORSTATEMENT_H
