#pragma once
#include "BaseDrawableShape.h"




/// <summary> »нтерфейс компонентов, представл€ющих фабрику дл€ отрисовываемой фигуры </summary>
class BaseDrawableShapeCreator {
        public:

        /// <summary>
        /// —оздание экземпл€ра, параметры которого будут получены генератором псевдослучайных чисел, 
        /// но границы которого гарантированно будут внутри экрана
        /// </summary>
        /// <returns> —озданный экземпл€р компонента, представл€ющего отрисовываемую фигуру </returns>
        virtual BaseDrawableShape* CreateWithRandomScreenSpaceParams() = 0;
};

