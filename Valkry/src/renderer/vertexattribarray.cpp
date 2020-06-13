#include "vertexattribarray.h"
#include "glad/glad.h"
#include "../app/logging.h"

namespace Valkry{

	void VertexAttribArray::SetData(unsigned int id, unsigned int size, unsigned int stride, unsigned int offset)
	{
		renderer_id_ = id;
		glEnableVertexAttribArray(renderer_id_);
		glVertexAttribPointer(renderer_id_, size, GL_FLOAT, GL_FALSE, stride, (void*)offset);
	}

}