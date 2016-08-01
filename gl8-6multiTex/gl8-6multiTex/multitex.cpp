#include "multitex.h"
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
multiTex::multiTex(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

multiTex::~multiTex()
{
	 glUseProgram(0);
    glDeleteProgram(base_prog);
    glDeleteTextures(1, &tex1);
    glDeleteTextures(2, &tex2);
    glDeleteVertexArrays(1, &vao);
}

void multiTex::initializeGL()
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
    glUseProgram(base_prog);
    time_loc = glGetUniformLocation(base_prog, "time");
    glUniform1i(glGetUniformLocation(base_prog, "tex1"), 0);
    glUniform1i(glGetUniformLocation(base_prog, "tex2"), 1);

    vglImageData image;
    tex1 = vglLoadTexture("test.dds", 0, &image);
    glBindTexture(image.target, tex1);
    glTexParameteri(image.target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    vglUnloadImage(&image);

    tex2 = vglLoadTexture("test3.dds", 0, &image);
    vglUnloadImage(&image);
}

void multiTex::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glDisable(GL_CULL_FACE);

	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	glUseProgram(base_prog);
	glUniform1f(time_loc, t);

    glBindVertexArray(vao);
	//ÆôÓÃ1
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex1);
	//ÆôÓÃ2
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, tex2);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void multiTex::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	aspect = float(h) / float(w);
	glViewport(0,0,w,h);
	glLoadIdentity();
}

void multiTex::timerEvent(QTimerEvent*)
{
	updateGL();
}