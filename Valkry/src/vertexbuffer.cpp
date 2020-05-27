#include "glad/glad.h"
#include "vertexbuffer.h"

namespace valkry{

	vertexbuffer::vertexbuffer()
	{
		glGenBuffers(1, &renderer_ID);
	}

	vertexbuffer::~vertexbuffer()
	{
		glDeleteBuffers(1, &renderer_ID);
	}

	void vertexbuffer::setData(const void* vertices, unsigned int verticesSize)
	{
		glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
	}

	void vertexbuffer::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, renderer_ID);
	}

	void vertexbuffer::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}