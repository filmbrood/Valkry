#include <glad/glad.h>

#include "window.h"
#include "logging.h"

namespace valkry {

	window::window()
	{
		if (!glfwInit())
			LogError("GLFW failed to initialize");
	}

	window::~window()
	{
		glfwTerminate();
	}

	void window::create(int GLVersionMajor, int GLVersionMinor)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLVersionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLVersionMinor);
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

	GLFWwindow* window::getWindow()
	{
		return win;
	}

	void window::setDimensions(int width, int height)
	{
		sizeX = width;
		sizeY = height;
	}

	int window::getWidth()
	{
		return sizeX;
	}

	int window::getHeight()
	{
		return sizeY;
	}

	void window::setClearColor(float red, float green, float blue, float alpha)
	{
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}

	void window::setTitle(std::string title)
	{
		this->title = title;
	}

	void window::beginFrame()
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void window::endFrame()
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