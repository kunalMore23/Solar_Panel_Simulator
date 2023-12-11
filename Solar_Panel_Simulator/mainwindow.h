#pragma once
#include <QMainWindow>
#include "SolarPanelWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void setupUi();

private:
    QWidget* mCentralwidget;
    QMenuBar* mMenubar;
    QStatusBar* mStatusbar;

    SolarPanelWidget* scene;
};