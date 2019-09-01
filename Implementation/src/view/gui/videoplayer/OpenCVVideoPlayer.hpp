#ifndef OPENCVVIDEOPLAYER_HPP
#define OPENCVVIDEOPLAYER_HPP

#include <opencv/highgui.h>
#include <src/view/gui/videoplayer/VideoPlayer.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class OpenCVVideoPlayer
                        : public VideoPlayer
                {
                    public:
                        OpenCVVideoPlayer(int captureInput, std::string nameOutput, bool isFromVideo,
                                          const std::string &videoFile);

                        virtual void init();
                        //virtual void run(cv::Mat newframe);
                        virtual void run(cv::Mat image, bool isShown);
                        virtual cv::Mat getCurrentFrame();

                    private:
                        std::string mWindowOutputName;
                        cv::VideoCapture mCapture;
                        cv::VideoWriter* mVideoWriter;
                        int mFrameNumber;
                        char mWaitKey;

                        bool mIsRunningThread;

                };
            }
        }
    }
}

#endif // OPENCVVIDEOPLAYER_HPP
