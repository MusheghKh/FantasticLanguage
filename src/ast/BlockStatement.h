//
// Created by max on 1/1/18.
//

#ifndef OWNCPP_BLOCKSTATEMENT_H
#define OWNCPP_BLOCKSTATEMENT_H


#include <vector>
#include "Statement.h"

class BlockStatement : public Statement{
public:
    BlockStatement() = default;

    ~BlockStatement() override;

    void add(const Statement* statement);

    void execute() const override;

    std::string toString() const override;

private:

    std::vector<const Statement*> statements;
};


#endif //OWNCPP_BLOCKSTATEMENT_H
