#ifndef CASTING_HPP
# define CASTING_HPP

#include <iostream>
#include <string.h>

class Casting {
    public:
        Casting();
        ~Casting();
        Casting(Casting const &org);
        Casting &operator=(Casting const &other);
        void checkValue(const std::string &str);
        bool isStringEqual(const std::string& str);
        //convert 
        void convert(const std::string &str);
        void toChar(const std::string &str);
        void toInt(const std::string &str);
        void toFloat(const std::string &str);
        void toDouble(const std::string &str);
};

#endif