#pragma once

namespace valkry{

	class vertexbuffer
	{
	private:
		unsigned int renderer_ID;

	public:
		vertexbuffer();
		~vertexbuffer();

		void setData(const void* vertices, unsigned int verticesSize);
		void bind();
		void unbind();
	};

}