#ifndef FACEDETECTION_HPP
#define FACEDETECTION_HPP

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class FaceDetection
                   : public AVView
           {
               public:
                   FaceDetection();

                   virtual void runCPUThread();
                   virtual void runGPUThread();

                   virtual void setScaleFactor(double factor);
                   virtual void setNeightbors(int neightbors);
                   virtual void setWidth(int width);
                   virtual void setHeight(int height);

               private:
                   double mScaleFactor;
                   int mNeightbors;
                   int mWidth;
                   int mHeight;

           };
       }
    }
}

#endif // FACEDETECTION_HPP
