//File: Benchmark.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/Benchmark.hpp>
#include <src/model/av/AVTypes.hpp>

#include <iostream>
namespace src
{
    namespace model
    {
        Benchmark::Benchmark()
            : mProcessingTimeMillisec(0.0)
            , mFramesPerSec(0)
            , mIsGPU(false)
            , mCurrentFrames(0)
        {
            mProcessingTimeMillisecVector.push_back(0.0);
            mFramesPerSecondsVector.push_back(0.0);
        }
        double Benchmark::getProcessingTimeMillisec() const
        {
            return mProcessingTimeMillisec;
        }

        void Benchmark::setProcessingTimeMillisec(double value)
        {
            if (value >= 0.0)
            {
                mProcessingTimeMillisecVector.push_back(mProcessingTimeMillisec);
                mProcessingTimeMillisec = value;
            }
        }
        int Benchmark::getFramesPerSec() const
        {
            return mFramesPerSec;
        }

        void Benchmark::setFramesPerSec(int value)
        {
            if (value >= 0)
            {
                mFramesPerSecondsVector.push_back(value);
                mFramesPerSec = value;
            }
        }

        int Benchmark::getFrames() const
        {
            return mFrames;
        }

        void Benchmark::setFrames(int value)
        {
            mFrames = value;
        }

        double Benchmark::getWeightedAverageProcessingTimeMillisec()
        {
            double acumValue = 0.0;
            int size = mProcessingTimeMillisecVector.size();
            for (int i = 0; i < size; i++)
            {
                acumValue = mProcessingTimeMillisecVector.at(i) + acumValue;
                if (acumValue < 0)
                {
                    break;
                }
            }

            mProcessingTimeMillisecVector.clear();
            return acumValue / size;
        }

        int Benchmark::getWeightedAverageFramesPerSeconds()
        {
            int acumValue = 0;
            int size = mFramesPerSecondsVector.size();
            for (int i = 0; i < size; i++)
            {
                acumValue = mFramesPerSecondsVector.at(i) + acumValue;
            }

            mFramesPerSecondsVector.clear();
            if (size > 0)
                return acumValue / size;
            else
                return 0;
        }

        bool Benchmark::getIsPlaying() const
        {
            return mIsPlaying;
        }

        void Benchmark::setIsPlaying(bool value)
        {
            mIsPlaying = value;
        }
        bool Benchmark::getIsGPU() const
        {
            return mIsGPU;
        }

        void Benchmark::setIsGPU(bool value)
        {
            mIsGPU = value;
        }

        void Benchmark::updateCurrentFrames()
        {
            mCurrentFrames++;
        }

        void Benchmark::clearAll()
        {
            mCurrentFrames = 0;
            mProcessingTimeMillisec = 0;
            mFramesPerSec = 0;
        }

        void Benchmark::updateBenchmarking()
        {
            notify(events::BenchmarkUpdatedEvent());
        }

        int Benchmark::getCurrentFrames() const
        {
            return mCurrentFrames;
        }

    }
}
