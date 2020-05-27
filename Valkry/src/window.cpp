#include <glad/glad.h>

#include "window.h"
#include "logging.h"

namespace valkry {

	window::window()
	{
		if (!glfwInit())
			LogError("GLFW failed to initialize");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		win = glfwCreateWindow(sizeX, sizeY, title.c_str(), NULL, NULL);

		if (!win)
			LogError("Failed to create GLFW window");
		else
			LogInfo("Created GLFW window");

		glfwMakeContextCurrent(win);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			LogFatal("Failed to initialize Glad");
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
		glfwTerminate();
	}

	bool window::isClosed()
	{
		return glfwWindowShouldClose(win);
	}

}