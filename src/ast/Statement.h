//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_STATEMENT_H
#define OWNCPP_STATEMENT_H

#include <string>

class Statement {
public:
    virtual ~Statement() = 0;

    virtual void execute() const = 0;

    virtual std::string toString() const = 0;

};


#endif //OWNCPP_STATEMENT_H
