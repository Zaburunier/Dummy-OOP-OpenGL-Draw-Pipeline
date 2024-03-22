#include "OpenGLWindow.h"
#include <functional>


void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}


void OnFramebufferResized(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


#pragma region Открытые методы
OpenGLWindow::OpenGLWindow(Size size) {
	this->viewportSize = size;

	SetupGlfwEnviroment();
}


void OpenGLWindow::InitializeOpenGlContextAndThrowIfErrorFound() {
	activeWindow = glfwCreateWindow(viewportSize.width, viewportSize.height, "SimpleShapeDrawer", nullptr, nullptr);
	if (activeWindow == nullptr) {
		glfwTerminate();
		throw GlfwWindowInitializationException("Unknown window creation error, no pointer present");
	}

	glfwMakeContextCurrent(activeWindow);
	glfwSetFramebufferSizeCallback(activeWindow, OnFramebufferResized);

	//glewExperimental = GL_TRUE;
	/*if (glewInit() != GLEW_OK) {
		glfwTerminate();
		throw GlewInitializationException("Unknown glew initialization error");
	}*/

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		throw GlewInitializationException("Unknown glew initialization error");
	}
}


GLFWwindow* OpenGLWindow::GetWindowPointer() {
	return activeWindow;
}


std::thread* OpenGLWindow::ShowWindowAndExecuteGraphicsLoop(IGraphicsContentProvider* contentProvider, float secondsDuration, bool blockUntilWindowDeactivation) {
	GraphicsLoop(contentProvider, secondsDuration);
	return nullptr;

	/*graphicsThread = new std::thread([&]() { 		
		GraphicsLoop(contentProvider, secondsDuration); 
	});

	if (blockUntilWindowDeactivation) {
		graphicsThread->join();
		delete graphicsThread;
	}

	return graphicsThread;*/
}


OpenGLWindow::~OpenGLWindow() {
	glfwDestroyWindow(activeWindow);
	glfwTerminate();
}
#pragma endregion


#pragma region Закрытые методы
void OpenGLWindow::SetupGlfwEnviroment() {
	// https://habr.com/ru/articles/311234/

	glfwInit();

	//Задается минимальная требуемая версия OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}


void OpenGLWindow::GraphicsLoop(IGraphicsContentProvider* contentProvider, float secondsDuration) {
	// https://habr.com/ru/articles/311234/

	int width, height;
	glfwGetFramebufferSize(activeWindow, &width, &height);

	glViewport(0, 0, width, height);

	glfwSetKeyCallback(activeWindow, OnKeyPressed);
	
	std::chrono::steady_clock::time_point startTime = std::chrono::high_resolution_clock::now();
	long startMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(startTime.time_since_epoch()).count();

	long maxMilliseconds = static_cast<long>(1e+3 * secondsDuration);

	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_LESS);

	// Проверку на положительное число можно вынести за цикл (будет актуально при раздувании блока внутри if)
	while (!glfwWindowShouldClose(activeWindow)) {
		glfwSwapBuffers(activeWindow);
		glfwPollEvents();

		glClearColor(0.1f, 0.18f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		contentProvider->DrawContent(activeWindow);

		std::chrono::steady_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
		long currentMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();

		if (secondsDuration >= 0.0 && currentMilliseconds - startMilliseconds > maxMilliseconds)
			break;
	}
}
#pragma endregion