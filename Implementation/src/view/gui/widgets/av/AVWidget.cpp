#include <src/view/gui/widgets/av/AVWidget.hpp>

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
                    AVWidget::AVWidget(model::av::AVManager& avManager, QWidget *parent)
                        : QWidget(parent)
                        , mAVManager(&avManager)
                    {
                       // mAVManager->src::util::Observable<model::av::events::AVStarted>::attach(*this);
                    }

                    void AVWidget::hidden()
                    {
                        setVisible(false);
                    }

                    void AVWidget::observableUpdated(const model::av::events::AVStarted &event)
                    {
                        setEnabled(event.getIsActivated());
                    }
                }
            }
        }
    }
}
