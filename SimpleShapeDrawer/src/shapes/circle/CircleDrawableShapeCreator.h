#pragma once
#include "../rectangle/RectangleDrawableShapeCreator.h"
class CircleDrawableShapeCreator : public RectangleDrawableShapeCreator {
        public:

        /// <summary>
        /// —оздание экземпл€ра, параметры которого будут получены генератором псевдослучайных чисел, 
        /// но границы которого гарантированно будут внутри экрана
        /// </summary>
        /// <returns> —озданный экземпл€р компонента, представл€ющего отрисовываемую фигуру </returns>
        BaseDrawableShape* CreateWithRandomScreenSpaceParams() override;
};

