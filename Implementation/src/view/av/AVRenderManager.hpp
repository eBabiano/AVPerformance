#ifndef AVRENDERMANAGER_HPP
#define AVRENDERMANAGER_HPP

#include <src/model/av/AVManager.hpp>
#include <src/model/av/events/AVStarted.hpp>
#include <src/view/av/AVView.hpp>
#include <src/controller/UpdateBenchmarkController.hpp>

#include <src/util/Observer.hpp>

#include <map>

#include <opencv2/opencv.hpp>

namespace src
{
    namespace view
    {
       namespace av
       {
           class AVRenderManager
                   : public util::Observer<model::av::events::AVStarted>
                   , public util::Observer<model::av::events::AlgorithmParametersModified>
           {
               public:
                   AVRenderManager(model::av::AVManager &avManager,
                                   controller::UpdateBenchmarkController& updateBenchmarkController);
                   ~AVRenderManager();

                   virtual void observableUpdated(const model::av::events::AVStarted& event);
                   virtual void observableUpdated(const model::av::events::AlgorithmParametersModified& event);

                   cv::Mat getImageForRender();
                   void sumAllAVImages();

                   void setCaptureImage(cv::Mat mat);
                   void setCaptureImageStereo(cv::Mat mat);
                   void setTotalFrames(int value);

                private:
                   void initializeBackgroundSubtractor();
                   void initializeFaceDetection();
                   void initializeOpticalFlow();
                   void initializePedestrianDetector();

                   void linker();

                   model::av::AVManager* mAVManager;

                   std::map<std::string, AVView*> mAVViews;
                   cv::Mat mImageForRender;

                   std::string mSelectedAV;
           };
       }
    }
}

#endif // AVRENDERMANAGER_HPP
