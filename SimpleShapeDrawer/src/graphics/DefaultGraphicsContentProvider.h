#pragma once
#include "IGraphicsContentProvider.h"
#include <map>
#include <iostream>




class DefaultGraphicsContentProvider : public IGraphicsContentProvider {
	#pragma region Поля
        private:

	std::map<int, BaseDrawableShape*> shapeMap;

        /// <summary> Счётчик, используемый для создания ключа в словаре </summary>
        std::atomic<int> registrationCounter;
	#pragma endregion


	#pragma region Методы
	public:

	DefaultGraphicsContentProvider();


        ~DefaultGraphicsContentProvider();


        /// <summary> Внесение рисуемого объекта для последующей обработки и вывода в окно </summary>
        /// <param name="shapeToRegister"> Рисуемый объект </param>
        /// <returns> Уникальный ключ в системе, остающийся постоянным на протяжении работы программы и 
        /// позволяющий отвязать объект от системы обработки </returns>
        int RegisterContent(BaseDrawableShape* shapeToRegister) override;


        /// <summary> Проверка наличия объекта с заданным ключом </summary>
        /// <param name="idToCheck"> Проверяемый ключ </param>
        /// <returns> Имеется ли зарегистрированный объект с ключом <paramref name="id"/>? </returns>
        bool HasContentWithId(int idToCheck) override;


        /// <summary> Удаление объекта из системы обработки и вывода в окно </summary>
        /// <param name="id"> Ключ объекта, полученный при регистрации </param>
        /// <param name="throwIfNotFound"> Если объект не найден, стоит ли выбрасывать исключение? </param>
        /// <returns></returns>
        bool TryUnregisterContent(int id, bool throwIfNotFound = false) override;


        /// <summary> Отрисовка зарегистрированных объектов в окне OpenGL </summary>
        void DrawContent(GLFWwindow* window) override;


        /// <summary> Переадресовываемое срабатывание события нажатия на клавиатуру </summary>
        void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) override;


	private:
	#pragma endregion


};

