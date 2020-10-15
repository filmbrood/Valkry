#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "window.h"

namespace Valkry {

	class Layer
	{
	public: // Automatically called by application layer stack
		virtual void OnInit() = 0; // Runs only once at startup, use to initialize members etc.
		virtual void OnUpdate() = 0; // Runs every frame, where most rendering will happen
		virtual void OnEvent() = 0; // Also runs every frame, but recommended to only use for events for organization's sake
		virtual void OnClose(); // Runs on layer termination
	public:
		virtual void InitImGui(Window& win); // Initializes ImGui
		virtual void OnImGuiRender() = 0; // Container function for all your ImGui stuff

	public:
		void SetName(std::string name);
		std::string GetName();
		void CloseProgram();
		bool ReturnClosingFlag();

	private:
		std::string name = "Default Layer Name";
		bool closingflag_ = false;
	};

}