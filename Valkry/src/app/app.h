#pragma once
#include <vector>

#include "window.h"
#include "../renderer/renderer2D.h"
#include "layerstack.h"

namespace Valkry{

	// Class containing layer stack, window, and renderer2D. Acts as singleton, call with Valkry::App::Get().
	class App
	{
	public:
		static App& Get();

		// Initializes all layers in layer stack, call the RunLayers() function of the stack, and checks for closing flags from any of the layers.
		void Run();

		// Pushes a new Layer into the LayerStack.
		void PushLayer(Layer* layer);

		// Removes a layer from the end of the LayerStack.
		void PopLayer();

		// Sets running_ variable to false
		virtual void CloseApp();

	public:
		Window& GetWindow();
		Renderer2D& GetRenderer2D();

	private:
		App() {}
		static App s_Instance;
		Window window_;
		Renderer2D renderer2D_;

		bool running_ = true;
		LayerStack stack_;
		int exitCode_ = 0;
	};
}
