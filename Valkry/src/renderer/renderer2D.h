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

	struct Renderer2DStats
	{
		unsigned int DrawCallsInFrame = 0;
		unsigned int DrawSkipsInFrame = 0;
		unsigned int BatchSkipsInFrame = 0;
		unsigned int BatchDrawsInFrame = 0;
	};

	// Vertex struct - mainly used in batch rendering, will be added to normal rendering
	struct Vertex
	{
		float x = 0, y = 0, z = 0, uvx = 0, uvy = 0;
	};

	// Struct containing vertex data for batch drawing.
	// Only contains a single shader and texture, so multiple batches will have to be used for different textures/shaders.
	struct BatchedQuads
	{
		std::vector<Vertex> vertices;
		Shader* shader;
		Texture* texture;
	};

	// Class for rendering in 2D. Contains matrices and drawing functions to do so.
	class Renderer2D
	{
	public:
		// Constructor logs that renderer has been created
		Renderer2D();

	public:
		// To be called at the beginning of every frame
		void Update();

		// Draws simple quad with shader only.
		void DrawQuad(Shader& Shader, float width, float height, float posx, float posy);

		// Draws quad with texture for use with shaders that have a sampler2D uniform.
		void DrawTexturedQuad(Shader& shader, Texture& texture, float width, float height, float posx, float posy);

		void InitQuadBatch(Shader& shader, Texture& texture);
		void AddQuadToBatch(float width, float height, float posx, float posy);
		void DrawQuadBatch();
		void ClearQuadBatch();

	public:
		// Sets the orthographic projection matrix
		void SetProjectionMatrix(float width, float height);

		void SetCameraPosition(float posx, float posy);
		float GetCameraPositionX();
		float GetCameraPositionY();

		void SetCameraZoom(float value);
		float GetCameraZoom();
		
		Renderer2DStats GetStats();

		void SetRenderDistanceOffset(float value);
		float GetRenderDistanceOffset();

		void SetQuadDrawSkipping(bool state);
		bool CheckIfSkipping();

	private:
		// Called by DrawQuad and DrawTexturedQuad. Binds a vertex array w/ necessary data before calling glDrawElements().
		void DrawQuadImpl(Shader& shader, float width, float height, float posx, float posy);

	private:
		Camera2D camera_;
		Renderer2DStats stats_;

		BatchedQuads batchedquads_;

	private:
		void LogExcessiveQuadWarning();
		bool quadWarningShown_ = false;
		bool batchWarningShown = false;

		// Sets view matrix based on two float coordinates
		void SetViewMatrix(float posx, float posy);
		glm::mat4 viewmatrix_ = glm::mat4(1.0f);
		float viewMatrixHeight_, viewMatrixWidth_;
		float renderDistanceOffset_ = 0.5;

		glm::mat4 projectionmatrix_ = glm::mat4(1.0f);

		bool CheckIfQuadOutsideCameraBounds(float posx, float posy);
		bool quadDrawSkipping_ = true;
	};

}
