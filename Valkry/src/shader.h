#pragma once
#include <string>

namespace valkry {

	class shader
	{
	private:
		unsigned int renderer_ID;
		std::string filepath;
		std::string vertexsrc;
		std::string fragmentsrc;

	public:
		shader();
		~shader();

		void setSource(std::string path);
		void bind();
		void unbind();
	};

}