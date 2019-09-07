//File: AVView.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef AVVIEW_HPP
#define AVVIEW_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/gpu/gpu.hpp>

#include <boost/thread.hpp>
#include <mutex>
#include <ctime>

#include <src/view/av/events/UpdateBenchmarkEvent.hpp>
#include <src/util/Observable.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class AVView : public util::Observable<events::UpdateBenchmarkEvent>
           {
               public:
                   AVView();
                   ~AVView();

                   virtual void start();
                   virtual void stop();
                   virtual void runCPUThread() = 0;
                   virtual void runGPUThread() = 0;
                   virtual void onMouseEvent(int event, int x, int y);

                   cv::Mat getImage();
                   void setImage(cv::Mat &image);

                   cv::Mat getCapturedImage();
                   cv::Mat getCapturedImageStereo();
                   void setCapturedImage(cv::Mat &capturedImage);
                   void setCapturedImageStereo(cv::Mat &capturedImage);

                   void resetImage();

                   void activateGPU(bool activate);

                   void setTotalFrames(int value);

                   //BACKGROUND SUBSTRACTOR
                   virtual void setLearningRate(double value){assert(false);}

                   //FACE DETECTION
                   virtual void setScaleFactor(double factor){assert(false);}
                   virtual void setNeightbors(int neightbors){assert(false);}
                   virtual void setWidth(int width){assert(false);}
                   virtual void setHeight(int height){assert(false);}

                   //OPTICAL FLOW
                   virtual void setMaxCorners(int corners){assert(false);}
                   virtual void setMinDistance(double distance){assert(false);}
                   virtual void setBlockSize(int size){assert(false);}
                   virtual void activateHarrisDetector(bool activate){assert(false);}
                   virtual void setKFactor(double factor){assert(false);}

                   virtual void setTermCriteriaType(int type){assert(false);}
                   virtual void setMaxCount(int count){assert(false);}
                   virtual void setEpsilonFactor(double epsilon){assert(false);}

                   virtual void setWinSize(int width, int height){assert(false);}
                   virtual void setMaxLevels(int levels){assert(false);}
                   virtual void setFlags(int flag){assert(false);}
                   virtual void setThresholdEigenvalue(double value){assert(false);}

                   //PEDESTRIAN DETECTOR
                   virtual void setHitThreshold(double value){assert(false);}
                   virtual void setWindStrideWidth(int value){assert(false);}
                   virtual void setWindStrideHeight(int value){assert(false);}
                   virtual void setPaddingWidth(int value){assert(false);}
                   virtual void setPaddingHeight(int value){assert(false);}
                   virtual void setScale(double value){assert(false);}
                   virtual void setFinalThreshold(double value){assert(false);}
                   virtual void setUseMeanShiftGrouping(int value){assert(false);}

               protected:
                   void updateBenchmark(double initTime, double endTime);
                   boost::thread* mThread;
                   bool mIsRunningThread;
                   cv::Mat mImage;
                   bool mIsGPU;

                   int mTotalFrames;

                   std::mutex mMutex;

               private:
                   cv::Mat mCapturedImage;
                   cv::Mat mCapturedImageStereo;

                   using util::Observable<events::UpdateBenchmarkEvent>::notify;

           };
       }
    }
}

#endif // AVVIEW_HPP
