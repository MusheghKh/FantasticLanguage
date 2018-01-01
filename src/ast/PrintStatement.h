//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_PRINTSTATEMENT_H
#define OWNCPP_PRINTSTATEMENT_H


#include "Statement.h"
#include "Expression.h"

class PrintStatement : public Statement{
public:
    explicit PrintStatement(const Expression *exprIn);

    ~PrintStatement() override;

    void execute() const override;

    std::string toString() const override;

private:
    const Expression* expr;
};


#endif //OWNCPP_PRINTSTATEMENT_H
