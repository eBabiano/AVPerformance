//File: main.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1
//Description: This is a performance application for the analysis of artificial vision algorithms in ARM embedded systems

#include <iostream>

#include <src/model/av/AVManager.hpp>
#include <src/model/Benchmark.hpp>

#include <src/view/gui/MainWindow.hpp>
#include <src/view/gui/videoplayer/VideoPlayerManager.hpp>

#include <src/view/gui/events/StartAVEvent.hpp>
#include <src/view/gui/events/SelectAVEvent.hpp>
#include <src/view/av/AVRenderManager.hpp>

#include <src/controller/av/StartAVController.hpp>
#include <src/controller/av/SelectAVController.hpp>
#include <src/controller/UpdateBenchmarkController.hpp>
#include <src/controller/ModifyAlgorithmParametersController.hpp>

#include <src/util/Observer.hpp>

#include <QApplication>

int main(int argc, char* argv[])
{

    int exitCode = -13;

    std::string videoCaptureOption = "";
    std::string videoPath = "";
    if (argc > 1)
    {
        videoCaptureOption = std::string(argv[1]);

        if (argc > 2)
        {
            videoPath = std::string(argv[2]);
        }
    }
    else
    {
        std::cout << "Error in parameters: Specify input camera: [--fly], [--cam], [--video [path]]" << std::endl;
        exit(-1);
    }


    std::cout << "Running... " << videoCaptureOption << std::endl;

    //Models
    src::model::av::AVManager* mAVManager = new src::model::av::AVManager();
    src::model::Benchmark* mBenchmark = new src::model::Benchmark();

    //Controllers
    src::controller::av::StartAVController* mStartAVController = new src::controller::av::StartAVController(*mAVManager, *mBenchmark);
    src::controller::av::SelectAVController* mSelectAVController = new src::controller::av::SelectAVController(*mAVManager);
    src::controller::UpdateBenchmarkController* mUpdateBenchmarkController = new src::controller::UpdateBenchmarkController(*mBenchmark);
    src::controller::ModifyAlgorithmParametersController* mModifyAlgorithmParametersController = new src::controller::ModifyAlgorithmParametersController(*mAVManager);

    //Views
    src::view::av::AVRenderManager* mAVRenderManager = new src::view::av::AVRenderManager(*mAVManager, *mUpdateBenchmarkController);

   /// std::string windowOutput = "Output Video";
    src::view::gui::videoplayer::VideoPlayerManager* videoPlayerManager = new src::view::gui::videoplayer::VideoPlayerManager(videoCaptureOption, videoPath);
    ///cv::setMouseCallback(windowOutput, onMouse, NULL);
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    QApplication app(argc, argv);
    src::view::gui::MainWindow* mainWindow;

    mainWindow = new src::view::gui::MainWindow(*mBenchmark, *mAVManager, *mAVRenderManager, *videoPlayerManager);

    mainWindow->setModifyAlgorithmParametersController(*mModifyAlgorithmParametersController);

    //LINKERS
    mainWindow->getControlPanel()->src::util::Observable<src::view::gui::events::StartAVEvent>::attach(*mStartAVController);
    mainWindow->getModifyParametersWidget()->src::util::Observable<src::view::gui::events::SelectAVEvent>::attach(*mSelectAVController);

    mainWindow->show();
    exitCode = app.exec();

    if (exitCode == 0)
    {
       delete mAVRenderManager;
    }
    return exitCode;

}
