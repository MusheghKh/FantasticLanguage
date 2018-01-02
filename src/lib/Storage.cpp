//
// Created by max on 1/2/18.
//

#include "../../include/lib/Storage.h"

using namespace storage;

const NumberValue* Variables::ZERO = new NumberValue(0);

Variables *Variables::singleton = nullptr;

Variables *Variables::instance() {
    if (singleton == nullptr){
        singleton = new Variables();
    }
    return singleton;
}

bool Variables::exist(const std::string &key) {
    return variables.find(key) != variables.end();
}

const Value * Variables::get(const std::string &key) {
    if (!exist(key)){
        return ZERO;
    }
    return variables.at(key);
}

// TODO make create and replace value in another method
void Variables::set(const std::string &key, const Value *value) {
    if (exist(key)){
        variables[key] = value;
        return;
    }
    variables.insert({key, value});
}