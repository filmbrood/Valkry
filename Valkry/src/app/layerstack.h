#pragma once

#include <vector>

#include "layer.h"

namespace Valkry {

	// Container class for a vector of Layers. Controls and runs through each as program runs.
	class LayerStack
	{
	public:
		// Pushes layer to end of layers_ vector
		void PushLayer(Layer* layer); 

		// Removes layer at end of layers_ vector
		void PopLayer(); 

		// Runs OnInit() function in all layers - intended to only be ran once
		void InitLayers(); 

		// Runs OnUpdate() and OnEvent() functions for all layers in a continuous loop
		void RunLayers(); 

		// Checks if any closing flag events were set to true, then tells the App object to set the running_ variable to false, closing the program
		bool CheckForClosingFlags(); 

	public:
		// Destructor calls all OnClose() functions for every layer in layers_ vector
		~LayerStack();

	private:
		std::vector<Layer*> layers_;
		bool programShouldClose_ = false;
	};
}
