#ifndef UPDATEBENCHMARKEVENT_HPP
#define UPDATEBENCHMARKEVENT_HPP

#include <string>

namespace src
{
    namespace view
    {
       namespace av
       {
           namespace events
           {
               class UpdateBenchmarkEvent
               {
                   public:
                       UpdateBenchmarkEvent(double timeProcMillis, int fps, const std::string &device);

                       double getTimeProcMillis() const;
                       std::string getDevice() const;
                       int getFPS() const;

               private:
                       double mTimeProcMillis;
                       int mFPS;
                       std::string mDevice;
               };
           }
       }
    }
}

#endif // UPDATEBENCHMARKEVENT_HPP
