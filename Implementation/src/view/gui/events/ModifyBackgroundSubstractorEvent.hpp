#ifndef MODIFYBACKGROUNDSUBSTRACTOREVENT_HPP
#define MODIFYBACKGROUNDSUBSTRACTOREVENT_HPP

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace events
            {
                class ModifyBackgroundSubstractorEvent
                {
                    public:
                        ModifyBackgroundSubstractorEvent(double learningRate);

                        double getLearningRate() const;

                private:
                        double mLearningRate;
                };
            }
        }
    }
}

#endif // MODIFYBACKGROUNDSUBSTRACTOREVENT_HPP
