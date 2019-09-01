#include <src/view/gui/container/View.hpp>
#include <iostream>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace container
            {
                View::View(const int &element)
                    : mElement(element)
                {

                }

                int View::getElement() const
                {
                    return mElement;
                }

                View* View::getView(const int &element)
                {
                    for (auto& view : mViews)
                    {
                        if (view->getElement() == element)
                        {
                            return view;
                        }
                    }
                    return nullptr;
                }

                void View::addView(View& view)
                {
                    if (&view != nullptr)
                    {
                        mViews.push_back(&view);
                    }
                    return;
                }

            }
        }
    }
}
