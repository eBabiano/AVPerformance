#include <src/view/gui/videoplayer/FlyCaptureVideoPlayer.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                FlyCaptureVideoPlayer::FlyCaptureVideoPlayer(int indexCamera)
                    : mIndexCamera(indexCamera)
                {
                    mCurrentFrame = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
                }

                FlyCaptureVideoPlayer::~FlyCaptureVideoPlayer()
                {
                    mCam->Disconnect();
                }

                void FlyCaptureVideoPlayer::init()
                {
                    initSingleCamera(mGuid);
                }

                int FlyCaptureVideoPlayer::initSingleCamera(FlyCapture2::PGRGuid guid)
                {
                    int ret = 0;
                    FlyCapture2::Error error;
                    mCam = new FlyCapture2::Camera();

                    // Connect to a camera
                    error = mCam->Connect(&guid);
                    if (error != FlyCapture2::PGRERROR_OK) {
                        std::cout << "FlyCapture2 camera error detected" << std::endl;
                        ret = -1;
                    }
                    else {
                        // Get the camera information
                        FlyCapture2::CameraInfo camInfo;
                        error = mCam->GetCameraInfo(&camInfo);
                        if (error != FlyCapture2::PGRERROR_OK) {
                            std::cout << "FlyCapture2 camera error detected" << std::endl;
                            ret = -1;
                        }
                        else {
                            ///printCameraInfo(&camInfo);
                            // Start capturing images
                            error = mCam->StartCapture();
                            if (error != FlyCapture2::PGRERROR_OK) {
                                std::cout << "FlyCapture2 camera error detected" << std::endl;
                                ret = -1;
                            }
                            else {
                                //read frames from camera and wait for user commands
                                ret = readFramesFromCamera();
                            }
                        }
                    }
                    return ret;
                }

                void FlyCaptureVideoPlayer::setGuid(const FlyCapture2::PGRGuid &value)
                {
                    mGuid = value;
                }

                cv::Mat FlyCaptureVideoPlayer::getCurrentFrame()
                {
                    return mCurrentFrame;
                }

                int FlyCaptureVideoPlayer::readFramesFromCamera()
                {
                    int ret = 0;
                    FlyCapture2::Error error;

                    mRawImage = new FlyCapture2::Image();

                    // Retrieve an image to get image size and allocate IplImage
                    error = mCam->RetrieveBuffer(mRawImage);
                    if (error != FlyCapture2::PGRERROR_OK) {
                        std::cout << "FlyCapture2 camera error detected" << std::endl;
                        ret = -1;
                    }
                    return ret;
                }

                void FlyCaptureVideoPlayer::run(cv::Mat image, bool isShown)
                {
                    FlyCapture2::Error error;

                    if (mCam->IsConnected())
                    {
                        // Retrieve an image
                        error = mCam->RetrieveBuffer(mRawImage);

                        if (error != FlyCapture2::PGRERROR_OK) {
                            std::cout << "FlyCapture2 camera error detected 1" << std::endl;
                        }
                        else {
                            // Create a converted image
                            FlyCapture2::Image convertedImage;
                            // Convert the raw image
                            error = mRawImage->Convert(FlyCapture2::PIXEL_FORMAT_BGR, &convertedImage);

                            if (error != FlyCapture2::PGRERROR_OK) {
                                std::cout << "FlyCapture2 camera error detected 2" << std::endl;
                            }
                            else {
                                unsigned int rowBytes = (double) convertedImage.GetReceivedDataSize() /
                                        (double) convertedImage.GetRows();
                                cv::Mat(convertedImage.GetRows(), convertedImage.GetCols(),
                                        CV_8UC3, convertedImage.GetData(), rowBytes).copyTo(mCurrentFrame);
                                if (mCurrentFrame.empty())
                                {
                                    std::cout << "Frame empty!!" << std::endl;
                                }

                                //cv::Mat imgReadColor;
                                //cv::cvtColor(mCurrentFrame, mCurrentFrame, CV_BGR2RGB);

                                if (isShown)
                                {
                                    cv::imshow("FlyCapture" + std::to_string(mIndexCamera), image);
                                }
                                mWaitKey = (char) cv::waitKey(1);
                            }
                        }
                    }

                }
            }
        }
    }
}
