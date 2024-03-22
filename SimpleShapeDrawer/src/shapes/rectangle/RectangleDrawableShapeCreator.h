#pragma once
#include "../BaseDrawableShapeCreator.h"


class RectangleDrawableShapeCreator : public BaseDrawableShapeCreator {
        public:

        /// <summary>
        /// �������� ����������, ��������� �������� ����� �������� ����������� ��������������� �����, 
        /// �� ������� �������� �������������� ����� ������ ������
        /// </summary>
        /// <returns> ��������� ��������� ����������, ��������������� �������������� ������ </returns>
        BaseDrawableShape* CreateWithRandomScreenSpaceParams() override;


        protected:

        /// <summary> ��������� ��������� ������ </summary>
        /// <param name="minWidth"> ����������� ������ ���������������� �������������� � �������� ����������� (� ������ OpenGL ����� ����������� � ��������� [0; 2]) </param>
        /// <param name="maxWidth"> ����������� ������ ���������������� �������������� � �������� ����������� (� ������ OpenGL ����� ����������� � ��������� [0; 2]) </param>
        /// <param name="minHeight"> ����������� ������ ���������������� �������������� � �������� ����������� (� ������ OpenGL ����� ����������� � ��������� [0; 2]) </param>
        /// <param name="maxHeight"> ����������� ������ ���������������� �������������� � �������� ����������� (� ������ OpenGL ����� ����������� � ��������� [0; 2]) </param>
        /// <returns></returns>
        GLfloat* GenerateVertices(float minWidth = 0, float maxWidth = 2, float minHeight = 0, float maxHeight = 2);
};

