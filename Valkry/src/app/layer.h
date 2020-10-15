#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "window.h"

namespace Valkry {

	// Abstract class that must be inherited. Children will be placed into the application Layer Stack.
	class Layer
	{
	public:
		// Runs only once at startup, use to initialize members etc.
		virtual void OnInit() = 0; 

		// Runs every frame, where most rendering will happen
		virtual void OnUpdate() = 0;

		// Also runs every frame, but recommended to only use for events for organization's sake
		virtual void OnEvent() = 0; 

		// Runs on layer termination
		virtual void OnClose();

	public:
		// Initializes ImGui
		virtual void InitImGui(Window& win);

		// Container function for all your ImGui stuff
		virtual void OnImGuiRender() = 0;

	public:
		void SetName(std::string name);
		std::string GetName();

		// Sets closingflag_ to true
		void CloseProgram();
		bool ReturnClosingFlag();

	private:
		std::string name = "Default Layer Name";
		bool closingflag_ = false;
	};

}