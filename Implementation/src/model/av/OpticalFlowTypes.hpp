//File: OpticalFlowTypes.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef OPTICALFLOWTYPES_HPP
#define OPTICALFLOWTYPES_HPP

#include <string>

namespace src
{
    namespace model
    {
        namespace av
        {
            class OpticalFlowTypes
            {
                public:
                    //GOOD FEATURES
                    static const std::string MAX_CORNERS;
                    static const std::string MIN_DISTANCE;
                    static const std::string BLOCK_SIZE;
                    static const std::string HARRIS_DETECTOR;
                    static const std::string K_FACTOR;

                    //TERM CRITERIA
                    static const std::string TYPE;
                    static const std::string MAX_COUNT;
                    static const std::string EPS;

                    //OPTICAL FLOW LUCAS-KANADE
                    static const std::string WIN_SIZE_WIDTH;
                    static const std::string WIN_SIZE_HEIGHT;
                    static const std::string MAX_LEVELS;
                    static const std::string FLAGS;
                    static const std::string THRESHOLD;

            };
        }
    }
}

#endif // OPTICALFLOWTYPES_HPP
