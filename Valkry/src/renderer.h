#pragma once

#include "logging.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "attribarray.h"
#include "shader.h"

namespace valkry {

	class renderer
	{
	private:

	public:
		void DrawQuad(shader& shader, float width, float height);
	};

}