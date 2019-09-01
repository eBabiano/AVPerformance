#include <src/view/gui/events/ModifyPedestrianDetectorEvent.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                ModifyPedestrianDetectorEvent::ModifyPedestrianDetectorEvent(const std::string& processorType, double hitThreshold, int widthStride,
                                                                             int heightStride, int widthPadding, int heightPadding, double scale,
                                                                             double finalThreshold, int useMeanShift)
                    : mProcessorType(processorType)
                    , mHitThreshold(hitThreshold)
                    , mWindStrideWidth(widthStride)
                    , mWindStrideHeight(heightStride)
                    , mPaddingWidth(widthPadding)
                    , mPaddingHeight(heightPadding)
                    , mScale(scale)
                    , mFinalThreshold(finalThreshold)
                    , mUseMeanShiftGrouping(useMeanShift)
                {
                }

                std::string ModifyPedestrianDetectorEvent::getProcessorType() const
                {
                    return mProcessorType;
                }
                double ModifyPedestrianDetectorEvent::getHitThreshold() const
                {
                    return mHitThreshold;
                }

                int ModifyPedestrianDetectorEvent::getWindStrideWidth() const
                {
                    return mWindStrideWidth;
                }

                int ModifyPedestrianDetectorEvent::getWindStrideHeight() const
                {
                    return mWindStrideHeight;
                }

                int ModifyPedestrianDetectorEvent::getPaddingWidth() const
                {
                    return mPaddingWidth;
                }

                int ModifyPedestrianDetectorEvent::getPaddingHeight() const
                {
                    return mPaddingHeight;
                }

                double ModifyPedestrianDetectorEvent::getScale() const
                {
                    return mScale;
                }

                double ModifyPedestrianDetectorEvent::getFinalThreshold() const
                {
                    return mFinalThreshold;
                }

                int ModifyPedestrianDetectorEvent::getUseMeanShiftGrouping() const
                {
                    return mUseMeanShiftGrouping;
                }

            }
        }
    }
}
