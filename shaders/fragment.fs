#version 330

in vec4 v_color;

out vec4 color;

uniform float u_time;

void main()
{
	color = vec4(
		abs(sin(u_time) * v_color.x),
		abs(cos(u_time) * v_color.y),
		abs(tan(u_time) * v_color.z),
		v_color.w
	);
}