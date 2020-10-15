#pragma once
#include "vertexbuffer.h"
#include "indexbuffer.h"

namespace Valkry{

	// Container class for an OpenGL VertexArray object.
	class VertexArray
	{
	public:
		// Constructor generates vertex array and binds it to renderer_id_, Destructor deletes the vertex array
		VertexArray();
		~VertexArray();

		void Bind();
		void Unbind();

	private:
		unsigned int renderer_id_;
	};

}
