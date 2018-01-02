//
// Created by max on 1/2/18.
//

#ifndef OWNCPP_STORAGE_H
#define OWNCPP_STORAGE_H

#include <string>
#include <map>
#include <cmath>

#include "Value.h"

using namespace std;

namespace storage {

    class Variables {
    public:

        static Variables *instance();

        bool exist(const string &key);

        const Value *get(const string &key);

        void set(const string &key, const Value *value);

        /// DISABLE COPY
        Variables(Variables const &) = delete;

        Variables &operator=(Variables const &) = delete;

    private:
        /// Singleton
        static Variables *singleton;

        /// Static Constant
        static const NumberValue *ZERO;

        /// Variables
        map<string, const Value *> variables = {
                {"PI", new NumberValue(M_PI)},
                {"E",  new NumberValue(M_E)}
        };

        /// PRIVATE CONSTRUCTOR, DESTRUCTOR
        Variables() = default;
        ~Variables() = default;
    };

}

#endif //OWNCPP_STORAGE_H
