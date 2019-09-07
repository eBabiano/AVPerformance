#ifndef OPTICALFLOWWIDGET_HPP
#define OPTICALFLOWWIDGET_HPP

#include <QWidget>
#include <src/view/gui/widgets/av/AVWidget.hpp>
#include <src/view/gui/events/ModifyOpticalFlowEvent.hpp>

namespace Ui {
class OpticalFlowWidget;
}

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
                    class OpticalFlowWidget
                           : public AVWidget
                    {
                        Q_OBJECT

                    public:
                        explicit OpticalFlowWidget(model::av::AVManager &avManager, QWidget *parent = 0);
                        ~OpticalFlowWidget();

                        virtual void setCPUGPUActivated(bool activate);


                    private slots:
                        //Good features to track
                        void on_maxCornerSpinBox_editingFinished();
                        void on_minDistSpinBox_editingFinished();
                        void on_blockSizeSpinBox_editingFinished();
                        void on_harrisCheckBox_clicked();
                        void on_kFactorSpinBox_editingFinished();

                        //TermCriteria
                        void on_countRadioButton_clicked();
                        void on_epsRadioButton_clicked();
                        void on_maxCountSpinBox_editingFinished();
                        void on_epsilonSpinBox_editingFinished();

                        void on_cpuRadioButton_toggled(bool checked);
                        void on_gpuRadioButton_toggled(bool checked);

                        void on_sizeWidthSpinBox_editingFinished();
                        void on_sizeHeightSpinBox_editingFinished();
                        void on_maxLevelsSpinBox_editingFinished();
                        void on_initialFlowRadioButton_clicked();
                        void on_eigenvalsRadioButton_clicked();
                        void on_thresholdSpinBox_editingFinished();

                    private:
                        Ui::OpticalFlowWidget *ui;
                        std::string mProcessing;

                        //Good features to track
                        int mMaxCorner;
                        double mMinDistance;
                        int mBlockSize;
                        int mHarris;
                        double mKFactor;

                        //TermCriteria
                        int mType;
                        int mMaxCount;
                        double mEpsilon;

                        //OpticalFlow
                        int mSizeWidth;
                        int mSizeHeight;
                        int mMaxLevels;
                        int mFlags;
                        double mThreshold;

                        void update();

                    };
                }
            }
        }
    }
}

#endif // OPTICALFLOWWIDGET_HPP
