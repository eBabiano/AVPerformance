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
               unsigned t1, t2;
               double time;
               cv::Mat frame;
               cv::Mat frame_gray;
               cv::BackgroundSubtractorMOG2 mog2;

               while (mIsRunningThread)
               {
                   mMutex.lock();
                   getCapturedImage().copyTo(frame);
                   if (!frame.empty())
                   {
                       if (frame.channels() == 3 || frame.channels() == 4)
                       {
                           cv::cvtColor(frame, frame_gray, CV_BGR2GRAY);

                           t1 = clock();
                           mog2(frame_gray, frame_gray, mLearningRate);
                           t2 = clock();

                           frame_gray.copyTo(mImage);

                           updateBenchmark(t1, t2);
                       }
                   }
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
