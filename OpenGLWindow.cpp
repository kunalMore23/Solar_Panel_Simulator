#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>

OpenGLWindow::OpenGLWindow(const QColor& background, QWidget* parent) : mBackground(background), orbitX(0.0f), orbitY(-8.0f), sunPosition(QPoint(0.0f, 0.0f))
{
	//initializeGL();
	setParent(parent);
	setMinimumSize(500, 250);
}
OpenGLWindow::~OpenGLWindow()
{
	reset();
}

void OpenGLWindow::reset()
{

	makeCurrent();
	delete mProgram;
	mProgram = nullptr;
	doneCurrent();
	QObject::disconnect(mContextWatchConnection);
}



void OpenGLWindow::paintGL()
{

	glClear(GL_COLOR_BUFFER_BIT);
	mProgram->bind();

	QMatrix4x4 matrix;
	matrix.ortho(-6.0f * mZoomFactor, 6.0f * mZoomFactor, -6.0f * mZoomFactor, 6.0f * mZoomFactor, 0.1f, 100.0f);  // Adjusted orthographic projection
	matrix.translate(0, 0, -2);

	mProgram->setUniformValue(m_matrixUniform, matrix);
	QVector<GLfloat> mColors;
	QVector<GLfloat> mVertices;


	drawOrbitingPlanets(mVertices, mColors);




	float* mVerticesData = mVertices.data();
	float* mColorsData = mColors.data();

	glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, mVerticesData);
	glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, mColorsData);

	glEnableVertexAttribArray(m_posAttr);
	glEnableVertexAttribArray(m_colAttr);

	glDrawArrays(GL_LINES, 0, mVertices.size() / 2);

	QVector<GLfloat> mSolarVertices;
	QVector<GLfloat> mSolarColors;

	drawSolarPanel(mSolarVertices, mSolarColors);

	GLfloat* mSvertex = mSolarVertices.data();
	GLfloat* mScolors = mSolarColors.data();

	glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, mSvertex);
	glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, mScolors);

	glDrawArrays(GL_QUADS, 0, mSolarVertices.size() / 2);

	glDisableVertexAttribArray(m_colAttr);
	glDisableVertexAttribArray(m_posAttr);

	mProgram->release();
	update();

}


void OpenGLWindow::drawSun(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors, float cx, float cy, float radius, int segments, const QVector3D& planetColor)
{
	for (int i = 0; i < segments; ++i)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(segments);
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);

		mVertices << cx + x << cy + y;
		mColors << planetColor.x() / 255.0f << planetColor.y() / 255.0f << planetColor.z() / 255.0f;

		mVertices << cx << cy;
		mColors << planetColor.x() / 255.0f << planetColor.y() / 255.0f << planetColor.z() / 255.0f;
	}
}

void OpenGLWindow::drawSolarPanel(QVector<GLfloat>& mSolarVertices, QVector<GLfloat>& mSolarColors)
{
	// Define the dimensions of the solar panel
	float panelWidth = 1.4f;
	float panelHeight = 0.1f;
	float columnWidth = 0.05f;
	float columnHeight = 0.5f;

	// Calculate the coordinates for the solar panel
	float panelX = 0.0f;
	float panelY = -7.45f;

	// Calculate the coordinates for the supporting column
	float columnX = 0;
	float columnY = -8.0;

	// Calculate the vector from the solar panel to the sun
	QVector2D panelToSun(sunPosition.x() - panelX, sunPosition.y() - panelY);

	// Calculate the rotation angle to make the solar panel face the sun
	float rotationAngle = qRadiansToDegrees(qAtan2(panelToSun.y(), panelToSun.x()));

	// Add vertices and colors for the solar panel with rotation
	addRotatedRectangle(mSolarVertices, mSolarColors, panelX, panelY, panelWidth, panelHeight, rotationAngle, QVector3D(0.25f, 0.25f, 0.25f));

	// Add vertices and colors for the supporting column
	mSolarVertices << columnX - columnWidth / 2 << columnY;
	mSolarColors << 0.0f << 0.0f << 0.0f;  // Dark gray color for the column

	mSolarVertices << columnX + columnWidth / 2 << columnY;
	mSolarColors << 0.0f << 0.0f << 0.0f;

	mSolarVertices << columnX + columnWidth / 2 << columnY + columnHeight;
	mSolarColors << 0.0f << 0.0f << 0.0f;

	mSolarVertices << columnX - columnWidth / 2 << columnY + columnHeight;
	mSolarColors << 0.0f << 0.0f << 0.0f;
}

void OpenGLWindow::addRotatedRectangle(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors, float centerX, float centerY, float width, float height, float rotationAngle, const QVector3D& color)
{
	float halfWidth = width / 2;
	float halfHeight = height / 2;

	// Define the vertices of the rectangle
	QVector<QVector3D> vertices = {
		QVector3D(-halfWidth, -halfHeight, 0),
		QVector3D(halfWidth, -halfHeight, 0),
		QVector3D(halfWidth, halfHeight, 0),
		QVector3D(-halfWidth, halfHeight, 0)
	};

	// Apply rotation to the vertices with an additional 90-degree offset
	QMatrix4x4 rotationMatrix;
	rotationMatrix.setToIdentity();
	rotationMatrix.rotate(rotationAngle + 90.0f, 0, 0, 1);

	for (const auto& vertex : vertices)
	{
		QVector3D rotatedVertex = rotationMatrix * vertex;
		mVertices << centerX + rotatedVertex.x() << centerY + rotatedVertex.y();
		mColors << color.x() << color.y() << color.z();
	}
}


void OpenGLWindow::drawOrbitingPlanets(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors)
{

	float theta = 0.0f;
	for (int j = 0; j < 180; ++j) {
		theta = qDegreesToRadians(float(j));
		orbitX = 7.5f * cosf(theta);
		orbitY = -8.0f + 8.0f * sinf(theta);
		mVertices << orbitX << orbitY;
		mColors << 1.0f << 1.0f << 1.0f;  // White color for the orbit
	}

	theta = qDegreesToRadians(planetAngle);
	orbitX = 7.5f * cosf(theta);
	orbitY = -8.0 + 8.0f * sinf(theta);
	sunPosition.setX(orbitX);
	sunPosition.setY(orbitY);
	drawSun(mVertices, mColors, orbitX, orbitY, 1.0f, 600, QVector3D(100.0f, 68.2f, 25.9f));
	planetAngle += 0.28f;

	// Keep the angle within 360 degrees
	if (planetAngle >= 180.0f) {
		planetAngle -= 180.0f;
		orbitX = 0.0f;
		orbitX = -8.0f;
	}
}
void OpenGLWindow::setZoomFactor(double zoomFactor)
{
	mZoomFactor = zoomFactor;
}
void OpenGLWindow::initializeGL()
{
	static const char* vertexShaderSource =
		"attribute highp vec4 posAttr;\n"
		"attribute lowp vec4 colAttr;\n"
		"varying lowp vec4 col;\n"
		"uniform highp mat4 matrix;\n"
		"void main() {\n"
		"   col = colAttr;\n"
		"   gl_Position = matrix * posAttr;\n"
		"}\n";

	static const char* fragmentShaderSource =
		"varying lowp vec4 col;\n"
		"void main() {\n"
		"   gl_FragColor = col;\n"
		"}\n";

	initializeOpenGLFunctions();

	mProgram = new QOpenGLShaderProgram(this);
	mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
	mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);

	if (!mProgram->link())
	{
		qDebug() << "Shader program link error:" << mProgram->log();
		// Handle the error appropriately, e.g., return or throw an exception
	}

	m_posAttr = mProgram->attributeLocation("posAttr");
	m_colAttr = mProgram->attributeLocation("colAttr");
	m_matrixUniform = mProgram->uniformLocation("matrix");

	if (m_posAttr == -1 || m_colAttr == -1 || m_matrixUniform == -1)
	{
		qDebug() << "Shader attribute or uniform location error.";
		// Handle the error appropriately, e.g., return or throw an exception
	}

	glClearColor(mBackground.redF(), mBackground.greenF(), mBackground.blueF(), 1.0f);

}