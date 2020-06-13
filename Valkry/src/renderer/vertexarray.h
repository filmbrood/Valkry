#pragma once
#include "vertexbuffer.h"
#include "indexbuffer.h"

namespace Valkry{

	class VertexArray
	{
	private:
		unsigned int renderer_id_;

	public:
		// Constructor generates vertex array and binds it to renderer_id_, Destructor deletes the vertex array
		VertexArray();
		~VertexArray();

		// Binds an vertex and index buffer to the array
		void SetData(VertexBuffer& vertex, IndexBuffer& index);

		// Binds and unbinds vertex array for drawing
		void Bind();
		void Unbind();
	};

}
