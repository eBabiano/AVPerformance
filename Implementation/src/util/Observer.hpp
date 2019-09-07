//File: Observer.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace src
{
    namespace util
    {
        template <class T>
        class Observer
        {
            public:
            Observer(){}
                virtual void observableUpdated(const T& event) = 0;
        };
    }
}

#endif // OBSERVER_HPP
