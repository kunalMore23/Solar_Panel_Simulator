// solarpanelscene.cpp
#include "SolarPanelWidget.h"
#include <cmath>

#define PI 3.14159265358979323846

SolarPanelWidget::SolarPanelWidget(QWidget* parent) : QWidget(parent), angle(0) {
    // Set up a timer to update the scene every 50 milliseconds
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SolarPanelWidget::updateScene);
    timer->start(50);
}

void SolarPanelWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Calculate the position of the sun based on the angle in an elliptical path
    int a = 200;  // Semi-major axis
    int b = 100;  // Semi-minor axis
    int columnX = width() / 2 - 5;  // Adjust the column position as needed
    int columnY = height() - 60;   // Set the desired distance from the bottom of the window

    int sunX = columnX + a * std::cos(angle);
    int sunY = columnY + b * std::sin(angle);

    // Calculate the position of the solar panel based on the angle
    int panelX = columnX;
    int panelY = columnY - 10;  // Set the desired distance between the panel and column

    // Calculate the rotation angle to make the solar panel face the sun
    double rotationAngle = std::atan2(sunY - panelY, sunX - panelX) + PI / 2;  // Rotate by 90 degrees

    // Draw the sky
    painter.fillRect(rect(), Qt::lightGray);

    // Draw the sun
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(sunX - 20, sunY - 20, 40, 40);

    // Save the current transformation matrix
    painter.save();

    // Translate to the column position
    painter.translate(columnX, columnY);

    // Draw the support column
    painter.setBrush(Qt::black);
    painter.drawRect(-5, 0, 10, panelY - columnY + 5);  // Draw a rectangular column

    // Rotate and translate to the solar panel position
    painter.translate(panelX - columnX, panelY - columnY);
    painter.rotate(rotationAngle * 180 / PI);

    // Draw the solar panel as a horizontal line
    painter.setBrush(Qt::gray);
    painter.drawRect(-50, -2, 100, 4);

    // Restore the original transformation matrix
    painter.restore();
}

void SolarPanelWidget::updateScene() {
    // Update the angle to simulate the movement of the sun in an elliptical path
    double a = 200;  // Semi-major axis
    double b = 100;  // Semi-minor axis
    if (angle >= PI)
    {
        angle = 0;
    }
    else {
        angle += 0.02;
    }

    // Calculate the x and y coordinates of the sun in an elliptical path
    int columnX = width() / 2 - 5;  // Adjust the column position as needed
    int columnY = height() - 60;   // Set the desired distance from the bottom of the window
    int sunX = columnX + a * std::cos(angle);
    int sunY = columnY + b * std::sin(angle);

    // Trigger a repaint to update the scene
    update();
}
