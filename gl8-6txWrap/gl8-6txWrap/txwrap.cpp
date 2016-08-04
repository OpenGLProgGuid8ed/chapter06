#include "txwrap.h"
#include <iostream>
using namespace vmath;
#define BUFFER_OFFSET(x)  ((const void*) (x))
static const GLfloat quad_data[] =
{
        -0.75f, -0.75f,
         0.75f, -0.75f,
         0.75f, 0.75f,
        -0.75f, 0.75f,

         0.0f, 0.0f,
         4.0f, 0.0f,
         4.0f, 4.0f,
         0.0f, 4.0f
};
static const unsigned char texture_data[] =
{
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF
};
txWrap::txWrap(QGLWidget *parent)
	: QGLWidget(parent)
{
	ui.setupUi(this);
	startTimer(100);
}

txWrap::~txWrap()
{

}

void txWrap::timerEvent(QTimerEvent*)
{
	updateGL();
}

void txWrap::initializeGL()
{
	//glewExperimental = GL_TRUE;
	if(glewInit())
	{
		std::cout<<"Unable to Init GLEW"<<std::endl;
		exit(EXIT_FAILURE);
	}
	setGeometry(200,100,640,480);
	glCreateProgram();
    ShaderInfo qua_shaders[] =
    {
        { GL_VERTEX_SHADER, "qua.vert" },
        { GL_FRAGMENT_SHADER, "qua.frag" },
        { GL_NONE }
    };
	//设置着色器
	base_prog = LoadShaders(qua_shaders);
	glUseProgram(base_prog);
	//设置顶点缓存数据
	glGenBuffers(1, &quad_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, quad_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_data), quad_data, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(8 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

	glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexStorage2D(GL_TEXTURE_2D, 4, GL_RGBA8, 8, 8);
	//设置数据
	glTexSubImage2D(GL_TEXTURE_2D,
                    0,											//mipmap级别
                    0, 0,										//x,y偏移
                    8, 8,										//宽高
                    GL_RED,								//格式
					GL_UNSIGNED_BYTE,				//数据类型
                    texture_data);						//数据
	//设置纹理参数 设置 RGBA
	static const GLint swizzles[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
    glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzles);

	//mipmap设置
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//设置采样器属性 
	//GL_TEXTURE_WRAP_S处理纹理域的S、T、R坐标轴
	//GL_CLAMP_TO_EDGE			纹理坐标超出0.1~1.0  用纹理边缘值返回着色器
	//GL_CLAMP_TO_BORDER		读取纹理范围外的坐标将生成用来形成最终值的纹理边界颜色
    //GL_REPEAT GL_MIRRORED 无限重复
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void txWrap::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClearDepth(1.0f);
    glDisable(GL_CULL_FACE);

    glUseProgram(base_prog);
	static const GLenum wrap_modes[] = { GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER, GL_REPEAT, GL_MIRRORED_REPEAT };
    unsigned int ticks = GetTickCount();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_modes[(ticks >> 11) & 0x3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_modes[(ticks >> 11) & 0x3]);
	glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void txWrap::resizeGL(int w,int h)
{
	if(0 == h)
		h = 1;
	aspect = (float)h/(float)w;
	glViewport(0,0,w,h);
	glLoadIdentity();
}
