#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:
	static unsigned int pWidth;
	static unsigned int pHeight;
	static GLFWwindow* pWindow;

public:
	static void Init(unsigned int Width, unsigned int Height, const char* Title);
	static void Terminate();

	static bool ShouldClose();

	static unsigned int GetWidth();
	static unsigned int GetHeight();
	static GLFWwindow* GetWindow();
};