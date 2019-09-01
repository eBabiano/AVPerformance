#ifndef BENCHMARKINGWIDGET_HPP
#define BENCHMARKINGWIDGET_HPP

#include <src/view/gui/events/StartAVEvent.hpp>
#include <src/view/gui/container/Container.hpp>
#include <src/util/Observable.hpp>
#include <src/model/Benchmark.hpp>
#include <src/model/av/AVManager.hpp>
#include <QWidget>
#include <QVector>
#include <mutex>

namespace Ui {
class BenchmarkingWidget;
}

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                class BenchmarkingWidget
                        : public QWidget
                        , public container::Container
                        , public util::Observer<model::events::BenchmarkUpdatedEvent>
                        , public util::Observer<model::av::events::AVStarted>
                {
                    Q_OBJECT

                    public:
                        explicit BenchmarkingWidget(model::av::AVManager& avManager, model::Benchmark &benchmark,
                                                    const int& element, QWidget *parent = 0);
                        ~BenchmarkingWidget();

                    virtual void observableUpdated(const model::events::BenchmarkUpdatedEvent& event);
                    virtual void observableUpdated(const model::av::events::AVStarted& event);

                private slots:
                    void plot();

                signals:
                    void plotSignal();

                    private:
                        Ui::BenchmarkingWidget *ui;
                        model::Benchmark* mBenchmark;
                        model::av::AVManager* mAVManager;

                        QVector<double> mVectorTimeX;
                        QVector<double> mVectorTimeY;

                        QVector<double> mVectorFPSX;
                        QVector<double> mVectorFPSY;

                        void addPointTime(double x, double y);
                        void addPointFPS(double x, double y);
                        void clearData();

                        void initGraph();

                        double mProcessingTime;
                        int mCurrentFrames;
                        int mFPS;

                        std::mutex mMutex;

                        QTimer* mTimer;

                        static int MAX_X;
                        static int MAX_Y;
                };
            }
        }
    }
}

#endif // BENCHMARKINGWIDGET_HPP
