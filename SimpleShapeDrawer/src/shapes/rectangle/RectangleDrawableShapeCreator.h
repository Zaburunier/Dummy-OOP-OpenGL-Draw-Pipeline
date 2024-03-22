#pragma once
#include "../BaseDrawableShapeCreator.h"


class RectangleDrawableShapeCreator : public BaseDrawableShapeCreator {
        public:

        /// <summary>
        /// Создание экземпляра, параметры которого будут получены генератором псевдослучайных чисел, 
        /// но границы которого гарантированно будут внутри экрана
        /// </summary>
        /// <returns> Созданный экземпляр компонента, представляющего отрисовываемую фигуру </returns>
        BaseDrawableShape* CreateWithRandomScreenSpaceParams() override;


        protected:

        /// <summary> Получение случайных вершин </summary>
        /// <param name="minWidth"> Минимальная ширина сгенерированного прямоугольника в экранных координатах (в случае OpenGL длина варьируется в интервале [0; 2]) </param>
        /// <param name="maxWidth"> Минимальная ширина сгенерированного прямоугольника в экранных координатах (в случае OpenGL длина варьируется в интервале [0; 2]) </param>
        /// <param name="minHeight"> Минимальная ширина сгенерированного прямоугольника в экранных координатах (в случае OpenGL длина варьируется в интервале [0; 2]) </param>
        /// <param name="maxHeight"> Минимальная ширина сгенерированного прямоугольника в экранных координатах (в случае OpenGL длина варьируется в интервале [0; 2]) </param>
        /// <returns></returns>
        GLfloat* GenerateVertices(float minWidth = 0, float maxWidth = 2, float minHeight = 0, float maxHeight = 2);
};

