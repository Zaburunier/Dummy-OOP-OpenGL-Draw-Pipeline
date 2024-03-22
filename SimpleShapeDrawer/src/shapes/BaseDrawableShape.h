#pragma once
#include "OpenGLShader.h"



/// <summary> ��������� ��� �����������, �������������� �������������� ������ </summary>
class BaseDrawableShape {
        #pragma region ��������� ���� ������
        public:

        /// <summary> ������������ �������� ��������� ������� �� ������ </summary>
        enum class OutlineSide {
                /// <summary> ������, ��������� �������� </summary>
                None = 0,
                /// <summary> ������� "�������" ����� ������� ������ </summary>
                Inner = 1,
                /// <summary> ������� ������������ ���, ����� ������� ����� ������ �� ���������� </summary>
                Outer = 2
        };


        /// <summary> ��������� � ����������� ������� ������ </summary>
        /// <remarks> ��������� ����� �������������� ��� �� �������������� ��������� ������ �� ��� ���������� (�� ��� �������� ����������) </remarks>
        struct OutlineSettings {
                /// <summary> ������ �������, ���������� � ��������� �� ������� ����� ������ </summary>
                float widthRatio;
                /// <summary> ������ ��������� ������� </summary>
                OutlineSide drawSide;

                OutlineSettings(float widthRatio = 0.0, OutlineSide drawSide = OutlineSide::Outer) {
                        this->widthRatio = widthRatio;
                        this->drawSide = drawSide;
                }
        };


        /// <summary> ������������ �������� ������� ������ </summary>
        /// <remarks> ����� �������� �����, ����� ������� �� ������ �������, � �����-�� ������� </remarks>
        enum class FillSide {
                /// <summary> ������, ��������� �������� </summary>
                None = 0,
                /// <summary> ������ ���������� ������� �� ��������� </summary>
                FromCenter = 1,
                /// <summary> ������ ���������� ������� �� ������ </summary>
                FromEdge = 2
        };


        /// <summary> ��������� � ����������� ������� ������ </summary>
        /// <remarks> ��������� ����� �������������� ��� �� �������������� ��������� ������ �� ��� ���������� (�� ��� �������� ����������) </remarks>
        struct FillSettings {
                /// <summary> ������ �������, ���������� � ��������� �� ������� ������ </summary>
                float fillRatio;
                /// <summary> ������ ������ ������ ��� ��������� ������� </summary>
                FillSide drawSide;


                FillSettings(float fillRatio = 1.0, FillSide drawSide = FillSide::FromCenter) {
                        this->fillRatio = fillRatio;
                        this->drawSide = drawSide;
                }
        };
        #pragma endregion


        #pragma region ����
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



        #pragma region ������
        public:

        virtual ~BaseDrawableShape();


        /// <summary> ��������� ��������� ������� ������ </summary>
        /// <param name="isVisible"></param>
        virtual void SetOutlineVisibility(bool isVisible) = 0;


        /// <summary> ��������� ��������� ������� ������ </summary>
        /// <param name="isVisible"></param>
        virtual void SetFillVisibility(bool isVisible) = 0;


        /// <summary> ��������� ������ </summary>
        /// <remarks> 
        /// �������������� ����� � ����� �������, 
        /// ��������� ��������� ������ ������� ������ ������� �� ������� ��������� (������ OpenGL)
        /// </remarks>
        /// <param name="window"> ����, � ������� ������������ ��������� </param>
        virtual void Draw(GLFWwindow* window);


        protected:

        /// <summary> ����������� ���������� </summary>
        /// <param name="vertices"> ������ �� 4 ������, ����������� �������������� </param>
        /// <param name="fillSettings"> ��������� ������� ��������������� </param>
        /// <param name="outlineSettings"> ��������� ������� ��������������� </param>
        /// <param name="vertexPath"> ������������ ����� � ��������� �������� </param>
        /// <param name="fragmentPath"> ������������ ����� � ����������� �������� </param>
        BaseDrawableShape(BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings, const GLchar* vertexPath, const GLchar* fragmentPath);


        /// <summary> ���������� ������ ��������� </summary>
        virtual int GetVertexCount() = 0;


        /// <summary> ���������� �����, ������� �������� ������ ������ ������� </summary>
        virtual int GetPerVertexNumberCount() = 0;


        /// <summary> ���������� �������� ��������� </summary>
        virtual int GetIndexCount() = 0;
        

        /// <summary> ��������� �������� ���������� �������� � ������ ��� ����������� ���������� ��� ��������� ������� �� ��������� </summary>
        /// <remarks> ���������� ���� ��� �� ����� ������������� </remarks>
        virtual void SetupShaderParamsLayout() = 0;


        /// <summary> ��������� ���������� ���������� ������� </summary>
        /// <remarks> ���������� ��������������� ����� ������ �������� ��������� </remarks>
        /// <param name="window"> ����, � ������� ������������ ��������� </param>
        virtual void SetupShaderUniformValues(GLFWwindow* window) = 0;


        /// <summary> ��������� ��������� ������� OpenGL </summary>
        virtual void InitializeBuffers();


        private:
        #pragma endregion
};

