//File: StartAVController.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef STARTAVCONTROLLER_HPP
#define STARTAVCONTROLLER_HPP

#include <src/model/av/AVManager.hpp>
#include <src/model/Benchmark.hpp>
#include <src/util/Observer.hpp>
#include <src/view/gui/events/StartAVEvent.hpp>

namespace src
{
    namespace controller
    {
        namespace av
        {
            class StartAVController
                    : public src::util::Observer<view::gui::events::StartAVEvent>
            {
                public:
                    StartAVController(model::av::AVManager &avManager, model::Benchmark& benchmark);
                    virtual void observableUpdated(const view::gui::events::StartAVEvent& event);

                private:
                    src::model::av::AVManager* mAVManager;
                    src::model::Benchmark* mBenchmark;
            };
        }
    }
}

#endif // STARTAVCONTROLLER_HPP
