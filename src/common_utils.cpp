//
// Created by max on 12/31/17.
//
#include "common_utils.h"

#include <fstream>
#include <algorithm>

std::string readFile(const std::string path) {
    std::ifstream ifs(path);
    std::string content { std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

    return content;
}

std::string makeRawSpecialChars(std::string target){
    std::string::size_type pos = 0;
    while ( ( pos = target.find ('\n',pos) ) != std::string::npos )
    {
        target.erase ( pos, 1 );
        target.insert(pos, "\\n");
    }
    return target;
}