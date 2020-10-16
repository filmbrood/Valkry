#shader vertex
#version 330 core

layout (location = 0) in vec3 Pos;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

uniform vec4 color;

out vec4 uColor;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(Pos, 1.0);
	uColor = color;
}

#shader fragment
#version 330 core

layout (location = 0) out vec4 outColor;

in vec4 uColor;

void main()
{
	outColor = uColor;
}
