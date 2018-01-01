//
// Created by max on 12/31/17.
//

#include <stdexcept>
#include <utility>
#include "StringValue.h"

StringValue::StringValue(std::string valueIn)
        : value(std::move(valueIn)) {

}

double StringValue::asNumber() const {
    try {
        return std::stod(value);
    }catch (const std::invalid_argument & e){
        return 0;
    }
}

const std::string StringValue::asString() const {
    return value;
}

std::string StringValue::toString() const {
    return '"' + asString() + '"';
}
