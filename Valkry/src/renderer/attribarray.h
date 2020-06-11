#pragma once

namespace valkry {

	class attribarray
	{
	private:
		unsigned int renderer_ID;

	public:
		void setData(unsigned int ID, unsigned int size, unsigned int stride, unsigned int offset);
	};

}

