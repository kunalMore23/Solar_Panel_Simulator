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