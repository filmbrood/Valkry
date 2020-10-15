#pragma once

namespace Valkry {

	// Container class for an OpenGL Vertex attribute array.
	class VertexAttribArray
	{
	public:
		void SetData(unsigned int id, unsigned int size, unsigned int stride, unsigned int offset);

	private:
		unsigned int renderer_id_;
	};

}

