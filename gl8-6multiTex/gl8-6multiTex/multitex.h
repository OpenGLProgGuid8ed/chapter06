#ifndef MULTITEX_H
#define MULTITEX_H

#include <QtWidgets/QWidget>
#include "ui_multitex.h"
#include "Loadshaders.h"
#include "vermilion.h"
#include "vbm.h"
#include "vmath.h"
#include <qgl.h>

class multiTex : public QGLWidget
{
	Q_OBJECT

public:
	multiTex(QGLWidget *parent = 0);
	~multiTex();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent *);

private:
	Ui::multiTexClass ui;
	// Member variables
    float aspect;
    GLuint base_prog;
    GLuint vao;

    GLuint quad_vbo;

    GLuint tex1;
    GLuint tex2;

    GLint  time_loc;
};

#endif // MULTITEX_H
