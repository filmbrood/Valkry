#include "glad/glad.h"
#include "indexbuffer.h"
#include "logging.h"

namespace valkry{

	indexbuffer::indexbuffer()
	{
		glGenBuffers(1, &renderer_ID);
	}

	indexbuffer::~indexbuffer()
	{
		glDeleteBuffers(1, &renderer_ID);
	}

	void indexbuffer::setData(const void* indices, unsigned int indicesSize)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
	}

	void indexbuffer::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_ID);
	}

	void indexbuffer::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}