#include <src/view/av/AVCircle.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           AVCircle::AVCircle()
           {

           }

           void AVCircle::runCPUThread()
           {
               cv::Mat image;
               unsigned t1, t2;
               double time;

                while(mIsRunningThread)
                {
                    std::cout << "Running AVCircle thread" << std::endl;
                    image = getImage();
                    t1 = clock();
                    cv::circle(image, cv::Point(320, 240), 32.0, cv::Scalar(0, 255, 0), 2, 8);
                    t2 = clock();

                    image.copyTo(mImage);

                    updateBenchmark(t1, t2);
                    sleep(1);
                }

           }

           void AVCircle::runGPUThread()
           {

           }
       }
    }
}
