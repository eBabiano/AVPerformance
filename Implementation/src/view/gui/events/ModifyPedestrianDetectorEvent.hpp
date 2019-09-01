#ifndef MODIFYPEDESTRIANDETECTOREVENT_HPP
#define MODIFYPEDESTRIANDETECTOREVENT_HPP

#include <string>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                class ModifyPedestrianDetectorEvent
                {
                    public:
                        ModifyPedestrianDetectorEvent(const std::string& processorType, double hitThreshold, int widthStride,
                                                      int heightStride, int widthPadding, int heightPadding, double scale,
                                                      double finalThreshold, int useMeanShift);

                        std::string getProcessorType() const;

                        double getHitThreshold() const;
                        int getWindStrideWidth() const;
                        int getWindStrideHeight() const;
                        int getPaddingWidth() const;
                        int getPaddingHeight() const;
                        double getScale() const;
                        double getFinalThreshold() const;
                        int getUseMeanShiftGrouping() const;

                private:
                        std::string mProcessorType;

                        double mHitThreshold;
                        int mWindStrideWidth;
                        int mWindStrideHeight;
                        int mPaddingWidth;
                        int mPaddingHeight;
                        double mScale;
                        double mFinalThreshold;
                        int mUseMeanShiftGrouping;
                };
            }
        }
    }
}

#endif // MODIFYPEDESTRIANDETECTOREVENT_HPP
