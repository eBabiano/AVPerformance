//File: BackgroundSubtractor.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/av/BackgroundSubtractor.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           BackgroundSubtractor::BackgroundSubtractor()
               : mLearningRate(-1.0)
           {
           }

           void BackgroundSubtractor::runCPUThread()
           {
               unsigned t1 = 0.0;
               unsigned t2 = 0.0;
               cv::Mat frame;
               cv::Mat frame_gray;
               cv::BackgroundSubtractorMOG2 mog2;

               while (mIsRunningThread)
               {
                   mMutex.lock();
                   getCapturedImage().copyTo(frame);
                   t1 = clock();
                   if (!frame.empty())
                   {
                       if (frame.channels() == 3 || frame.channels() == 4)
                       {
                           cv::cvtColor(frame, frame_gray, CV_BGR2GRAY);

                           mog2(frame_gray, frame_gray, mLearningRate);
                       }
                   }

                   frame_gray.copyTo(mImage);

                   t2 = clock();
                   updateBenchmark(t1, t2);
                   mMutex.unlock();
               }
           }

           void BackgroundSubtractor::runGPUThread()
           {

           }

           void BackgroundSubtractor::setLearningRate(double value)
           {
               mLearningRate = value;
           }

       }
    }
}
