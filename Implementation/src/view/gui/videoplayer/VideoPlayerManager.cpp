#include <src/view/gui/videoplayer/VideoPlayerManager.hpp>
#include <lib/flycapture2/include/FlyCapture2.h>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                VideoPlayerManager::VideoPlayerManager(const std::string& cameraType, const std::string& videoPath)
                    : mCameraType(cameraType)
                    , mIsStereo(false)
                {
                     if (cameraType == VideoPlayerTypes::FLY_CAPTURE)
                     {
                         FlyCapture2::BusManager busManager;
                         unsigned int numCameras;
                         FlyCapture2::Error error = busManager.GetNumOfCameras(&numCameras);
                         if (error != FlyCapture2::PGRERROR_OK)
                         {
                             std::cout << "FlyCapture2 camera error detected" << std::endl;
                         }
                         else
                         {
                             std::cout << "Number of cameras detected: " << numCameras << std::endl;

                             for (unsigned int i = 0; i < numCameras; i++)
                             {
                                 FlyCapture2::PGRGuid guid;
                                 error = busManager.GetCameraFromIndex(i, &guid);
                                 if (error != FlyCapture2::PGRERROR_OK)
                                 {
                                     std::cout << "Error detected for camera " << i << std::endl;
                                 }
                                 FlyCaptureVideoPlayer* videoPlayer = new FlyCaptureVideoPlayer(i);

                                 ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                 /// CONCATENATE STRING FOR EACH CAPTURE IN STEREO
                                 /// //////////////////////////////////////////////
                                 mVideoPlayersVector[VideoPlayerTypes::FLY_CAPTURE] = videoPlayer;
                                 videoPlayer->setType(VideoPlayerTypes::FLY_CAPTURE);
                                 videoPlayer->setGuid(guid);
                                 videoPlayer->init();
                             }
                         }

                     }
                     else if (cameraType == VideoPlayerTypes::WEB_CAM)
                     {
                         OpenCVVideoPlayer* videoPlayer = new OpenCVVideoPlayer(0, "WebCam", false, "");
                         mVideoPlayersVector[VideoPlayerTypes::WEB_CAM] = videoPlayer;
                         videoPlayer->setType(VideoPlayerTypes::WEB_CAM);
                         videoPlayer->init();
                     }
                     else if (cameraType == VideoPlayerTypes::VIDEO_MONO)
                     {
//                         std::string video1 = "../res/videos/sea.avi";
//                         std::string video2 = "../res/videos/video_0009_C0.raw";
                         OpenCVVideoPlayer* videoPlayer1 = new OpenCVVideoPlayer(0, "Video", true, videoPath);
                         mVideoPlayersVector[VideoPlayerTypes::VIDEO_MONO] = videoPlayer1;
                         videoPlayer1->setType(VideoPlayerTypes::VIDEO_MONO);
                         videoPlayer1->init();
                     }

                     ///@todo This is for develop the Stereo input video
//                     else if (stereoType == VideoPlayerTypes::VIDEO_STEREO)
//                     {
//                         mIsStereo = true;

//                         std::string video1 = "../res/videos/sea.avi";
//                         std::string video2 = "../res/videos/video_0009_C0.raw";
//                         OpenCVVideoPlayer* videoPlayer1 = new OpenCVVideoPlayer(0, "Video1", true, video2);
//                         mVideoPlayersVector[VideoPlayerTypes::VIDEO_1] = videoPlayer1;
//                         videoPlayer1->setType(VideoPlayerTypes::VIDEO_1);
//                         videoPlayer1->init();

//                         OpenCVVideoPlayer* videoPlayer2 = new OpenCVVideoPlayer(0, "Video2", true, "../res/videos/sea.avi");
//                         mVideoPlayersVector[VideoPlayerTypes::VIDEO_2] = videoPlayer2;
//                         videoPlayer2->setType(VideoPlayerTypes::VIDEO_2);
//                         videoPlayer2->init();
//                     }
                     else
                     {
                         std::cout << "Error in parameters: Specify input camera: [--fly], [--cam], [--video [path]]" << std::endl;
                         exit(-1);
                     }
                }

                std::vector<VideoPlayer*> VideoPlayerManager::getVideoPlayers()
                {
                    std::vector<VideoPlayer*> vector;
                    for (auto& videoPlayer : mVideoPlayersVector)
                    {
                        vector.push_back(videoPlayer.second);
                    }
                    return vector;
                }

                bool VideoPlayerManager::isStereo() const
                {
                    return mIsStereo;
                }

            }
        }
    }
}
