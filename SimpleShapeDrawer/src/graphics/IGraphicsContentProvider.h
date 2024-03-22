#pragma once

#include "../shapes/BaseDrawableShape.h"




class IGraphicsContentProvider
{
        public:

        /// <summary> Внесение рисуемого объекта для последующей обработки и вывода в окно </summary>
        /// <param name="shape"> Рисуемый объект </param>
        /// <returns> Уникальный ключ в системе, остающийся постоянным на протяжении работы программы и 
        /// позволяющий отвязать объект от системы обработки </returns>
        virtual int RegisterContent(BaseDrawableShape* shape) = 0;


        /// <summary> Проверка наличия объекта с заданным ключом </summary>
        /// <param name="id"> Проверяемый ключ </param>
        /// <returns> Имеется ли зарегистрированный объект с ключом <paramref name="id"/>? </returns>
        virtual bool HasContentWithId(int id) = 0;


        /// <summary> Удаление объекта из системы обработки и вывода в окно </summary>
        /// <param name="id"> Ключ объекта, полученный при регистрации </param>
        /// <param name="throwIfNotFound"> Если объект не найден, стоит ли выбрасывать исключение? </param>
        /// <returns></returns>
        virtual bool TryUnregisterContent(int id, bool throwIfNotFound = false) = 0;


        /// <summary> Отрисовка зарегистрированных объектов в окне OpenGL </summary>
        virtual void DrawContent(GLFWwindow* window) = 0;


        /// <summary> Переадресовываемое срабатывание события нажатия на клавиатуру </summary>
        //virtual GLFWkeyfun OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) = 0;
        virtual void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) = 0;
};

