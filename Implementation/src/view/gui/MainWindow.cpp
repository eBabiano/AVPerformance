//File: MainWindow.cpp
//Author: Emilio Babiano <emilio.babiano@edu.uah.es>
//Version: 0.0.1

#include <src/view/gui/MainWindow.hpp>
#include <src/view/gui/container/ViewElements.hpp>
#include "ui_MainWindow.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            MainWindow::MainWindow(model::Benchmark& benchmark,
                                   model::av::AVManager &avManager, av::AVRenderManager& avRenderManager,
                                   videoplayer::VideoPlayerManager& videoPlayerManager,
                                   QWidget *parent) :
                QWidget(parent),
                ui(new Ui::MainWindow)
              , mAVManager(&avManager)
              , mBenchmark(&benchmark)
              , mIsPainted(false)
              , mVideoPlayerManager(&videoPlayerManager)
              , mAVRenderManager(&avRenderManager)
            {
                ui->setupUi(this);

                mAVManager->src::util::Observable<model::av::events::AVStarted>::attach(*this);

                initializeGUI();

                mFlipVert=false;
                mFlipHoriz=false;
            }

            MainWindow::~MainWindow()
            {
                delete ui;
            }

            void MainWindow::initializeGUI()
            {
                mModifyParametersWidget = new widgets::ModifyParametersWidget(*mAVManager, container::ViewElements::AV_WIDGET);
                ui->modifyParametersLayout->addWidget(mModifyParametersWidget, 0, 0);

                mBenchmarkingWidget = new widgets::BenchmarkingWidget(*mAVManager, *mBenchmark, container::ViewElements::BENCHMARKING_WIDGET);
                ui->benchmarkLayout->addWidget(mBenchmarkingWidget, 0, 0);

                mControlPanelWidget = new widgets::ControlPanelWidget(*mAVManager, container::ViewElements::CONTROL_PANEL);
                ui->controlPanelLayout->addWidget(mControlPanelWidget, 0, 0);
            }

            widgets::ControlPanelWidget *MainWindow::getControlPanel()
            {
                return mControlPanelWidget;
            }

            widgets::BenchmarkingWidget *MainWindow::getBenchmarkingWidget()
            {
                return mBenchmarkingWidget;
            }

            widgets::ModifyParametersWidget *MainWindow::getModifyParametersWidget()
            {
                return mModifyParametersWidget;
            }

            void MainWindow::setModifyAlgorithmParametersController(
                    controller::ModifyAlgorithmParametersController &ModifyAlgorithmParametersController)
            {
                mModifyParametersWidget->setModifyAlgorithmParametersController(ModifyAlgorithmParametersController);
                mModifyParametersWidget->initAVParameters();
            }

            void MainWindow::observableUpdated(const model::av::events::AVStarted &event)
            {
                if (event.getIsActivated())
                {
                    int fps = 30.0;
                    int milliseconds = (1.0 / fps) * 1000.0;

                    mIdTimer = startTimer(milliseconds);
                }
                else
                {
                    killTimer(mIdTimer);
                    for (auto& videoPlayer : mVideoPlayerManager->getVideoPlayers())
                    {
                        videoPlayer->stop();
                    }
                }
            }

            void MainWindow::timerEvent(QTimerEvent *event)
            {
                if (mVideoPlayerManager->isStereo())
                {
                    for (auto& videoPlayer : mVideoPlayerManager->getVideoPlayers())
                    {
                        if (videoPlayer->getType() == videoplayer::VideoPlayerTypes::VIDEO_1)
                        {
                            ///@todo SUM all the CV::MAT images
                            mAVRenderManager->setCaptureImage(videoPlayer->getCurrentFrame());
                            mAVRenderManager->sumAllAVImages();
                            // Show the image
                            videoPlayer->run(mAVRenderManager->getImageForRender(), false);
                        }
                        else if (videoPlayer->getType() == videoplayer::VideoPlayerTypes::VIDEO_2)
                        {
                            ///@todo SUM all the CV::MAT images
                            mAVRenderManager->setCaptureImageStereo(videoPlayer->getCurrentFrame());
                            mAVRenderManager->sumAllAVImages();
                            // Show the image
                            videoPlayer->run(mAVRenderManager->getImageForRender(), true);
                        }
                    }
                }
                else
                {
                    for (auto& videoPlayer : mVideoPlayerManager->getVideoPlayers())
                    {
                        ///@todo SUM all the CV::MAT images
                        mAVRenderManager->setCaptureImage(videoPlayer->getCurrentFrame());
                        mAVRenderManager->sumAllAVImages();
                        // Show the image
                        videoPlayer->run(mAVRenderManager->getImageForRender(), true);
                    }
                }

            }

        }
    }
}
