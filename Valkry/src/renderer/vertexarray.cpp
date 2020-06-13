#include "glad/glad.h"
#include "vertexarray.h"
#include "../app/logging.h"

namespace Valkry{

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &renderer_id_);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &renderer_id_);
	}

	void VertexArray::SetData(VertexBuffer& vertex, IndexBuffer& index)
	{
		Bind();
		vertex.Bind();
		index.Bind();
		Unbind();
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(renderer_id_);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

}