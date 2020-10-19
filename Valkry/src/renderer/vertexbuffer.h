#pragma once

namespace Valkry{

	// Container class for an OpenGL vertex buffer.
	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		// Takes in array of vertices.
		void SetData(const void* vertices, unsigned int size);
		void SetDataDynamic(const void* vertices, unsigned int size);

		void Bind();
		void Unbind();

	private:
		unsigned int renderer_id_;
	};

}
