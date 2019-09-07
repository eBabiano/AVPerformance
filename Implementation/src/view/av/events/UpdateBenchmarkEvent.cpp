//File: UpdateBenchmarkEvent.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/av/events/UpdateBenchmarkEvent.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           namespace events
           {
               UpdateBenchmarkEvent::UpdateBenchmarkEvent(double timeProcMillis, int fps, const std::string& device)
                   : mTimeProcMillis(timeProcMillis)
                   , mDevice(device)
                   , mFPS(fps)
               {
               }

               double UpdateBenchmarkEvent::getTimeProcMillis() const
               {
                   return mTimeProcMillis;
               }

               std::string UpdateBenchmarkEvent::getDevice() const
               {
                   return mDevice;
               }

               int UpdateBenchmarkEvent::getFPS() const
               {
                   return mFPS;
               }
               
           }
       }
    }
}
