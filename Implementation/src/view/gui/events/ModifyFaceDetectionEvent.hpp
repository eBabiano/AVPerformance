#ifndef MODIFYFACEDETECTIONEVENT_HPP
#define MODIFYFACEDETECTIONEVENT_HPP

#include <string>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                class ModifyFaceDetectionEvent
                {
                    public:
                        ModifyFaceDetectionEvent(const std::string& type, double scaleFactor, int neightbors,
                                                 int width, int height);

                        std::string getProcessorType() const;

                        double getScaleFactor() const;
                        int getNeightbors() const;
                        int getWidth() const;
                        int getHeight() const;

                    private:
                        std::string mProcessorType;
                        double mScaleFactor;
                        int mNeightbors;
                        int mWidth;
                        int mHeight;
                };
            }
        }
    }
}

#endif // MODIFYFACEDETECTIONEVENT_HPP
