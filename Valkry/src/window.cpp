#include "window.h"
#include "logging.h"

namespace valkry {

	window::window(int width, int height, std::string name) : sizeX(width), sizeY(height), title(name)
	{
		if (!glfwInit())
			LogError("GLFW failed to initialize");

		win = glfwCreateWindow(sizeX, sizeY, title.c_str(), NULL, NULL);

		if (!win)
			LogError("Failed to create GLFW window");
		else
			LogInfo("Created GLFW window");

		glfwMakeContextCurrent(win);
	}

	window::~window()
	{
		glfwTerminate();
	}

	GLFWwindow* window::getWindow()
	{
		return win;
	}

	int window::getWidth()
	{
		return sizeX;
	}

	int window::getHeight()
	{
		return sizeY;
	}

	void window::setClearColor()
	{

	}

	void window::refresh()
	{
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	void window::close()
	{
		glfwSetWindowShouldClose(win, GLFW_TRUE);
	}

	bool window::isClosed()
	{
		return glfwWindowShouldClose(win);
	}

}