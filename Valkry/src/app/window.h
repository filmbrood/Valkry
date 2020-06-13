#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace Valkry {

	class Window
	{
	private:
		GLFWwindow* window_;

		int size_x_ = 1280, size_y_ = 720;
		bool vsync_ = false;
		std::string title_ = "Valkry";

		// Float values for background clear color
		float red_ = 0.0f, green_ = 0.0f, blue_ = 0.0f, alpha_ = 0.0f;

	public:
		// Constructor initalizes GLFW, Destructor terminates GLFW
		Window();
		~Window();

		// Sets OpenGL version, creates GLFW window context, and initializes Glad OpenGL loader
		void Create(int GLVersionMajor = 3, int GLVersionMinor = 3);

		GLFWwindow* GetWindow();
		int GetWidth();
		int GetHeight();

		void SetDimensions(int width, int height);
		void SetTitle(std::string title);
		void SetClearColor(float red, float green, float blue, float alpha);

		// Clears the color buffer, calls glClearColor
		void BeginFrame();

		// Swaps buffers and polls for events
		void EndFrame();

		// Sets GLFW window to close
		void Close();

		// Returns whether or not GLFW window has been set to close
		bool CheckIfClosed();
	};

}