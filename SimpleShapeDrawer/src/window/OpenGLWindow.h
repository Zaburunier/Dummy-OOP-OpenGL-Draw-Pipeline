#pragma once

#include <thread>

#include "../graphics/IGraphicsContentProvider.h"
#include "GlfwWindowInitializationException.h"
#include "GlewInitializationException.h"




class OpenGLWindow {
	#pragma region Вложенные типы данных
	public: 

	struct Size {
		int width;
		int height;
	};
	#pragma endregion



	#pragma region Поля
	private:

	GLFWwindow* activeWindow;
	IGraphicsContentProvider* activeContentProvider;

	Size viewportSize;

	std::thread* graphicsThread;
	#pragma endregion


	#pragma region Методы
	public:

	OpenGLWindow(Size size);

	
	~OpenGLWindow();


	/// <summary> Метод инициализации всех контекстов OpenGL. При обнаружении ошибки выбрасывается исключение /// </summary>
	void InitializeOpenGlContextAndThrowIfErrorFound();


	GLFWwindow* GetWindowPointer();


	/// <summary> Активация основного интерактивного окна </summary>
	/// <param name="contentProvider"> Компонент, управляющий содержимым для отрисовки </param>
	/// <param name="secondsDuration"> 
	/// Длительность периода активности.
	/// Отрицательные значения означают, что окно будет активно до уничтожения экземпляра или до ручного закрытия окна через кнопку
	/// </param>
	/// <param name="blockUntilWindowDeactivation"> 
	/// Следует ли заблокировать передачу управления до тех пор, пока окно не закрыто? 
	/// </param>
	/// <returns> Ссылка на поток исполнения кода отрисовки </returns>
	std::thread* ShowWindowAndExecuteGraphicsLoop(IGraphicsContentProvider *contentProvider, float secondsDuration = -1.0f, bool blockUntilWindowDeactivation = false);


	private:

	/// <summary> Базовая настройка окна OpenGL </summary>
	void SetupGlfwEnviroment();


	/// <summary> Метод, реализующий цикл отрисовки содержимого в окно </summary>
	/// <param name="window"></param>
	/// <param name="contentProvider"></param>
	/// param name="secondsDuration"></param>
	void GraphicsLoop(IGraphicsContentProvider *contentProvider, float secondsDuration = -1.0f);


	/*void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode);


	void OnFramebufferResized(GLFWwindow* window, int width, int height);*/
	#pragma endregion


};

