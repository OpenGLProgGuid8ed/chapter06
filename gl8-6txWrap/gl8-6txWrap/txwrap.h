#ifndef TXWRAP_H
#define TXWRAP_H

#include <QtWidgets/QWidget>
#include "ui_txwrap.h"
#include "LoadShaders.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>

class txWrap : public QGLWidget
{
	Q_OBJECT

public:
	txWrap(QGLWidget *parent = 0);
	~txWrap();
	void initializeGL();
	void paintGL();
	void DrawScene(bool depth_only);
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);

private:
	Ui::txWrapClass ui;
	 // Member variables
    float aspect;
    GLuint base_prog;
    GLuint vao;
    GLuint quad_vbo;
    GLuint tex;
};

#endif // TXWRAP_H
