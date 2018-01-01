//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_STRINGVALUE_H
#define OWNCPP_STRINGVALUE_H

#include <string>
#include <iostream>
#include "Value.h"

class StringValue : public Value{
public:
    explicit StringValue(std::string valueIn);

    ~StringValue() override {
        std::cout << "destruct StringValue" << std::endl;
    }

    double asNumber() const override;

    const std::string asString() const override;

    std::string toString() const override;

private:
    const std::string value;
};


#endif //OWNCPP_STRINGVALUE_H
