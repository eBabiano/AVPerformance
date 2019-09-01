#ifndef UPDATEBENCHMARKCONTROLLER_HPP
#define UPDATEBENCHMARKCONTROLLER_HPP

#include <src/model/Benchmark.hpp>
#include <src/util/Observer.hpp>
#include <src/view/av/events/UpdateBenchmarkEvent.hpp>

namespace src
{
    namespace controller
    {
        class UpdateBenchmarkController
                : public src::util::Observer<view::av::events::UpdateBenchmarkEvent>

        {
            public:
                UpdateBenchmarkController(model::Benchmark& benchmark);
                virtual void observableUpdated(const view::av::events::UpdateBenchmarkEvent& event);


            private:
                model::Benchmark* mBenchmark;

        };
    }
}


#endif // UPDATEBENCHMARKCONTROLLER_HPP
