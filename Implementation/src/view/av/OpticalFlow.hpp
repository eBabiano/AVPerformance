//File: OpticalFlow.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef OPTICALFLOW_HPP
#define OPTICALFLOW_HPP

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class OpticalFlow
                   : public AVView
           {
               public:
                   OpticalFlow();

                   virtual void runCPUThread();
                   virtual void runGPUThread();

                   //GOOD FEATURES TO TRACK
                   virtual void setMaxCorners(int corners);
                   virtual void setMinDistance(double distance);
                   virtual void setBlockSize(int size);
                   virtual void activateHarrisDetector(bool activate);
                   virtual void setKFactor(double factor);

                   //TERM CRITERIA
                   virtual void setTermCriteriaType(int type);
                   virtual void setMaxCount(int count);
                   virtual void setEpsilonFactor(double epsilon);

                   //OPTICAL FLOW
                   virtual void setWinSize(int width, int height);
                   virtual void setMaxLevels(int levels);
                   virtual void setFlags(int flag);
                   virtual void setThresholdEigenvalue(double value);

               private:
                   //GOOD FEATURES TO TRACK
                   int mCorners;
                   double mMinDistance;
                   int mSize;
                   bool mIsHarrisDetectorActivated;
                   double mKFactor;

                   //TERM CRITERIA
                   int mType;
                   int mMaxCount;
                   double mEpsilon;

                   //OPTICAL FLOW
                   int mSizeWidth;
                   int mSizeHeight;
                   int mMaxLevels;
                   int mFlags;
                   double mThreshold;
           };
       }
    }
}

#endif // OPTICALFLOW_HPP
