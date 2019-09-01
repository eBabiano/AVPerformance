//File: OpticalFlow.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/OpticalFlow.hpp>
#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            OpticalFlow::OpticalFlow()
                : mProcessorType(model::av::AVTypes::CPU)
            {
                mGoodFeaturesParameters[OpticalFlowTypes::MAX_CORNERS] = 500;
                mGoodFeaturesParameters[OpticalFlowTypes::MIN_DISTANCE] = 10.0;
                mGoodFeaturesParameters[OpticalFlowTypes::BLOCK_SIZE] = 3;
                mGoodFeaturesParameters[OpticalFlowTypes::HARRIS_DETECTOR] = 0;
                mGoodFeaturesParameters[OpticalFlowTypes::K_FACTOR] = 0.04;

                mTermCriteriaParameters[OpticalFlowTypes::TYPE] = 1;
                mTermCriteriaParameters[OpticalFlowTypes::MAX_COUNT] = 20;
                mTermCriteriaParameters[OpticalFlowTypes::EPS] = 0.03;
            }

            std::string OpticalFlow::getProcessorType() const
            {
                return mProcessorType;
            }

            void OpticalFlow::setProcessorType(const std::string &type)
            {
                if (type != mProcessorType)
                {
                    mProcessorType = type;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::OPTICAL_FLOW));
                }
            }

            double OpticalFlow::getGoodFeaturesParameters(const std::string& type) const
            {
                return mGoodFeaturesParameters.at(type);
            }

            void OpticalFlow::setGoodFeaturesParameters(const std::map<std::string, double> &value)
            {
                mGoodFeaturesParameters = value;
                notify(events::AlgorithmParametersModified(model::av::AVTypes::OPTICAL_FLOW));
            }

            double OpticalFlow::getTermCriteriaParameters(const std::string &type) const
            {
                return mTermCriteriaParameters.at(type);

            }

            void OpticalFlow::setTermCriteriaParameters(const std::map<std::string, double> &value)
            {
                mTermCriteriaParameters = value;
                notify(events::AlgorithmParametersModified(model::av::AVTypes::OPTICAL_FLOW));
            }

        }
    }
}
