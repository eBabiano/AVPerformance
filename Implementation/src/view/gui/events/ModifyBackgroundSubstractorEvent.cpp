#include <src/view/gui/events/ModifyBackgroundSubstractorEvent.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                ModifyBackgroundSubstractorEvent::ModifyBackgroundSubstractorEvent(double learningRate)
                    : mLearningRate(learningRate)
                {
                }

                double ModifyBackgroundSubstractorEvent::getLearningRate() const
                {
                    return mLearningRate;
                }

            }
        }
    }
}
