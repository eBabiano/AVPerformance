//File: AVTypes.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            const std::string AVTypes::FACE_DETECTION("FACE DETECTION");
            const std::string AVTypes::BACKGROUND_SUBTRACTOR("BACKGROUND SUBTRACTOR MOG2");
            const std::string AVTypes::OPTICAL_FLOW("OPTICAL FLOW");
            const std::string AVTypes::PEDESTRIAN_DETECTOR("PEDESTRIAN DETECTOR");
            ///const std::string AVTypes::STEREO("STEREO");

            const std::string AVTypes::GPU("GPU");
            const std::string AVTypes::CPU("CPU");

        }
    }
}
