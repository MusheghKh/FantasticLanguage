//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_VALUE_H
#define OWNCPP_VALUE_H

#include <string>

class Value {
public:

    virtual ~Value() = 0;

    virtual double asNumber() const = 0;

    virtual const std::string asString() const = 0;

    virtual std::string toString() const = 0;
};


#endif //OWNCPP_VALUE_H
