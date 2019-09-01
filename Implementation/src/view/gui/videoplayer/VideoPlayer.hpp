#ifndef VIDEOPLAYER_HPP
#define VIDEOPLAYER_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace videoplayer
            {
                class VideoPlayer
                {
                    public:
                        VideoPlayer();

                        virtual void init() = 0;
                        //virtual void run(cv::Mat newframe) = 0;
                        virtual void run(cv::Mat image, bool isShown) = 0;

                        virtual cv::Mat getCurrentFrame(){}

                        std::string getType() const;
                        void setType(const std::string &value);

                protected:
                        cv::Mat mCurrentFrame;
                        std::string mType;

                };
            }
        }
    }
}

#endif // VIDEOPLAYER_HPP
