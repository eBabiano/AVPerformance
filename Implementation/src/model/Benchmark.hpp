//File: Benchmark.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <string>
#include <src/util/Observable.hpp>
#include <src/model/events/BenchmarkUpdatedEvent.hpp>

namespace src
{
    namespace model
    {
        class Benchmark
                : public util::Observable<events::BenchmarkUpdatedEvent>
        {
            public:
                Benchmark();

                double getProcessingTimeMillisec() const;
                void setProcessingTimeMillisec(double value);

                int getFramesPerSec() const;
                void setFramesPerSec(int value);

                int getFrames() const;
                void setFrames(int value);

                double getWeightedAverageProcessingTimeMillisec();
                int getWeightedAverageFramesPerSeconds();

                bool getIsPlaying() const;
                void setIsPlaying(bool value);

                bool getIsGPU() const;
                void setIsGPU(bool value);

                void updateCurrentFrames();
                void clearAll();

                void updateBenchmarking();
                int getCurrentFrames() const;

            private:
                double mProcessingTimeMillisec;
                int mFramesPerSec;
                bool mIsGPU;
                int mCurrentFrames;

                int mFrames;
                bool mIsPlaying;

                std::vector<double> mProcessingTimeMillisecVector;
                std::vector<double> mFramesPerSecondsVector;

                using util::Observable<events::BenchmarkUpdatedEvent>::notify;

        };
    }
}

#endif // BENCHMARK_HPP
