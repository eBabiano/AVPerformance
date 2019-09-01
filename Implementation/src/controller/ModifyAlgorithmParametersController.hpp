#ifndef ModifyAlgorithmParametersController_HPP
#define ModifyAlgorithmParametersController_HPP

#include <src/model/av/AVManager.hpp>
#include <src/view/gui/events/ModifyBackgroundSubstractorEvent.hpp>
#include <src/view/gui/events/ModifyFaceDetectionEvent.hpp>
#include <src/view/gui/events/ModifyOpticalFlowEvent.hpp>
#include <src/view/gui/events/ModifyPedestrianDetectorEvent.hpp>

namespace src
{
    namespace controller
    {
        class ModifyAlgorithmParametersController
                : public src::util::Observer<view::gui::events::ModifyBackgroundSubstractorEvent>
                , public src::util::Observer<view::gui::events::ModifyFaceDetectionEvent>
                , public src::util::Observer<view::gui::events::ModifyOpticalFlowEvent>
                , public src::util::Observer<view::gui::events::ModifyPedestrianDetectorEvent>
        {
            public:
                ModifyAlgorithmParametersController(model::av::AVManager &avManager);
                virtual void observableUpdated(const view::gui::events::ModifyBackgroundSubstractorEvent& event);
                virtual void observableUpdated(const view::gui::events::ModifyFaceDetectionEvent& event);
                virtual void observableUpdated(const view::gui::events::ModifyOpticalFlowEvent& event);
                virtual void observableUpdated(const view::gui::events::ModifyPedestrianDetectorEvent& event);

        private:
                model::av::AVManager* mAVManager;
        };
    }
}

#endif // ModifyAlgorithmParametersController_HPP
