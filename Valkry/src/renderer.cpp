#include <glad/glad.h>
#include "renderer.h"

namespace valkry{

<<<<<<< HEAD
	renderer::renderer()
	{
		LogInfo("Initialized Valkry Renderer");
	}

=======
>>>>>>> 0e68f78c2250b45f71aa8f95faa8ef55a86cfafd
	void renderer::DrawQuad(shader& shader, float width, float height, float posx, float posy)
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

	void renderer::SetProjectionMatrix(float screenWidth, float screenHeight)
	{
<<<<<<< HEAD
		projectionMatrix = glm::ortho(0.0f, screenWidth, screenHeight, 0.0f, -50.0f, 50.0f);
=======
		projectionMatrix = glm::perspective(glm::radians(70.0f), screenWidth / screenHeight, 0.0f, 100.0f);
>>>>>>> 0e68f78c2250b45f71aa8f95faa8ef55a86cfafd
	}

	void renderer::SetViewMatrix(float posx, float posy)
	{
		viewMatrix = glm::mat4(1.0f);
		viewMatrix = glm::translate(viewMatrix, glm::vec3(posx, posy, -1.0f));
	}

}