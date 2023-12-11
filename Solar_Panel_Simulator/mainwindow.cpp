#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setupUi();
	scene = new SolarPanelWidget(this);
	QVBoxLayout* layout = new QVBoxLayout(mCentralwidget);
	layout->addWidget(scene);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi()
{
	resize(800, 600);
	mCentralwidget = new QWidget(this);
	mCentralwidget->setObjectName("centralwidget");
	setCentralWidget(mCentralwidget);
	mMenubar = new QMenuBar(this);
	mMenubar->setObjectName("menubar");
	mMenubar->setGeometry(QRect(0, 0, 800, 26));
	setMenuBar(mMenubar);
	mStatusbar = new QStatusBar(this);
	mStatusbar->setObjectName("statusbar");
	setStatusBar(mStatusbar);
}