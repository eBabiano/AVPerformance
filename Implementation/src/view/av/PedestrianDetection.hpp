#ifndef PEDESTRIANDETECTION_HPP
#define PEDESTRIANDETECTION_HPP

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class PedestrianDetection
                   : public AVView
           {
               public:
                   PedestrianDetection();

                   virtual void runCPUThread();
                   virtual void runGPUThread();

                   virtual void setHitThreshold(double value);
                   virtual void setWindStrideWidth(int value);
                   virtual void setWindStrideHeight(int value);
                   virtual void setPaddingWidth(int value);
                   virtual void setPaddingHeight(int value);
                   virtual void setScale(double value);
                   virtual void setFinalThreshold(double value);
                   virtual void setUseMeanShiftGrouping(int value);

           private:
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
