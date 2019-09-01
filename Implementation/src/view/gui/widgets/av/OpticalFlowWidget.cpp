#include <src/view/gui/widgets/av/OpticalFlowWidget.hpp>
#include "ui_OpticalFlowWidget.h"
#include <src/model/av/AVTypes.hpp>
#include <src/model/av/OpticalFlowTypes.hpp>

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
                    OpticalFlowWidget::OpticalFlowWidget(model::av::AVManager &avManager, QWidget *parent) :
                        AVWidget(avManager, parent) ,
                        ui(new Ui::OpticalFlowWidget)
                      , mMaxCorner(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                                   getGoodFeaturesParameters(model::av::OpticalFlowTypes::MAX_CORNERS))
                      , mMinDistance(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                                   getGoodFeaturesParameters(model::av::OpticalFlowTypes::MIN_DISTANCE))
                      , mBlockSize(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                                   getGoodFeaturesParameters(model::av::OpticalFlowTypes::BLOCK_SIZE))
                      , mHarris(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                                   getGoodFeaturesParameters(model::av::OpticalFlowTypes::HARRIS_DETECTOR))
                      , mKFactor(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                                   getGoodFeaturesParameters(model::av::OpticalFlowTypes::K_FACTOR))
                      , mType(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                              getTermCriteriaParameters(model::av::OpticalFlowTypes::TYPE))
                      , mMaxCount(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                              getTermCriteriaParameters(model::av::OpticalFlowTypes::MAX_COUNT))
                      , mEpsilon(mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
                              getTermCriteriaParameters(model::av::OpticalFlowTypes::EPS))
                    {
                        ui->setupUi(this);

                        if (mAVManager->getAlgorithm(model::av::AVTypes::OPTICAL_FLOW)->
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

                        //Good features to track
                        ui->maxCornerSpinBox->setValue(mMaxCorner);
                        ui->minDistSpinBox->setValue(mMinDistance);
                        ui->blockSizeSpinBox->setValue(mBlockSize);
                        ui->harrisCheckBox->setChecked(mHarris);
                        ui->kFactorSpinBox->setValue(mKFactor);

                        //TermCriteria
                        ui->maxCountSpinBox->setValue(mMaxCount);
                        ui->epsilonSpinBox->setValue(mEpsilon);

                        if (mType == 1)
                        {
                            ui->countRadioButton->setChecked(true);
                        }
                        else if (mType == 2)
                        {
                            ui->epsRadioButton->setChecked(true);
                        }

                    }

                    OpticalFlowWidget::~OpticalFlowWidget()
                    {
                        delete ui;
                    }

                    void OpticalFlowWidget::on_maxCornerSpinBox_editingFinished()
                    {
                        int value = ui->maxCornerSpinBox->value();
                        if (mMaxCorner != value)
                        {
                            mMaxCorner = value;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_minDistSpinBox_editingFinished()
                    {
                        double value = ui->minDistSpinBox->value();
                        if (mMinDistance != value)
                        {
                            mMinDistance = value;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_blockSizeSpinBox_editingFinished()
                    {
                        int value = ui->blockSizeSpinBox->value();
                        if (mBlockSize != value)
                        {
                            mBlockSize = value;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_harrisCheckBox_clicked()
                    {
                        int value = ui->harrisCheckBox->isChecked();
                        if (mHarris != value)
                        {
                            mHarris = value;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_kFactorSpinBox_editingFinished()
                    {
                        double value = ui->kFactorSpinBox->value();
                        if (mKFactor != value)
                        {
                            mKFactor = value;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_countRadioButton_clicked()
                    {
                        if (mType != 1)
                        {
                            mType = 1;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_epsRadioButton_clicked()
                    {
                        if (mType != 2)
                        {
                            mType = 2;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_maxCountSpinBox_editingFinished()
                    {
                        int value = ui->maxCountSpinBox->value();
                        if (mMaxCount != value)
                        {
                            mMaxCount = value;
                            update();
                        }
                    }

                    void OpticalFlowWidget::on_epsilonSpinBox_editingFinished()
                    {
                        double value = ui->epsilonSpinBox->value();
                        if (mEpsilon != value)
                        {
                            mEpsilon = value;
                            update();
                        }
                    }

                    void OpticalFlowWidget::update()
                    {
                        std::map<std::string, double> goodFeatures;
                        goodFeatures[model::av::OpticalFlowTypes::MAX_CORNERS] = mMaxCorner;
                        goodFeatures[model::av::OpticalFlowTypes::MIN_DISTANCE] = mMinDistance;
                        goodFeatures[model::av::OpticalFlowTypes::BLOCK_SIZE] = mBlockSize;
                        goodFeatures[model::av::OpticalFlowTypes::HARRIS_DETECTOR] = mHarris;
                        goodFeatures[model::av::OpticalFlowTypes::K_FACTOR] = mKFactor;

                        std::map<std::string, double> termCriteria;
                        termCriteria[model::av::OpticalFlowTypes::TYPE] = mType;
                        termCriteria[model::av::OpticalFlowTypes::MAX_COUNT] = mMaxCount;
                        termCriteria[model::av::OpticalFlowTypes::EPS] = mEpsilon;

                        notify(events::ModifyOpticalFlowEvent(mProcessing, goodFeatures, termCriteria));
                    }


                }
            }
        }
    }
}
