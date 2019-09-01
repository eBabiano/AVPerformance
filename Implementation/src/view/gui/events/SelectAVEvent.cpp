#include <src/view/gui/events/SelectAVEvent.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                SelectAVEvent::SelectAVEvent(const std::string& type, bool isGPU)
                    : mType(type)
                    , mIsGPU(isGPU)
                {

                }

                std::string SelectAVEvent::getType() const
                {
                    return mType;
                }

                bool SelectAVEvent::getIsGPU() const
                {
                    return mIsGPU;
                }
                
            }
        }
    }
}
