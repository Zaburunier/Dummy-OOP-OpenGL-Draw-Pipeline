#include "TriangleDrawableShape.h"




TriangleDrawableShape::TriangleDrawableShape(GLfloat* vertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings) : 
        BaseDrawableShape(fillSettings, outlineSettings, ".\\src\\shapes\\triangle\\TriangleShader.vertex", ".\\src\\shapes\\triangle\\TriangleShader.fragment") {
        this->vertices = vertices;

        this->indices = new GLuint[3]{ 0, 1, 2 };

        InitializeBuffers();
}


TriangleDrawableShape::~TriangleDrawableShape() {
        delete[] indices;
}


int TriangleDrawableShape::GetVertexCount() {
        return 3;
}


int TriangleDrawableShape::GetPerVertexNumberCount() {
        return 6;
}


int TriangleDrawableShape::GetIndexCount() {
        return 3;
}


void TriangleDrawableShape::SetFillVisibility(bool isVisible) {

}


void TriangleDrawableShape::SetOutlineVisibility(bool isVisible) {

}


void TriangleDrawableShape::Draw(GLFWwindow* window) {
        BaseDrawableShape::Draw(window);
        //this->shader->Use();

        //SetupShaderUniformValues(window);

        //glBindVertexArray(vertexArrayObjectCode);
        ////glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, GetIndexCount(), GL_UNSIGNED_INT, 0);
        //glBindVertexArray(0);

}


void TriangleDrawableShape::SetupShaderParamsLayout() {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
}


void TriangleDrawableShape::SetupShaderUniformValues(GLFWwindow* window) {

}
