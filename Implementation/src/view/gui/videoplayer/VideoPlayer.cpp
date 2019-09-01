#include <src/view/gui/videoplayer/VideoPlayer.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                VideoPlayer::VideoPlayer()
                {
                }
                std::string VideoPlayer::getType() const
                {
                    return mType;
                }

                void VideoPlayer::setType(const std::string &value)
                {
                    mType = value;
                }


                /*cv::Mat VideoPlayer::getCurrentFrame()
                {
                    if (mCurrentFrame.empty())
                    {
                        std::cout << "Emptyyyyy" << std::endl;
                    }
                    return mCurrentFrame;
                }*/
            }
        }
    }
}
