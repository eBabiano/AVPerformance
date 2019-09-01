#include <src/controller/av/StartAVController.hpp>
#include <src/model/av/AVTypes.hpp>
#include <iostream>

namespace src
{
    namespace controller
    {
        namespace av
        {
            StartAVController::StartAVController(src::model::av::AVManager& avManager, model::Benchmark& benchmark)
                : mAVManager(&avManager)
                , mBenchmark(&benchmark)
            {

            }

            void StartAVController::observableUpdated(const view::gui::events::StartAVEvent &event)
            {
                if (event.isStarting())
                {
                    std::cout << "Start av algorithm" << std::endl;
                    mAVManager->play();
                }
                else
                {
                    std::cout << "Stop av algorithm" << std::endl;
                    mAVManager->stop();
                    mBenchmark->clearAll();
                }
            }
        }
    }
}
