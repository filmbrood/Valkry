#shader vertex
#version 330 core

layout (location = 0) in vec3 Pos;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(Pos, 1.0);
}

#shader fragment
#version 330 core

layout (location = 0) out vec4 color;

void main()
{
	color = vec4(0.0, 0.0, 1.0, 1.0);
}