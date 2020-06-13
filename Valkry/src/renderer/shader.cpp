#include <glad/glad.h>

#include "shader.h"
#include "../app/logging.h"

#include <fstream>
#include <sstream>

namespace Valkry {

	void Shader::SetSource(std::string path)
	{
		// Parsing shader file, looking for vertex and fragment code
		filepath_ = path;

		std::ifstream stream;
		std::string line;
		std::stringstream ss[2];

		stream.open(filepath_);

		enum class shaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		shaderType type = shaderType::NONE;
		while (getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
					type = shaderType::VERTEX;
				else if (line.find("fragment") != std::string::npos)
					type = shaderType::FRAGMENT;
			}
			else
			{
				ss[(int)type] << line << "\n";
			}
		}

		// Send stringstream arrays into shader source strings
		vertexsource_ = ss[0].str();
		fragmentsource_ = ss[1].str();

		const char* vertexsrc_char = vertexsource_.c_str();
		const char* fragmentsrc_char = fragmentsource_.c_str();

		// Compile vertex and fragment shaders
		unsigned int vertex, fragment;
		int success;
		char infolog[512];

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexsrc_char, NULL);
		glCompileShader(vertex);

		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infolog);
			LogError("Vertex shader compilation failed");
			LogError(infolog);
		}

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentsrc_char, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infolog);
			LogError("Vertex shader compilation failed");
			LogError(infolog);
		}

		renderer_id_ = glCreateProgram();
		glAttachShader(renderer_id_, vertex);
		glAttachShader(renderer_id_, fragment);
		glLinkProgram(renderer_id_);

		glGetProgramiv(renderer_id_, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(renderer_id_, 512, NULL, infolog);
			LogError("Shader linking failed");
			LogError(infolog);
		}
		else
			LogInfo("Created shader program with render ID ", renderer_id_);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void Shader::Bind()
	{
		glUseProgram(renderer_id_);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::SetFloat(const std::string name, float value)
	{
		auto location = glGetUniformLocation(renderer_id_, name.c_str());
		if (location < -1)
			LogError("Uniform location not found", renderer_id_);
		glUniform1f(location, value);
	}

	void Shader::SetInt(const std::string name, int value)
	{
		auto location = glGetUniformLocation(renderer_id_, name.c_str());
		if (location < -1)
			LogError("Uniform location not found", renderer_id_);
		glUniform1i(location, value);
	}

	void Shader::SetBool(const std::string name, int value)
	{
		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1)
			LogError("Uniform location not found", renderer_id_);

		glUniform1i(location, (int)value);
	}

	void Shader::SetVec2(const std::string name, float value1, float value2)
	{
		glm::vec2 value = glm::vec2(value1, value2);

		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1)
			LogError("Uniform location not found", renderer_id_);

		glUniform2fv(location, 1, glm::value_ptr(value));
	}

	void Shader::SetVec3(const std::string name, float value1, float value2, float value3)
	{
		glm::vec3 value = glm::vec3(value1, value2, value3);
		glUniform3fv(glGetUniformLocation(renderer_id_, name.c_str()), 1, glm::value_ptr(value));
	}

	void Shader::SetMat4(const std::string name, glm::mat4 value)
	{
		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1)
			LogError("Uniform location not found", renderer_id_);

		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

}