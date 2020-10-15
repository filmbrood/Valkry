#include "valkrypch.h"
#include "glad/glad.h"
#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image/stb_image.h"

namespace Valkry {

	Texture::Texture()
	{
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &renderer_id_);
	}

	void Texture::LoadFromPath(const std::string& filepath)
	{
		filepath_ = filepath;

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);

		glGenTextures(1, &renderer_id_);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, renderer_id_);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			Logger::Get().LogInfo("STB_IMAGE loaded texture from " + filepath);
		}
		else
			Logger::Get().LogError("STB_IMAGE failed to load texture from " + filepath);

		stbi_image_free(data);

		Unbind();
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, renderer_id_);
	}

	void Texture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}
