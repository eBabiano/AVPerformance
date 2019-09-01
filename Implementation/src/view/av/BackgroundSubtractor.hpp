#ifndef BACKGROUNDSUBTRACTOR_HPP
#define BACKGROUNDSUBTRACTOR_HPP

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class BackgroundSubtractor
                   : public AVView
           {
               public:
                   BackgroundSubtractor();

                   virtual void runCPUThread();
                   virtual void runGPUThread();

                   virtual void setLearningRate(double value);

               private:
                   double mLearningRate;
           };
       }
    }
}

#endif // BACKGROUNDSUBTRACTOR_HPP
