#pragma once

#include <thread>

#include "../graphics/IGraphicsContentProvider.h"
#include "GlfwWindowInitializationException.h"
#include "GlewInitializationException.h"




class OpenGLWindow {
	#pragma region ��������� ���� ������
	public: 

	struct Size {
		int width;
		int height;
	};
	#pragma endregion



	#pragma region ����
	private:

	GLFWwindow* activeWindow;
	IGraphicsContentProvider* activeContentProvider;

	Size viewportSize;

	std::thread* graphicsThread;
	#pragma endregion


	#pragma region ������
	public:

	OpenGLWindow(Size size);

	
	~OpenGLWindow();


	/// <summary> ����� ������������� ���� ���������� OpenGL. ��� ����������� ������ ������������� ���������� /// </summary>
	void InitializeOpenGlContextAndThrowIfErrorFound();


	GLFWwindow* GetWindowPointer();


	/// <summary> ��������� ��������� �������������� ���� </summary>
	/// <param name="contentProvider"> ���������, ����������� ���������� ��� ��������� </param>
	/// <param name="secondsDuration"> 
	/// ������������ ������� ����������.
	/// ������������� �������� ��������, ��� ���� ����� ������� �� ����������� ���������� ��� �� ������� �������� ���� ����� ������
	/// </param>
	/// <param name="blockUntilWindowDeactivation"> 
	/// ������� �� ������������� �������� ���������� �� ��� ���, ���� ���� �� �������? 
	/// </param>
	/// <returns> ������ �� ����� ���������� ���� ��������� </returns>
	std::thread* ShowWindowAndExecuteGraphicsLoop(IGraphicsContentProvider *contentProvider, float secondsDuration = -1.0f, bool blockUntilWindowDeactivation = false);


	private:

	/// <summary> ������� ��������� ���� OpenGL </summary>
	void SetupGlfwEnviroment();


	/// <summary> �����, ����������� ���� ��������� ����������� � ���� </summary>
	/// <param name="window"></param>
	/// <param name="contentProvider"></param>
	/// param name="secondsDuration"></param>
	void GraphicsLoop(IGraphicsContentProvider *contentProvider, float secondsDuration = -1.0f);


	/*void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode);


	void OnFramebufferResized(GLFWwindow* window, int width, int height);*/
	#pragma endregion


};

