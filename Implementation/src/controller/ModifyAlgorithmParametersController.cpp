#include <src/controller/ModifyAlgorithmParametersController.hpp>
#include <src/model/av/AVTypes.hpp>
#include <src/model/av/OpticalFlowTypes.hpp>

namespace src
{
    namespace controller
    {
        ModifyAlgorithmParametersController::ModifyAlgorithmParametersController(
                model::av::AVManager &avManager)
            : mAVManager(&avManager)
        {
        }

        void ModifyAlgorithmParametersController::observableUpdated(const view::gui::events::ModifyBackgroundSubstractorEvent &event)
        {
            mAVManager->getAlgorithm(model::av::AVTypes::BACKGROUND_SUBTRACTOR)->setLearningRate(event.getLearningRate());
        }

        void ModifyAlgorithmParametersController::observableUpdated(const view::gui::events::ModifyFaceDetectionEvent &event)
        {
            mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->setProcessorType(event.getProcessorType());
            mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->setScaleFactor(event.getScaleFactor());
            mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->setNeightbors(event.getNeightbors());
            mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->setWidth(event.getWidth());
            mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->setHeight(event.getHeight());
        }

        void ModifyAlgorithmParametersController::observableUpdated(const view::gui::events::ModifyOpticalFlowEvent &event)
        {
            mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->setProcessorType(event.getProcessorType());
            mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->setGoodFeaturesParameters(event.getGoodFeaturesParameters());
            mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->setTermCriteriaParameters(event.getTermCriteriaParameters());
        }

        void ModifyAlgorithmParametersController::observableUpdated(const view::gui::events::ModifyPedestrianDetectorEvent &event)
        {
            mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setProcessorType(event.getProcessorType());
            mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setHitThreshold(event.getHitThreshold());
            mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setWindStride(
                        event.getWindStrideWidth(), event.getWindStrideHeight());
            mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setPadding(
                        event.getPaddingWidth(), event.getPaddingHeight());
            mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setScale(event.getScale());
            mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setFinalThreshold(event.getFinalThreshold());
            mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->setUseMeanShiftGrouping(event.getUseMeanShiftGrouping());
        }
    }
}
