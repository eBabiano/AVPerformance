#include <src/view/gui/widgets/av/FaceDetectionWidget.hpp>
#include "ui_FaceDetectionWidget.h"
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
                    FaceDetectionWidget::FaceDetectionWidget(model::av::AVManager &avManager, QWidget *parent) :
                        AVWidget(avManager, parent)
                        , ui(new Ui::FaceDetectionWidget)
                        , mScaleFactor(mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getScaleFactor())
                        , mNeightbors(mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getNeightbors())
                        , mWidth(mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getWidth())
                        , mHeight(mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->getHeight())
                    {
                        ui->setupUi(this);

                        if (mAVManager->getAlgorithm(model::av::AVTypes::FACE_DETECTION)->
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

                        ui->scaleFactorSpinBox->setValue(mScaleFactor);
                        ui->neighborsSpinBox->setValue(mNeightbors);
                        ui->sizeWidthSpinBox->setValue(mWidth);
                        ui->sizeHeightSpinBox->setValue(mHeight);
                    }

                    FaceDetectionWidget::~FaceDetectionWidget()
                    {
                        delete ui;
                    }

                    void FaceDetectionWidget::setCPUGPUActivated(bool activate)
                    {
                        ui->cpuRadioButton->setEnabled(activate);
                        ui->gpuRadioButton->setEnabled(activate);
                    }

                    void FaceDetectionWidget::on_cpuRadioButton_toggled(bool checked)
                    {
                        ui->gpuRadioButton->setChecked(false);

                        mProcessing = model::av::AVTypes::CPU;
                        update();
                    }

                    void FaceDetectionWidget::on_gpuRadioButton_toggled(bool checked)
                    {
                        ui->cpuRadioButton->setChecked(false);

                        mProcessing = model::av::AVTypes::GPU;
                        update();
                    }

                    void FaceDetectionWidget::on_scaleFactorSpinBox_editingFinished()
                    {
                        double value = ui->scaleFactorSpinBox->value();
                        if (mScaleFactor != value)
                        {
                            mScaleFactor = ui->scaleFactorSpinBox->value();
                            update();
                        }
                    }

                    void FaceDetectionWidget::on_neighborsSpinBox_editingFinished()
                    {
                        double value = ui->neighborsSpinBox->value();
                        if (value != mNeightbors)
                        {
                            mNeightbors = ui->neighborsSpinBox->value();
                            update();
                        }
                    }

                    void FaceDetectionWidget::on_sizeWidthSpinBox_editingFinished()
                    {
                        double value = ui->neighborsSpinBox->value();
                        if (value != mWidth)
                        {
                            mWidth = ui->sizeWidthSpinBox->value();
                            update();
                        }
                    }

                    void FaceDetectionWidget::on_sizeHeightSpinBox_editingFinished()
                    {
                        double value = ui->neighborsSpinBox->value();
                        if (value != mHeight)
                        {
                            mHeight = ui->sizeHeightSpinBox->value();
                            update();
                        }
                    }

                    void FaceDetectionWidget::update()
                    {
                        notify(events::ModifyFaceDetectionEvent(mProcessing, mScaleFactor, mNeightbors, mWidth, mHeight));
                    }

                }
            }
        }
    }
}
