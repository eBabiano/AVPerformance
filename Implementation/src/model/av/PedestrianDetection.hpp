//File: PedestrianDetection.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef PEDESTRIANDETECTION_HPP
#define PEDESTRIANDETECTION_HPP

#include <src/model/av/AV.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            class PedestrianDetection
                    : public AV
            {
                public:
                    PedestrianDetection();

                    virtual std::string getProcessorType() const;
                    virtual void setProcessorType(const std::string& type);

                    virtual double getHitThreshold() const;
                    virtual void setHitThreshold(double value);

                    virtual int getWindStrideWidth() const;
                    virtual int getWindStrideHeight() const;
                    virtual void setWindStride(int width, int height);

                    virtual int getPaddingWidth() const;
                    virtual int getPaddingHeight() const;
                    virtual void setPadding(int width, int height);

                    virtual double getScale() const;
                    virtual void setScale(double value);

                    virtual double getFinalThreshold() const;
                    virtual void setFinalThreshold(double value);

                    virtual int getUseMeanShiftGrouping() const;
                    virtual void setUseMeanShiftGrouping(int value);

            private:
                    std::string mProcessorType;

                    double mHitThreshold;
                    int mWindStrideWidth;
                    int mWindStrideHeight;
                    int mPaddingWidth;
                    int mPaddingHeight;
                    double mScale;
                    double mFinalThreshold;
                    int mUseMeanShiftGrouping;
            };
        }
    }
}

#endif // PEDESTRIANDETECTION_HPP
