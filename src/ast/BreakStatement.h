//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_BREAKSTATEMENT_H
#define OWNCPP_BREAKSTATEMENT_H

#include <stdexcept>
#include "Statement.h"

using std::runtime_error;

class BreakStatement : public runtime_error, public Statement{
public:
    explicit BreakStatement();

    ~BreakStatement() override;

    void execute() const override;

    std::string toString() const override;

};

#endif //OWNCPP_BREAKSTATEMENT_H
