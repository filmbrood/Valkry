#pragma once

namespace valkry{

	class indexbuffer
	{
	private:
		unsigned int renderer_ID;

	public:
		indexbuffer();
		~indexbuffer();

		void setData(const void* indices, unsigned int indicesSize);
		void bind();
		void unbind();
	};

}

