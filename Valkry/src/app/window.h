#pragma once
#include <GLFW/glfw3.h>
#include <string>

namespace Valkry {

	// Container class for a GLFWwindow.
	class Window
	{
	public:
		// Constructor initalizes GLFW, Destructor terminates GLFW
		Window();
		~Window();

		// Returns GLFWwindow pointer
		GLFWwindow* GetWindow();

		// Sets OpenGL version, creates GLFW window context, and initializes Glad OpenGL loader
		void Create();
		void SetDimensions(int width, int height);
		void SetTitle(std::string title);
		void SetClearColor(float red, float green, float blue, float alpha);
		void SetVerticalSync(bool state);
		void SetResizable(bool state);
		void SetFullscreen(bool state);
		int GetWidth();
		int GetHeight();
		double GetCursorPositionX();
		double GetCursorPositionY();

	public:
		// Clears the color buffer, calls glClearColor
		void BeginFrame();

		// Swaps buffers and polls for events, updates mouse position
		void EndFrame();

		// Sets GLFW window to close
		void Close();

		// Returns whether or not GLFW window has been set to close
		bool CheckIfClosed();

	private:
		GLFWwindow* window_;

		int size_x_ = 1280, size_y_ = 720;
		bool vsync_ = false;
		bool fullscreen_ = false;
		bool resizeable_ = false;
		std::string title_ = "Valkry";

		// Stores mouse cursor coordinates
		double mousex_, mousey_;

		// Float values for clear color
		float red_ = 0.0f, green_ = 0.0f, blue_ = 0.0f, alpha_ = 0.0f;

	};

}