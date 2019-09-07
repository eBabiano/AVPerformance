//File: UpdateBenchmarkController.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/controller/UpdateBenchmarkController.hpp>

namespace src
{
    namespace controller
    {
        UpdateBenchmarkController::UpdateBenchmarkController(model::Benchmark& benchmark)
            : mBenchmark(&benchmark)
        {
        }

        void UpdateBenchmarkController::observableUpdated(const view::av::events::UpdateBenchmarkEvent &event)
        {
            if (event.getFPS() == 0)
            {
                mBenchmark->clearAll();
            }
            else
            {
                mBenchmark->updateCurrentFrames();
            }
            mBenchmark->setProcessingTimeMillisec(event.getTimeProcMillis());
            mBenchmark->setFramesPerSec(event.getFPS());
            mBenchmark->updateBenchmarking();
        }
    }
}
