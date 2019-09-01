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

                        void update();

                    };
                }
            }
        }
    }
}

#endif // OPTICALFLOWWIDGET_HPP
