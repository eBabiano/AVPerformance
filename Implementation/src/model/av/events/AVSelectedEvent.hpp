//File: AVSelectedEvent.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef AVSELECTEDEVENT_HPP
#define AVSELECTEDEVENT_HPP

#include <string>

namespace src
{
    namespace model
    {
       namespace av
       {
           namespace events
           {
               class AVSelectedEvent
               {
                   public:
                       AVSelectedEvent(const std::string& type);

                       std::string getType() const;

                   private:
                       std::string mType;
               };
           }
       }
    }
}

#endif // AVSELECTEDEVENT_HPP
