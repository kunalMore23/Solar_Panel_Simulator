#pragma once
#include "Point3D.h"
class Solar_Panel_System
{
public:
	Solar_Panel_System();
	~Solar_Panel_System();

    void showSolarPanelSystem(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors, QVector<GLfloat>& mSolarVertices, QVector<GLfloat>& mSolarColors);

	void drawSun(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors);
	void drawSolarPanel(QVector<GLfloat>& mSolarVertices, QVector<GLfloat>& mSolarColors);

    void setMultiplier(float value);
    void startRevolving();
    void stopRevolving();
    void resetPositions();
    void updatePositions(float minutes);


private:
	void rotateSun(QVector<GLfloat>& vertices, QVector<GLfloat>& colors);
    void rotateSolarPanel(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors);

private:
    Point3D* sunColor = new Point3D(255.0f, 215.0f, 0.0f);
    float mMultiplier;
    float planetAngle = 0.0f;
    float orbitX;
    float orbitY;
    bool isRevolving;

    QVector2D* sunPos;
    float sRadius = 1.0f;
    int sSegments = 600;
    
    // solar panel properties
    QVector2D* mSolarPanelCenter = new QVector2D(0.0f, -7.45f);
    QVector3D* mSolarPanelColor = new QVector3D(0.25f, 0.25f, 0.25f);
    float mPanelHeight = 2.4f;
    float mPanelWidth = 0.1f;
    QVector2D* panelPos = new QVector2D(0.0f, 7.45f);

    float halfWidth = mPanelWidth / 2;
    float halfHeight = mPanelHeight / 2;

    // Define the vertices of the rectangle
    QVector<QVector3D> vertices =
    {
        QVector3D(-halfWidth, -halfHeight, 0),
        QVector3D(halfWidth, -halfHeight, 0),
        QVector3D(halfWidth, halfHeight, 0),
        QVector3D(-halfWidth, halfHeight, 0)
    };

    //properties of base of solar panel
    QVector2D* basePos = new QVector2D(0.0f, -8.0f);
    float mBaseHeight = 0.5f;
    float mBaseWidth = 0.05f;
    float rotationAngle = 0.0f;
};