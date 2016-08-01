#include "loadtex.h"
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
LoadTex::LoadTex(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

LoadTex::~LoadTex()
{
	glUseProgram(0);
    glDeleteProgram(base_prog);
    glDeleteTextures(1, &tex);
    glDeleteVertexArrays(1, &tex);
}

void LoadTex::initializeGL()
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

	vglImageData image;
    tex = vglLoadTexture("test.dds", 0, &image);
    glTexParameteri(image.target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    vglUnloadImage(&image);
}

void LoadTex::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.25f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    
	float t = float(GetTickCount() & 0x3FFF) / float(0x3FFF);
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);

	glUseProgram(base_prog);
	glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void LoadTex::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	aspect = float(h) / float(w);
	glViewport(0,0,w,h);
	glLoadIdentity();
}

void LoadTex::timerEvent(QTimerEvent*)
{
	updateGL();
}