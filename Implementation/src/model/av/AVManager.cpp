//File: AVManager.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/model/av/AVManager.hpp>

#include <src/model/av/AVTypes.hpp>
#include <src/model/av/BackgroundSubstractor.hpp>
#include <src/model/av/FaceDetection.hpp>
#include <src/model/av/OpticalFlow.hpp>
#include <src/model/av/PedestrianDetection.hpp>

namespace src
{
    namespace model
    {
        namespace av
        {
            AVManager::AVManager()
                : mSelectedType(AVTypes::BACKGROUND_SUBTRACTOR)
                , mIsPlaying(false)
            {
                mAVVector[AVTypes::BACKGROUND_SUBTRACTOR] = new BackgroundSubstractor();
                mAVVector[AVTypes::FACE_DETECTION] = new FaceDetection();
                mAVVector[AVTypes::OPTICAL_FLOW] = new OpticalFlow();
                mAVVector[AVTypes::PEDESTRIAN_DETECTOR] = new PedestrianDetection();
                ///@todo Create new algorithms
                ///mAVVector[AVTypes::STEREO] = new Stereo();
            }

            std::string AVManager::getSelectedType() const
            {
                return mSelectedType;
            }

            void AVManager::selectAV(const std::string &type)
            {
                mSelectedType = type;
                notify(events::AVSelectedEvent(mSelectedType));
            }

            void AVManager::play()
            {
                mIsPlaying = true;
                notify(events::AVStarted(mSelectedType, true));
            }

            void AVManager::stop()
            {
                mIsPlaying = false;
                notify(events::AVStarted(mSelectedType, false));
            }

            AV *AVManager::getAlgorithm(const std::string &type)
            {
                return mAVVector.at(type);
            }

            AV *AVManager::getSelectedAlgorithm()
            {
                return mAVVector.at(mSelectedType);
            }
            
        }
    }
}
