#ifndef SELECTAVCONTROLLER_HPP
#define SELECTAVCONTROLLER_HPP

#include <src/model/av/AVManager.hpp>
#include <src/util/Observer.hpp>
#include <src/view/gui/events/SelectAVEvent.hpp>

namespace src
{
    namespace controller
    {
        namespace av
        {
            class SelectAVController
                    : public src::util::Observer<view::gui::events::SelectAVEvent>
            {
                public:
                    SelectAVController(model::av::AVManager &avManager);
                    virtual void observableUpdated(const view::gui::events::SelectAVEvent& event);

                private:
                    src::model::av::AVManager* mAVManager;
            };
        }
    }
}

#endif // SELECTAVCONTROLLER_HPP
