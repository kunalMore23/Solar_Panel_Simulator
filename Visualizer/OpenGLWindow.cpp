#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>

OpenGLWindow::OpenGLWindow(const QColor& background, QWidget* parent) : mBackground(background), orbitX(0.0f), orbitY(-8.0f), sunPosition(QPoint(0.0f, 0.0f)), mMultiplier{ 1.0f }
{
	//initializeGL();
	timer = new QTimer(this);
	solar = new Solar_Panel_System();
	setParent(parent);
	setMinimumSize(500, 250);
	isRevolving = false;
	 // Adjust the interval as needed
}

void OpenGLWindow::startRendereing()
{
	connect(timer, &QTimer::timeout, this, &OpenGLWindow::updateSolarPanelData);
	timer->start(32);
}

void OpenGLWindow::stopRendereing()
{
	timer->stop();
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

void OpenGLWindow::updateData(std::vector<float>& vertices, std::vector<float>& colors)
{
	mVertices.clear();
	mColors.clear();
	mVertices = vertices;
	mColors = colors;
	update();
}

void OpenGLWindow::paintGL()
{
		glClear(GL_COLOR_BUFFER_BIT);
		mProgram->bind();

		QMatrix4x4 matrix;
		matrix.ortho(-6.0f * 1.475, 6.0f * 1.475, -6.0f * 1.475f, 6.0f * 1.475, 0.1f, 100.0f);
		matrix.translate(0, 0, -2);

		mProgram->setUniformValue(m_matrixUniform, matrix);

		mVerticesData = mVertices.data();
		mColorsData = mColors.data();

		int size = mVertices.size();

		glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, mVerticesData);
		glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, mColorsData);

		glEnableVertexAttribArray(m_posAttr);
		glEnableVertexAttribArray(m_colAttr);

		glDrawArrays(GL_LINES, 0, size / 2);

		glDisableVertexAttribArray(m_colAttr);
		glDisableVertexAttribArray(m_posAttr);

		mProgram->release();
}

void OpenGLWindow::updateSolarPanelData()
{
	mVertices.clear();
	mColors.clear();
	solar->showSolarPanelSystem(mVertices, mColors);
	update();
}

void OpenGLWindow::startRevolving()
{
	timer->start(32);
}

void OpenGLWindow::stopRevolving()
{
	timer->stop();
}

void OpenGLWindow::setMultiplier(float value)
{
	mMultiplier = value;
}

void OpenGLWindow::resetPositions()
{
	//planetAngle = 0.0f;
	updateSolarPanelData();
}

void OpenGLWindow::updatePositions(float minutes)
{
	//planetAngle += (minutes / 1440) * 360.0f;
	updateSolarPanelData();
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