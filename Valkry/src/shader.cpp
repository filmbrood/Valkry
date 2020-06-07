#include <glad/glad.h>

#include "shader.h"
#include <fstream>
#include <sstream>
#include "logging.h"

namespace valkry {

	shader::shader()
	{
		
	}

	shader::~shader()
	{

	}

	void shader::setSource(std::string path)
	{
		filepath = path;

		std::ifstream stream;
		std::string line;
		std::stringstream ss[2];

		stream.open(filepath);

		enum class shaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};

		// Parsing shader file, looking for vertex and fragment code
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
		vertexsrc = ss[0].str();
		fragmentsrc = ss[1].str();

		const char* vertexsrc_char = vertexsrc.c_str();
		const char* fragmentsrc_char = fragmentsrc.c_str();

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

		renderer_ID = glCreateProgram();
		glAttachShader(renderer_ID, vertex);
		glAttachShader(renderer_ID, fragment);
		glLinkProgram(renderer_ID);

		glGetProgramiv(renderer_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(renderer_ID, 512, NULL, infolog);
			LogError("Shader linking failed");
			LogError(infolog);
		}
		else
			LogInfo("Created shader program with render ID ", renderer_ID);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void shader::bind()
	{
		glUseProgram(renderer_ID);
	}

	void shader::unbind()
	{
		glUseProgram(0);
	}

	void shader::setFloat(const std::string name, float value)
	{
		auto location = glGetUniformLocation(renderer_ID, name.c_str());
		if (location < -1)
			LogError("Uniform location not found", renderer_ID);
		glUniform1f(location, value);
	}

	void shader::setInt(const std::string name, int value)
	{
		auto location = glGetUniformLocation(renderer_ID, name.c_str());
		if (location < -1)
			LogError("Uniform location not found", renderer_ID);
		glUniform1i(location, value);
	}

	void shader::setBool(const std::string name, int value)
	{
		auto location = glGetUniformLocation(renderer_ID, name.c_str());

		if (location < -1)
			LogError("Uniform location not found", renderer_ID);

		glUniform1i(location, (int)value);
	}

	void shader::setVec2(const std::string name, float value1, float value2)
	{
		glm::vec2 value = glm::vec2(value1, value2);

		auto location = glGetUniformLocation(renderer_ID, name.c_str());

		if (location < -1)
			LogError("Uniform location not found", renderer_ID);

		glUniform2fv(location, 1, glm::value_ptr(value));
	}

	void shader::setVec3(const std::string name, float value1, float value2, float value3)
	{
		glm::vec3 value = glm::vec3(value1, value2, value3);
		glUniform3fv(glGetUniformLocation(renderer_ID, name.c_str()), 1, glm::value_ptr(value));
	}

	void shader::setMat4(const std::string name, glm::mat4 value)
	{
		auto location = glGetUniformLocation(renderer_ID, name.c_str());

		if (location < -1)
			LogError("Uniform location not found", renderer_ID);

		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

}