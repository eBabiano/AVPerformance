//File: OpticalFlow.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/av/OpticalFlow.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           OpticalFlow::OpticalFlow()
               : mCorners(0)
               , mMinDistance(0.0)
               , mSize(0)
               , mIsHarrisDetectorActivated(false)
               , mKFactor(0.0)
           {
           }

           void OpticalFlow::runCPUThread()
           {
               unsigned t1 = 0.0;
               unsigned t2 = 0.0;

               cv::TermCriteria termcrit(mType, mMaxCount, mEpsilon);
               cv::Size subPixWinSize(10,10), winSize(mSizeWidth, mSizeHeight);

               bool needToInit = true;

               cv::Mat gray, prevGray, image;
               std::vector<cv::Point2f> points[2];

               while(mIsRunningThread)
               {
                   mMutex.lock();

                   getCapturedImage().copyTo(image);
                   t1 = clock();
                   if( !image.empty() )
                   {
                       cv::cvtColor(image, gray, CV_BGR2GRAY);

                       if( needToInit )
                       {
                           // automatic initialization
                           cv::goodFeaturesToTrack(gray, points[1], mCorners, 0.01,
                                   mMinDistance, cv::Mat(), mSize, mIsHarrisDetectorActivated, mKFactor);
                           if (points[1].size() > 0)
                           {
                               cv::cornerSubPix(gray, points[1], subPixWinSize, cv::Size(-1,-1), termcrit);
                               needToInit = false;
                           }
                       }
                       else if( !points[0].empty() )
                       {
                           std::vector<uchar> status;
                           std::vector<float> err;
                           if(prevGray.empty())
                               gray.copyTo(prevGray);
                           cv::calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,
                                   mMaxLevels, termcrit, mFlags, mThreshold);
                           size_t i, k;
                           for( i = k = 0; i < points[1].size(); i++ )
                           {
                               if( !status[i] )
                                   continue;

                               points[1][k++] = points[1][i];
                               cv::circle( image, points[1][i], 3, cv::Scalar(0,255,0), -1, 8);
                           }
                           points[1].resize(k);
                       }

                       image.copyTo(mImage);

                       t2 = clock();
                       updateBenchmark(t1, t2);

                       std::swap(points[1], points[0]);
                       cv::swap(prevGray, gray);
                   }
                   mMutex.unlock();

               }
           }

          void OpticalFlow::runGPUThread()
           {
//              unsigned t1 = 0.0;
//              unsigned t2 = 0.0;

//              cv::TermCriteria termcrit(cv::TermCriteria::COUNT|cv::TermCriteria::EPS,20,0.03);
//              cv::Size subPixWinSize(10,10), winSize(31,31);
//              cv::gpu::GoodFeaturesToTrackDetector_GPU goodFeaturesToTrack;

//              const int MAX_COUNT = 500;
//              bool needToInit = true;

//              cv::Mat frame, gray, prevGray, image, corners;
//              cv::gpu::GpuMat gpu_gray, gpu_prevGray, gpu_image, gpu_corners;
//              cv::gpu::GpuMat velx, vely, buffer;
//              std::vector<cv::Point2f> points[2];

//              while(mIsRunningThread)
//              {
//                  mMutex.lock();

//                  getCapturedImage().copyTo(frame);
//                  gpu_image.upload(frame);
//                  if( !gpu_image.empty() )
//                  {
//                      cv::gpu::cvtColor(gpu_image, gpu_gray, CV_BGR2GRAY);

//                      if( needToInit )
//                      {
//                          // automatic initialization
//                          goodFeaturesToTrack = cv::gpu::GoodFeaturesToTrackDetector_GPU(
//                                      mCorners, 0.01, mMinDistance, mSize, mIsHarrisDetectorActivated, mKFactor);
//                          goodFeaturesToTrack.operator ()(gpu_gray, gpu_corners, cv::gpu::GpuMat());
//                      }
//                      else if( !gpu_corners.empty() )
//                      {
//                          std::vector<uchar> status;
//                          std::vector<float> err;
//                          if(gpu_gray.empty())
//                              gpu_gray.copyTo(gpu_prevGray);
//                          t1 = clock();
//                          cv::gpu::calcOpticalFlowBM(
//                                      gpu_prevGray, gpu_gray, cv::Size(30,30), cv::Size(30,30), cv::Size(30,30), false,
//                                      velx, vely, buffer);
//                          t2 = clock();
//                          size_t i, k;
//                          for( i = k = 0; i < points[1].size(); i++ )
//                          {
//                              if( !status[i] )
//                                  continue;

//                              points[1][k++] = points[1][i];
//                              cv::circle( image, points[1][i], 3, cv::Scalar(0,255,0), -1, 8);
//                          }
//                          points[1].resize(k);
//                      }


//                      needToInit = false;
//                      image.copyTo(mImage);

//                      updateBenchmark(t1, t2);

//                      std::swap(points[1], points[0]);
//                      cv::gpu::swap(gpu_prevGray, gpu_gray);
//                  }
//                  mMutex.unlock();

//              }
          }

          void OpticalFlow::setMaxCorners(int corners)
          {
              mCorners = corners;
          }

          void OpticalFlow::setMinDistance(double distance)
          {
              mMinDistance = distance;
          }

          void OpticalFlow::setBlockSize(int size)
          {
              mSize = size;
          }

          void OpticalFlow::activateHarrisDetector(bool activate)
          {
              mIsHarrisDetectorActivated = activate;
          }

          void OpticalFlow::setKFactor(double factor)
          {
              mKFactor = factor;
          }

          void OpticalFlow::setTermCriteriaType(int type)
          {
              mType = type;
          }

          void OpticalFlow::setMaxCount(int count)
          {
              mMaxCount = count;
          }

          void OpticalFlow::setEpsilonFactor(double epsilon)
          {
              mEpsilon = epsilon;
          }

          void OpticalFlow::setWinSize(int width, int height)
          {
              mSizeWidth = width;
              mSizeHeight = height;
          }

          void OpticalFlow::setMaxLevels(int levels)
          {
              mMaxLevels = levels;
          }

          void OpticalFlow::setFlags(int flag)
          {
              mFlags = flag;
          }

          void OpticalFlow::setThresholdEigenvalue(double value)
          {
              mThreshold = value;
          }
       }
    }
}
