#include "attribarray.h"
#include "glad/glad.h"
#include "logging.h"

namespace valkry{

	void attribarray::setData(unsigned int ID, unsigned int size, unsigned int stride, unsigned int offset)
	{
		renderer_ID = ID;
		glVertexAttribPointer(renderer_ID, size, GL_FLOAT, GL_FALSE, stride, (void*)offset);
		LogInfo("Set vertex attrib array", renderer_ID);
	}

	void attribarray::enable()
	{
		glEnableVertexAttribArray(renderer_ID);
	}

}