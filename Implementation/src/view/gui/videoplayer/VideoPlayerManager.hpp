#ifndef VideoPlayerManager_HPP
#define VideoPlayerManager_HPP

#include <src/view/gui/videoplayer/FlyCaptureVideoPlayer.hpp>
#include <src/view/gui/videoplayer/OpenCVVideoPlayer.hpp>
#include <src/view/gui/videoplayer/VideoPlayerTypes.hpp>

#include <string>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class VideoPlayerManager
                {
                    public:
                        VideoPlayerManager(const std::string &cameraType, const std::string& stereoType);

                        std::vector<VideoPlayer *> getVideoPlayers();
                        VideoPlayer* getVideoPlayerMono();

                        bool isStereo() const;

                private:
                        std::map<std::string, VideoPlayer*> mVideoPlayersVector;
                        std::string mCameraType;
                        bool mIsStereo;

                };
            }
        }
    }
}

#endif // VideoPlayerManager_HPP
