#include <src/view/gui/widgets/BenchmarkingWidget.hpp>
#include "ui_BenchmarkingWidget.h"
#include <src/util/String.hpp>
#include <assert.h>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                int BenchmarkingWidget::MAX_X = 2000;
                int BenchmarkingWidget::MAX_Y = 100;

                BenchmarkingWidget::BenchmarkingWidget(model::av::AVManager &avManager, model::Benchmark &benchmark,
                                                       const int& element, QWidget *parent)
                    : QWidget(parent)
                    , ui(new Ui::BenchmarkingWidget)
                    , Container(element)
                    , mBenchmark(&benchmark)
                    , mAVManager(&avManager)
                    , mProcessingTime(0.0)
                    , mCurrentFrames(0)
                    , mFPS(0)
                {
                    ui->setupUi(this);

                    mAVManager->src::util::Observable<model::av::events::AVStarted>::attach(*this);
                    mBenchmark->src::util::Observable<model::events::BenchmarkUpdatedEvent>::attach(*this);

                    mTimer = new QTimer();
                    mTimer->setInterval(1000);
                    assert(connect(mTimer, SIGNAL(timeout()), this, SLOT(plot())));

                    initGraph();
                }

                BenchmarkingWidget::~BenchmarkingWidget()
                {
                    delete ui;
                }

                void BenchmarkingWidget::observableUpdated(const model::events::BenchmarkUpdatedEvent &event)
                {
                    std::string proccessigTime = util::String::getFixed(mBenchmark->getProcessingTimeMillisec(), 2);
                    std::string fps = std::to_string(mBenchmark->getFramesPerSec());
                    ui->tpProccesing->setText(proccessigTime.c_str());
                    ui->fps->setText(fps.c_str());

                    mCurrentFrames = mBenchmark->getCurrentFrames();
                    mProcessingTime = mBenchmark->getProcessingTimeMillisec();
                    mFPS = mBenchmark->getFramesPerSec();
                }

                void BenchmarkingWidget::observableUpdated(const model::av::events::AVStarted &event)
                {
                    if(event.getIsActivated())
                    {
                        mTimer->start();
                    }
                    else
                    {

                        mTimer->stop();
                        clearData();

                        std::string averageProccessigTime = util::String::getFixed(mBenchmark->getWeightedAverageProcessingTimeMillisec(), 2);
                        std::string fpsTime = std::to_string(mBenchmark->getWeightedAverageFramesPerSeconds());

                        ui->tpWeighted->setText(averageProccessigTime.c_str());
                        ui->fpsWeighted->setText(fpsTime.c_str());
                    }
                }

                void BenchmarkingWidget::addPointTime(double x, double y)
                {
                    mVectorTimeX.append(x);
                    mVectorTimeY.append(y);
                }

                void BenchmarkingWidget::addPointFPS(double x, double y)
                {
                    mVectorFPSX.append(x);
                    mVectorFPSY.append(y);
                }

                void BenchmarkingWidget::clearData()
                {
                    mVectorFPSX.clear();
                    mVectorFPSY.clear();
                    mVectorTimeX.clear();
                    mVectorTimeY.clear();

                    mCurrentFrames = 0;
                    mProcessingTime = 0.0;
                    mFPS = 0;

                    addPointTime(mCurrentFrames, mProcessingTime);
                    addPointFPS(mCurrentFrames, mFPS);

                    ui->plotTimeWidget->graph(0)->setData(mVectorTimeX, mVectorTimeY);
                    ui->plotFPSWidget->graph(0)->setData(mVectorFPSX, mVectorFPSY);
//                    ui->plotTimeWidget->replot();
//                    ui->plotFPSWidget->replot();
                }

                void BenchmarkingWidget::plot()
                {
                    mMutex.lock();


                    addPointTime(mCurrentFrames, mProcessingTime);
                    addPointFPS(mCurrentFrames, mFPS);

                    ui->plotTimeWidget->graph(0)->setData(mVectorTimeX, mVectorTimeY);
                    ui->plotFPSWidget->graph(0)->setData(mVectorFPSX, mVectorFPSY);
                    ui->plotTimeWidget->replot();
                    ui->plotFPSWidget->replot();

                    if (mCurrentFrames < MAX_X + 50 && mCurrentFrames > MAX_X - 50)
                    {
                        clearData();
                        mBenchmark->clearAll();
                    }
                    mMutex.unlock();
                }

                void BenchmarkingWidget::initGraph()
                {
                   // ui->plotTimeWidget->setOpenGl(true)

                    //Graph 0: Time Proccessing graph
                    ui->plotTimeWidget->addGraph();
                    ui->plotTimeWidget->graph(0)->setPen(QPen(Qt::blue));
                    ui->plotTimeWidget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

                    ui->plotTimeWidget->xAxis->setLabel("Current Frames");
                    ui->plotTimeWidget->yAxis->setLabel("T. Proccessing (ms)");
                    ui->plotTimeWidget->xAxis->setRange(0, MAX_X);
                    ui->plotTimeWidget->yAxis->setRange(0, MAX_Y);

                    //Graph 1: FPS graph
                    ui->plotFPSWidget->addGraph();
                    ui->plotFPSWidget->graph(0)->setPen(QPen(Qt::red));
                    ui->plotFPSWidget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

                    ui->plotFPSWidget->xAxis->setLabel("Current Frames");
                    ui->plotFPSWidget->yAxis->setLabel("FPS");
                    ui->plotFPSWidget->xAxis->setRange(0, MAX_X);
                    ui->plotFPSWidget->yAxis->setRange(0, MAX_Y);
                }

            }
        }
    }
}
