#include <iostream>
#include <chrono>

#include "src/window/OpenGLWindow.h"
#include "src/graphics/DefaultGraphicsContentProvider.h"
#include "src/shapes/rectangle/RectangleDrawableShapeCreator.h"
#include "src/shapes/circle/CircleDrawableShapeCreator.h"
#include "src/shapes/triangle/TriangleDrawableShapeCreator.h"


int main(int argc, char* argv[])
{
	OpenGLWindow::Size viewportSize = {800, 600};
	OpenGLWindow* window = new OpenGLWindow(viewportSize);
	
	try {
		window->InitializeOpenGlContextAndThrowIfErrorFound();
	} catch (const char* error_message) {
		std::cout << "������ ������������� ��������� OpenGL:" << std::endl << error_message << std::endl;
		//throw std::rethrow_exception;
		return 1;
	}

	IGraphicsContentProvider* contentProvider = new DefaultGraphicsContentProvider();

	// ������ ��������� ������� ����
	contentProvider->RegisterContent(RectangleDrawableShapeCreator().CreateWithRandomScreenSpaceParams());
	contentProvider->RegisterContent(CircleDrawableShapeCreator().CreateWithRandomScreenSpaceParams());
	contentProvider->RegisterContent(TriangleDrawableShapeCreator().CreateWithRandomScreenSpaceParams());
	
	// ������ �������� ��������� ������ �������������� ��� ������������ ������ ����
	if (argc == 1) {
		window->ShowWindowAndExecuteGraphicsLoop(contentProvider, -1.0f, false);
	} else {
		int duration = std::atoi(argv[0]);
		window->ShowWindowAndExecuteGraphicsLoop(contentProvider, duration, false);
	}
	
	std::chrono::milliseconds sleepDuration(50);
	while (!glfwWindowShouldClose(window->GetWindowPointer())) {
		std::this_thread::sleep_for(sleepDuration);
	}

	delete contentProvider;
	delete window;

	return 0;
}