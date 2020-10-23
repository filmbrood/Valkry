#include "valkrypch.h"

#include <glad/glad.h>
#include "renderer2D.h"

namespace Valkry{

	Renderer2D::Renderer2D()
	{
		Logger::Get().LogInfo("Initialized Valkry 2D Renderer");
	}

	void Renderer2D::DrawQuadImpl(Shader& shader, float width, float height, float posx, float posy)
	{
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

	void Renderer2D::DrawQuad(Shader& shader, float width, float height, float posx, float posy)
	{
		if (quadDrawSkipping_ && this->CheckIfQuadOutsideCameraBounds(posx, posy))
		{
			stats_.DrawSkipsInFrame++;
			this->LogExcessiveQuadWarning();
		}
		else
		{
			stats_.DrawCallsInFrame++;
			shader.Bind();
			this->DrawQuadImpl(shader, width, height, posx, posy);
		}
	}

	void Renderer2D::DrawTexturedQuad(Shader& shader, Texture& texture, float width, float height, float posx, float posy)
	{
		if (quadDrawSkipping_ && this->CheckIfQuadOutsideCameraBounds(posx, posy))
		{
			stats_.DrawSkipsInFrame++;
			this->LogExcessiveQuadWarning();
		}
		else
		{
			stats_.DrawCallsInFrame++;
			shader.Bind();
			texture.Bind();
			this->DrawQuadImpl(shader, width, height, posx, posy);
		}
	}

	void Renderer2D::InitQuadBatch(Shader& shader, Texture& texture)
	{
		batchedquads_.shader = &shader;
		batchedquads_.texture = &texture;
	}

	void Renderer2D::AddQuadToBatch(float width, float height, float posx, float posy)
	{
		if (quadDrawSkipping_ && this->CheckIfQuadOutsideCameraBounds(posx, posy))
		{
			stats_.BatchSkipsInFrame++;
			this->LogExcessiveQuadWarning();
		}
		else if (!quadDrawSkipping_ && batchedquads_.vertices.size() > 4000 && !batchWarningShown)
		{
			batchWarningShown = true;
			Logger::Get().LogWarn("Batch renderer receiving too many requests (> 1,000 quads) without quad skipping enabled.");
			Logger::Get().LogWarn("Cannot render batched quads past 1,000. Please re-enable quad skipping.");
			Logger::Get().LogInfo("Dumping log to file...");
			Logger::Get().DumpLogToFile();
			return;
		}
		else
		{
			stats_.BatchDrawsInFrame++;
			Vertex vertices[6];
			vertices[0] = {-0.5f * width + posx, -0.5f * height + posy, 0.0f, 0.0f, 0.0f};
			vertices[1] = { 0.5f * width + posx, -0.5f * height + posy, 0.0f, 1.0f, 0.0f};
			vertices[2] = { 0.5f * width + posx,  0.5f * height + posy, 0.0f, 1.0f, 1.0f};
			vertices[3] = { 0.5f * width + posx,  0.5f * height + posy, 0.0f, 1.0f, 1.0f};
			vertices[4] = {-0.5f * width + posx,  0.5f * height + posy, 0.0f, 0.0f, 1.0f};
			vertices[5] = {-0.5f * width + posx, -0.5f * height + posy, 0.0f, 0.0f, 0.0f};

			for (int i = 0; i < 6; i++)
				batchedquads_.vertices.push_back(vertices[i]);
		}
	}

	void Renderer2D::DrawQuadBatch()
	{
		stats_.DrawCallsInFrame++;
		batchedquads_.shader->Bind();
		batchedquads_.texture->Bind();

		VertexArray vao;
		vao.Bind();

		VertexBuffer vbo;
		vbo.SetData(batchedquads_.vertices.data(),  batchedquads_.vertices.size() * (6 * sizeof(float)));

		VertexAttribArray attrib;
		attrib.SetData(0, 3, 5 * sizeof(float), 0);
		attrib.SetData(1, 2, 5 * sizeof(float), 3 * sizeof(float));

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		batchedquads_.shader->SetMat4("projectionMatrix", projectionmatrix_);
		batchedquads_.shader->SetMat4("viewMatrix", viewmatrix_);
		batchedquads_.shader->SetMat4("modelMatrix", modelMatrix);

		glDrawArrays(GL_TRIANGLES, 0, batchedquads_.vertices.size());
	}

	void Renderer2D::ClearQuadBatch()
	{
		batchedquads_.vertices.clear();
	}

	void Renderer2D::SetProjectionMatrix(float width, float height)
	{
		viewMatrixWidth_ = width / 100;
		viewMatrixHeight_ = height / 100;

		projectionmatrix_ = glm::ortho(0.0f, viewMatrixWidth_, viewMatrixHeight_, 0.0f, -10.0f, 10.0f);
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
		stats_ = {0, 0, 0, 0};
		SetViewMatrix((camera_.GetPosX() * -1) + (viewMatrixWidth_ / 2), (camera_.GetPosY() * -1) + (viewMatrixHeight_ / 2));
	}

	void Renderer2D::SetViewMatrix(float posx, float posy)
	{
		viewmatrix_ = glm::mat4(1.0f);
		viewmatrix_ = glm::translate(viewmatrix_, glm::vec3(posx, posy, -1.0f));
	}

	Renderer2DStats Renderer2D::GetStats()
	{
		return stats_;
	}

	void Renderer2D::SetRenderDistanceOffset(float value)
	{
		if (renderDistanceOffset_ == value)
			return;
		else
		{
			renderDistanceOffset_ = value;
			Logger::Get().LogInfo("Renderer2D render distance offset set", renderDistanceOffset_);
		}

	}

	float Renderer2D::GetRenderDistanceOffset()
	{
		return renderDistanceOffset_;
	}

	void Renderer2D::SetQuadDrawSkipping(bool state)
	{
		quadDrawSkipping_ = state;
		Logger::Get().LogInfo("Renderer2D draw skipping toggled", quadDrawSkipping_);
		batchWarningShown = false;
	}

	bool Renderer2D::CheckIfSkipping()
	{
		return quadDrawSkipping_;
	}

	bool Renderer2D::CheckIfQuadOutsideCameraBounds(float posx, float posy)
	{
		if (posx > camera_.GetPosX() + renderDistanceOffset_ + viewMatrixWidth_ / 2
		|| posy > camera_.GetPosY() + renderDistanceOffset_ + viewMatrixHeight_ / 2
		|| posx < camera_.GetPosX() - renderDistanceOffset_ - viewMatrixWidth_ / 2
		|| posy < camera_.GetPosY() - renderDistanceOffset_ - viewMatrixHeight_ / 2)
			return true;
		else
			return false;
	}

	void Renderer2D::LogExcessiveQuadWarning()
	{
		if (stats_.DrawSkipsInFrame + stats_.DrawCallsInFrame >= 1000000 && !quadWarningShown_)
		{
			Logger::Get().LogWarn("Total draw requests per frame exceeding 1,000,000 quads.");
			quadWarningShown_ = true;
		}
	}
}
