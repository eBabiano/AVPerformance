//File: PedestrianDetection.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/PedestrianDetection.hpp>
#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            PedestrianDetection::PedestrianDetection()
                :mProcessorType(AVTypes::CPU)
                , mHitThreshold(0)
                , mWindStrideWidth(8)
                , mWindStrideHeight(8)
                , mPaddingWidth(0)
                , mPaddingHeight(0)
                , mScale(1.05)
                , mFinalThreshold(2)
                , mUseMeanShiftGrouping(false)
            {
            }

            std::string PedestrianDetection::getProcessorType() const
            {
                return mProcessorType;
            }

            void PedestrianDetection::setProcessorType(const std::string &type)
            {
                mProcessorType = type;
                notify(events::AlgorithmParametersModified(model::av::AVTypes::PEDESTRIAN_DETECTOR));
            }

            int PedestrianDetection::getWindStrideWidth() const
            {
                return mWindStrideWidth;
            }

            int PedestrianDetection::getWindStrideHeight() const
            {
                return mWindStrideHeight;
            }

            void PedestrianDetection::setWindStride(int width, int height)
            {
                bool change = false;
                if (height != mWindStrideHeight)
                {
                    mWindStrideHeight = height;
                    change = true;
                }
                if (width != mWindStrideWidth)
                {
                    mWindStrideWidth = width;
                    change = true;
                }
                if (change)
                {
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::PEDESTRIAN_DETECTOR));
                }
            }

            int PedestrianDetection::getPaddingWidth() const
            {
                return mPaddingWidth;
            }

            int PedestrianDetection::getPaddingHeight() const
            {
                return mPaddingHeight;
            }

            void PedestrianDetection::setPadding(int width, int height)
            {
                bool change = false;
                if (height != mPaddingHeight)
                {
                    mPaddingHeight = height;
                    change = true;
                }
                if (width != mPaddingWidth)
                {
                    mPaddingWidth = width;
                    change = true;
                }
                if (change)
                {
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::PEDESTRIAN_DETECTOR));
                }
            }

            double PedestrianDetection::getScale() const
            {
                return mScale;
            }

            void PedestrianDetection::setScale(double value)
            {
                if (value != mScale)
                {
                    mScale = value;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::PEDESTRIAN_DETECTOR));
                }
            }

            double PedestrianDetection::getFinalThreshold() const
            {
                return mFinalThreshold;
            }

            void PedestrianDetection::setFinalThreshold(double value)
            {
                if (value != mFinalThreshold)
                {
                    mFinalThreshold = value;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::PEDESTRIAN_DETECTOR));
                }
            }

            int PedestrianDetection::getUseMeanShiftGrouping() const
            {
                return mUseMeanShiftGrouping;
            }

            void PedestrianDetection::setUseMeanShiftGrouping(int value)
            {
                if (value != mUseMeanShiftGrouping)
                {
                    mUseMeanShiftGrouping = value;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::PEDESTRIAN_DETECTOR));
                }
            }

            double PedestrianDetection::getHitThreshold() const
            {
                return mHitThreshold;
            }

            void PedestrianDetection::setHitThreshold(double value)
            {
                if (value != mHitThreshold)
                {
                    mHitThreshold = value;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::PEDESTRIAN_DETECTOR));
                }
            }

        }
    }
}
