#include "attribarray.h"
#include "glad/glad.h"

namespace valkry{

	void attribarray::setData(unsigned int ID, unsigned int size, unsigned int stride, unsigned int offset)
	{
		renderer_ID = ID;
		glVertexAttribPointer(renderer_ID, size, GL_FLOAT, GL_FALSE, stride, (void*)offset);
	}

	void attribarray::enable()
	{
		glEnableVertexAttribArray(renderer_ID);
	}

}