#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <cmath>

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

namespace Solar_Panel_Simulator
{
    class OpenGLWindow;
}

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLWindow(const QColor& background, QWidget* parent);
    ~OpenGLWindow();
    void setZoomFactor(double zoomFactor);
    void setMultiplier(float value);
    void startRevolving();
    void stopRevolving();
    void resetPositions();
    void updatePositions(float minutes);

protected:
    void paintGL() override;
    void initializeGL() override;


private:
    void drawSun(QVector<GLfloat>& vertices, QVector<GLfloat>& colors, float cx, float cy, float radius, int segments, const QVector3D& planetColor);
    void drawOrbitingPlanets(QVector<GLfloat>& vertices, QVector<GLfloat>& colors);
    void reset();
    void drawSolarPanel(QVector<GLfloat>& mSolarVertices, QVector<GLfloat>& mSolarColors);
    void addRotatedRectangle(QVector<GLfloat>& mVertices, QVector<GLfloat>& mColors, float centerX, float centerY, float width, float height, float rotationAngle, const QVector3D& color);

private:
    float mMultiplier;
    float planetAngle = 0.0f;
    float orbitX;
    float orbitY;
    bool isRevolving;

    QVector2D sunPosition;
    double mZoomFactor;
    QOpenGLShaderProgram* mProgram = nullptr;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
};
