#include "stdafx.h"
#include "Solar_Panel_System.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>

Solar_Panel_System::Solar_Panel_System()
{
	isRevolving = false;
	sunPos = new QVector2D(7.5f, 0.0f);
	mMultiplier = 1.0f;
	orbitX = 0.0f;
	orbitY = -8.0f;
}

Solar_Panel_System::~Solar_Panel_System()
{
}

void Solar_Panel_System::showSolarPanelSystem(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors, QVector<GLfloat>& mSolarVertices, QVector<GLfloat>& mSolarColors)
{
	drawSun(mVertices, mColors);
	drawSolarPanel(mSolarVertices, mSolarColors);
}

void Solar_Panel_System::drawSun(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors)
{
	float cx = sunPos->x();
	float cy = sunPos->y(); 
	 
	for (int i = 0; i < sSegments; ++i)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(sSegments);
		float x = sRadius * cosf(theta);
		float y = sRadius * sinf(theta);

		mVertices << cx + x << cy + y;
		mColors << sunColor->x() / 255.0f << sunColor->y() / 255.0f << sunColor->z() / 255.0f;

		mVertices << cx << cy;
		mColors << sunColor->x() / 255.0f << sunColor->y() / 255.0f << sunColor->z() / 255.0f;
	}
	if (isRevolving)
	{
		rotateSun(mVertices, mColors);
	}
}

void Solar_Panel_System::drawSolarPanel(QVector<GLfloat>& mSolarVertices, QVector<GLfloat>& mSolarColors)
{	
	for (auto& vertex : vertices)
	{
		mSolarVertices << mSolarPanelCenter->x() + vertex.x() << mSolarPanelCenter->y() + vertex.y();
		mSolarColors << mSolarPanelColor->x() << mSolarPanelColor->y() << mSolarPanelColor->z();
		vertex.setX(mSolarPanelCenter->x() + vertex.x());
		vertex.setY(mSolarPanelCenter->y() + vertex.y());
	}

	// Add vertices and colors for the supporting column
	mSolarVertices << basePos->x() - mBaseWidth / 2 << basePos->y();
	mSolarColors << 0.0f << 0.0f << 0.0f;  // Dark gray color for the column

	mSolarVertices << basePos->x() + mBaseWidth / 2 << basePos->y();
	mSolarColors << 0.0f << 0.0f << 0.0f;

	mSolarVertices << basePos->x() + mBaseWidth / 2 << basePos->y() + mBaseHeight;
	mSolarColors << 0.0f << 0.0f << 0.0f;

	mSolarVertices << basePos->x() - mBaseWidth / 2 << basePos->y() + mBaseHeight;
	mSolarColors << 0.0f << 0.0f << 0.0f;

	if (isRevolving)
	{
	// Calculate the vector from the solar panel to the sun
		QVector2D panelToSun(sunPos->x() - panelPos->x(), sunPos->y() - panelPos->y());

	// Calculate the rotation angle to make the solar panel face the sun
		rotationAngle = qRadiansToDegrees(qAtan2(panelToSun.y(), panelToSun.x()));

	// Add vertices and colors for the solar panel with rotation
		rotateSolarPanel(mSolarVertices, mSolarColors);
	}

}

void Solar_Panel_System::rotateSolarPanel(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors)
{
	// Apply rotation to the vertices with an additional 90-degree offset
	QMatrix4x4 rotationMatrix;
	rotationMatrix.setToIdentity();
	rotationMatrix.rotate(rotationAngle + 90.0f, 0, 0, 1);

	for (const auto& vertex : vertices)
	{
		QVector3D rotatedVertex = rotationMatrix * vertex;
		mVertices << mSolarPanelCenter->x() + rotatedVertex.x() << mSolarPanelCenter->y() + rotatedVertex.y();
		mColors << mSolarPanelColor->x() << mSolarPanelColor->y() << mSolarPanelColor->z();
	}
}


void Solar_Panel_System::rotateSun(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors)
{
	float theta = qDegreesToRadians(planetAngle);
	orbitX = 7.5f * cosf(theta);
	orbitY = -8.0 + 8.0f * sinf(theta);
	sunPos->setX(orbitX);
	sunPos->setY(orbitY);
	planetAngle += mMultiplier * 0.28f;

	// Keep the angle within 360 degrees
	if (planetAngle >= 180.0f) {
		planetAngle -= 180.0f;
		orbitX = 0.0f;
		orbitX = -8.0f;
	}
}

void Solar_Panel_System::startRevolving()
{
	isRevolving = true;
}

void Solar_Panel_System::stopRevolving()
{
	isRevolving = false;
}

void Solar_Panel_System::setMultiplier(float value)
{
	mMultiplier = value;
}

void Solar_Panel_System::resetPositions()
{
	planetAngle = 0.0f;
}

void Solar_Panel_System::updatePositions(float minutes)
{
	planetAngle += (minutes / 1440) * 360.0f;
}
