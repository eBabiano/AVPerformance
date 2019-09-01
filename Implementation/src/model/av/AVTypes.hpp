//File: AVTypes.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef AVTYPES_HPP
#define AVTYPES_HPP

#include <string>

namespace src
{
    namespace model
    {
        namespace av
        {
            class AVTypes
            {
                public:
                    static const std::string FACE_DETECTION;
                    static const std::string BACKGROUND_SUBTRACTOR;
                    static const std::string OPTICAL_FLOW;
                    static const std::string PEDESTRIAN_DETECTOR;
                    ///@todo Add new string for create new AV algorithm
                    ///static const std::string STEREO;

                    static const std::string GPU;
                    static const std::string CPU;

            };
        }
    }
}

#endif // AVTYPES_HPP
