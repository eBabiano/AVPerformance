//File: PedestrianDetection.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/av/PedestrianDetection.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           PedestrianDetection::PedestrianDetection()
               : mHitThreshold(0)
               , mWindStrideWidth(0)
               , mWindStrideHeight(0)
               , mPaddingWidth(0)
               , mPaddingHeight(0)
               , mScale(0)
               , mFinalThreshold(0)
               , mUseMeanShiftGrouping(false)
           {
           }

           void PedestrianDetection::runCPUThread()
           {
               unsigned t1 = 0.0;
               unsigned t2 = 0.0;
               cv::Mat frame;
               cv::HOGDescriptor hog;
               hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

               while(mIsRunningThread)
               {
                   mMutex.lock();
                   getCapturedImage().copyTo(frame);
                   t1 = clock();

                   if (!frame.empty())
                   {
                       cv::cvtColor(frame, frame, CV_RGB2GRAY);

                       std::vector<cv::Rect> found, found_filtered;
                       hog.detectMultiScale(frame, found, mHitThreshold, cv::Size(mWindStrideWidth, mWindStrideHeight),
                                            cv::Size(mPaddingWidth, mPaddingHeight), mScale, mFinalThreshold, mUseMeanShiftGrouping);

                       size_t i, j;
                       for (i=0; i<found.size(); i++)
                       {
                           cv::Rect r = found[i];
                           for (j=0; j<found.size(); j++)
                               if (j!=i && (r & found[j])==r)
                                   break;
                           if (j==found.size())
                               found_filtered.push_back(r);
                       }

                       for (i=0; i<found_filtered.size(); i++)
                       {
                           cv::Rect r = found_filtered[i];
                           r.x += cvRound(r.width*0.1);
                           r.width = cvRound(r.width*0.8);
                           r.y += cvRound(r.height*0.06);
                           r.height = cvRound(r.height*0.9);
                           cv::rectangle(frame, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
                       }

                       frame.copyTo(mImage);

                       t2 = clock();
                       updateBenchmark(t1, t2);
                       mMutex.unlock();
                   }
               }

           }

           void PedestrianDetection::runGPUThread()
           {
               unsigned t1 = 0.0;
               unsigned t2 = 0.0;
               cv::Mat frame;
               cv::gpu::GpuMat grayScaleFrame, capturedFrameGPU;
               cv::gpu::HOGDescriptor hog;
               hog.setSVMDetector(cv::gpu::HOGDescriptor::getDefaultPeopleDetector());

               while(mIsRunningThread)
               {
                   mMutex.lock();
                   getCapturedImage().copyTo(frame);
                   t1 = clock();
                   capturedFrameGPU.upload(frame);

                   if (!capturedFrameGPU.empty())
                   {
                       cv::gpu::cvtColor(capturedFrameGPU, grayScaleFrame, CV_RGB2GRAY);

                       std::vector<cv::Rect> found, found_filtered;
                       hog.detectMultiScale(grayScaleFrame, found, mHitThreshold, cv::Size(0, 0),
                                            cv::Size(0, 0), mScale);

                       size_t i, j;
                       for (i=0; i<found.size(); i++)
                       {
                           cv::Rect r = found[i];
                           for (j=0; j<found.size(); j++)
                               if (j!=i && (r & found[j])==r)
                                   break;
                           if (j==found.size())
                               found_filtered.push_back(r);
                       }

                       for (i=0; i<found_filtered.size(); i++)
                       {
                           cv::Rect r = found_filtered[i];
                           r.x += cvRound(r.width*0.1);
                           r.width = cvRound(r.width*0.8);
                           r.y += cvRound(r.height*0.06);
                           r.height = cvRound(r.height*0.9);
                           cv::rectangle(frame, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
                       }

                       frame.copyTo(mImage);

                       t2 = clock();
                       updateBenchmark(t1, t2);
                       mMutex.unlock();
                   }
               }
           }

           void PedestrianDetection::setHitThreshold(double value)
           {
               mHitThreshold = value;
           }

           void PedestrianDetection::setWindStrideWidth(int value)
           {
               mWindStrideWidth = value;
           }

           void PedestrianDetection::setWindStrideHeight(int value)
           {
               mWindStrideHeight = value;
           }

           void PedestrianDetection::setPaddingWidth(int value)
           {
               mPaddingWidth = value;
           }

           void PedestrianDetection::setPaddingHeight(int value)
           {
               mPaddingHeight = value;
           }

           void PedestrianDetection::setScale(double value)
           {
               mScale = value;
           }

           void PedestrianDetection::setFinalThreshold(double value)
           {
               mFinalThreshold = value;
           }

           void PedestrianDetection::setUseMeanShiftGrouping(int value)
           {
               mUseMeanShiftGrouping = value;
           }
       }
    }
}
