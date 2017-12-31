//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_CONSTANTS_H
#define OWNCPP_CONSTANTS_H

#include <string>
#include <map>

#include <cmath>

class Variables{
public:

    static Variables& instance(){
        static Variables s;
        return s;
    }

    bool exist(const std::string &key);

    double get(const std::string &key);

    void set(const std::string &key, double value);

    /// DISABLE COPY
    Variables(Variables const&) = delete;
    Variables& operator= (Variables const&) = delete;

private:
    /// PRIVATE CONSTRUCTOR, DESTRUCTOR
    Variables() = default;
    ~Variables() = default;

    /// Variables
    std::map<std::string, double> variables = {
            {"PI", M_PI},
            {"E", M_E}
    };
};

#endif //OWNCPP_CONSTANTS_H
