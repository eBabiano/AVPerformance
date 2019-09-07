#ifndef AVWidget_HPP
#define AVWidget_HPP

#include <src/model/av/AVManager.hpp>
#include <QWidget>

#include <src/view/gui/events/ModifyBackgroundSubstractorEvent.hpp>
#include <src/view/gui/events/ModifyFaceDetectionEvent.hpp>
#include <src/view/gui/events/ModifyOpticalFlowEvent.hpp>
#include <src/view/gui/events/ModifyPedestrianDetectorEvent.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                namespace av
                {
                    class AVWidget
                            : public QWidget
                            , public util::Observable<events::ModifyBackgroundSubstractorEvent>
                            , public util::Observable<events::ModifyFaceDetectionEvent>
                            , public util::Observable<events::ModifyOpticalFlowEvent>
                            , public util::Observable<events::ModifyPedestrianDetectorEvent>
                            , public util::Observer<src::model::av::events::AVStarted>
                    {
                        Q_OBJECT

                        public:
                            AVWidget(model::av::AVManager &avManager, QWidget *parent = 0);

                            void hidden();
                            virtual void observableUpdated(const model::av::events::AVStarted& event);

                            virtual void setCPUGPUActivated(bool activate) = 0;

                    protected:
                            model::av::AVManager* mAVManager;

                            using util::Observable<events::ModifyBackgroundSubstractorEvent>::notify;
                            using util::Observable<events::ModifyFaceDetectionEvent>::notify;
                            using util::Observable<events::ModifyOpticalFlowEvent>::notify;
                            using util::Observable<events::ModifyPedestrianDetectorEvent>::notify;


                    };
                }
            }
        }
    }
}

#endif // AVWidget_HPP
