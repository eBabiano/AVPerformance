#ifndef VIEW_HPP
#define VIEW_HPP

#include <vector>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace container
            {
                class View
                {
                    public:
                        View(const int& element);

                        int getElement() const;
                        View *getView(const int& element);

                protected:
                        void addView(View &view);

                        int mElement;
                        std::vector<View*> mViews;

                };
            }
        }
    }
}

#endif // VIEW_HPP
