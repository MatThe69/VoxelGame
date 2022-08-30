#include "Window.h"

unsigned int Window::pWidth; 
unsigned int Window::pHeight;
GLFWwindow* Window::pWindow;

void Window::Init(unsigned int Width, unsigned int Height, const char* Title)
{
	Window::pWidth = Width;
	Window::pHeight = Height;

	glfwInit();
	Window::pWindow = glfwCreateWindow(Width, Height, Title, nullptr, nullptr);
	glfwMakeContextCurrent(Window::pWindow);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glClearColor(0.6f, 0.6f, 1.0f, 1.0f);
	glViewport(0, 0, Width, Height);
}
void Window::Terminate()
{
	glfwTerminate();
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(Window::pWindow);
}

unsigned int Window::GetWidth() { return Window::pWidth; }
unsigned int Window::GetHeight() { return Window::pHeight; }
GLFWwindow* Window::GetWindow() { return Window::pWindow; }