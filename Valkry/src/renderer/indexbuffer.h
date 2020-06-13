#pragma once

namespace Valkry{

	class IndexBuffer
	{
	private:
		unsigned int renderer_id_;

	public:
		IndexBuffer();
		~IndexBuffer();

		void SetData(const void* indices, unsigned int size);
		void Bind();
		void Unbind();
	};

}

