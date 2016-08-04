#ifndef VOLUMETEX_H
#define VOLUMETEX_H

#include <QtWidgets/QWidget>
#include "ui_volumetex.h"
#include "Loadshaders.h"
#include "vermilion.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
class volumeTex : public QGLWidget
{
	Q_OBJECT

public:
	volumeTex(QGLWidget *parent = 0);
	~volumeTex();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent *);

private:
	Ui::volumeTexClass ui;
	 // Member variables
    float aspect;
    GLuint base_prog;
    GLuint vao;

    GLuint quad_vbo;

    GLuint tex;
    GLint tc_rotate_loc;
};

#endif // VOLUMETEX_H
