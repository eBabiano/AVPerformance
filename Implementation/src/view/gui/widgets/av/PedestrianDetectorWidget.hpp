#ifndef PEDESTRIANDETECTORWIDGET_HPP
#define PEDESTRIANDETECTORWIDGET_HPP

#include <QWidget>
#include <src/view/gui/widgets/av/AVWidget.hpp>

namespace Ui {
class PedestrianDetectorWidget;
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
                    class PedestrianDetectorWidget
                            : public AVWidget
                    {
                        Q_OBJECT
                    public:
                        explicit PedestrianDetectorWidget(model::av::AVManager& avManager, QWidget *parent = 0);
                        ~PedestrianDetectorWidget();

                        virtual void setCPUGPUActivated(bool activate);

                    private slots:
                        void on_cpuRadioButton_toggled(bool checked);
                        void on_gpuRadioButton_toggled(bool checked);

                        void on_hitThresholdSpinBox_editingFinished();

                        void on_strideWidthSpinBox_editingFinished();

                        void on_strideHeightSpinBox_editingFinished();

                        void on_paddingWithSpinBox_editingFinished();

                        void on_paddingHeightSpinBox_editingFinished();

                        void on_scaleSpinBox_editingFinished();

                        void on_finalThresholdSpinBox_editingFinished();

                        void on_meanShiftCheckBox_clicked();

                    private:
                        Ui::PedestrianDetectorWidget *ui;

                        double mHitThreshold;
                        int mWindStrideWidth;
                        int mWindStrideHeight;
                        int mPaddingWidth;
                        int mPaddingHeight;
                        double mScale;
                        double mFinalThreshold;
                        int mUseMeanShiftGrouping;
                        std::string mProcessing;

                        void update();

                    };
                }
            }
        }
    }
}

#endif // PEDESTRIANDETECTORWIDGET_HPP
