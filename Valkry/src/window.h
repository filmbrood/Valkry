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

	public:
		window();
		~window();

		GLFWwindow* getWindow();

		int getWidth();
		int getHeight();

		void setClearColor();
		void refresh();
		void close();
		bool isClosed();
	};

}