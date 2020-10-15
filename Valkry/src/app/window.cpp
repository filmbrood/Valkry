#include "valkrypch.h"
#include <glad/glad.h>

#include "window.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Valkry {

	Window::Window()
	{
		if (!glfwInit())
			Logger::Get().LogError("GLFW failed to initialize");
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::Create()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (fullscreen_)
			window_ = glfwCreateWindow(size_x_, size_y_, title_.c_str(), glfwGetPrimaryMonitor(), NULL);
		else
			window_ = glfwCreateWindow(size_x_, size_y_, title_.c_str(), NULL, NULL);

		if (!window_)
			Logger::Get().LogError("Failed to create GLFW window");
		else
			Logger::Get().LogInfo("Created GLFW window");

		glfwMakeContextCurrent(window_);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			Logger::Get().LogFatal("Failed to initialize Glad");

		glViewport(0, 0, (int)size_x_, (int)size_y_);
	}

	GLFWwindow* Window::GetWindow()
	{
		return window_;
	}

	int Window::GetWidth()
	{
		return size_x_;
	}

	int Window::GetHeight()
	{
		return size_y_;
	}

	void Window::SetDimensions(int width, int height)
	{
		size_x_ = width;
		size_y_ = height;
	}

	void Window::SetClearColor(float red, float green, float blue, float alpha)
	{
		red_ = red;
		green_ = green;
		blue_ = blue;
		alpha_ = alpha;
	}

	void Window::SetVerticalSync(bool state)
	{
		vsync_ = state;

		if (vsync_)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void Window::SetResizable(bool state)
	{
		// Just sets the member variable for now, but will have extra code to create a framebuffer callback
		resizeable_ = state;
	}

	void Window::SetFullscreen(bool state)
	{
		fullscreen_ = state;
	}

	void Window::SetTitle(std::string title)
	{
		this->title_ = title;
	}

	void Window::BeginFrame()
	{
		glClearColor(red_, green_, blue_, alpha_);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::EndFrame()
	{
		glfwSwapBuffers(window_);
		glfwPollEvents();
		glfwGetCursorPos(window_, &mousex_, &mousey_);
	}

	void Window::Close()
	{
		glfwSetWindowShouldClose(window_, GLFW_TRUE);
	}

	bool Window::CheckIfClosed()
	{
		return glfwWindowShouldClose(window_);
	}

	double Window::GetCursorPositionX()
	{
		return mousex_;
	}

	double Window::GetCursorPositionY()
	{
		return mousey_;
	}

}