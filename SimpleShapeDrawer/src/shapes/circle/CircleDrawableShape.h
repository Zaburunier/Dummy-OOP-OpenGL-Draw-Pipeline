#pragma once
#include "../rectangle/RectangleDrawableShape.h"




// Основная хитрость в том, что мы воспользуемся функционалом прямоугольника, а круг будет будет получен маской пиксельного шейдера
// В текущей реализации есть ошибка, когда пиксели внутри прямоугольника, но вне круга записываются с прозрачностью 0, но при этом оставляют след в буфере глубины
class CircleDrawableShape : public RectangleDrawableShape {
        #pragma region Поля
        private:

        GLfloat* centerPoint;
        GLfloat radius;
        #pragma endregion



        #pragma region Методы
        public:

        /// <summary> Конструктор экземпляра </summary>
        /// <param name="vertices"> Массив из 4 вершин, описывающий четырёхугольник </param>
        /// <param name="fillSettings"> Параметры заливки четырёхугольника </param>
        /// <param name="outlineSettings"> Параметры обводки четырёхугольника </param>
        CircleDrawableShape(GLfloat radius, GLfloat* rectVertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings);


        ~CircleDrawableShape();


        /// <summary> Отрисовка фигуры </summary>
        /// <remarks> 
        /// Предполагается вызов в цикле рендера, 
        /// поскольку результат вызова данного метода зависит от внешних состояний (самого OpenGL)
        /// </remarks>
        /// <param name="window"> Окно, в которое производится отрисовка </param>
        void Draw(GLFWwindow* window) override;


        protected:

        /// <summary> Настройка разметки параметров шейдеров в памяти для корректного управления при получении команды на отрисовку </summary>
        void SetupShaderParamsLayout() override;

        /// <summary> Настройка глобальных параметров шейдера </summary>
        /// <remarks> Вызывается непосредственно перед каждой командой отрисовки </remarks>
        void SetupShaderUniformValues(GLFWwindow* window) override;


        private:

        GLfloat* CalculateCentroid(GLfloat* vertices);
        #pragma endregion
};

