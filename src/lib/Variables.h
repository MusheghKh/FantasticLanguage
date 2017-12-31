//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_CONSTANTS_H
#define OWNCPP_CONSTANTS_H

#include <string>
#include <map>

#include <cmath>

class Constants{
public:

    static Constants& instance(){
        static Constants s;
        return s;
    }

    bool constantExists(const std::string &key);

    double getConstant(const std::string &key);


private:
    /// PRIVATE CONSTRUCTOR, DESTRUCTOR
    Constants() = default;
    ~Constants() = default;

    /// DISABLE COPY
    Constants(Constants const&) = delete;
    Constants& operator= (Constants const&) = delete;

    /// Variables
    std::map<std::string, double> constants = {
            {"PI", M_PI},
            {"E", M_E}
    };
};

#endif //OWNCPP_CONSTANTS_H
