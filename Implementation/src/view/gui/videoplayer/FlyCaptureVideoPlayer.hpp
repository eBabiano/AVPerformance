#ifndef FLYCAPTUREVIDEOPLAYER_HPP
#define FLYCAPTUREVIDEOPLAYER_HPP

#include <lib/flycapture2/include/FlyCapture2.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <src/view/gui/videoplayer/VideoPlayer.hpp>

#include <boost/thread.hpp>
#include <mutex>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class FlyCaptureVideoPlayer
                        : public VideoPlayer
                {
                    public:
                        FlyCaptureVideoPlayer(int indexCamera);
                        ~FlyCaptureVideoPlayer();

                        virtual void init();
                        virtual void run(cv::Mat image, bool isShown);
                        virtual void stop();

                        void setGuid(const FlyCapture2::PGRGuid &value);
                        virtual cv::Mat getCurrentFrame();

                private:
                        int readFramesFromCamera();
                        int initSingleCamera(FlyCapture2::PGRGuid guid);

                        FlyCapture2::Camera* mCam;
                        FlyCapture2::Image* mRawImage;
                        unsigned int mIndexCamera;
                        char mWaitKey;
                        FlyCapture2::PGRGuid mGuid;

                        std::mutex mMutex;
                        cv::Mat mCurrentFrame;

                };
            }
        }
    }
}

#endif // FLYCAPTUREVIDEOPLAYER_HPP
