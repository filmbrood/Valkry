#include "valkrypch.h"
#include "layer.h"

void Valkry::Layer::OnClose()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	Logger::Get().LogInfo("Closing layer " + this->GetName());
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

void Valkry::Layer::BeginImGuiFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Valkry::Layer::EndImGuiFrame()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
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
