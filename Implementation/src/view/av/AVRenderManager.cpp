//File: AVRenderManager.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/av/AVRenderManager.hpp>

#include <src/view/av/FaceDetection.hpp>
#include <src/view/av/BackgroundSubtractor.hpp>
#include <src/view/av/OpticalFlow.hpp>
#include <src/view/av/PedestrianDetection.hpp>

#include <src/model/av/AVTypes.hpp>
#include <src/model/av/OpticalFlowTypes.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           AVRenderManager::AVRenderManager(model::av::AVManager &avManager,
                                            controller::UpdateBenchmarkController& updateBenchmarkController)
               : mAVManager(&avManager)
               , mImageForRender(cv::Mat::zeros(cv::Size(640, 480), CV_8UC3))
               , mSelectedAV(avManager.getSelectedType())
           {
               mAVViews[model::av::AVTypes::FACE_DETECTION] = new view::av::FaceDetection();
               mAVViews[model::av::AVTypes::BACKGROUND_SUBTRACTOR] = new view::av::BackgroundSubtractor();
               mAVViews[model::av::AVTypes::OPTICAL_FLOW] = new view::av::OpticalFlow();
               mAVViews[model::av::AVTypes::PEDESTRIAN_DETECTOR] = new view::av::PedestrianDetection();
               ///@todo Create new algorithms
               ///mAVViews[model::av::AVTypes::STEREO] = new view::av::Stereo();

               mAVManager->src::util::Observable<model::av::events::AVStarted>::attach(*this);

               linker();

               for (auto& view : mAVViews)
               {
                   view.second->src::util::Observable<view::av::events::UpdateBenchmarkEvent>::attach(updateBenchmarkController);
               }

               initializeBackgroundSubtractor();
               initializeFaceDetection();
               initializeOpticalFlow();
               initializePedestrianDetector();
           }

           AVRenderManager::~AVRenderManager()
           {
               for (auto& av : mAVViews)
               {
                   delete av.second;
               }
           }

           void AVRenderManager::observableUpdated(const model::av::events::AVStarted &event)
           {
               mSelectedAV = event.getType();
               if (event.getIsActivated())
               {
                   mAVViews.at(mSelectedAV)->start();
               }
               else
               {
                   mAVViews.at(mSelectedAV)->stop();
               }
           }

           void AVRenderManager::observableUpdated(const model::av::events::AlgorithmParametersModified &event)
           {
               if (event.getType() == model::av::AVTypes::BACKGROUND_SUBTRACTOR)
               {
                   initializeBackgroundSubtractor();
               }
               else if (event.getType() == model::av::AVTypes::PEDESTRIAN_DETECTOR)
               {
                   initializePedestrianDetector();
               }
               else if (event.getType() == model::av::AVTypes::FACE_DETECTION)
               {
                   initializeFaceDetection();
               }
               else if (event.getType() == model::av::AVTypes::OPTICAL_FLOW)
               {
                   initializeOpticalFlow();
               }

           }

           cv::Mat AVRenderManager::getImageForRender()
           {
               cv::Mat image;
               mImageForRender.copyTo(image);
               mImageForRender = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
               return image;
           }

           void AVRenderManager::sumAllAVImages()
           {
               if (!mAVViews.at(mSelectedAV)->getImage().empty())
               {
                   if (mImageForRender.channels() == mAVViews.at(mSelectedAV)->getImage().channels())
                   {
                       mImageForRender = mImageForRender + mAVViews.at(mSelectedAV)->getImage();
                   }
                   else
                   {
                       mImageForRender = mAVViews.at(mSelectedAV)->getImage();
                   }
               }
           }

           void AVRenderManager::setCaptureImage(cv::Mat mat)
           {
               mAVViews.at(mSelectedAV)->setCapturedImage(mat);
           }

           void AVRenderManager::setCaptureImageStereo(cv::Mat mat)
           {
               mAVViews.at(mSelectedAV)->setCapturedImageStereo(mat);
           }

           void AVRenderManager::setTotalFrames(int value)
           {
               mAVViews.at(mSelectedAV)->setTotalFrames(value);
           }

           void AVRenderManager::initializeBackgroundSubtractor()
           {
               double learningRate = mAVManager->getAlgorithm(model::av::AVTypes::BACKGROUND_SUBTRACTOR)->getLearningRate();
               mAVViews.at(model::av::AVTypes::BACKGROUND_SUBTRACTOR)->setLearningRate(learningRate);
           }

           void AVRenderManager::initializeFaceDetection()
           {
               std::string processorType = mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getProcessorType();
               double scaleFactor = mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getScaleFactor();
               int neightbors = mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getNeightbors();
               int width = mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getWidth();
               int height = mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getHeight();

               mAVViews.at(model::av::AVTypes::FACE_DETECTION)->activateGPU(processorType != model::av::AVTypes::CPU);
               mAVViews.at(model::av::AVTypes::FACE_DETECTION)->setScaleFactor(scaleFactor);
               mAVViews.at(model::av::AVTypes::FACE_DETECTION)->setNeightbors(neightbors);
               mAVViews.at(model::av::AVTypes::FACE_DETECTION)->setWidth(width);
               mAVViews.at(model::av::AVTypes::FACE_DETECTION)->setHeight(height);
           }

           void AVRenderManager::initializeOpticalFlow()
           {
               std::string processorType = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->getProcessorType();

               //GOOD FEATURES TO TRACK
               int maxCorners = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getGoodFeaturesParameters(model::av::OpticalFlowTypes::MAX_CORNERS);
               double minDistance = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getGoodFeaturesParameters(model::av::OpticalFlowTypes::MIN_DISTANCE);
               int blockSize = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getGoodFeaturesParameters(model::av::OpticalFlowTypes::BLOCK_SIZE);
               bool isHarrisDetectorActivated = (bool) mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getGoodFeaturesParameters(model::av::OpticalFlowTypes::HARRIS_DETECTOR);
               double kFactor = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getGoodFeaturesParameters(model::av::OpticalFlowTypes::K_FACTOR);

               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->activateGPU(processorType != model::av::AVTypes::CPU);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setMaxCorners(maxCorners);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setMinDistance(minDistance);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setBlockSize(blockSize);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->activateHarrisDetector(isHarrisDetectorActivated);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setKFactor(kFactor);

               //TERM CRITERIA
               int typeCriteria = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getTermCriteriaParameters(model::av::OpticalFlowTypes::TYPE);
               int maxCount = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getTermCriteriaParameters(model::av::OpticalFlowTypes::MAX_COUNT);
               double epsilon = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getTermCriteriaParameters(model::av::OpticalFlowTypes::EPS);

               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setTermCriteriaType(typeCriteria);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setMaxCount(maxCount);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setEpsilonFactor(epsilon);

               //OPTICAL FLOW LUCAS KANADE

               int width = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getOpticalFlowParameters(model::av::OpticalFlowTypes::WIN_SIZE_WIDTH);
               int height = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getOpticalFlowParameters(model::av::OpticalFlowTypes::WIN_SIZE_HEIGHT);
               int levels = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getOpticalFlowParameters(model::av::OpticalFlowTypes::MAX_LEVELS);
               int flags = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getOpticalFlowParameters(model::av::OpticalFlowTypes::FLAGS);
               double threshold = mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       getOpticalFlowParameters(model::av::OpticalFlowTypes::THRESHOLD);

               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setWinSize(width, height);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setMaxLevels(levels);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setFlags(flags);
               mAVViews.at(model::av::AVTypes::OPTICAL_FLOW)->setThresholdEigenvalue(threshold);
           }

           void AVRenderManager::initializePedestrianDetector()
           {
               std::string processorType = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getProcessorType();
               double hitThreshold = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getHitThreshold();
               int windStrideWidth = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getWindStrideWidth();
               int windStrideHeight = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getWindStrideHeight();
               int paddingWidth = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getPaddingWidth();
               int paddingHeight = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getPaddingHeight();
               double scale = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getScale();
               double finalThreshold = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getFinalThreshold();
               int useMeanShift = mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getUseMeanShiftGrouping();

               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->activateGPU(processorType != model::av::AVTypes::CPU);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setHitThreshold(hitThreshold);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setWindStrideWidth(windStrideWidth);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setWindStrideHeight(windStrideHeight);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setPaddingWidth(paddingWidth);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setPaddingHeight(paddingHeight);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setScale(scale);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setFinalThreshold(finalThreshold);
               mAVViews.at(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setUseMeanShiftGrouping(useMeanShift);
           }

           void AVRenderManager::linker()
           {
               mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->
                       src::util::Observable<model::av::events::AlgorithmParametersModified>::attach(*this);
               mAVManager->getAlgorithm(model::av::AVTypes::BACKGROUND_SUBTRACTOR)->
                       src::util::Observable<model::av::events::AlgorithmParametersModified>::attach(*this);
               mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                       src::util::Observable<model::av::events::AlgorithmParametersModified>::attach(*this);
               mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->
                       src::util::Observable<model::av::events::AlgorithmParametersModified>::attach(*this);
               ///@todo Create new algorithms
               ///mAVManager->getAlgorithm(model::av::AVTypes::STEREO)->
               ///        src::util::Observable<model::av::events::AlgorithmParametersModified>::attach(*this);
           }

       }
    }
}
