#ifndef AVCIRCLE_HPP
#define AVCIRCLE_HPP

#include <src/view/av/AVView.hpp>
#include <src/util/Observable.hpp>
#include <src/view/av/events/UpdateBenchmarkEvent.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class AVCircle
                   : public AVView

           {
               public:
                   AVCircle();

                   virtual void runCPUThread();
                   virtual void runGPUThread();

               private:
                   ///@todo This is for tracker algorithm
                   //cv::Rect2d mRoi; //Region of interest
                   cv::Mat mFrame;

           };
       }
    }
}

#endif // AVCIRCLE_HPP
