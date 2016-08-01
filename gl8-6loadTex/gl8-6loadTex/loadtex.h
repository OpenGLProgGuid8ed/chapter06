#ifndef LOADTEX_H
#define LOADTEX_H

#include <QtWidgets/QWidget>
#include "ui_loadtex.h"
#include "Loadshaders.h"
#include "vermilion.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
class LoadTex : public QGLWidget
{
	Q_OBJECT

public:
	LoadTex(QGLWidget *parent = 0);
	~LoadTex();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent *);

private:
	Ui::LoadTexClass ui;
	// Member variables
    float aspect;
    GLuint base_prog;
    GLuint vao;

    GLuint quad_vbo;

    GLuint tex;
};

#endif // LOADTEX_H
