//File: String.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef STRING_HPP
#define STRING_HPP

#include <string>

namespace src
{
    namespace util
    {
        class String
        {
            public:
                static std::string getFixed(double value, int numDecimals);
        };
    }
}

#endif // STRING_HPP
