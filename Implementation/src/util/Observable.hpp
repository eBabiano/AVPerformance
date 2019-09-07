//File: Observable.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <src/util/Observer.hpp>
#include <vector>

namespace src
{
    namespace util
    {
        template <class T>
        class Observable
        {
            public:
                Observable()
                {

                }

                void notify(T event)
                {
                    for (auto& observer : mObserverList)
                    {
                        observer->observableUpdated(event);
                    }
                }

                void attach(Observer<T>& observer)
                {
                    mObserverList.push_back(&observer);
                }

            private:
                std::vector<src::util::Observer<T>*> mObserverList;
        };


    }
}

#endif // OBSERVABLE_HPP
