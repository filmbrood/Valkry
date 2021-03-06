#include "valkrypch.h"

#include "glad/glad.h"
#include "vertexarray.h"

namespace Valkry{

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &renderer_id_);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &renderer_id_);
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