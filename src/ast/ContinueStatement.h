//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_CONTINUESTATEMENT_H
#define OWNCPP_CONTINUESTATEMENT_H


#include <stdexcept>
#include "Statement.h"

class ContinueStatement : public std::runtime_error, public Statement{
public:

    explicit ContinueStatement();

    ~ContinueStatement() override;

    void execute() const override;

    std::string toString() const override;
};


#endif //OWNCPP_CONTINUESTATEMENT_H
