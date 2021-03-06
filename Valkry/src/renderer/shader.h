#pragma once
#include <string>

#include "glm.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"

namespace Valkry {

	// Container class for an OpenGL shader program.
	class Shader
	{

	public:
		// Retrieves GLSL source file from argument path.
		// For use with vertex + fragment shader in one file. Denote use with "#shader vertex" and "#shader fragment".
		void SetSource(const std::string& path);

		// Retrieves GLSL source files as separate Vertex and Fragment source.
		void SetSeparateSource(const std::string& vertexpath, const std::string& fragmentpath);

		void Bind();
		void Unbind();

		void SetFloat(const std::string name, float value);
		void SetInt(const std::string name, int value);
		void SetBool(const std::string name, int value);
		void SetVec2(const std::string name, float value1, float value2);
		void SetVec3(const std::string name, float value1, float value2, float value3);
		void SetVec4(const std::string name, float value1, float value2, float value3, float value4);
		void SetMat4(const std::string name, glm::mat4 value);

	private:
		unsigned int renderer_id_;
		std::string filepath_;
		std::string vertexsource_;
		std::string fragmentsource_;

		void SetVertexSource(const std::string& path);
		void SetFragmentSource(const std::string& path);

		// Parses single source file into vertexsource_ and fragmentsource_ strings
		void ParseSource();

		// Compiles vertex and fragment shaders, links into program
		void CompileSource();

		void LogUniformNotFoundError(const std::string& name);
	};

}
