//File: OpticalFlowTypes.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/OpticalFlowTypes.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            //GOOD FEATURES
            const std::string OpticalFlowTypes::MAX_CORNERS("MAX_CORNERS");
            const std::string OpticalFlowTypes::MIN_DISTANCE("MIN_DISTANCE");
            const std::string OpticalFlowTypes::BLOCK_SIZE("BLOCK_SIZE");
            const std::string OpticalFlowTypes::HARRIS_DETECTOR("HARRIS_DETECTOR");
            const std::string OpticalFlowTypes::K_FACTOR("K_FACTOR");

            //TERM CRITERIA
            const std::string OpticalFlowTypes::TYPE("TYPE");
            const std::string OpticalFlowTypes::MAX_COUNT("MAX_COUNT");
            const std::string OpticalFlowTypes::EPS("EPS");

        }
    }
}
