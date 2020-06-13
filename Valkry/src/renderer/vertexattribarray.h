#pragma once

namespace Valkry {

	class VertexAttribArray
	{
	private:
		unsigned int renderer_id_;

	public:
		void SetData(unsigned int id, unsigned int size, unsigned int stride, unsigned int offset);
	};

}

