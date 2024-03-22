#include "RectangleDrawableShape.h"




RectangleDrawableShape::RectangleDrawableShape(GLfloat* vertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings) : 
        RectangleDrawableShape(vertices, fillSettings, outlineSettings, ".\\src\\shapes\\rectangle\\RectangleShader.vertex", ".\\src\\shapes\\rectangle\\RectangleShader.fragment") {

}


RectangleDrawableShape::RectangleDrawableShape(GLfloat* vertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings, const GLchar* vertexPath, const GLchar* fragmentPath) :
        BaseDrawableShape(fillSettings, outlineSettings, vertexPath, fragmentPath) {
        this->vertices = vertices;

        this->indices = new GLuint[6]{ 0, 1, 2, 2, 0, 3 };

        InitializeBuffers();
}


RectangleDrawableShape::~RectangleDrawableShape() {
        delete[] indices;
}


int RectangleDrawableShape::GetVertexCount() {
        return 4;
}


int RectangleDrawableShape::GetPerVertexNumberCount() {
        return 3;
}



int RectangleDrawableShape::GetIndexCount() {
        return 6;
}


void RectangleDrawableShape::SetFillVisibility(bool isVisible) {

}


void RectangleDrawableShape::SetOutlineVisibility(bool isVisible) {

}


void RectangleDrawableShape::Draw(GLFWwindow* window) {
        BaseDrawableShape::Draw(window);


}


void RectangleDrawableShape::SetupShaderParamsLayout() {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
}


void RectangleDrawableShape::SetupShaderUniformValues(GLFWwindow* window) {

}