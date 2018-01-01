//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_IFSTATEMENT_H
#define OWNCPP_IFSTATEMENT_H


#include "Statement.h"
#include "Expression.h"

class IfStatement : public Statement{
public:
    IfStatement(const Expression *exprIn, const Statement *ifStatementIn, const Statement *elseStatementIn);

    IfStatement(const Expression *exprIn, const Statement *ifStatementIn);

    ~IfStatement() override;

    void execute() const override;

    std::string toString() const override;

private:

    const Expression *expr;
    const Statement *ifStatement, *elseStatement = nullptr;
};


#endif //OWNCPP_IFSTATEMENT_H
