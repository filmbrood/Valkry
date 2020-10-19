#pragma once
#include <vector>

#include "window.h"
#include "layerstack.h"

namespace Valkry{

	// Abstract class that must be inherited by applications using Valkry. Also acts as a container class for a LayerStack.
	class App
	{
	public:
		// Initializes all layers in layer stack, call the RunLayers() function of the stack, and checks for closing flags from any of the layers.
		void Run();

		// Pushes a new Layer into the LayerStack.
		void PushLayer(Layer* layer);

		// Removes a layer from the end of the LayerStack.
		void PopLayer();

		// Sets running_ variable to false
		virtual void CloseApp();

	private:
		bool running_ = true;
		LayerStack stack_;
		int exitCode_ = 0;
	};
}
