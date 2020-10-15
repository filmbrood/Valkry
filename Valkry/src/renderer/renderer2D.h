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

	// Class for rendering in 2D. Contains matrices and drawing functions to do so.
	class Renderer2D
	{
	public:
		// Constructor logs that renderer has been created
		Renderer2D();

	public:
		// To be called at the beginning of every frame
		void Update();

		// Creates vertex array with quad vertices, sends model, view, and projection matrices as uniforms to shader, makes draw call to OpenGL
		void DrawQuad(Shader& Shader, float width, float height, float posx, float posy);

		// Like DrawQuad(), but takes in a texture that can be read as a sampler2D uniform by the shader.
		void DrawTexturedQuad(Shader& shader, Texture& texture, float width, float height, float posx, float posy);

		// Sets the orthographic projection matrix
		void SetResolution(float width, float height);

		void SetCameraPosition(float posx, float posy);
		float GetCameraPositionX();
		float GetCameraPositionY();

	private:
		glm::mat4 viewmatrix_ = glm::mat4(1.0f);
		glm::mat4 projectionmatrix_ = glm::mat4(1.0f);

		Camera2D camera_;

		// Sets view matrix based on two float coordinates
		void SetViewMatrix(float posx, float posy);

		// Sets orthographic projection matrix (preferably from screen width and height)
		void SetProjectionMatrix(float width, float height);

	};

}