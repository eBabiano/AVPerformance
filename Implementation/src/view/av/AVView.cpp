//File: AVView.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           AVView::AVView()
               : mIsRunningThread(false)
               , mIsGPU(false)
               , mTotalFrames(0)
           {
               mImage = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
               mCapturedImage = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
           }

           AVView::~AVView()
           {
               if (mIsRunningThread)
               {
                   mThread->join();
               }
           }

           void AVView::start()
           {
               mIsRunningThread = true;
               std::cout << "OpenCV version: " << CV_VERSION << std::endl;
               if (mIsGPU)
                   mThread = new boost::thread(boost::bind(&AVView::runGPUThread, this));
               else
                   mThread = new boost::thread(boost::bind(&AVView::runCPUThread, this));

           }

           void AVView::stop()
           {
               mIsRunningThread = false;
               resetImage();
               mThread->join();
           }

           void AVView::onMouseEvent(int event, int x, int y)
           {

           }

           cv::Mat AVView::getImage()
           {
               return mImage;
           }

           void AVView::setImage(cv::Mat &image)
           {
               mImage = image;
           }

           cv::Mat AVView::getCapturedImage()
           {
               return mCapturedImage;
           }

           cv::Mat AVView::getCapturedImageStereo()
           {
               return mCapturedImageStereo;
           }

           void AVView::setCapturedImage(cv::Mat &capturedImage)
           {
               if (!capturedImage.empty())
               {
                   mCapturedImage = capturedImage;
               }
           }

           void AVView::setCapturedImageStereo(cv::Mat &capturedImage)
           {
               if (!capturedImage.empty())
               {
                   mCapturedImageStereo = capturedImage;
               }
           }

           void AVView::resetImage()
           {
               mMutex.lock();
               mImage = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
               mMutex.unlock();
           }

           void AVView::activateGPU(bool activate)
           {
               mIsGPU = activate;
           }

           void AVView::updateBenchmark(double initTime, double endTime)
           {
               double time = (double(endTime - initTime) / CLOCKS_PER_SEC);

               double millisec = time * 1000;
               int fps = 1 / time;

               notify(events::UpdateBenchmarkEvent(millisec, fps, ""));
           }

           void AVView::setTotalFrames(int value)
           {
               mTotalFrames = value;
           }

       }
    }
}
