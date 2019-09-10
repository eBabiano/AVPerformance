#include <src/view/gui/widgets/av/PedestrianDetectorWidget.hpp>
#include "ui_PedestrianDetectorWidget.h"
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
                    PedestrianDetectorWidget::PedestrianDetectorWidget(model::av::AVManager &avManager, QWidget *parent) :
                        AVWidget(avManager, parent) ,
                        ui(new Ui::PedestrianDetectorWidget)
                      , mHitThreshold(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getHitThreshold())
                      , mWindStrideWidth(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getWindStrideWidth())
                      , mWindStrideHeight(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getWindStrideHeight())
                      , mPaddingWidth(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getPaddingWidth())
                      , mPaddingHeight(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getPaddingHeight())
                      , mScale(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getScale())
                      , mFinalThreshold(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getFinalThreshold())
                      , mUseMeanShiftGrouping(mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->getUseMeanShiftGrouping())
                    {
                        ui->setupUi(this);

                        if (mAVManager->getAlgorithm(model::av::AVTypes::PEDESTRIAN_DETECTOR)->
                                getProcessorType() == model::av::AVTypes::CPU)
                        {
                            ui->cpuRadioButton->setChecked(true);
                            mProcessing = model::av::AVTypes::CPU;
                        }
                        else
                        {
                            ui->gpuRadioButton->setChecked(true);
                            mProcessing = model::av::AVTypes::GPU;
                        }

                        ui->hitThresholdSpinBox->setValue(mHitThreshold);
                        ui->strideWidthSpinBox->setValue(mWindStrideWidth);
                        ui->strideHeightSpinBox->setValue(mWindStrideHeight);
                        ui->paddingWithSpinBox->setValue(mPaddingWidth);
                        ui->paddingHeightSpinBox->setValue(mPaddingHeight);
                        ui->scaleSpinBox->setValue(mScale);
                        ui->finalThresholdSpinBox->setValue(mFinalThreshold);
                        ui->meanShiftCheckBox->setChecked(mUseMeanShiftGrouping);
                    }

                    PedestrianDetectorWidget::~PedestrianDetectorWidget()
                    {
                        delete ui;
                    }

                    void PedestrianDetectorWidget::setCPUGPUActivated(bool activate)
                    {
                        ui->cpuRadioButton->setEnabled(activate);
                        ui->gpuRadioButton->setEnabled(activate);
                    }

                    void PedestrianDetectorWidget::on_cpuRadioButton_toggled(bool checked)
                    {
                        ui->gpuRadioButton->setChecked(false);
                        mProcessing = model::av::AVTypes::CPU;

                        ui->strideWidthSpinBox->setEnabled(true);
                        ui->strideHeightSpinBox->setEnabled(true);
                        ui->paddingWithSpinBox->setEnabled(true);
                        ui->paddingHeightSpinBox->setEnabled(true);
                        ui->finalThresholdSpinBox->setEnabled(true);
                        ui->meanShiftCheckBox->setEnabled(true);

                        update();
                    }

                    void PedestrianDetectorWidget::on_gpuRadioButton_toggled(bool checked)
                    {
                        ui->cpuRadioButton->setChecked(false);
                        mProcessing = model::av::AVTypes::GPU;

                        ui->strideWidthSpinBox->setEnabled(false);
                        ui->strideHeightSpinBox->setEnabled(false);
                        ui->paddingWithSpinBox->setEnabled(false);
                        ui->paddingHeightSpinBox->setEnabled(false);
                        ui->finalThresholdSpinBox->setEnabled(false);
                        ui->meanShiftCheckBox->setEnabled(false);

                        update();
                    }

                    void PedestrianDetectorWidget::on_hitThresholdSpinBox_editingFinished()
                    {
                        double value = ui->hitThresholdSpinBox->value();
                        if (value != mHitThreshold)
                        {
                            mHitThreshold = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::on_strideWidthSpinBox_editingFinished()
                    {
                        int value = ui->strideWidthSpinBox->value();
                        if (value != mWindStrideWidth)
                        {
                            mWindStrideWidth = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::on_strideHeightSpinBox_editingFinished()
                    {
                        int value = ui->strideHeightSpinBox->value();
                        if (value != mWindStrideHeight)
                        {
                            mWindStrideHeight = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::on_paddingWithSpinBox_editingFinished()
                    {
                        int value = ui->paddingWithSpinBox->value();
                        if (value != mPaddingWidth)
                        {
                            mPaddingWidth = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::on_paddingHeightSpinBox_editingFinished()
                    {
                        int value = ui->paddingHeightSpinBox->value();
                        if (value != mPaddingHeight)
                        {
                            mPaddingHeight = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::on_scaleSpinBox_editingFinished()
                    {
                        double value = ui->scaleSpinBox->value();
                        if (value != mScale)
                        {
                            mScale = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::on_finalThresholdSpinBox_editingFinished()
                    {
                        double value = ui->finalThresholdSpinBox->value();
                        if (value != mFinalThreshold)
                        {
                            mFinalThreshold = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::on_meanShiftCheckBox_clicked()
                    {
                        int value = ui->meanShiftCheckBox->isChecked();
                        if (value != mUseMeanShiftGrouping)
                        {
                            mUseMeanShiftGrouping = value;
                            update();
                        }
                    }

                    void PedestrianDetectorWidget::update()
                    {
                        notify(events::ModifyPedestrianDetectorEvent(mProcessing, mHitThreshold, mWindStrideWidth, mWindStrideHeight,
                                                                     mPaddingWidth, mPaddingHeight, mScale, mFinalThreshold, mUseMeanShiftGrouping));
                    }

                }
            }
        }
    }
}
