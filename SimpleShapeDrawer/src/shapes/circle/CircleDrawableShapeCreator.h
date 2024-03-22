#pragma once
#include "../rectangle/RectangleDrawableShapeCreator.h"
class CircleDrawableShapeCreator : public RectangleDrawableShapeCreator {
        public:

        /// <summary>
        /// �������� ����������, ��������� �������� ����� �������� ����������� ��������������� �����, 
        /// �� ������� �������� �������������� ����� ������ ������
        /// </summary>
        /// <returns> ��������� ��������� ����������, ��������������� �������������� ������ </returns>
        BaseDrawableShape* CreateWithRandomScreenSpaceParams() override;
};

