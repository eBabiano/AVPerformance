//File: MainWindow.hpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>

#include <src/controller/ModifyAlgorithmParametersController.hpp>

#include <src/view/gui/widgets/ModifyParametersWidget.hpp>
#include <src/view/gui/widgets/BenchmarkingWidget.hpp>
#include <src/view/gui/widgets/ControlPanelWidget.hpp>
#include <src/view/av/AVRenderManager.hpp>
#include <src/view/gui/videoplayer/VideoPlayerManager.hpp>
#include <src/model/av/AVManager.hpp>
#include <src/model/Benchmark.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindow;
}

namespace src
{
    namespace view
    {
        namespace gui
        {
            class MainWindow : public QWidget
                    , public util::Observer<model::av::events::AVStarted>
            {
                Q_OBJECT

            public:
                explicit MainWindow(model::Benchmark &benchmark, model::av::AVManager &avManager
                                    , av::AVRenderManager& avRenderManager
                                    , videoplayer::VideoPlayerManager& videoPlayerManager
                                    , QWidget *parent = 0);
                virtual ~MainWindow();

                widgets::ControlPanelWidget* getControlPanel();
                widgets::BenchmarkingWidget* getBenchmarkingWidget();
                widgets::ModifyParametersWidget* getModifyParametersWidget();

                void setModifyAlgorithmParametersController(
                        controller::ModifyAlgorithmParametersController& ModifyAlgorithmParametersController);

                virtual void observableUpdated(const model::av::events::AVStarted& event);

            public slots:
                void timerEvent(QTimerEvent *event);

            private:
                void initializeGUI();

                Ui::MainWindow *ui;
                src::model::av::AVManager* mAVManager;
                src::model::Benchmark* mBenchmark;
                av::AVRenderManager* mAVRenderManager;
                bool mFlipVert;
                bool mFlipHoriz;

                videoplayer::VideoPlayerManager* mVideoPlayerManager;

                widgets::ModifyParametersWidget* mModifyParametersWidget;
                widgets::BenchmarkingWidget* mBenchmarkingWidget;
                widgets::ControlPanelWidget* mControlPanelWidget;
                cv::Mat mImage;
                int mIdTimer;

                bool mIsPainted;

            };
        }
    }
}

#endif // MAINWINDOW_HPP
