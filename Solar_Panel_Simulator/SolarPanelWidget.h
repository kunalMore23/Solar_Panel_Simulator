#pragma once
#include <QWidget>
#include <QTimer>
#include <QPainter>

class SolarPanelWidget : public QWidget {
    Q_OBJECT

public:
    SolarPanelWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void updateScene();

private:
    QTimer* timer;
    double angle;
};

