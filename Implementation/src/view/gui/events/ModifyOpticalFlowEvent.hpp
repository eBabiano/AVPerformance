#ifndef MODIFYOPTICALFLOWEVENT_HPP
#define MODIFYOPTICALFLOWEVENT_HPP

#include <map>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                class ModifyOpticalFlowEvent
                {
                    public:
                        ModifyOpticalFlowEvent(const std::string& type,
                                               const std::map<std::string, double>& goodFeatures,
                                               const std::map<std::string, double>& termCriteria,
                                               /*const std::map<const std::string&, double>& cornerSubPix,*/
                                               const std::map<std::string, double>& opticalFlow);

                        std::string getProcessorType() const;

                        const std::map<std::string, double>& getGoodFeaturesParameters() const;
                        const std::map<std::string, double>& getTermCriteriaParameters() const;
//                        const std::map<const std::string&, double>& getCornerSubPixParameters() const;
                        const std::map<std::string, double>& getOpticalFlowParameters() const;

                    private:
                        std::string mProcessorType;

                        const std::map<std::string, double>& mGoodFeaturesParameters;
                        const std::map<std::string, double>& mTermCriteriaParameters;
//                        const std::map<const std::string&, double>& mCornerSubPixParameters;
                        const std::map<std::string, double>& mOpticalFlowParameters;
                };
            }
        }
    }
}

#endif // MODIFYOPTICALFLOWEVENT_HPP
