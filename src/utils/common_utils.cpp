//
// Created by max on 12/31/17.
//
#include "../../include/utils/common_utils.h"

string utils::readFile(const string &path) {
    ifstream ifs(path);
    string content { istreambuf_iterator<char>(ifs), istreambuf_iterator<char>() };

    return content;
}

string utils::makeRawSpecialChars(string target){
    string::size_type pos = 0;
    while ( ( pos = target.find ('\n',pos) ) != string::npos )
    {
        target.erase ( pos, 1 );
        target.insert(pos, "\\n");
    }
    return target;
}