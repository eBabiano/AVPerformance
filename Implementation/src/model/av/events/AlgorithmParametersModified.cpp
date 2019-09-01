//File: AlgorithmParametersModified.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/events/AlgorithmParametersModified.hpp>

namespace src
{
    namespace model
    {
       namespace av
       {
           namespace events
           {
               AlgorithmParametersModified::AlgorithmParametersModified(const std::string &type)
                   : mType(type)
               {
               }
               std::string AlgorithmParametersModified::getType() const
               {
                   return mType;
               }

           }
       }
    }
}
