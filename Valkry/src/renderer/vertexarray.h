#pragma once
#include "vertexbuffer.h"
#include "indexbuffer.h"

namespace valkry{

	class vertexarray
	{
	private:
		unsigned int renderer_ID;

	public:
		vertexarray();
		~vertexarray();

		void setData(vertexbuffer& vertex, indexbuffer& index);
		void bind();
		void unbind();
	};

}
