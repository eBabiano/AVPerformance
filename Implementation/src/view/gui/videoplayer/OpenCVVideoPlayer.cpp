#include <src/view/gui/videoplayer/OpenCVVideoPlayer.hpp>
#include <iostream>

namespace src
{
    namespace view
    {
        namespace gui
        {

            namespace videoplayer
            {
                OpenCVVideoPlayer::OpenCVVideoPlayer(int captureInput, std::string nameOutput,
                                                     bool isFromVideo, const std::string& videoFile)
                    : mWindowOutputName(nameOutput)
                    , mIsRunningThread(true)
                    , mFrameNumber(0)
                    , isInit(true)
                    , mCaptureInput(captureInput)
                    , mIsFromVideo(isFromVideo)
                    , mVideoFile(videoFile)
                {
                    mCurrentFrame = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);

                    mCapture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
                    mCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);


                }

                void OpenCVVideoPlayer::init()
                {
                    if (mIsFromVideo)
                    {
                        mCapture.open(mVideoFile);
                    }
                    else
                    {
                        mCapture.open(mCaptureInput);
                    }

                    if (!mCapture.isOpened())
                    {
                        std::cout << "Could not open" << std::endl;
                    }

                    cv::Size sizeRef = cv::Size((int) mCapture.get(CV_CAP_PROP_FRAME_WIDTH),
                                                (int) mCapture.get(CV_CAP_PROP_FRAME_HEIGHT));

                    cv::namedWindow(mWindowOutputName, CV_WINDOW_AUTOSIZE);
                    cv::moveWindow(mWindowOutputName, 1000, 0);

                    std::cout << "Width: " << sizeRef.width << ", Height: " << sizeRef.height << std::endl;

                    int frameWidth = mCapture.get(CV_CAP_PROP_FRAME_WIDTH);
                    int frameHeight = mCapture.get(CV_CAP_PROP_FRAME_HEIGHT);

                    mVideoWriter = new cv::VideoWriter("../res/Video.avi", CV_FOURCC('M','J','P','G'), 10,
                                                       cv::Size(frameWidth, frameHeight));
                }

                void OpenCVVideoPlayer::run(cv::Mat image, bool isShown)
                {
                    if (isInit)
                        init();
                    isInit = false;
                    mCapture >> mCurrentFrame;

                    if (mCurrentFrame.empty())
                    {
                        std::cout << "Frame empty!!" << std::endl;
                    }

                    ///@brief Enable this for activate the record
                    //mVideoWriter->write(mCurrentFrame);
                    //std::string fileName = "../res/images/image" + std::to_string(mFrameNumber) + ".png";
                    //cv::imwrite(fileName, mCurrentFrame);
                    //mFrameNumber++;

                    if (isShown)
                    {
                        cv::imshow(mWindowOutputName, image);
                    }
                    mWaitKey = (char) cv::waitKey(1);
                }

                void OpenCVVideoPlayer::stop()
                {
                    mCapture.release();
                    isInit = true;
                }

                cv::Mat OpenCVVideoPlayer::getCurrentFrame()
                {
                    return mCurrentFrame;
                }

            }
        }
    }
}
