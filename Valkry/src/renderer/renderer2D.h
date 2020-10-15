#pragma once

#include "../app/logging.h"
#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "vertexattribarray.h"
#include "shader.h"
#include "camera2D.h"
#include "texture.h"

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

		Camera2D camera_;

		// Sets view matrix based on two float coordinates
		void SetViewMatrix(float posx, float posy);

		// Sets orthographic projection matrix (preferably from screen width and height)
		void SetProjectionMatrix(float width, float height);

	public:
		// Constructor logs that renderer has been created
		Renderer2D();

		// Creates vertex array with quad vertices, sends model, view, and projection matrices as uniforms to shader
		void DrawQuad(Shader& Shader, float width, float height, float posx, float posy);

		void DrawTexturedQuad(Shader& shader, Texture& texture, float width, float height, float posx, float posy);

		// Sets the orthographic projection matrix based on resolution arguments
		void SetResolution(float width, float height);

		// Camera controllers
		void SetCameraPosition(float posx, float posy);
		float GetCameraPositionX();
		float GetCameraPositionY();

		// To be called at the beginning of every frame
		void Update();
	};

}