//File: AVStarted.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/events/AVStarted.hpp>

namespace src
{
    namespace model
    {
       namespace av
       {
           namespace events
           {
               AVStarted::AVStarted(const std::string &type, bool activated)
                   : mType(type)
                   , mIsActivated(activated)
               {

               }

               std::string AVStarted::getType() const
               {
                   return mType;
               }

               bool AVStarted::getIsActivated() const
               {
                   return mIsActivated;
               }

           }
       }
    }
}
