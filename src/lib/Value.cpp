//
// Created by max on 12/31/17.
//

#include "../../include/lib/Value.h"

using namespace storage;

Value::~Value() = default;

StringValue::StringValue(std::string valueIn)
        : value(std::move(valueIn)) {

}

double StringValue::asNumber() const {
    try {
        return stod(value);
    }catch (const invalid_argument & e){
        return 0;
    }
}

const string StringValue::asString() const {
    return value;
}

string StringValue::toString() const {
    return '"' + asString() + '"';
}

NumberValue::NumberValue(double valueIn) : value(valueIn){
}

double NumberValue::asNumber() const {
    return value;
}

const string NumberValue::asString() const {
    return to_string(value);
}

string NumberValue::toString() const {
    return asString();
}