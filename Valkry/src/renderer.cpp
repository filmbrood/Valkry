#include <glad/glad.h>
#include "renderer.h"

namespace valkry{

	void renderer::DrawQuad(shader& shader, float width, float height)
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
		vao.bind();
		vbo.bind();
		ibo.bind();
		shader.bind();

		//Draw the quad
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

}