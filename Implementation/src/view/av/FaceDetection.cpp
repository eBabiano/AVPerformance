//File: FaceDetection.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/av/FaceDetection.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           FaceDetection::FaceDetection()
               : mScaleFactor(0.0)
               , mNeightbors(0)
               , mWidth(0)
               , mHeight(0)
           {
           }

           void FaceDetection::runCPUThread()
           {
               cv::CascadeClassifier face_cascade;
               cv::Mat grayScaleFrame, capturedFrame;
               unsigned t1, t2;
               double time;
               //create a vector array to store the face found
               std::vector<cv::Rect> faces;

               face_cascade.load("../res/cpu/haarcascade_frontalface_alt.xml");

               while (mIsRunningThread)
               {
                   mMutex.lock();

                   getCapturedImage().copyTo(capturedFrame);
                   int flags = CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE;

                   //convert captured image to gray scale and equalize
                   if (capturedFrame.channels() == 3 || capturedFrame.channels() == 4)
                   {
                       cv::cvtColor(capturedFrame, grayScaleFrame, CV_RGB2GRAY);
                       cv::equalizeHist(grayScaleFrame, grayScaleFrame);

                       t1 = clock();
                       //find faces and store them in the vector array
                       face_cascade.detectMultiScale(grayScaleFrame, faces, mScaleFactor, mNeightbors,
                                                     flags, cv::Size(mWidth, mHeight));
                       t2 = clock();
                   }

                   //draw a rectangle for all found faces in the vector array on the original image
                   for (int i = 0; i < faces.size(); i++)
                   {
                       cv::Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
                       cv::Point pt2(faces[i].x, faces[i].y);

                       cv::rectangle(capturedFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
                   }

                   capturedFrame.copyTo(mImage);

                   updateBenchmark(t1, t2);
                   mMutex.unlock();
               }
           }


           void FaceDetection::runGPUThread()
           {
               cv::gpu::CascadeClassifier_GPU face_cascade;
               cv::gpu::GpuMat grayScaleFrame, capturedFrameGPU, bufferFrame;
               cv::Mat cpuFrame, capturedFrameCPU;
               unsigned t1, t2;
               double time;
               int numFaces;

               const std::string& file = "../res/gpu/haarcascade_frontalface_alt.xml";

               face_cascade.load(file);

               while (mIsRunningThread)
               {
                   mMutex.lock();

                   getCapturedImage().copyTo(capturedFrameCPU);
                   capturedFrameGPU.upload(getCapturedImage());

                   //convert captured image to gray scale and equalize
                   if (capturedFrameCPU.channels() == 3 || capturedFrameCPU.channels() == 4)
                   {
                       cv::gpu::cvtColor(capturedFrameGPU, grayScaleFrame, CV_RGB2GRAY);
                       cv::gpu::equalizeHist(grayScaleFrame, grayScaleFrame);

                       t1 = clock();
                       //find faces and store them in the vector array
                       numFaces = face_cascade.detectMultiScale(grayScaleFrame, bufferFrame, mScaleFactor, mNeightbors, cv::Size(mWidth, mHeight));
                       t2 = clock();
                   }


                   bufferFrame.colRange(0, numFaces).download(cpuFrame);

                   cv::Rect* faces = cpuFrame.ptr<cv::Rect>();
                   std::vector<cv::Rect> faceVector;

                   //draw a rectangle for all found faces in the vector array on the original image
                   for (int i = 0; i < numFaces; i++)
                   {
                       faceVector.push_back(faces[i]);
                   }

                   for (int i = 0; i < faceVector.size(); i++)
                   {
                       cv::Point pt1(faceVector[i].x + faceVector[i].width, faceVector[i].y + faceVector[i].height);
                       cv::Point pt2(faceVector[i].x, faceVector[i].y);

                       cv::rectangle(capturedFrameCPU, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
                   }

                   capturedFrameCPU.copyTo(mImage);

                   updateBenchmark(t1, t2);
                   mMutex.unlock();
               }
           }

           void FaceDetection::setScaleFactor(double factor)
           {
               mScaleFactor = factor;
           }

           void FaceDetection::setNeightbors(int neightbors)
           {
               mNeightbors = neightbors;
           }

           void FaceDetection::setWidth(int width)
           {
               mWidth = width;
           }

           void FaceDetection::setHeight(int height)
           {
               mHeight = height;
           }
       }
    }
}
