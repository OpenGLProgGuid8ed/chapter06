#include "cubemap.h"
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

CubeMap::CubeMap(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

CubeMap::~CubeMap()
{
	glUseProgram(0);
    glDeleteProgram(skybox_prog);
    glDeleteProgram(object_prog);
    glDeleteTextures(1, &tex);
    glDeleteVertexArrays(1, &tex);
}

void CubeMap::initializeGL()
{
	if(glewInit())
	{
		std::cout<<"Unable to init glew"<<std::endl;
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
	skybox_prog = LoadShaders(sky_shaders);
	ShaderInfo obj_shaders[] =
    {
        { GL_VERTEX_SHADER, "obj.vert" },
        { GL_FRAGMENT_SHADER, "obj.frag" },
        { GL_NONE }
    };
	object_prog = LoadShaders(obj_shaders);

	glGenBuffers(1, &cube_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, cube_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &cube_element_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_element_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);

    skybox_rotate_loc = glGetUniformLocation(skybox_prog, "tc_rotate");
    object_mat_mvp_loc = glGetUniformLocation(object_prog, "mat_mvp");
    object_mat_mv_loc = glGetUniformLocation(object_prog, "mat_mv");

	vglImageData image;
    tex = vglLoadTexture("TantolundenCube.dds", 0, &image);
    GLenum e;
    e = glGetError();
    vglUnloadImage(&image);
    object.LoadFromVBM("C:/Vermilion-Book/trunk/Code/media/unit_torus.vbm", 0, 1, 2);

}

void CubeMap::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.25f, 0.3f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glUseProgram(skybox_prog);
	//在面的交界处进行双边线性采样
    glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

	static const unsigned int start_time = GetTickCount();
    float t = float((GetTickCount() - start_time)) / float(0x3FFF);
    static const vmath::vec3 X(1.0f, 0.0f, 0.0f);
    static const vmath::vec3 Y(0.0f, 1.0f, 0.0f);
    static const vmath::vec3 Z(0.0f, 0.0f, 1.0f);
	mat4 tc_matrix(vmath::mat4::identity());
	tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;

    glUniformMatrix4fv(skybox_rotate_loc, 1, GL_FALSE, tc_matrix);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cube_element_buffer);
    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, NULL);
    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_SHORT, BUFFER_OFFSET(8 * sizeof(GLushort)));
	
	glUseProgram(object_prog);
    tc_matrix = vmath::translate(vmath::vec3(0.0f, 0.0f, -4.0f)) *
                vmath::rotate(80.0f * 3.0f * t, Y) * vmath::rotate(70.0f * 3.0f * t, Z);
    glUniformMatrix4fv(object_mat_mv_loc, 1, GL_FALSE, tc_matrix);
    tc_matrix = vmath::perspective(35.0f, 1.0f / aspect, 0.1f, 100.0f) * tc_matrix;
    glUniformMatrix4fv(object_mat_mvp_loc, 1, GL_FALSE, tc_matrix);
    glClear(GL_DEPTH_BUFFER_BIT);
	object.Render();
}

void CubeMap::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	aspect = float(h) / float(w);
	glViewport(0,0,w,h);
	glLoadIdentity();
}

void CubeMap::timerEvent(QTimerEvent*)
{
	updateGL();
}