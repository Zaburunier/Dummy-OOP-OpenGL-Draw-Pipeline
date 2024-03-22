#pragma once
#include "OpenGLShader.h"



/// <summary> Интерфейс для компонентов, представляющих отрисовываемую фигуру </summary>
class BaseDrawableShape {
        #pragma region Вложенные типы данных
        public:

        /// <summary> Перечисление способов наложения обводки на фигуру </summary>
        enum class OutlineSide {
                /// <summary> Пустое, служебное значение </summary>
                None = 0,
                /// <summary> Обводка "съедает" часть площади фигуры </summary>
                Inner = 1,
                /// <summary> Обводка прибавляется так, чтобы площадь самой фигуры не изменилась </summary>
                Outer = 2
        };


        /// <summary> Контейнер с параметрами обводки фигуры </summary>
        /// <remarks> Параметры могут использоваться или не использоваться шейдерами фигуры на своё усмотрение (за это отвечает реализация) </remarks>
        struct OutlineSettings {
                /// <summary> Размер обводки, выраженный в процентах от размера самой фигуры </summary>
                float widthRatio;
                /// <summary> Способ нанесения обводки </summary>
                OutlineSide drawSide;

                OutlineSettings(float widthRatio = 0.0, OutlineSide drawSide = OutlineSide::Outer) {
                        this->widthRatio = widthRatio;
                        this->drawSide = drawSide;
                }
        };


        /// <summary> Перечисление способов заливки фигуры </summary>
        /// <remarks> Имеет значение тогда, когда указана не полная заливка, а какой-то процент </remarks>
        enum class FillSide {
                /// <summary> Пустое, служебное значение </summary>
                None = 0,
                /// <summary> Фигура заливается начиная от центроида </summary>
                FromCenter = 1,
                /// <summary> Фигура заливается начиная от сторон </summary>
                FromEdge = 2
        };


        /// <summary> Контейнер с параметрами заливки фигуры </summary>
        /// <remarks> Параметры могут использоваться или не использоваться шейдерами фигуры на своё усмотрение (за это отвечает реализация) </remarks>
        struct FillSettings {
                /// <summary> Размер заливки, выраженный в процентах от площади фигуры </summary>
                float fillRatio;
                /// <summary> Способ обхода фигуры для нанесения заливки </summary>
                FillSide drawSide;


                FillSettings(float fillRatio = 1.0, FillSide drawSide = FillSide::FromCenter) {
                        this->fillRatio = fillRatio;
                        this->drawSide = drawSide;
                }
        };
        #pragma endregion


        #pragma region Поля
        protected:

        OpenGLShader* shader;

        GLfloat* vertices;
        GLuint* indices;

        BaseDrawableShape::FillSettings fillSettings;
        BaseDrawableShape::OutlineSettings outlineSettings;

        GLuint elementBufferObjectCode;
        GLuint vertexBufferObjectCode;
        GLuint vertexArrayObjectCode;
        #pragma endregion



        #pragma region Методы
        public:

        virtual ~BaseDrawableShape();


        /// <summary> Установка видимости обводки фигуры </summary>
        /// <param name="isVisible"></param>
        virtual void SetOutlineVisibility(bool isVisible) = 0;


        /// <summary> Установка видимости заливки фигуры </summary>
        /// <param name="isVisible"></param>
        virtual void SetFillVisibility(bool isVisible) = 0;


        /// <summary> Отрисовка фигуры </summary>
        /// <remarks> 
        /// Предполагается вызов в цикле рендера, 
        /// поскольку результат вызова данного метода зависит от внешних состояний (самого OpenGL)
        /// </remarks>
        /// <param name="window"> Окно, в которое производится отрисовка </param>
        virtual void Draw(GLFWwindow* window);


        protected:

        /// <summary> Конструктор экземпляра </summary>
        /// <param name="vertices"> Массив из 4 вершин, описывающий четырёхугольник </param>
        /// <param name="fillSettings"> Параметры заливки четырёхугольника </param>
        /// <param name="outlineSettings"> Параметры обводки четырёхугольника </param>
        /// <param name="vertexPath"> Расположение файла с вершинным шейдером </param>
        /// <param name="fragmentPath"> Расположение файла с фрагментным шейдером </param>
        BaseDrawableShape(BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings, const GLchar* vertexPath, const GLchar* fragmentPath);


        /// <summary> Количество вершин примитива </summary>
        virtual int GetVertexCount() = 0;


        /// <summary> Количество чисел, которое занимают данные каждой вершины </summary>
        virtual int GetPerVertexNumberCount() = 0;


        /// <summary> Количество индексов примитива </summary>
        virtual int GetIndexCount() = 0;
        

        /// <summary> Настройка разметки параметров шейдеров в памяти для корректного управления при получении команды на отрисовку </summary>
        /// <remarks> Вызовается один раз на этапе инициализации </remarks>
        virtual void SetupShaderParamsLayout() = 0;


        /// <summary> Настройка глобальных параметров шейдера </summary>
        /// <remarks> Вызывается непосредственно перед каждой командой отрисовки </remarks>
        /// <param name="window"> Окно, в которое производится отрисовка </param>
        virtual void SetupShaderUniformValues(GLFWwindow* window) = 0;


        /// <summary> Начальная настройка буферов OpenGL </summary>
        virtual void InitializeBuffers();


        private:
        #pragma endregion
};

