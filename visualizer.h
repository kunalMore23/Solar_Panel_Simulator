#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMenuBar>
#include <QStatusBar>
#include <QTimer>

class OpenGLWindow;

namespace Ui {
	class Visualizer;
}

class Visualizer : public QMainWindow
{
	Q_OBJECT

public:
	Visualizer(QWidget* parent = nullptr);
	~Visualizer();


private:
	void setupUi();// UI setup function
	void zoomSliderChanged(int value);


private:

	QMenuBar* menubar;
	QStatusBar* statusbar;
	QWidget* centralwidget;
	QVBoxLayout* verticalLayout;
	QGraphicsView* graphicsView;
	QHBoxLayout* horizontalLayout;
	QPushButton* startButton;
	QPushButton* stopButton;
	QPushButton* resetButton;
	QPushButton* updateButton;
	QLineEdit* timeInput;
	QTimer* timer;

	QMenuBar* mMenuBar;
	QToolBar* mMainToolBar;
	QWidget* mCentralWidget;
	QStatusBar* mStatusBar;
	OpenGLWindow* mRenderer;
};
