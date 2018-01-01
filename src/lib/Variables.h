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

    /// PRIVATE CONSTRUCTOR, DESTRUCTOR
    Variables() = default;
    ~Variables() = default;

    /// Variables
    std::map<std::string, const Value*> variables = {
            {"PI", new NumberValue(M_PI)},
            {"E", new NumberValue(M_E)}
    };
};

/// Singleton
static Variables *singleton = nullptr;

static const NumberValue * ZERO = new NumberValue(0);

#endif //OWNCPP_CONSTANTS_H
