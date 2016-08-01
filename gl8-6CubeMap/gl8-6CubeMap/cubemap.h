#ifndef CUBEMAP_H
#define CUBEMAP_H

#include <QtWidgets/QWidget>
#include "ui_cubemap.h"
#include "Loadshaders.h"
#include "vermilion.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
class CubeMap : public QGLWidget
{
	Q_OBJECT

public:
	CubeMap(QGLWidget *parent = 0);
	~CubeMap();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent *);

private:
	Ui::CubeMapClass ui;
	// Member variables
    float aspect;
    GLuint skybox_prog;
    GLuint object_prog;
    GLuint vao;
    GLuint cube_vbo;
    GLuint cube_element_buffer;

    GLuint tex;
    GLint skybox_rotate_loc;

    GLint object_mat_mvp_loc;
    GLint object_mat_mv_loc;

    VBObject object;
};

#endif // CUBEMAP_H
