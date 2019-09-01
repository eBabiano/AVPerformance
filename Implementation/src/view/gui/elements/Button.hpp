#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <src/util/Observable.hpp>
#include <src/view/gui/container/View.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace elements
            {
                class Button
                        : public container::View
                {
                    public:
                        Button(const int &element);

                        void onClicked();

                };
            }
        }
    }
}

#endif // BUTTON_HPP
