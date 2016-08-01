#include "mipmap.h"
#include <iostream>
using namespace vmath;
#define BUFFER_OFFSET(x)  ((const void*) (x))
 static const GLfloat plane_vertices[] =
    {
        -20.0f, 0.0f, -50.0f,
        -20.0f, 0.0f,  50.0f,
         20.0f, 0.0f, -50.0f,
         20.0f, 0.0f,  50.0f
    };

    static const GLfloat plane_texcoords[] =
    {
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 0.0f,
        1.0f, 1.0f
    };

    static const GLushort plane_indices[] =
    {
        0, 1, 2, 3
    };
mipMap::mipMap(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

mipMap::~mipMap()
{

}

void mipMap::timerEvent(QTimerEvent*)
{
	updateGL();
}

void mipMap::initializeGL()
{
	//glewExperimental = GL_TRUE;
	if(glewInit())
	{
		std::cout<<"Unable to Init GLEW"<<std::endl;
		exit(EXIT_FAILURE);
	}
	
	setGeometry(200,100,640,480);
	glCreateProgram();
    ShaderInfo sky_shaders[] =
    {
        { GL_VERTEX_SHADER, "sky.vert" },
        { GL_FRAGMENT_SHADER, "sky.frag" },
        { GL_NONE }
    };
	//设置着色器
	mipmap_prog = LoadShaders(sky_shaders);
	glUseProgram(mipmap_prog);
	//设置顶点缓存数据
	glGenBuffers(1, &cube_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, cube_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(plane_vertices) + sizeof(plane_texcoords), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(plane_vertices), plane_vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(plane_vertices), sizeof(plane_texcoords), plane_texcoords);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(plane_vertices)));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &cube_element_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(plane_indices), plane_indices, GL_STATIC_DRAW);

    skybox_rotate_loc = glGetUniformLocation(mipmap_prog, "tc_rotate");

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexStorage2D(GL_TEXTURE_2D, 7, GL_RGBA8, 64, 64);

    unsigned int * data = new unsigned int [64 * 64];

    unsigned int colors[] = { 0xFF0000FF, 0xFF00FF00, 0xFFFF0000, 0xFF00FFFF, 0xFFFF00FF, 0xFFFFFF00, 0xFFFFFFFF };
    for (int i = 0; i < 7; i++)
    { 
        for (int j = 0; j < 64 * 64; j++)
        {
            data[j] = colors[i];
        }
        glTexSubImage2D(GL_TEXTURE_2D, i, 0, 0, 64 >> i, 64 >> i, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, 4.5f);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    delete [] data;
}

void mipMap::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.25f, 0.3f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);
    glDisable(GL_CULL_FACE);

	static const unsigned int start_time = GetTickCount();
    float t = float((GetTickCount() - start_time)) / float(0x3FFF);
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);
    mat4 tc_matrix(vmath::mat4::identity());

    glUseProgram(mipmap_prog);
    tc_matrix = translate(vec3(0.0f, 0.0f, -60.0f)) * rotate(80.0f * 3.0f * 0.03f, X);
    tc_matrix = perspective(35.0f, 1.0f / aspect, 0.1f, 700.0f) * tc_matrix;
    glUniformMatrix4fv(skybox_rotate_loc, 1, GL_FALSE, tc_matrix);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_element_buffer);

    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, NULL);
    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, BUFFER_OFFSET(8 * sizeof(GLushort)));
}

void mipMap::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	aspect = (float)h/(float)w;
	glViewport(0,0,w,h);
	glLoadIdentity();
}