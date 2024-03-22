#pragma once
#include "../BaseDrawableShape.h"




class TriangleDrawableShape : public BaseDrawableShape {
	#pragma region Поля

	#pragma endregion


	#pragma region Методы
	public:

	/// <summary> Конструктор экземпляра </summary>
	/// <param name="vertices"> Массив из 4 вершин, описывающий четырёхугольник </param>
	/// <param name="fillSettings"> Параметры заливки четырёхугольника </param>
	/// <param name="outlineSettings"> Параметры обводки четырёхугольника </param>
	TriangleDrawableShape(GLfloat* vertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings);


	/// <summary> Установка видимости обводки фигуры </summary>
	/// <param name="isVisible"></param>
	void SetOutlineVisibility(bool isVisible) override;


	/// <summary> Установка видимости заливки фигуры </summary>
	/// <param name="isVisible"></param>
	void SetFillVisibility(bool isVisible) override;


	/// <summary> Отрисовка фигуры </summary>
	/// <remarks> 
	/// Предполагается вызов в цикле рендера, 
	/// поскольку результат вызова данного метода зависит от внешних состояний (самого OpenGL)
	/// </remarks>
	/// <param name="window"> Окно, в которое производится отрисовка </param>
	void Draw(GLFWwindow* window) override;


	~TriangleDrawableShape();


	protected:


	/// <summary> Количество вершин примитива </summary>
	int GetVertexCount() override;


	/// <summary> Количество чисел, которое занимают данные каждой вершины </summary>
	int GetPerVertexNumberCount() override;


	/// <summary> Количество индексов примитива </summary>
	int GetIndexCount() override;


	/// <summary> Настройка разметки параметров шейдеров в памяти для корректного управления при получении команды на отрисовку </summary>
	void SetupShaderParamsLayout() override;

	/// <summary> Настройка глобальных параметров шейдера </summary>
	/// <remarks> Вызывается непосредственно перед каждой командой отрисовки </remarks>
	void SetupShaderUniformValues(GLFWwindow* window) override;
	#pragma endregion
};

