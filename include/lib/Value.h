//
// Created by max on 12/31/17.
//

#ifndef OWNCPP_VALUE_H
#define OWNCPP_VALUE_H

#include <string>
#include <stdexcept>

using namespace std;

namespace storage
{

    class Value
    {
    public:

        virtual ~Value() = 0;

        virtual double asNumber() const = 0;

        virtual const string asString() const = 0;

        virtual string toString() const = 0;
    };

    class StringValue : public Value
    {
    public:
        explicit StringValue(string valueIn);

        ~StringValue() override = default;

        double asNumber() const override;

        const string asString() const override;

        string toString() const override;

    private:
        const string value;
    };

    class NumberValue : public Value
    {
    public:
        explicit NumberValue(double valueIn);

        ~NumberValue() override = default;;

        double asNumber() const override;

        const string asString() const override;

        string toString() const override;

    private:
        const double value;
    };

}


#endif //OWNCPP_VALUE_H
