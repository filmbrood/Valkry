#include "valkrypch.h"

#include "glad/glad.h"
#include "vertexbuffer.h"

namespace Valkry{

	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &renderer_id_);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &renderer_id_);
	}

	void VertexBuffer::SetData(const void* vertices, unsigned int size)
	{
		glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
	}

	void VertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}