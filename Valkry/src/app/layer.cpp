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
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	ImGui::StyleColorsLight();

	ImGui_ImplGlfw_InitForOpenGL(win.GetWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 330");

	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}
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
