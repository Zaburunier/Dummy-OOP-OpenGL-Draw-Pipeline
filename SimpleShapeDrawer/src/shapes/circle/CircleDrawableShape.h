#pragma once
#include "../rectangle/RectangleDrawableShape.h"




// �������� �������� � ���, ��� �� ������������� ������������ ��������������, � ���� ����� ����� ������� ������ ����������� �������
// � ������� ���������� ���� ������, ����� ������� ������ ��������������, �� ��� ����� ������������ � ������������� 0, �� ��� ���� ��������� ���� � ������ �������
class CircleDrawableShape : public RectangleDrawableShape {
        #pragma region ����
        private:

        GLfloat* centerPoint;
        GLfloat radius;
        #pragma endregion



        #pragma region ������
        public:

        /// <summary> ����������� ���������� </summary>
        /// <param name="vertices"> ������ �� 4 ������, ����������� �������������� </param>
        /// <param name="fillSettings"> ��������� ������� ��������������� </param>
        /// <param name="outlineSettings"> ��������� ������� ��������������� </param>
        CircleDrawableShape(GLfloat radius, GLfloat* rectVertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings);


        ~CircleDrawableShape();


        /// <summary> ��������� ������ </summary>
        /// <remarks> 
        /// �������������� ����� � ����� �������, 
        /// ��������� ��������� ������ ������� ������ ������� �� ������� ��������� (������ OpenGL)
        /// </remarks>
        /// <param name="window"> ����, � ������� ������������ ��������� </param>
        void Draw(GLFWwindow* window) override;


        protected:

        /// <summary> ��������� �������� ���������� �������� � ������ ��� ����������� ���������� ��� ��������� ������� �� ��������� </summary>
        void SetupShaderParamsLayout() override;

        /// <summary> ��������� ���������� ���������� ������� </summary>
        /// <remarks> ���������� ��������������� ����� ������ �������� ��������� </remarks>
        void SetupShaderUniformValues(GLFWwindow* window) override;


        private:

        GLfloat* CalculateCentroid(GLfloat* vertices);
        #pragma endregion
};

