#include "renderWidget.h"
#include <iostream>
using namespace vmath;
#define BUFFER_OFFSET(x)  ((const void*) (x))
static const GLfloat cube_vertices[] =
    {
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f
    };

    static const GLushort cube_indices[] =
    {
        0, 1, 2, 3, 6, 7, 4, 5,         // First strip
        2, 6, 0, 4, 1, 5, 3, 7          // Second strip
    };

renderWidget::renderWidget(QGLWidget *parent)
	: QGLWidget(parent)
{
	startTimer(100);
}

renderWidget::~renderWidget()
{
	glUseProgram(0);
    glDeleteProgram(render_prog);
    glDeleteTextures(1, &output_image);
}

void renderWidget::initializeGL()
{
	if(glewInit())
	{
		std::cout<<"Unable to init glew"<<std::endl;
		exit(EXIT_FAILURE);
	}
	//setGeometry(200,100,640,480);
	glCreateProgram();
	ShaderInfo obj_shaders[] =
    {
        { GL_VERTEX_SHADER, "obj.vert" },
        { GL_FRAGMENT_SHADER, "obj.frag" },
        { GL_NONE }
    };
	render_prog = LoadShaders(obj_shaders);
	glLinkProgram(render_prog);

    mv_mat_loc = glGetUniformLocation(render_prog, "model_matrix");
    prj_mat_loc = glGetUniformLocation(render_prog, "proj_matrix");
    col_amb_loc = glGetUniformLocation(render_prog, "color_ambient");
    col_diff_loc = glGetUniformLocation(render_prog, "color_diffuse");
    col_spec_loc = glGetUniformLocation(render_prog, "color_specular");
	object.LoadFromVBM("C:/Vermilion-Book/trunk/Code/media/unit_torus.vbm", 0, 1, 2);


}

void renderWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

	float time = float(GetTickCount() & 0xFFFF) / float(0xFFFF);
    mat4 mv_matrix =translate(0.0f, 0.0f, -4.0f) *
                            rotate(987.0f * time * 3.14159f, vec3(0.0f, 0.0f, 1.0f)) *
                            rotate(1234.0f * time * 3.14159f, vec3(1.0f, 0.0f, 0.0f));
    mat4 prj_matrix = perspective(60.0f, 1.333f, 0.1f, 1000.0f);

    glUseProgram(render_prog);
    glUniformMatrix4fv(mv_mat_loc, 1, GL_FALSE, mv_matrix);
    glUniformMatrix4fv(prj_mat_loc, 1, GL_FALSE, prj_matrix);
	object.Render();
}

void renderWidget::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	glViewport(0,0,w,h);
	glLoadIdentity();
}

void renderWidget::timerEvent(QTimerEvent*)
{
	updateGL();
}