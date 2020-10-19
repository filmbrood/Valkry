#version 410 core

out vec4 outColor;

in vec2 uTexUV;

uniform sampler2D uTexture;

void main()
{
	outColor = texture(uTexture, uTexUV);
}
