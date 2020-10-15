#pragma once

namespace Valkry{

	// Container class for an OpenGL index buffer (element array buffer).
	class IndexBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();
		void SetData(const void* indices, unsigned int size);
		void Bind();
		void Unbind();

	private:
		unsigned int renderer_id_;
	};

}

