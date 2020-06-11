#include <glad/glad.h>
#include "renderer2D.h"

namespace valkry{

	renderer2D::renderer2D()
	{
		LogInfo("Initialized Valkry 2D Renderer");
	}

	void renderer2D::DrawQuad(shader& shader, float width, float height, float posx, float posy)
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
		vertexarray vao;
		vao.bind();

		vertexbuffer vbo;
		vbo.setData(vertices, sizeof(vertices));

		attribarray attrib;
		attrib.setData(0, 3, 3 * sizeof(float), 0);

		indexbuffer ibo;
		ibo.setData(indices, sizeof(indices));

		//Bind all necessary things before drawing
		shader.bind();
		vao.bind();

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		modelMatrix = glm::translate(modelMatrix, glm::vec3(posx, posy, 0.0f));

		shader.setMat4("projectionMatrix", projectionMatrix);
		shader.setMat4("viewMatrix", viewMatrix);
		shader.setMat4("modelMatrix", modelMatrix);

		//Draw the quad
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void renderer2D::SetProjectionMatrix(float screenWidth, float screenHeight)
	{
		projectionMatrix = glm::ortho(0.0f, screenWidth, screenHeight, 0.0f, -50.0f, 50.0f);
	}

	void renderer2D::SetViewMatrix(float posx, float posy)
	{
		viewMatrix = glm::mat4(1.0f);
		viewMatrix = glm::translate(viewMatrix, glm::vec3(posx, posy, -1.0f));
	}

}