#pragma once
#include <string>

#include "glm.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"

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

		void setFloat(const std::string name, float value);
		void setInt(const std::string name, int value);
		void setBool(const std::string name, int value);
		void setVec2(const std::string name, float value1, float value2);
		void setVec3(const std::string name, float value1, float value2, float value3);
		void setMat4(const std::string name, glm::mat4 value);
	};

}