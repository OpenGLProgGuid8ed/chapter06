#ifndef STATICTEX_H
#define STATICTEX_H

#include <QtWidgets/QWidget>
#include "ui_statictex.h"
#include "LoadShaders.h"
#include "vmath.h"
#include <qgl.h>
class staticTex : public QGLWidget
{
	Q_OBJECT

public:
	staticTex(QGLWidget *parent = 0);
	~staticTex();
	void initializeGL();
	void paintGL();
	void DrawScene(bool depth_only);
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);

private:
	Ui::staticTexClass ui;
	 // Member variables
    float aspect;
    GLuint base_prog;
    GLuint vao;
    GLuint quad_vbo;
    GLuint tex;
};

#endif // STATICTEX_H
