#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QtWidgets/QWidget>
#include "Loadshaders.h"
#include "vermilion.h"
#include "vmath.h"
#include "vbm.h"
#include <qgl.h>
class renderWidget : public QGLWidget
{
	Q_OBJECT

public:
	renderWidget(QGLWidget *parent = 0);
	~renderWidget();
	void initializeGL();
	void paintGL();
	void resizeGL(int w,int h);
	void timerEvent(QTimerEvent *);

private:
	// Texture for compute shader to write into
    GLuint  output_image;

    // Program, vao and vbo to render a full screen quad
    GLuint  render_prog;

    // Uniform locations
    GLint   mv_mat_loc;
    GLint   prj_mat_loc;
    GLint   col_amb_loc;
    GLint   col_diff_loc;
    GLint   col_spec_loc;

    // Object to render
    VBObject    object;
};

#endif // CUBEMAP_H
