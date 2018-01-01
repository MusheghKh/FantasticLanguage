//
// Created by max on 12/31/17.
//

#include "Variables.h"

bool Variables::exist(const std::string &key) {
    return variables.find(key) != variables.end();
}

const Value * Variables::get(const std::string &key) {
    if (!exist(key)){
        return ZERO;
    }
    return variables.at(key);
}

void Variables::set(const std::string &key, const Value *value) {
    variables.insert({key, value});
}