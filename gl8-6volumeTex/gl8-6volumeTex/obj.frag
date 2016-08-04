#version 330 core
in vec3 tex_coord;

uniform sampler3D tex;

layout (location = 0) out vec4 color;

void main()
{
	color = texture(tex, tex_coord).rrrr;
}

        