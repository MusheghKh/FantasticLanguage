//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_CONSTANTS_H
#define OWNCPP_CONSTANTS_H

#include <string>
#include <map>

#include <cmath>
#include "NumberValue.h"

class Variables{
public:

    static Variables * instance();

    bool exist(const std::string &key);

    const Value * get(const std::string &key);

    void set(const std::string &key, const Value * value);

    /// DISABLE COPY
    Variables(Variables const&) = delete;
    Variables& operator= (Variables const&) = delete;

private:

    const NumberValue * ZERO = new NumberValue(0);

    /// Variables
    std::map<std::string, const Value*> variables = {
            {"PI", new NumberValue(M_PI)},
            {"E", new NumberValue(M_E)}
    };

    /// PRIVATE CONSTRUCTOR, DESTRUCTOR
    Variables() = default;
    ~Variables() = default;
};

/// Singleton
static Variables *singleton;

#endif //OWNCPP_CONSTANTS_H
