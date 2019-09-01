#include <src/view/gui/events/ModifyFaceDetectionEvent.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                ModifyFaceDetectionEvent::ModifyFaceDetectionEvent(const std::string &type, double scaleFactor, int neightbors,
                                                                   int width, int height)
                    : mProcessorType(type)
                    , mScaleFactor(scaleFactor)
                    , mNeightbors(neightbors)
                    , mWidth(width)
                    , mHeight(height)
                {
                }

                std::string ModifyFaceDetectionEvent::getProcessorType() const
                {
                    return mProcessorType;
                }
                double ModifyFaceDetectionEvent::getScaleFactor() const
                {
                    return mScaleFactor;
                }

                int ModifyFaceDetectionEvent::getNeightbors() const
                {
                    return mNeightbors;
                }

                int ModifyFaceDetectionEvent::getWidth() const
                {
                    return mWidth;
                }

                int ModifyFaceDetectionEvent::getHeight() const
                {
                    return mHeight;
                }

            }
        }
    }
}
