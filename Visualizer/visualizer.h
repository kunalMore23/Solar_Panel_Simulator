#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTimer>

class OpenGLWindow;

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWidget* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();

//---------------------------------------------------------Solar Panel-------------------------------------------------------------

private slots:
    void startBtn();
    void stopBtn();
    void resetBtn();
    void updateBtn();
    void zoomSliderChanged(float value);

private:
    QGridLayout* mBaseLayout;
    QVBoxLayout* mVbuttonsLayout;
    QHBoxLayout* mButtonsLayout;

    QPushButton* mStartButton;
    QPushButton* mStopButton;
    QPushButton* mResetButton;
    QPushButton* mUpdateButton;

    QLineEdit* mTimeInput;
    QTimer* mTimer;
    QWidget* mWidget;

    QWidget* mCentralWidget;
    OpenGLWindow* mRenderer;
    QSlider* mZoomSlider;

    //---------------------------------------------Bezier--------------------------------
private:
    OpenGLWindow* mBezierRenderer;

    QLabel* mBezierlabel1;
    QLabel* mBezierlabel2;
    QLabel* mBezierlabel3;
    QLabel* mBezierlabel4;
    QLabel* mBezierlabel5;
    QLabel* mBezierlabel6;
    QLabel* mBezierlabel7;
    QLabel* mBezierlabel8;
    QLabel* mBezierlabel9;
    QLabel* mBezierlabel10;
    QLabel* mBezierlabel11;
    QLabel* mBezierlabel12;

    QDoubleSpinBox* mBezierdoubleSpinBox1;
    QDoubleSpinBox* mBezierdoubleSpinBox2;
    QDoubleSpinBox* mBezierdoubleSpinBox3;
    QDoubleSpinBox* mBezierdoubleSpinBox4;
    QDoubleSpinBox* mBezierdoubleSpinBox5;
    QDoubleSpinBox* mBezierdoubleSpinBox6;
    QDoubleSpinBox* mBezierdoubleSpinBox7;
    QDoubleSpinBox* mBezierdoubleSpinBox8;
    QDoubleSpinBox* mBezierdoubleSpinBox9;
    QDoubleSpinBox* mBezierdoubleSpinBox10;
    QDoubleSpinBox* mBezierdoubleSpinBox11;
    QDoubleSpinBox* mBezierdoubleSpinBox12;

    QPushButton* mBezierpushButton;

    //--------------------------------------------------BSpline---------------------------------------------------
    OpenGLWindow* mBSplineRenderer;

    QLabel* mBSplinelabel1;
    QLabel* mBSplinelabel2;
    QLabel* mBSplinelabel3;
    QLabel* mBSplinelabel4;
    QLabel* mBSplinelabel5;
    QLabel* mBSplinelabel6;
    QLabel* mBSplinelabel7;
    QLabel* mBSplinelabel8;
    QLabel* mBSplinelabel9;
    QLabel* mBSplinelabel10;
    QLabel* mBSplinelabel11;
    QLabel* mBSplinelabel12;

    QDoubleSpinBox* mBSplinedoubleSpinBox1;
    QDoubleSpinBox* mBSplinedoubleSpinBox2;
    QDoubleSpinBox* mBSplinedoubleSpinBox3;
    QDoubleSpinBox* mBSplinedoubleSpinBox4;
    QDoubleSpinBox* mBSplinedoubleSpinBox5;
    QDoubleSpinBox* mBSplinedoubleSpinBox6;
    QDoubleSpinBox* mBSplinedoubleSpinBox7;
    QDoubleSpinBox* mBSplinedoubleSpinBox8;
    QDoubleSpinBox* mBSplinedoubleSpinBox9;
    QDoubleSpinBox* mBSplinedoubleSpinBox10;
    QDoubleSpinBox* mBSplinedoubleSpinBox11;
    QDoubleSpinBox* mBSplinedoubleSpinBox12;

    QPushButton* mBSplinepushButton;
    //------------------------------------------------------Hermite-----------------------------------------------------------
    OpenGLWindow* mHermiteRenderer;

    QLabel* mHermitelabel1;
    QLabel* mHermitelabel2;
    QLabel* mHermitelabel3;
    QLabel* mHermitelabel4;
    QLabel* mHermitelabel5;
    QLabel* mHermitelabel6;
    QLabel* mHermitelabel7;
    QLabel* mHermitelabel8;
    QLabel* mHermitelabel9;
    QLabel* mHermitelabel10;
    QLabel* mHermitelabel11;
    QLabel* mHermitelabel12;

    QDoubleSpinBox* mHermitedoubleSpinBox1;
    QDoubleSpinBox* mHermitedoubleSpinBox2;
    QDoubleSpinBox* mHermitedoubleSpinBox3;
    QDoubleSpinBox* mHermitedoubleSpinBox4;
    QDoubleSpinBox* mHermitedoubleSpinBox5;
    QDoubleSpinBox* mHermitedoubleSpinBox6;
    QDoubleSpinBox* mHermitedoubleSpinBox7;
    QDoubleSpinBox* mHermitedoubleSpinBox8;
    QDoubleSpinBox* mHermitedoubleSpinBox9;
    QDoubleSpinBox* mHermitedoubleSpinBox10;
    QDoubleSpinBox* mHermitedoubleSpinBox11;
    QDoubleSpinBox* mHermitedoubleSpinBox12;

    QPushButton* mHermitepushButton;
};