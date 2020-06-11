#pragma once

#include "../app/logging.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "attribarray.h"
#include "shader.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"

namespace valkry {

	class renderer2D
	{
	private:
		glm::mat4 viewMatrix = glm::mat4(1.0f);
		glm::mat4 projectionMatrix = glm::mat4(1.0f);

	public:
		renderer2D();

		void DrawQuad(shader& shader, float width, float height, float posx, float posy);

		void SetProjectionMatrix(float screenWidth, float screenHeight);
		void SetViewMatrix(float posx, float posy);
	};

}