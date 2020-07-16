#pragma once
#include <string>

#include "glm.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"

namespace Valkry {

	class Shader
	{
	private:
		unsigned int renderer_id_;
		std::string filepath_;
		std::string vertexsource_;
		std::string fragmentsource_;

		void ParseSource();
		void CompileSource();

	public:
		// Retrieves GLSL source file from argument path, parses, compiles, and links the vertex and fragment sources into a shader program
		void SetSource(std::string path);

		// Binds and unbinds the shader program for drawing
		void Bind();
		void Unbind();

		// Sets shader uniforms
		void SetFloat(const std::string name, float value);
		void SetInt(const std::string name, int value);
		void SetBool(const std::string name, int value);
		void SetVec2(const std::string name, float value1, float value2);
		void SetVec3(const std::string name, float value1, float value2, float value3);
		void SetMat4(const std::string name, glm::mat4 value);
	};

}