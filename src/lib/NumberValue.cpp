//
// Created by max on 12/31/17.
//

#include "NumberValue.h"

using std::to_string;

NumberValue::NumberValue(double valueIn) : value(valueIn){

}


double NumberValue::asNumber() const {
    return value;
}

const std::string NumberValue::asString() const {
    return to_string(value);
}

std::string NumberValue::toString() const {
    return asString();
}