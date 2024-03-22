#pragma once
#include "../BaseDrawableShapeCreator.h"



class TriangleDrawableShapeCreator : public BaseDrawableShapeCreator {
        public:

        /// <summary>
        /// �������� ����������, ��������� �������� ����� �������� ����������� ��������������� �����, 
        /// �� ������� �������� �������������� ����� ������ ������
        /// </summary>
        /// <returns> ��������� ��������� ����������, ��������������� �������������� ������ </returns>
        BaseDrawableShape* CreateWithRandomScreenSpaceParams() override;


        protected:

        /// <summary> ��������� ��������� ������ </summary>
        /// <returns></returns>
        GLfloat* GenerateVertices();
};

