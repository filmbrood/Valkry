#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace valkry {

	class window
	{
	private:
		GLFWwindow* win;

		int sizeX = 1280, sizeY = 720;
		bool vsync = false;
		std::string title = "Valkry";

		//clear color
		float r = 0.0f, g = 0.0f, b = 0.0f, a = 0.0f;

	public:
		window();
		~window();

		GLFWwindow* getWindow();

		int getWidth();
		int getHeight();

		void setClearColor(float red, float green, float blue, float alpha);

		void beginFrame();
		void endFrame();

		void close();
		bool isClosed();
	};

}