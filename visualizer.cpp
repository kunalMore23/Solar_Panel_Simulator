// mainwindow.cpp
#include "stdafx.h"
#include "visualizer.h"
#include "OpenGLWindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QInputDialog>
#include <iostream>


Visualizer::Visualizer(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi();

}

Visualizer::~Visualizer()
{
}

void Visualizer::setupUi()
{
    resize(720, 700);
    QWidget* widget = new QWidget(this);
    QGridLayout* mBaseLayout = new QGridLayout(widget);
    setCentralWidget(widget);
    QVBoxLayout* VbuttonsLayout = new QVBoxLayout();

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    VbuttonsLayout->addLayout(buttonsLayout);

    QSlider* zoomSlider = new QSlider(Qt::Horizontal, widget);
    zoomSlider->setRange(0, 100);  // Adjust the range as needed
    zoomSlider->setValue(50);      // Set initial value to the middle
    connect(zoomSlider, &QSlider::valueChanged, this, &Visualizer::zoomSliderChanged);

    // Add the zoom slider to the layout
    VbuttonsLayout->addWidget(zoomSlider);

    mRenderer = new OpenGLWindow(QColor(0.0f, 31.0f, 63.0f), widget);
    VbuttonsLayout->addWidget(mRenderer, 1);
    mBaseLayout->addLayout(VbuttonsLayout, 0, 0);



    setWindowTitle(QCoreApplication::translate("Solar System Simulator", "Solar System Simulator", nullptr));

}

void Visualizer::zoomSliderChanged(int value)
{
    // Map the slider value to a zoom factor, e.g., from 0.5 to 2.0
    double zoomFactor = 0.5 + (value / 100.0) * 1.5;

    // Apply the zoom factor to your OpenGL renderer or adjust as needed
    mRenderer->setZoomFactor(zoomFactor);
}
