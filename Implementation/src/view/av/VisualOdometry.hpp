#ifndef VISUALODOMETRY_HPP
#define VISUALODOMETRY_HPP

#include <src/view/av/AVView.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class VisualOdometry
                   : public AVView
           {
               public:
                   VisualOdometry();

                   virtual void runCPUThread();
                   virtual void runGPUThread();
           };
       }
    }
}

#endif // VISUALODOMETRY_HPP
