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
		shader(std::string path);
		~shader();

		void bind();
		void unbind();
	};

}