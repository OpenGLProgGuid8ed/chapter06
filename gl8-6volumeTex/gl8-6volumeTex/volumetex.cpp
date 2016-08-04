#include "volumetex.h"
#include <iostream>
using namespace vmath;
#define BUFFER_OFFSET(x)  ((const void*) (x))
static const GLfloat quad_data[] =
    {
         1.0f, -1.0f,
        -1.0f, -1.0f,
        -1.0f, 1.0f,
         1.0f, 1.0f,

         0.0f, 0.0f,
         1.0f, 0.0f,
         1.0f, 1.0f,
         0.0f, 1.0f
    };
volumeTex::volumeTex(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

volumeTex::~volumeTex()
{

}

void volumeTex::initializeGL()
{
	if(glewInit())
	{
		std::cout<<"Unable to init glew"<<std::endl;
		exit(EXIT_FAILURE);
	}
	setGeometry(200,100,640,480);
	glCreateProgram();
	ShaderInfo obj_shaders[] =
    {
        { GL_VERTEX_SHADER, "obj.vert" },
        { GL_FRAGMENT_SHADER, "obj.frag" },
        { GL_NONE }
    };
	base_prog = LoadShaders(obj_shaders);
	glGenBuffers(1, &quad_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_data), quad_data, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(8 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glLinkProgram(base_prog);
    char buf[1024];
    glGetProgramInfoLog(base_prog, 1024, NULL, buf);
    tc_rotate_loc = glGetUniformLocation(base_prog, "tc_rotate");

    vglImageData image;
    tex = vglLoadTexture("cloud.dds", 0, &image);
    glTexParameteri(image.target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    vglUnloadImage(&image);
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}

void volumeTex::paintGL()
{
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearDepth(1.0f);
   
    glDisable(GL_CULL_FACE);

	static const unsigned int start_time = GetTickCount();
    float t = float((GetTickCount() - start_time)) / float(0x3FFF);
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

    vmath::mat4 tc_matrix(vmath::mat4::identity());
	glUseProgram(base_prog);
    tc_matrix = vmath::rotate(t * 170.0f, X) *
                vmath::rotate(t * 137.0f, Y) *
                vmath::rotate(t * 93.0f, Z);

    glUniformMatrix4fv(tc_rotate_loc, 1, GL_FALSE, tc_matrix);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}

void volumeTex::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	aspect = float(h) / float(w);
	glViewport(0,0,w,h);
	glLoadIdentity();
}

void volumeTex::timerEvent(QTimerEvent*)
{
	updateGL();
}