#pragma once
#include "../BaseDrawableShapeCreator.h"



class TriangleDrawableShapeCreator : public BaseDrawableShapeCreator {
        public:

        /// <summary>
        /// —оздание экземпл€ра, параметры которого будут получены генератором псевдослучайных чисел, 
        /// но границы которого гарантированно будут внутри экрана
        /// </summary>
        /// <returns> —озданный экземпл€р компонента, представл€ющего отрисовываемую фигуру </returns>
        BaseDrawableShape* CreateWithRandomScreenSpaceParams() override;


        protected:

        /// <summary> ѕолучение случайных вершин </summary>
        /// <returns></returns>
        GLfloat* GenerateVertices();
};

