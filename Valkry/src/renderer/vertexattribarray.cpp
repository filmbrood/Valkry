#include "valkrypch.h"

#include "vertexattribarray.h"
#include "glad/glad.h"

namespace Valkry{

	void VertexAttribArray::SetData(unsigned int id, unsigned int size, unsigned int stride, unsigned int offset)
	{
		renderer_id_ = id;
		glVertexAttribPointer(renderer_id_, size, GL_FLOAT, GL_FALSE, stride, (void*)offset);
		glEnableVertexAttribArray(renderer_id_);
	}

}