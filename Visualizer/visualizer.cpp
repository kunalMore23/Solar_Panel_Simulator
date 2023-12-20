#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QInputDialog>
#include <iostream>   

Visualizer::Visualizer(QWidget* parent)
	: QMainWindow(parent)
{
	setupUi();

	connect(mStartButton, &QPushButton::clicked, this, &Visualizer::startBtn);
	connect(mStopButton, &QPushButton::clicked, this, &Visualizer::stopBtn);
	connect(mResetButton, &QPushButton::clicked, this, &Visualizer::resetBtn);
	connect(mUpdateButton, &QPushButton::clicked, this, &Visualizer::updateBtn);
	connect(mZoomSlider, &QSlider::valueChanged, this, &Visualizer::zoomSliderChanged);
}
Visualizer::~Visualizer()
{
}

void Visualizer::setupUi()
{
	resize(720, 700);
	mWidget = new QWidget(this);
	mBaseLayout = new QGridLayout(mWidget);
	mVbuttonsLayout = new QVBoxLayout();
	mButtonsLayout = new QHBoxLayout();
	mZoomSlider = new QSlider(Qt::Horizontal, mWidget);
	mRenderer = new OpenGLWindow(QColor(135.0f, 206.0f, 250.0f), mWidget);

	setCentralWidget(mWidget);
	mStartButton = new QPushButton("Start", mWidget);
	mStopButton = new QPushButton("Stop", mWidget);
	mResetButton = new QPushButton("Reset", mWidget);
	mUpdateButton = new QPushButton("Update", mWidget);
	mTimeInput = new QLineEdit(mWidget);
	mTimeInput->setPlaceholderText("Enter Minutes");

	mStartButton->setFixedWidth(140);
	mButtonsLayout->addWidget(mStartButton);
	mStopButton->setFixedWidth(140);
	mButtonsLayout->addWidget(mStopButton);
	mResetButton->setFixedWidth(140);
	mButtonsLayout->addWidget(mResetButton);
	mUpdateButton->setFixedWidth(140);
	mButtonsLayout->addWidget(mUpdateButton);
	mTimeInput->setFixedWidth(140);
	mButtonsLayout->addWidget(mTimeInput);

	mZoomSlider->setRange(0, 100);
	mZoomSlider->setValue(50);

	mVbuttonsLayout->addWidget(mRenderer, 1);
	mVbuttonsLayout->addLayout(mButtonsLayout);
	mVbuttonsLayout->addWidget(mZoomSlider);
	mBaseLayout->addLayout(mVbuttonsLayout, 0, 0);
	setWindowTitle(QCoreApplication::translate("Solar Panel Simulator", "Solar Panel Simulator", nullptr));

	//----------------------------------------------------BSpline----------------------------------------------------------------------------------------------
    mBSplinelabel1 = new QLabel(this);
    mBSplinelabel1->setObjectName("X0");
    mBSplinelabel1->setText("X0:");
    mBSplinelabel1->setGeometry(QRect(150, 10, 150, 50));

    mBSplinedoubleSpinBox1 = new QDoubleSpinBox(this);
    mBSplinedoubleSpinBox1->setObjectName("mBSplinedoubleSpinBox1");
    mBSplinedoubleSpinBox1->setGeometry(QRect(200, 20, 70, 25));
    mBSplinedoubleSpinBox1->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

    mBSplinelabel2 = new QLabel(this);
    mBSplinelabel2->setObjectName("Y0");
    mBSplinelabel2->setText("Y0:");
    mBSplinelabel2->setGeometry(QRect(300, 10, 150, 50));

    mBSplinedoubleSpinBox2 = new QDoubleSpinBox(this);
    mBSplinedoubleSpinBox2->setObjectName("mBSplinedoubleSpinBox2");
    mBSplinedoubleSpinBox2->setGeometry(QRect(350, 20, 70, 25));
    mBSplinedoubleSpinBox2->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

    mBSplinelabel3 = new QLabel(this);
    mBSplinelabel3->setObjectName("Z0");
    mBSplinelabel3->setText("Z0:");
    mBSplinelabel3->setGeometry(QRect(450, 10, 150, 50));

    mBSplinedoubleSpinBox3 = new QDoubleSpinBox(this);
    mBSplinedoubleSpinBox3->setObjectName("mdoubleSpinBox3");
    mBSplinedoubleSpinBox3->setGeometry(QRect(500, 20, 70, 25));
    mBSplinedoubleSpinBox3->setMinimum(-100.000000000000000);
    //-----------------------------------------------------------

   mBSplinelabel4 = new QLabel(this);
   mBSplinelabel4->setObjectName("X1");
   mBSplinelabel4->setText("X1:");
   mBSplinelabel4->setGeometry(QRect(150, 70, 150, 50));

   mBSplinedoubleSpinBox4 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox4->setObjectName("mdoubleSpinBox3");
   mBSplinedoubleSpinBox4->setGeometry(QRect(200, 80, 70, 25));
   mBSplinedoubleSpinBox4->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

   mBSplinelabel5 = new QLabel(this);
   mBSplinelabel5->setObjectName("Y1");
   mBSplinelabel5->setText("Y1:");
   mBSplinelabel5->setGeometry(QRect(300, 70, 150, 50));

   mBSplinedoubleSpinBox5 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox5->setObjectName("mdoubleSpinBox2");
   mBSplinedoubleSpinBox5->setGeometry(QRect(350, 80, 70, 25));
   mBSplinedoubleSpinBox5->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

   mBSplinelabel6 = new QLabel(this);
   mBSplinelabel6->setObjectName("Z1");
   mBSplinelabel6->setText("Z1:");
   mBSplinelabel6->setGeometry(QRect(450, 70, 150, 50));

   mBSplinedoubleSpinBox6 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox6->setObjectName("mdoubleSpinBox2");
   mBSplinedoubleSpinBox6->setGeometry(QRect(500, 80, 70, 25));
   mBSplinedoubleSpinBox6->setMinimum(-100.000000000000000);

    //-----------------------------------------------------------

   mBSplinelabel7 = new QLabel(this);
   mBSplinelabel7->setObjectName("X2");
   mBSplinelabel7->setText("X2:");
   mBSplinelabel7->setGeometry(QRect(150, 130, 150, 50));

   mBSplinedoubleSpinBox7 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox7->setObjectName("mdoubleSpinBox3");
   mBSplinedoubleSpinBox7->setGeometry(QRect(200, 140, 70, 25));
   mBSplinedoubleSpinBox7->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

   mBSplinelabel8 = new QLabel(this);
   mBSplinelabel8->setObjectName("Y2");
   mBSplinelabel8->setText("Y2:");
   mBSplinelabel8->setGeometry(QRect(300, 130, 150, 50));

   mBSplinedoubleSpinBox8 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox8->setObjectName("mdoubleSpinBox2");
   mBSplinedoubleSpinBox8->setGeometry(QRect(350, 140, 70, 25));
   mBSplinedoubleSpinBox8->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

   mBSplinelabel9 = new QLabel(this);
   mBSplinelabel9->setObjectName("Z2");
   mBSplinelabel9->setText("Z2:");
   mBSplinelabel9->setGeometry(QRect(450, 130, 150, 50));

   mBSplinedoubleSpinBox9 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox9->setObjectName("mdoubleSpinBox2");
   mBSplinedoubleSpinBox9->setGeometry(QRect(500, 140, 70, 25));
   mBSplinedoubleSpinBox9->setMinimum(-100.000000000000000);

    //--------------------------------------------------------------

   mBSplinelabel10 = new QLabel(this);
   mBSplinelabel10->setObjectName("X3");
   mBSplinelabel10->setText("X3:");
   mBSplinelabel10->setGeometry(QRect(150, 190, 150, 50));

   mBSplinedoubleSpinBox10 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox10->setObjectName("mdoubleSpinBox3");
   mBSplinedoubleSpinBox10->setGeometry(QRect(200, 200, 70, 25));
   mBSplinedoubleSpinBox10->setMinimum(-100.000000000000000);

    //------------------------------------------------------------

   mBSplinelabel11 = new QLabel(this);
   mBSplinelabel11->setObjectName("Y3");
   mBSplinelabel11->setText("Y3:");
   mBSplinelabel11->setGeometry(QRect(300, 190, 150, 50));

   mBSplinedoubleSpinBox11 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox11->setObjectName("mdoubleSpinBox2");
   mBSplinedoubleSpinBox11->setGeometry(QRect(350, 200, 70, 25));
   mBSplinedoubleSpinBox11->setMinimum(-100.000000000000000);
    //---------------------------------------------------------------

   mBSplinelabel12 = new QLabel(this);
   mBSplinelabel12->setObjectName("Z3");
   mBSplinelabel12->setText("Z3:");
   mBSplinelabel12->setGeometry(QRect(450, 190, 150, 50));

   mBSplinedoubleSpinBox12 = new QDoubleSpinBox(this);
   mBSplinedoubleSpinBox12->setObjectName("mdoubleSpinBox2");
   mBSplinedoubleSpinBox12->setGeometry(QRect(500, 200, 70, 25));
   mBSplinedoubleSpinBox12->setMinimum(-100.000000000000000);


   mBSplinepushButton = new QPushButton(this);
   mBSplinepushButton->setObjectName("mpushButton");
   mBSplinepushButton->setText("Bezier");
   mBSplinepushButton->setGeometry(QRect(330, 250, 100, 25));

    //--------------------------------------------------------------
   mBSplineRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
   mBSplineRenderer->setGeometry(QRect(100, 300, 600, 375));
    setWindowTitle(QCoreApplication::translate("B_Spline_Curve", "B_Spline_Curve", nullptr));


    //--------------------------------------------------------------Bezier--------------------------------------------------------------------------------

   mBezierlabel1 = new QLabel(this);
   mBezierlabel1->setObjectName("X0");
   mBezierlabel1->setText("X0:");
   mBezierlabel1->setGeometry(QRect(150, 10, 150, 50));

   mBezierdoubleSpinBox1 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox1->setObjectName("mBezierdoubleSpinBox1");
   mBezierdoubleSpinBox1->setGeometry(QRect(200, 20, 70, 25));
   mBezierdoubleSpinBox1->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

   mBezierlabel2 = new QLabel(this);
   mBezierlabel2->setObjectName("Y0");
   mBezierlabel2->setText("Y0:");
   mBezierlabel2->setGeometry(QRect(300, 10, 150, 50));

   mBezierdoubleSpinBox2 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox2->setObjectName("mBezierdoubleSpinBox2");
   mBezierdoubleSpinBox2->setGeometry(QRect(350, 20, 70, 25));
   mBezierdoubleSpinBox2->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

   mBezierlabel3 = new QLabel(this);
   mBezierlabel3->setObjectName("Z0");
   mBezierlabel3->setText("Z0:");
   mBezierlabel3->setGeometry(QRect(450, 10, 150, 50));

   mBezierdoubleSpinBox3 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox3->setObjectName("mBezierdoubleSpinBox3");
   mBezierdoubleSpinBox3->setGeometry(QRect(500, 20, 70, 25));
   mBezierdoubleSpinBox3->setMinimum(-100.000000000000000);
    //-----------------------------------------------------------

   mBezierlabel4 = new QLabel(this);
   mBezierlabel4->setObjectName("X1");
   mBezierlabel4->setText("X1:");
   mBezierlabel4->setGeometry(QRect(150, 70, 150, 50));

   mBezierdoubleSpinBox4 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox4->setObjectName("mBezierdoubleSpinBox3");
   mBezierdoubleSpinBox4->setGeometry(QRect(200, 80, 70, 25));
   mBezierdoubleSpinBox4->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

   mBezierlabel5 = new QLabel(this);
   mBezierlabel5->setObjectName("Y1");
   mBezierlabel5->setText("Y1:");
   mBezierlabel5->setGeometry(QRect(300, 70, 150, 50));

   mBezierdoubleSpinBox5 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox5->setObjectName("mBezierdoubleSpinBox2");
   mBezierdoubleSpinBox5->setGeometry(QRect(350, 80, 70, 25));
   mBezierdoubleSpinBox5->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

   mBezierlabel6 = new QLabel(this);
   mBezierlabel6->setObjectName("Z1");
   mBezierlabel6->setText("Z1:");
   mBezierlabel6->setGeometry(QRect(450, 70, 150, 50));

   mBezierdoubleSpinBox6 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox6->setObjectName("mBezierdoubleSpinBox2");
   mBezierdoubleSpinBox6->setGeometry(QRect(500, 80, 70, 25));
   mBezierdoubleSpinBox6->setMinimum(-100.000000000000000);

    //-----------------------------------------------------------

   mBezierlabel7 = new QLabel(this);
   mBezierlabel7->setObjectName("X2");
   mBezierlabel7->setText("X2:");
   mBezierlabel7->setGeometry(QRect(150, 130, 150, 50));

   mBezierdoubleSpinBox7 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox7->setObjectName("mBezierdoubleSpinBox3");
   mBezierdoubleSpinBox7->setGeometry(QRect(200, 140, 70, 25));
   mBezierdoubleSpinBox7->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

   mBezierlabel8 = new QLabel(this);
   mBezierlabel8->setObjectName("Y2");
   mBezierlabel8->setText("Y2:");
   mBezierlabel8->setGeometry(QRect(300, 130, 150, 50));

   mBezierdoubleSpinBox8 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox8->setObjectName("mBezierdoubleSpinBox2");
   mBezierdoubleSpinBox8->setGeometry(QRect(350, 140, 70, 25));
   mBezierdoubleSpinBox8->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

   mBezierlabel9 = new QLabel(this);
   mBezierlabel9->setObjectName("Z2");
   mBezierlabel9->setText("Z2:");
   mBezierlabel9->setGeometry(QRect(450, 130, 150, 50));

   mBezierdoubleSpinBox9 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox9->setObjectName("mBezierdoubleSpinBox2");
   mBezierdoubleSpinBox9->setGeometry(QRect(500, 140, 70, 25));
   mBezierdoubleSpinBox9->setMinimum(-100.000000000000000);

    //--------------------------------------------------------------

   mBezierlabel10 = new QLabel(this);
   mBezierlabel10->setObjectName("X3");
   mBezierlabel10->setText("X3:");
   mBezierlabel10->setGeometry(QRect(150, 190, 150, 50));

   mBezierdoubleSpinBox10 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox10->setObjectName("mBezierdoubleSpinBox3");
   mBezierdoubleSpinBox10->setGeometry(QRect(200, 200, 70, 25));
   mBezierdoubleSpinBox10->setMinimum(-100.000000000000000);

    //------------------------------------------------------------

   mBezierlabel11 = new QLabel(this);
   mBezierlabel11->setObjectName("Y3");
   mBezierlabel11->setText("Y3:");
   mBezierlabel11->setGeometry(QRect(300, 190, 150, 50));

   mBezierdoubleSpinBox11 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox11->setObjectName("mBezierdoubleSpinBox2");
   mBezierdoubleSpinBox11->setGeometry(QRect(350, 200, 70, 25));
   mBezierdoubleSpinBox11->setMinimum(-100.000000000000000);
    //---------------------------------------------------------------

   mBezierlabel12 = new QLabel(this);
   mBezierlabel12->setObjectName("Z3");
   mBezierlabel12->setText("Z3:");
   mBezierlabel12->setGeometry(QRect(450, 190, 150, 50));

   mBezierdoubleSpinBox12 = new QDoubleSpinBox(this);
   mBezierdoubleSpinBox12->setObjectName("mBezierdoubleSpinBox2");
   mBezierdoubleSpinBox12->setGeometry(QRect(500, 200, 70, 25));
   mBezierdoubleSpinBox12->setMinimum(-100.000000000000000);


   mBezierpushButton = new QPushButton(this);
   mBezierpushButton->setObjectName("mBezierpushButton");
   mBezierpushButton->setText("Bezier");
   mBezierpushButton->setGeometry(QRect(330, 250, 100, 25));

    //--------------------------------------------------------------
   mBezierRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
   mBezierRenderer->setGeometry(QRect(100, 300, 600, 375));
    setWindowTitle(QCoreApplication::translate("Bezier_Curve", "Bezier_Curve", nullptr));



    //--------------------------------------------------------------------------------Hermite-----------------------------------------------------------------------------------
   mHermitelabel1 = new QLabel(this);
   mHermitelabel1->setObjectName("X0");
   mHermitelabel1->setText("X0:");
   mHermitelabel1->setGeometry(QRect(150, 10, 150, 50));

   mHermitedoubleSpinBox1 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox1->setObjectName("mHermitedoubleSpinBox1");
   mHermitedoubleSpinBox1->setGeometry(QRect(200, 20, 70, 25));
   mHermitedoubleSpinBox1->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

   mHermitelabel2 = new QLabel(this);
   mHermitelabel2->setObjectName("Y0");
   mHermitelabel2->setText("Y0:");
   mHermitelabel2->setGeometry(QRect(300, 10, 150, 50));

   mHermitedoubleSpinBox2 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox2->setObjectName("mHermitedoubleSpinBox2");
   mHermitedoubleSpinBox2->setGeometry(QRect(350, 20, 70, 25));
   mHermitedoubleSpinBox2->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

   mHermitelabel3 = new QLabel(this);
   mHermitelabel3->setObjectName("Z0");
   mHermitelabel3->setText("Z0:");
   mHermitelabel3->setGeometry(QRect(450, 10, 150, 50));

   mHermitedoubleSpinBox3 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox3->setObjectName("mHermitedoubleSpinBox3");
   mHermitedoubleSpinBox3->setGeometry(QRect(500, 20, 70, 25));
   mHermitedoubleSpinBox3->setMinimum(-100.000000000000000);
    //-----------------------------------------------------------

   mHermitelabel4 = new QLabel(this);
   mHermitelabel4->setObjectName("X1");
   mHermitelabel4->setText("X1:");
   mHermitelabel4->setGeometry(QRect(150, 70, 150, 50));

   mHermitedoubleSpinBox4 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox4->setObjectName("mHermitedoubleSpinBox3");
   mHermitedoubleSpinBox4->setGeometry(QRect(200, 80, 70, 25));
   mHermitedoubleSpinBox4->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

   mHermitelabel5 = new QLabel(this);
   mHermitelabel5->setObjectName("Y1");
   mHermitelabel5->setText("Y1:");
   mHermitelabel5->setGeometry(QRect(300, 70, 150, 50));

   mHermitedoubleSpinBox5 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox5->setObjectName("mHermitedoubleSpinBox2");
   mHermitedoubleSpinBox5->setGeometry(QRect(350, 80, 70, 25));
   mHermitedoubleSpinBox5->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

   mHermitelabel6 = new QLabel(this);
   mHermitelabel6->setObjectName("Z1");
   mHermitelabel6->setText("Z1:");
   mHermitelabel6->setGeometry(QRect(450, 70, 150, 50));

   mHermitedoubleSpinBox6 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox6->setObjectName("mHermitedoubleSpinBox2");
   mHermitedoubleSpinBox6->setGeometry(QRect(500, 80, 70, 25));
   mHermitedoubleSpinBox6->setMinimum(-100.000000000000000);

    //-----------------------------------------------------------

   mHermitelabel7 = new QLabel(this);
   mHermitelabel7->setObjectName("X2");
   mHermitelabel7->setText("X2:");
   mHermitelabel7->setGeometry(QRect(150, 130, 150, 50));

   mHermitedoubleSpinBox7 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox7->setObjectName("mHermitedoubleSpinBox3");
   mHermitedoubleSpinBox7->setGeometry(QRect(200, 140, 70, 25));
   mHermitedoubleSpinBox7->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

   mHermitelabel8 = new QLabel(this);
   mHermitelabel8->setObjectName("Y2");
   mHermitelabel8->setText("Y2:");
   mHermitelabel8->setGeometry(QRect(300, 130, 150, 50));

   mHermitedoubleSpinBox8 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox8->setObjectName("mHermitedoubleSpinBox2");
   mHermitedoubleSpinBox8->setGeometry(QRect(350, 140, 70, 25));
   mHermitedoubleSpinBox8->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

   mHermitelabel9 = new QLabel(this);
   mHermitelabel9->setObjectName("Z2");
   mHermitelabel9->setText("Z2:");
   mHermitelabel9->setGeometry(QRect(450, 130, 150, 50));

   mHermitedoubleSpinBox9 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox9->setObjectName("mHermitedoubleSpinBox2");
   mHermitedoubleSpinBox9->setGeometry(QRect(500, 140, 70, 25));
   mHermitedoubleSpinBox9->setMinimum(-100.000000000000000);

    //--------------------------------------------------------------

   mHermitelabel10 = new QLabel(this);
   mHermitelabel10->setObjectName("X3");
   mHermitelabel10->setText("X3:");
   mHermitelabel10->setGeometry(QRect(150, 190, 150, 50));

   mHermitedoubleSpinBox10 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox10->setObjectName("mHermitedoubleSpinBox3");
   mHermitedoubleSpinBox10->setGeometry(QRect(200, 200, 70, 25));
   mHermitedoubleSpinBox10->setMinimum(-100.000000000000000);

    //------------------------------------------------------------

   mHermitelabel11 = new QLabel(this);
   mHermitelabel11->setObjectName("Y3");
   mHermitelabel11->setText("Y3:");
   mHermitelabel11->setGeometry(QRect(300, 190, 150, 50));

   mHermitedoubleSpinBox11 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox11->setObjectName("mHermitedoubleSpinBox2");
   mHermitedoubleSpinBox11->setGeometry(QRect(350, 200, 70, 25));
   mHermitedoubleSpinBox11->setMinimum(-100.000000000000000);
    //---------------------------------------------------------------

   mHermitelabel12 = new QLabel(this);
   mHermitelabel12->setObjectName("Z3");
   mHermitelabel12->setText("Z3:");
   mHermitelabel12->setGeometry(QRect(450, 190, 150, 50));

   mHermitedoubleSpinBox12 = new QDoubleSpinBox(this);
   mHermitedoubleSpinBox12->setObjectName("mHermitedoubleSpinBox2");
   mHermitedoubleSpinBox12->setGeometry(QRect(500, 200, 70, 25));
   mHermitedoubleSpinBox12->setMinimum(-100.000000000000000);


   mHermitepushButton = new QPushButton(this);
   mHermitepushButton->setObjectName("mHermitepushButton");
   mHermitepushButton->setText("Hermite");
   mHermitepushButton->setGeometry(QRect(330, 250, 100, 25));

    //--------------------------------------------------------------
   mHermiteRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
   mHermiteRenderer->setGeometry(QRect(100, 300, 600, 375));
    setWindowTitle(QCoreApplication::translate("Hermite_Curve", "Hermite_Curve", nullptr));
}

void Visualizer::zoomSliderChanged(float value)
{
	float zoomFactor = 0.5f + (value / 25.0f) * 1.5f;
	mRenderer->setMultiplier(zoomFactor);
}

void Visualizer::startBtn()
{
	mRenderer->startRevolving();
}

void Visualizer::stopBtn()
{
	mRenderer->stopRevolving();
}

void Visualizer::resetBtn()
{
	mRenderer->resetPositions();
}

void Visualizer::updateBtn()
{
	bool ok;
	float numberOfDays = mTimeInput->text().toInt(&ok);

	if (ok)
	{
		mRenderer->updatePositions(numberOfDays);
	}
}