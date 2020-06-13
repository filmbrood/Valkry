#include "glad/glad.h"
#include "indexbuffer.h"
#include "../app/logging.h"

namespace Valkry{

	IndexBuffer::IndexBuffer()
	{
		glGenBuffers(1, &renderer_id_);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &renderer_id_);
	}

	void IndexBuffer::SetData(const void* indices, unsigned int size)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
	}

	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
	}

	void IndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}