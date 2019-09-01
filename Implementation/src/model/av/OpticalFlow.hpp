//File: OpticalFlow.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef OPTICALFLOW_HPP
#define OPTICALFLOW_HPP

#include <src/model/av/AV.hpp>
#include <src/model/av/OpticalFlowTypes.hpp>

#include <map>

namespace src
{
    namespace model
    {
        namespace av
        {
            class OpticalFlow
                    : public AV
            {
                public:
                    OpticalFlow();

                    virtual std::string getProcessorType() const;
                    virtual void setProcessorType(const std::string& type);

                    double getGoodFeaturesParameters(const std::string &type) const;
                    void setGoodFeaturesParameters(const std::map<std::string, double> &value);

                    virtual double getTermCriteriaParameters(const std::string &type) const;
                    virtual void setTermCriteriaParameters(const std::map<std::string, double> &value);

            private:
                    std::string mProcessorType;

                    std::map<std::string, double> mGoodFeaturesParameters;
                    std::map<std::string, double> mCornerSubPixParameters;
                    std::map<std::string, double> mTermCriteriaParameters;
                    std::map<std::string, double> mOpticalFlowParameters;
            };
        }
    }
}

#endif // OPTICALFLOW_HPP
