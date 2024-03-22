#pragma once
#include "../BaseDrawableShape.h"




class TriangleDrawableShape : public BaseDrawableShape {
	#pragma region ����

	#pragma endregion


	#pragma region ������
	public:

	/// <summary> ����������� ���������� </summary>
	/// <param name="vertices"> ������ �� 4 ������, ����������� �������������� </param>
	/// <param name="fillSettings"> ��������� ������� ��������������� </param>
	/// <param name="outlineSettings"> ��������� ������� ��������������� </param>
	TriangleDrawableShape(GLfloat* vertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings);


	/// <summary> ��������� ��������� ������� ������ </summary>
	/// <param name="isVisible"></param>
	void SetOutlineVisibility(bool isVisible) override;


	/// <summary> ��������� ��������� ������� ������ </summary>
	/// <param name="isVisible"></param>
	void SetFillVisibility(bool isVisible) override;


	/// <summary> ��������� ������ </summary>
	/// <remarks> 
	/// �������������� ����� � ����� �������, 
	/// ��������� ��������� ������ ������� ������ ������� �� ������� ��������� (������ OpenGL)
	/// </remarks>
	/// <param name="window"> ����, � ������� ������������ ��������� </param>
	void Draw(GLFWwindow* window) override;


	~TriangleDrawableShape();


	protected:


	/// <summary> ���������� ������ ��������� </summary>
	int GetVertexCount() override;


	/// <summary> ���������� �����, ������� �������� ������ ������ ������� </summary>
	int GetPerVertexNumberCount() override;


	/// <summary> ���������� �������� ��������� </summary>
	int GetIndexCount() override;


	/// <summary> ��������� �������� ���������� �������� � ������ ��� ����������� ���������� ��� ��������� ������� �� ��������� </summary>
	void SetupShaderParamsLayout() override;

	/// <summary> ��������� ���������� ���������� ������� </summary>
	/// <remarks> ���������� ��������������� ����� ������ �������� ��������� </remarks>
	void SetupShaderUniformValues(GLFWwindow* window) override;
	#pragma endregion
};

