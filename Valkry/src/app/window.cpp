#include "valkrypch.h"

#include <glad/glad.h>
#include "window.h"

namespace Valkry {

	Window::Window()
	{
		if (!glfwInit())
			LogError("GLFW failed to initialize");
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::Create(int GLVersionMajor, int GLVersionMinor)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLVersionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLVersionMinor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (fullscreen_)
			window_ = glfwCreateWindow(size_x_, size_y_, title_.c_str(), glfwGetPrimaryMonitor(), NULL);
		else
			window_ = glfwCreateWindow(size_x_, size_y_, title_.c_str(), NULL, NULL);

		if (!window_)
			LogError("Failed to create GLFW window");
		else
			LogInfo("Created GLFW window");

		glfwMakeContextCurrent(window_);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			LogFatal("Failed to initialize Glad");

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