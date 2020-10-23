#include "valkrypch.h"

#include <glad/glad.h>

#include "shader.h"

namespace Valkry {

	void Shader::ParseSource()
	{
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
	}

	void Shader::CompileSource()
	{
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
			Logger::Get().LogError("Vertex shader compilation failed");
			Logger::Get().LogError(infolog);
		}

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentsrc_char, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infolog);
			Logger::Get().LogError("Vertex shader compilation failed");
			Logger::Get().LogError(infolog);
		}

		renderer_id_ = glCreateProgram();
		glAttachShader(renderer_id_, vertex);
		glAttachShader(renderer_id_, fragment);
		glLinkProgram(renderer_id_);

		glGetProgramiv(renderer_id_, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(renderer_id_, 512, NULL, infolog);
			Logger::Get().LogError("Shader linking failed");
			Logger::Get().LogError(infolog);
		}
		else
			Logger::Get().LogInfo("Created shader program with render ID " + std::to_string(renderer_id_));

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void Shader::SetSource(const std::string& path)
	{
		// Parsing shader file, looking for vertex and fragment code
		filepath_ = path;

		this->ParseSource();
		this->CompileSource();
	}

	void Shader::SetSeparateSource(const std::string& vertexpath, const std::string& fragmentpath)
	{
		this->SetVertexSource(vertexpath);
		this->SetFragmentSource(fragmentpath);
		this->CompileSource();
	}

	void Shader::SetVertexSource(const std::string& path)
	{
		std::ifstream stream;
		std::string line;
		std::stringstream ss;
		stream.open(path);
		while (getline(stream, line))
			ss << line << "\n";
		vertexsource_ = ss.str();
		stream.close();
	}

	void Shader::SetFragmentSource(const std::string& path)
	{
		std::ifstream stream;
		std::string line;
		std::stringstream ss;
		stream.open(path);
		while(getline(stream, line))
			ss << line << "\n";
		fragmentsource_ = ss.str();
		stream.close();
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

		if (location < -1) this->LogUniformNotFoundError(name);

		glUniform1f(location, value);
	}

	void Shader::SetInt(const std::string name, int value)
	{
		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1) this->LogUniformNotFoundError(name);

		glUniform1i(location, value);
	}

	void Shader::SetBool(const std::string name, int value)
	{
		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1) this->LogUniformNotFoundError(name);

		glUniform1i(location, (int)value);
	}

	void Shader::SetVec2(const std::string name, float value1, float value2)
	{
		glm::vec2 value = glm::vec2(value1, value2);

		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1) this->LogUniformNotFoundError(name);

		glUniform2fv(location, 1, glm::value_ptr(value));
	}

	void Shader::SetVec3(const std::string name, float value1, float value2, float value3)
	{
		glm::vec3 value = glm::vec3(value1, value2, value3);

		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1) this->LogUniformNotFoundError(name);

		glUniform3fv(location, 1, glm::value_ptr(value));
	}

	void Shader::SetVec4(const std::string name, float value1, float value2, float value3, float value4)
	{
		glm::vec4 value = glm::vec4(value1, value2, value3, value4);

		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1) this->LogUniformNotFoundError(name);

		glUniform4fv(location, 1, glm::value_ptr(value));
	}

	void Shader::SetMat4(const std::string name, glm::mat4 value)
	{
		auto location = glGetUniformLocation(renderer_id_, name.c_str());

		if (location < -1) this->LogUniformNotFoundError(name);

		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

	void Shader::LogUniformNotFoundError(const std::string& name)
	{
		Logger::Get().LogError("Uniform '" + name + "' location not found" + std::to_string(renderer_id_));
	}
}
