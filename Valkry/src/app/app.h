#pragma once
#include <vector>

#include "window.h"
#include "layerstack.h"

namespace Valkry{

	class App
	{
	private:
		bool running_ = true;

		LayerStack stack_;
	public:

		void Run();

		void PushLayer(Layer* layer);
		void PopLayer();

		// Sets running_ variable to false
		virtual void CloseApp();
	};
}