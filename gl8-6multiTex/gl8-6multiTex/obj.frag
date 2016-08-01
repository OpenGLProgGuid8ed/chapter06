#version 330 core
in vec2 tex_coord0;
in vec2 tex_coord1;

uniform sampler2D  tex1;
uniform sampler2D  tex2;
layout (location = 0) out vec4 color;

void main()
{
	color = texture(tex1, tex_coord0) + texture(tex2, tex_coord1) *0.5;
}

        