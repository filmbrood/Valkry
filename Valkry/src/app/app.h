#pragma once
#include "window.h"

namespace Valkry{

	class App
	{
	private:
		bool running_ = true;

	public:
		// Calls OnInit(), then OnUpdate() and OnEvent() on while loop as long as running_ is true
		void Run();

		// Sets running_ variable to false
		virtual void CloseApp();

		// Interface methods - must be defined in child app classes
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent() = 0;
	};

	// Must be defined in application
	App* CreateApp();
}