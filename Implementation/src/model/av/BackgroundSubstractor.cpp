//File: BackgroundSubstractor.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/BackgroundSubstractor.hpp>
#include <iostream>
#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            BackgroundSubstractor::BackgroundSubstractor()
                : mLearningRate(0.0)
            {
            }

            double BackgroundSubstractor::getLearningRate() const
            {
                return mLearningRate;
            }

            void BackgroundSubstractor::setLearningRate(double learningRate)
            {
                mLearningRate = learningRate;
                notify(events::AlgorithmParametersModified(model::av::AVTypes::BACKGROUND_SUBTRACTOR));
            }
        }
    }
}
