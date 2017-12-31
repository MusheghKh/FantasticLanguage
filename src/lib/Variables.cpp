//
// Created by max on 12/31/17.
//

#include "Variables.h"

bool Variables::exist(const std::string &key) {
    return variables.find(key) != variables.end();
}

double Variables::get(const std::string &key) {
    if (!exist(key)){
        return 0;
    }
    return variables.at(key);
}

void Variables::set(const std::string &key, double value) {
    variables.insert({key, value});
}