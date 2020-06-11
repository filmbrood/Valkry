#include "glad/glad.h"
#include "vertexarray.h"
#include "../app/logging.h"

namespace valkry{

	vertexarray::vertexarray()
	{
		glGenVertexArrays(1, &renderer_ID);
	}

	vertexarray::~vertexarray()
	{
		glDeleteVertexArrays(1, &renderer_ID);
	}

	void vertexarray::setData(vertexbuffer& vertex, indexbuffer& index)
	{
		bind();
		vertex.bind();
		index.bind();
		unbind();
	}

	void vertexarray::bind()
	{
		glBindVertexArray(renderer_ID);
	}

	void vertexarray::unbind()
	{
		glBindVertexArray(0);
	}

}