#include <src/view/gui/widgets/av/BackgroundSubstractorWidget.hpp>
#include "ui_BackgroundSubstractorWidget.h"
#include <iostream>
#include <src/model/av/AVTypes.hpp>

namespace src
{
    namespace view
    {
        namespace gui
        {
            namespace widgets
            {
                namespace av
                {
                    BackgroundSubstractorWidget::BackgroundSubstractorWidget(model::av::AVManager& avManager, QWidget *parent) :
                        AVWidget(avManager, parent),
                        ui(new Ui::BackgroundSubstractorWidget)
                    {
                        ui->setupUi(this);
                        double value = mAVManager->getAlgorithm(model::av::AVTypes::BACKGROUND_SUBTRACTOR)->getLearningRate();
                        mLearningRateValue = value;

                        ui->learningRateValue->setText(QString::number(value));
                        ui->learningRateSpinBox->setValue(value);
                    }

                    BackgroundSubstractorWidget::~BackgroundSubstractorWidget()
                    {
                        delete ui;
                    }

                    void BackgroundSubstractorWidget::on_learningRateSpinBox_editingFinished()
                    {
                        double value = ui->learningRateSpinBox->value();

                        if (value != mLearningRateValue)
                        {
                            ui->learningRateValue->setText(QString::number(value));
                            notify(events::ModifyBackgroundSubstractorEvent(value));
                            mLearningRateValue = value;
                        }
                    }

                }
            }
        }
    }
}


