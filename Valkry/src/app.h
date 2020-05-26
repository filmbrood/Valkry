#pragma once

namespace valkry{

	class app
	{
	public:

		app();
		~app();

		virtual void Run() = 0;
	};

	//define in application
	app* createapp();

}