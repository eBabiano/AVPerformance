//File: AVManager.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef AVMANAGER_HPP
#define AVMANAGER_HPP

#include <src/util/Observable.hpp>
#include <src/model/av/events/AVStarted.hpp>
#include <src/model/av/events/AVSelectedEvent.hpp>

#include <src/model/av/AV.hpp>

#include <map>

namespace src
{
    namespace model
    {
        namespace av
        {
            class AVManager
                    : public util::Observable<events::AVStarted>
                    , public util::Observable<events::AVSelectedEvent>
            {
                public:
                    AVManager();

                    std::string getSelectedType() const;
                    void selectAV(const std::string& type);
                    void play();
                    void stop();

                    bool getIsGPU() const;
                    void setIsGPU(bool value);

                    AV* getAlgorithm(const std::string& type);
                    AV* getSelectedAlgorithm();

            private:
                    std::string mSelectedType;

                    std::map<std::string, AV*> mAVVector;
                    bool mIsPlaying;

                    using util::Observable<events::AVStarted>::notify;
                    using util::Observable<events::AVSelectedEvent>::notify;

            };
        }
    }
}

#endif // AVMANAGER_HPP
