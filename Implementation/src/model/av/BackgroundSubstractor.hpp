//File: BackgroundSubstractor.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef BACKGROUNDSUBSTRACTOR_HPP
#define BACKGROUNDSUBSTRACTOR_HPP

#include <src/model/av/AV.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            class BackgroundSubstractor
                    : public AV
            {
                public:
                    BackgroundSubstractor();

                    virtual double getLearningRate() const;
                    virtual void setLearningRate(double learningRate);

            private:
                    double mLearningRate;

            };
        }
    }
}

#endif // BACKGROUNDSUBSTRACTOR_HPP
