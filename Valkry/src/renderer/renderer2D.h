#pragma once

#include "../app/logging.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "vertexattribarray.h"
#include "shader.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"

namespace Valkry {

	class Renderer2D
	{
	private:
		glm::mat4 viewmatrix_ = glm::mat4(1.0f);
		glm::mat4 projectionmatrix_ = glm::mat4(1.0f);

	public:
		// Constructor logs that renderer has been created
		Renderer2D();

		// Creates vertex array with quad vertices, sends model, view, and projection matrices as uniforms to shader
		void DrawQuad(Shader& Shader, float width, float height, float posx, float posy);

		// Sets orthographic projection matrix (preferably from screen width and height)
		void SetProjectionMatrix(float width, float height);

		// Sets view matrix based on two float coordinates, but will eventually take in a view matrix from dedicated orthographic camera object
		void SetViewMatrix(float posx, float posy);
	};

}