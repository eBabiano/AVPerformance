#include <src/view/gui/events/ModifyOpticalFlowEvent.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                ModifyOpticalFlowEvent::ModifyOpticalFlowEvent(const std::string &type,
                                                               const std::map<std::string, double>& goodFeatures,
                                                               const std::map<std::string, double> &termCriteria
                                                               /*const std::map<const std::string&, double>& cornerSubPix,
                                                               const std::map<const std::string&, double>& opticalFlow*/,
                                                               const std::map<std::string, double> &opticalFlow)
                    : mProcessorType(type)
                    , mGoodFeaturesParameters(goodFeatures)
                    , mTermCriteriaParameters(termCriteria)
                    /*, mCornerSubPixParameters(cornerSubPix)*/
                    , mOpticalFlowParameters(opticalFlow)
                {
                }

                std::string ModifyOpticalFlowEvent::getProcessorType() const
                {
                    return mProcessorType;
                }

                const std::map<std::string, double> &ModifyOpticalFlowEvent::getGoodFeaturesParameters() const
                {
                    return mGoodFeaturesParameters;
                }

                const std::map<std::string, double> &ModifyOpticalFlowEvent::getTermCriteriaParameters() const
                {
                    return mTermCriteriaParameters;
                }

//                const std::map<const std::string&, double>& ModifyOpticalFlowEvent::getCornerSubPixParameters() const
//                {
//                    return mCornerSubPixParameters;
//                }


                const std::map<std::string, double>& ModifyOpticalFlowEvent::getOpticalFlowParameters() const
                {
                    return mOpticalFlowParameters;
                }


            }
        }
    }
}
