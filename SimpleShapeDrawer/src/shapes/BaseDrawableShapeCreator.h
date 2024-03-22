#pragma once
#include "BaseDrawableShape.h"




/// <summary> ��������� �����������, �������������� ������� ��� �������������� ������ </summary>
class BaseDrawableShapeCreator {
        public:

        /// <summary>
        /// �������� ����������, ��������� �������� ����� �������� ����������� ��������������� �����, 
        /// �� ������� �������� �������������� ����� ������ ������
        /// </summary>
        /// <returns> ��������� ��������� ����������, ��������������� �������������� ������ </returns>
        virtual BaseDrawableShape* CreateWithRandomScreenSpaceParams() = 0;
};

