#shader vertex
#version 330 core

layout (location = 0) in vec3 Pos;

void main()
{
	gl_Position = vec4(Pos, 1.0);
}

#shader fragment
#version 330 core

out vec4 color;

void main()
{
	color = vec4(0.0, 0.0, 1.0, 1.0);
}