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
};