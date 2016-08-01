#version 330 core
in vec3 vs_fs_normal;
in vec3 vs_fs_position;
uniform samplerCube tex;
layout (location = 0) out vec4 color;

void main()
{
	//根据摄像机与观察点计算反射颜色
    vec3 tc     =  reflect(vs_fs_position, normalize(vs_fs_normal));
	vec4 rgba_ref = vec4(0.97, 0.83, 0.79, 0.0) * texture(tex, tc);
	//叠加至银色物体上
    color        = vec4(0.4627, 0.422, 0.45, 0.5) *vs_fs_position.y+ rgba_ref;
}

        