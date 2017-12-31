//
// Created by max on 12/31/17.
//

#include "Constants.h"

bool Constants::constantExists(const std::string &key) {
    return constants.find(key) != constants.end();
}

double Constants::getConstant(const std::string &key) {
    if (!constantExists(key)){
        return 0;
    }
    return constants.at(key);
}