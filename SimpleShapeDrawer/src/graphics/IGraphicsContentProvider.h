#pragma once

#include "../shapes/BaseDrawableShape.h"




class IGraphicsContentProvider
{
        public:

        /// <summary> �������� ��������� ������� ��� ����������� ��������� � ������ � ���� </summary>
        /// <param name="shape"> �������� ������ </param>
        /// <returns> ���������� ���� � �������, ���������� ���������� �� ���������� ������ ��������� � 
        /// ����������� �������� ������ �� ������� ��������� </returns>
        virtual int RegisterContent(BaseDrawableShape* shape) = 0;


        /// <summary> �������� ������� ������� � �������� ������ </summary>
        /// <param name="id"> ����������� ���� </param>
        /// <returns> ������� �� ������������������ ������ � ������ <paramref name="id"/>? </returns>
        virtual bool HasContentWithId(int id) = 0;


        /// <summary> �������� ������� �� ������� ��������� � ������ � ���� </summary>
        /// <param name="id"> ���� �������, ���������� ��� ����������� </param>
        /// <param name="throwIfNotFound"> ���� ������ �� ������, ����� �� ����������� ����������? </param>
        /// <returns></returns>
        virtual bool TryUnregisterContent(int id, bool throwIfNotFound = false) = 0;


        /// <summary> ��������� ������������������ �������� � ���� OpenGL </summary>
        virtual void DrawContent(GLFWwindow* window) = 0;


        /// <summary> ������������������ ������������ ������� ������� �� ���������� </summary>
        //virtual GLFWkeyfun OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) = 0;
        virtual void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) = 0;
};

