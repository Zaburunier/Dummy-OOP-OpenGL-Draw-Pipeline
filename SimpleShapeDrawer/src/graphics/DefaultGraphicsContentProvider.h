#pragma once
#include "IGraphicsContentProvider.h"
#include <map>
#include <iostream>




class DefaultGraphicsContentProvider : public IGraphicsContentProvider {
	#pragma region ����
        private:

	std::map<int, BaseDrawableShape*> shapeMap;

        /// <summary> �������, ������������ ��� �������� ����� � ������� </summary>
        std::atomic<int> registrationCounter;
	#pragma endregion


	#pragma region ������
	public:

	DefaultGraphicsContentProvider();


        ~DefaultGraphicsContentProvider();


        /// <summary> �������� ��������� ������� ��� ����������� ��������� � ������ � ���� </summary>
        /// <param name="shapeToRegister"> �������� ������ </param>
        /// <returns> ���������� ���� � �������, ���������� ���������� �� ���������� ������ ��������� � 
        /// ����������� �������� ������ �� ������� ��������� </returns>
        int RegisterContent(BaseDrawableShape* shapeToRegister) override;


        /// <summary> �������� ������� ������� � �������� ������ </summary>
        /// <param name="idToCheck"> ����������� ���� </param>
        /// <returns> ������� �� ������������������ ������ � ������ <paramref name="id"/>? </returns>
        bool HasContentWithId(int idToCheck) override;


        /// <summary> �������� ������� �� ������� ��������� � ������ � ���� </summary>
        /// <param name="id"> ���� �������, ���������� ��� ����������� </param>
        /// <param name="throwIfNotFound"> ���� ������ �� ������, ����� �� ����������� ����������? </param>
        /// <returns></returns>
        bool TryUnregisterContent(int id, bool throwIfNotFound = false) override;


        /// <summary> ��������� ������������������ �������� � ���� OpenGL </summary>
        void DrawContent(GLFWwindow* window) override;


        /// <summary> ������������������ ������������ ������� ������� �� ���������� </summary>
        void OnKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mode) override;


	private:
	#pragma endregion


};

