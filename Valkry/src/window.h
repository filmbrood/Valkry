#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace valkry {

	class window
	{
	private:
		GLFWwindow* win;

		int sizeX, sizeY;
		bool vsync = false;
		std::string title;

	public:
		window(int width, int height, std::string name);
		~window();

		GLFWwindow* getWindow();

		int getWidth();
		int getHeight();

		void setClearColor();
		void refresh();
	};

}