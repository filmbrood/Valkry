#include "valkrypch.h"

#include <glad/glad.h>
#include "renderer2D.h"

namespace Valkry{

	Renderer2D::Renderer2D()
	{
		Logger::Get().LogInfo("Initialized Valkry 2D Renderer");
	}

	void Renderer2D::DrawQuad(Shader& shader, float width, float height, float posx, float posy)
	{
		shader.Bind();

		// Create data for drawing quad
		float vertices[] = {
			-0.5f * width, -0.5f * height, 0.0f,
			 0.5f * width, -0.5f * height, 0.0f,
			 0.5f * width,  0.5f * height, 0.0f,
			-0.5f * width,  0.5f * height, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		//Bind the vertex array, vertex buffer and attrib arrays, and then index buffer
		VertexArray vao;
		vao.Bind();

		VertexBuffer vbo;
		vbo.SetData(vertices, sizeof(vertices));

		VertexAttribArray attrib;
		attrib.SetData(0, 3, 3 * sizeof(float), 0);

		IndexBuffer ibo;
		ibo.SetData(indices, sizeof(indices));

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(posx, posy, 0.0f));

		shader.SetMat4("projectionMatrix", projectionmatrix_);
		shader.SetMat4("viewMatrix", viewmatrix_);
		shader.SetMat4("modelMatrix", modelMatrix);

		//Draw the quad
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void Renderer2D::DrawTexturedQuad(Shader& shader, Texture& texture, float width, float height, float posx, float posy)
	{
		shader.Bind();
		texture.Bind();

		// Create data for drawing quad
		float vertices[] = {
			-0.5f * width, -0.5f * height, 0.0f, 0.0f, 0.0f,
			 0.5f * width, -0.5f * height, 0.0f, 1.0f, 0.0f,
			 0.5f * width,  0.5f * height, 0.0f, 1.0f, 1.0f,
			-0.5f * width,  0.5f * height, 0.0f, 0.0f, 1.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		// Bind the vertex array, vertex buffer and attrib arrays, and then index buffer
		VertexArray vao;
		vao.Bind();

		VertexBuffer vbo;
		vbo.SetData(vertices, sizeof(vertices));

		VertexAttribArray attrib;
		attrib.SetData(0, 3, 5 * sizeof(float), 0);
		attrib.SetData(1, 2, 5 * sizeof(float), 3 * sizeof(float));

		IndexBuffer ibo;
		ibo.SetData(indices, sizeof(indices));

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(posx, posy, 0.0f));

		shader.SetMat4("projectionMatrix", projectionmatrix_);
		shader.SetMat4("viewMatrix", viewmatrix_);
		shader.SetMat4("modelMatrix", modelMatrix);

		// Draw the quad
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void Renderer2D::SetResolution(float width, float height)
	{
		SetProjectionMatrix(width, height);
	}

	void Renderer2D::SetCameraPosition(float x, float y)
	{
		camera_.SetPosX(x);
		camera_.SetPosY(y);
	}

	float Renderer2D::GetCameraPositionX()
	{
		return camera_.GetPosX();
	}

	float Renderer2D::GetCameraPositionY()
	{
		return camera_.GetPosY();
	}

	void Renderer2D::Update()
	{
		SetViewMatrix(camera_.GetPosX() * -1, camera_.GetPosY() * -1);
	}

	void Renderer2D::SetProjectionMatrix(float width, float height)
	{
		projectionmatrix_ = glm::ortho(0.0f, width, height, 0.0f, -100.0f, 100.0f);
	}

	void Renderer2D::SetViewMatrix(float posx, float posy)
	{
		viewmatrix_ = glm::mat4(1.0f);
		viewmatrix_ = glm::translate(viewmatrix_, glm::vec3(posx, posy, -1.0f));
	}

}
