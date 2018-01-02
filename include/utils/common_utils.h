//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_FILE_UTIL_H
#define OWNCPP_FILE_UTIL_H

#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

namespace utils
{

    std::string readFile(const std::string &path);

    std::string makeRawSpecialChars(std::string target);

}

#endif //OWNCPP_FILE_UTIL_H
