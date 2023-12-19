#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mpushButton, &QPushButton::clicked, this, &Visualizer::bezierClicked);
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi() {
    resize(800, 600);

    mlabel1 = new QLabel(this);
    mlabel1->setObjectName("X0");
    mlabel1->setText("X0:");
    mlabel1->setGeometry(QRect(150, 10, 150, 50));

    mdoubleSpinBox1 = new QDoubleSpinBox(this);
    mdoubleSpinBox1->setObjectName("mdoubleSpinBox1");
    mdoubleSpinBox1->setGeometry(QRect(200, 20, 70, 25));
    mdoubleSpinBox1->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

    mlabel2 = new QLabel(this);
    mlabel2->setObjectName("Y0");
    mlabel2->setText("Y0:");
    mlabel2->setGeometry(QRect(300, 10, 150, 50));

    mdoubleSpinBox2 = new QDoubleSpinBox(this);
    mdoubleSpinBox2->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBox2->setGeometry(QRect(350, 20, 70, 25));
    mdoubleSpinBox2->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

    mlabel3 = new QLabel(this);
    mlabel3->setObjectName("Z0");
    mlabel3->setText("Z0:");
    mlabel3->setGeometry(QRect(450, 10, 150, 50));

    mdoubleSpinBox3 = new QDoubleSpinBox(this);
    mdoubleSpinBox3->setObjectName("mdoubleSpinBox3");
    mdoubleSpinBox3->setGeometry(QRect(500, 20, 70, 25));
    mdoubleSpinBox3->setMinimum(-100.000000000000000);

    //-----------------------------------------------------------

    mlabel4 = new QLabel(this);
    mlabel4->setObjectName("X1");
    mlabel4->setText("X1:");
    mlabel4->setGeometry(QRect(150, 70, 150, 50));

    mdoubleSpinBox4 = new QDoubleSpinBox(this);
    mdoubleSpinBox4->setObjectName("mdoubleSpinBox3");
    mdoubleSpinBox4->setGeometry(QRect(200, 80, 70, 25));
    mdoubleSpinBox4->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

    mlabel5 = new QLabel(this);
    mlabel5->setObjectName("Y1");
    mlabel5->setText("Y1:");
    mlabel5->setGeometry(QRect(300, 70, 150, 50));

    mdoubleSpinBox5 = new QDoubleSpinBox(this);
    mdoubleSpinBox5->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBox5->setGeometry(QRect(350, 80, 70, 25));
    mdoubleSpinBox5->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

    mlabel6 = new QLabel(this);
    mlabel6->setObjectName("Z1");
    mlabel6->setText("Z1:");
    mlabel6->setGeometry(QRect(450, 70, 150, 50));

    mdoubleSpinBox6 = new QDoubleSpinBox(this);
    mdoubleSpinBox6->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBox6->setGeometry(QRect(500, 80, 70, 25));
    mdoubleSpinBox6->setMinimum(-100.000000000000000);

    //-----------------------------------------------------------

    mlabel7 = new QLabel(this);
    mlabel7->setObjectName("X2");
    mlabel7->setText("X2:");
    mlabel7->setGeometry(QRect(150, 130, 150, 50));

    mdoubleSpinBox7 = new QDoubleSpinBox(this);
    mdoubleSpinBox7->setObjectName("mdoubleSpinBox3");
    mdoubleSpinBox7->setGeometry(QRect(200, 140, 70, 25));
    mdoubleSpinBox7->setMinimum(-100.000000000000000);
    //------------------------------------------------------------

    mlabel8 = new QLabel(this);
    mlabel8->setObjectName("Y2");
    mlabel8->setText("Y2:");
    mlabel8->setGeometry(QRect(300, 130, 150, 50));

    mdoubleSpinBox8 = new QDoubleSpinBox(this);
    mdoubleSpinBox8->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBox8->setGeometry(QRect(350, 140, 70, 25));
    mdoubleSpinBox8->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------

    mlabel9 = new QLabel(this);
    mlabel9->setObjectName("Z2");
    mlabel9->setText("Z2:");
    mlabel9->setGeometry(QRect(450, 130, 150, 50));

    mdoubleSpinBox9 = new QDoubleSpinBox(this);
    mdoubleSpinBox9->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBox9->setGeometry(QRect(500, 140, 70, 25));
    mdoubleSpinBox9->setMinimum(-100.000000000000000);

    //--------------------------------------------------------------

    mlabel10 = new QLabel(this);
    mlabel10->setObjectName("X3");
    mlabel10->setText("X3:");
    mlabel10->setGeometry(QRect(150, 190, 150, 50));

    mdoubleSpinBox10 = new QDoubleSpinBox(this);
    mdoubleSpinBox10->setObjectName("mdoubleSpinBox3");
    mdoubleSpinBox10->setGeometry(QRect(200, 200, 70, 25));
    mdoubleSpinBox10->setMinimum(-100.000000000000000);

    //------------------------------------------------------------

    mlabel11 = new QLabel(this);
    mlabel11->setObjectName("Y3");
    mlabel11->setText("Y3:");
    mlabel11->setGeometry(QRect(300, 190, 150, 50));

    mdoubleSpinBox11 = new QDoubleSpinBox(this);
    mdoubleSpinBox11->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBox11->setGeometry(QRect(350, 200, 70, 25));
    mdoubleSpinBox11->setMinimum(-100.000000000000000);
    //---------------------------------------------------------------

    mlabel12 = new QLabel(this);
    mlabel12->setObjectName("Z3");
    mlabel12->setText("Z3:");
    mlabel12->setGeometry(QRect(450, 190, 150, 50));

    mdoubleSpinBox12 = new QDoubleSpinBox(this);
    mdoubleSpinBox12->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBox12->setGeometry(QRect(500, 200, 70, 25));
    mdoubleSpinBox12->setMinimum(-100.000000000000000);


    mpushButton = new QPushButton(this);
    mpushButton->setObjectName("mpushButton");
    mpushButton->setText("Bezier");
    mpushButton->setGeometry(QRect(330, 250, 100, 25));

    //--------------------------------------------------------------
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(100, 300, 600, 375));
    setWindowTitle(QCoreApplication::translate("Sutherland_Cohen", "Sutherland_Cohen", nullptr));
}




void Visualizer::bezierClicked()
{
    double x0Coordinate = mdoubleSpinBox1->value();
    double y0Coordinate = mdoubleSpinBox2->value();
    double z0Coordinate = mdoubleSpinBox2->value();

    double x1Coordinate = mdoubleSpinBox4->value();
    double y1Coordinate = mdoubleSpinBox5->value();
    double z1Coordinate = mdoubleSpinBox6->value();

    double x2Coordinate = mdoubleSpinBox7->value();
    double y2Coordinate = mdoubleSpinBox8->value();
    double z2Coordinate = mdoubleSpinBox9->value();

    double x3Coordinate = mdoubleSpinBox10->value();
    double y3Coordinate = mdoubleSpinBox11->value();
    double z3Coordinate = mdoubleSpinBox12->value();

    Point3D p0 = Point3D(x0Coordinate, y0Coordinate, z0Coordinate);
    Point3D p1 = Point3D(x1Coordinate, y1Coordinate, z1Coordinate);
    Point3D p2 = Point3D(x2Coordinate, y2Coordinate, z2Coordinate);
    Point3D p3 = Point3D(x3Coordinate, y3Coordinate, z3Coordinate);

    Bezier bezier(p0, p1, p2, p3);
    bezier.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);

    mVertices << x0Coordinate << y0Coordinate << z0Coordinate;
    mColors << 0.0f << 1.0f << 0.0f;

    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    mVertices << x3Coordinate << y3Coordinate << z3Coordinate;
    mColors << 0.0f << 1.0f << 0.0f;

    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}