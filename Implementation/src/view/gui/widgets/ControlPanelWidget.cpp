#include <src/view/gui/widgets/ControlPanelWidget.hpp>
#include "ui_ControlPanelWidget.h"

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                ControlPanelWidget::ControlPanelWidget(const model::av::AVManager& model, const int &element, QWidget *parent) :
                    QWidget(parent),
                    ui(new Ui::ControlPanelWidget)
                  , Container(element)
                  , mIsRunning(false)
                {
                    ui->setupUi(this);

                 //   startTimer(0);
                 //   mTime = new QTime();
                }

                ControlPanelWidget::~ControlPanelWidget()
                {
                    delete ui;
                }

                void ControlPanelWidget::timerEvent(QTimerEvent *event)
                {
                    if (mIsRunning)
                    {
                   //     ui->minLabel->setText(QDateTime::fromTime_t(10).toUTC().toString("hh:mm:ss"));
                   //     ui->secLabel->setText(std::to_string(mTime->elapsed()).c_str());
                    }
                }

                void ControlPanelWidget::on_playButton_clicked()
                {
                    if (!mIsRunning)
                    {
                        ui->playButton->setEnabled(false);
                        ui->stopButton->setEnabled(true);
                        notify(events::StartAVEvent(true));
                    //    mTime->restart();
                        mIsRunning = true;
                    }
                }

                void ControlPanelWidget::on_stopButton_clicked()
                {
                    if (mIsRunning)
                    {
                        ui->playButton->setEnabled(true);
                        ui->stopButton->setEnabled(false);
                        notify(events::StartAVEvent(false));
                        mIsRunning = false;
                    }
                }
            }
        }
    }
}
