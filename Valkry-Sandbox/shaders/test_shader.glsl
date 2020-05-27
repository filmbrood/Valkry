#shader vertex
#version 330 core

layout (location = 0) in vec3 Pos;

out vec4 fragcolor;

void main()
{
	gl_Position = vec4(Pos, 1.0);
	fragcolor = vec4(0.5, 0.5, 0.5, 1.0);
}

#shader fragment
#version 330 core

in vec4 fragcolor;
out vec4 color;

void main()
{
	color = fragcolor;
}