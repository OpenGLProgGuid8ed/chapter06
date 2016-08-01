#ifndef MIPFILTER_H
#define MIPFILTER_H

#include <QtWidgets/QWidget>
#include "ui_mipfilter.h"
#include "LoadShaders.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
class mipFilter : public QGLWidget
{
	Q_OBJECT

public:
	mipFilter(QGLWidget *parent = 0);
	~mipFilter();
	void initializeGL();
	void paintGL();
	void DrawScene(bool depth_only);
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent*);
private:
	Ui::mipFilterClass ui;
    // Member variables
    float aspect;
    GLuint mipmap_prog;
    GLuint vao;
    GLuint cube_vbo;
    GLuint cube_element_buffer;
    GLuint tex;
    GLint skybox_rotate_loc;
    GLint object_mat_mvp_loc;
    GLint object_mat_mv_loc;
    VBObject object;
};

#endif // MIPFILTER_H
