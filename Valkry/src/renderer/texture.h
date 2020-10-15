#pragma once

namespace Valkry {

	// Container class for an OpenGL texture.
	class Texture
	{
	public:
		Texture();
		~Texture();

	public:
		// Loads image from filepath with STB_IMAGE, binds to GL texture.
		void LoadFromPath(const std::string& filepath);

		void Bind();
		void Unbind();

	private:
		unsigned int renderer_id_;
		std::string filepath_;
	};

}