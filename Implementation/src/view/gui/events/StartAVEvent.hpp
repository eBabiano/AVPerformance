#ifndef STARTAVEVENT_HPP
#define STARTAVEVENT_HPP

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                class StartAVEvent
                {
                    public:
                        StartAVEvent(bool isStarting);

                        bool isStarting() const;

                private:
                        bool mIsStarting;
                };
            }
        }
    }
}

#endif // STARTAVEVENT_HPP
