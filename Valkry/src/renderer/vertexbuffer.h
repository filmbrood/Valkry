#pragma once

namespace Valkry{

	class VertexBuffer
	{
	private:
		unsigned int renderer_id_;

	public:
		// Constructor generates the vertex buffer and binds it to renderer_id_, Destructor deletes the vertex buffer
		VertexBuffer();
		~VertexBuffer();

		// Sets vertex buffer data from an array of vertices
		void SetData(const void* vertices, unsigned int size);

		// Binds and unbinds the vertex buffer for drawing
		void Bind();
		void Unbind();
	};

}