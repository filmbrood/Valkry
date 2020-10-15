#include "valkrypch.h"
#include "layer.h"

void Valkry::Layer::OnClose()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Valkry::Layer::InitImGui(Window& win)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsLight();

	ImGui_ImplGlfw_InitForOpenGL(win.GetWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void Valkry::Layer::SetName(std::string name)
{
	this->name = name;
}

std::string Valkry::Layer::GetName()
{
	return name;
}

void Valkry::Layer::CloseProgram()
{
	closingflag_ = true;
}

bool Valkry::Layer::ReturnClosingFlag()
{
	return closingflag_;
}
