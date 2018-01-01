//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_NUMBERVALUE_H
#define OWNCPP_NUMBERVALUE_H


#include <iostream>
#include "Value.h"

class NumberValue : public Value{
public:
    explicit NumberValue(double valueIn);

    ~NumberValue() override{
        std::cout << "destruct NumberValue" << std::endl;
    };

    double asNumber() const override;

    const std::string asString() const override;

    std::string toString() const override;

private:
    const double value;
};


#endif //OWNCPP_NUMBERVALUE_H
