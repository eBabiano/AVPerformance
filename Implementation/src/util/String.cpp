//File: String.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/util/String.hpp>
#include <iomanip>
#include <sstream>

namespace src
{
    namespace util
    {
        std::string String::getFixed(double value, int numDecimals)
        {
            std::stringstream stream;
            stream << std::fixed << std::setprecision(numDecimals) << value;
            return stream.str();
        }
    }
}
