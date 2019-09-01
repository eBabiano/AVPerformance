//File: FaceDetection.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/FaceDetection.hpp>
#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            FaceDetection::FaceDetection()
                : mProcessorType(model::av::AVTypes::CPU)
                , mScaleFactor(1.1)
                , mNeightbors(1)
                , mWidth(30)
                , mHeight(30)
            {
            }

            std::string FaceDetection::getProcessorType() const
            {
                return mProcessorType;
            }

            void FaceDetection::setProcessorType(const std::string &type)
            {
                if (type != mProcessorType)
                {
                    mProcessorType = type;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::FACE_DETECTION));
                }
            }

            double FaceDetection::getScaleFactor() const
            {
                return mScaleFactor;
            }

            void FaceDetection::setScaleFactor(double factor)
            {
                if (factor != mScaleFactor)
                {
                    mScaleFactor = factor;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::FACE_DETECTION));
                }
            }

            int FaceDetection::getNeightbors() const
            {
                return mNeightbors;
            }

            void FaceDetection::setNeightbors(int neightbors)
            {
                if (neightbors != mNeightbors)
                {
                    mNeightbors = neightbors;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::FACE_DETECTION));
                }
            }

            int FaceDetection::getWidth() const
            {
                return mWidth;
            }

            void FaceDetection::setWidth(int width)
            {
                if (width != mWidth)
                {
                    mWidth = width;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::FACE_DETECTION));
                }
            }

            int FaceDetection::getHeight() const
            {
                return mHeight;
            }

            void FaceDetection::setHeight(int height)
            {
                if (height != mHeight)
                {
                    mHeight = height;
                    notify(events::AlgorithmParametersModified(model::av::AVTypes::FACE_DETECTION));
                }
            }
        }
    }
}
