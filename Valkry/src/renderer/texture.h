#pragma once

namespace Valkry {

	class Texture
	{
	public:
		Texture();
		~Texture();

	public:
		void LoadFromPath(const std::string& filepath);
		void Bind();
		void Unbind();

	private:
		unsigned int renderer_id_;

		std::string filepath_;
	};

}