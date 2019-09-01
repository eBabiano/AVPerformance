#include <src/view/gui/events/StartAVEvent.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                StartAVEvent::StartAVEvent(bool isStarting)
                    : mIsStarting(isStarting)
                {

                }

                bool StartAVEvent::isStarting() const
                {
                    return mIsStarting;
                }

            }
        }
    }
}
