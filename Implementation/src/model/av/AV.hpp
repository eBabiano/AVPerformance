//File: AV.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef AV_HPP
#define AV_HPP

#include <src/util/Observable.hpp>
#include <src/model/av/events/AlgorithmParametersModified.hpp>

#include <assert.h>
#include <map>

namespace src
{
    namespace model
    {
        namespace av
        {
            class AV
                    : public util::Observable<events::AlgorithmParametersModified>
            {
                public:
                    AV();

                    //BACKGROUND SUBSTRACTOR
                    virtual double getLearningRate() const {assert(false);}
                    virtual void setLearningRate(double learningRate){assert(false);}

                    //FACE DETECTION
                    virtual double getScaleFactor() const {assert(false);}
                    virtual void setScaleFactor(double factor) {assert(false);}
                    virtual int getNeightbors() const {assert(false);}
                    virtual void setNeightbors(int neightbors) {assert(false);}
                    virtual int getWidth() const {assert(false);}
                    virtual void setWidth(int width) {assert(false);}
                    virtual int getHeight() const {assert(false);}
                    virtual void setHeight(int height) {assert(false);}

                    //OPTICAL FLOW
                    virtual double getGoodFeaturesParameters(const std::string &type) const{assert(false);}
                    virtual void setGoodFeaturesParameters(const std::map<std::string, double> &value){assert(false);}

                    virtual double getTermCriteriaParameters(const std::string &type) const{assert(false);}
                    virtual void setTermCriteriaParameters(const std::map<std::string, double> &value){assert(false);}

                    virtual double getOpticalFlowParameters(const std::string &type) const{assert(false);}
                    virtual void setOpticalFlowParameters(const std::map<std::string, double> &value){assert(false);}

                    //PEDESTRIAN DETECTOR
                    virtual double getHitThreshold() const{assert(false);}
                    virtual void setHitThreshold(double value){assert(false);}

                    virtual int getWindStrideWidth() const{assert(false);}
                    virtual int getWindStrideHeight() const{assert(false);}
                    virtual void setWindStride(int width, int height){assert(false);}

                    virtual int getPaddingWidth() const{assert(false);}
                    virtual int getPaddingHeight() const{assert(false);}
                    virtual void setPadding(int width, int height){assert(false);}

                    virtual double getScale() const{assert(false);}
                    virtual void setScale(double value){assert(false);}

                    virtual double getFinalThreshold() const{assert(false);}
                    virtual void setFinalThreshold(double value){assert(false);}

                    virtual int getUseMeanShiftGrouping() const{assert(false);}
                    virtual void setUseMeanShiftGrouping(int value){assert(false);}

                    //COMMON
                    virtual std::string getProcessorType() const {assert(false);}
                    virtual void setProcessorType(const std::string& type) {assert(false);}

            protected:
                    using util::Observable<events::AlgorithmParametersModified>::notify;


            };
        }
    }
}

#endif // AV_HPP
