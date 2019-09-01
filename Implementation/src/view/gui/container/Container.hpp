#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <src/view/gui/container/View.hpp>
namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace container
            {
                class Container
                        : public View
                {
                    public:
                        Container(const int& element);
                };
            }
        }
    }
}

#endif // CONTAINER_HPP
