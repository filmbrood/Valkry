#shader vertex
#version 410 core

layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 TexUV;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec2 uTexUV;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(Pos, 1.0);
	uTexUV = TexUV;
}

#shader fragment
#version 410 core

out vec4 outColor;

in vec2 uTexUV;

uniform sampler2D uTexture;

void main()
{
	outColor = texture(uTexture, uTexUV);
}
