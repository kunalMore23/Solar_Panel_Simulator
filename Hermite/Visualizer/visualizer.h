#pragma once
#include <QtWidgets/QMainWindow>
#include "OpenGLWindow.h"
#include <vector>
#include "Point3D.h"
#include "Hermite.h"

class OpenGLWindow;

class Visualizer : public QMainWindow {
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();

public:
    std::vector<float>      mVerticess;
    std::vector<float>      mColorss;
    QVector<GLfloat>   mVertices;
    QVector<GLfloat>   mColors;

private slots:
    void bezierClicked();

private:
    QWidget* mCentralWidget;
    OpenGLWindow* mRenderer;

    QLabel* mlabel1;
    QLabel* mlabel2;
    QLabel* mlabel3;
    QLabel* mlabel4;
    QLabel* mlabel5;
    QLabel* mlabel6;
    QLabel* mlabel7;
    QLabel* mlabel8;
    QLabel* mlabel9;
    QLabel* mlabel10;
    QLabel* mlabel11;
    QLabel* mlabel12;

    QDoubleSpinBox* mdoubleSpinBox1;
    QDoubleSpinBox* mdoubleSpinBox2;
    QDoubleSpinBox* mdoubleSpinBox3;
    QDoubleSpinBox* mdoubleSpinBox4;
    QDoubleSpinBox* mdoubleSpinBox5;
    QDoubleSpinBox* mdoubleSpinBox6;
    QDoubleSpinBox* mdoubleSpinBox7;
    QDoubleSpinBox* mdoubleSpinBox8;
    QDoubleSpinBox* mdoubleSpinBox9;
    QDoubleSpinBox* mdoubleSpinBox10;
    QDoubleSpinBox* mdoubleSpinBox11;
    QDoubleSpinBox* mdoubleSpinBox12;

    QPushButton* mpushButton;
};
