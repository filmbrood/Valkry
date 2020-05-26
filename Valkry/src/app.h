#pragma once

namespace valkry{

	class app
	{
	private:

	public:
		app();
		~app();

		virtual void run() = 0;
	};

	//define in application
	app* createapp();

}