#include "valkrypch.h"

#include <glad/glad.h>
#include "renderer2D.h"

namespace Valkry{

	Renderer2D::Renderer2D()
	{
		LogInfo("Initialized Valkry 2D Renderer");
	}

	void Renderer2D::DrawQuad(Shader& shader, float width, float height, float posx, float posy)
	{
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

		//Bind all necessary things before drawing
		shader.Bind();
		vao.Bind();

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(posx, posy, 0.0f));

		shader.SetMat4("projectionMatrix", projectionmatrix_);
		shader.SetMat4("viewMatrix", viewmatrix_);
		shader.SetMat4("modelMatrix", modelMatrix);

		//Draw the quad
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void Renderer2D::SetProjectionMatrix(float width, float height)
	{
		projectionmatrix_ = glm::ortho(0.0f, width, height, 0.0f, -50.0f, 50.0f);
	}

	void Renderer2D::SetViewMatrix(float posx, float posy)
	{
		viewmatrix_ = glm::mat4(1.0f);
		viewmatrix_ = glm::translate(viewmatrix_, glm::vec3(posx, posy, -1.0f));
	}

}