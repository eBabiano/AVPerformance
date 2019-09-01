#ifndef SELECTAVEVENT_HPP
#define SELECTAVEVENT_HPP

#include <string>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                class SelectAVEvent
                {
                    public:
                        SelectAVEvent(const std::string& type, bool isGPU);

                        std::string getType() const;
                        bool getIsGPU() const;

                    private:
                        std::string mType;
                        bool mIsGPU;
                };
            }
        }
    }
}

#endif // SELECTAVEVENT_HPP
