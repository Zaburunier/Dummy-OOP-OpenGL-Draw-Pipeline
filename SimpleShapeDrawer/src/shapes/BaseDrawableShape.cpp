#include "BaseDrawableShape.h"





BaseDrawableShape::BaseDrawableShape(BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings, const GLchar* vertexPath, const GLchar* fragmentPath) {
        this->fillSettings = fillSettings;
        this->outlineSettings = outlineSettings;

        this->shader = new OpenGLShader(vertexPath, fragmentPath);
}


BaseDrawableShape::~BaseDrawableShape() {
        delete this->shader;

        glDeleteVertexArrays(1, &vertexArrayObjectCode);
        glDeleteBuffers(1, &vertexBufferObjectCode);
        glDeleteBuffers(1, &elementBufferObjectCode);
}


void BaseDrawableShape::Draw(GLFWwindow* window) {
        this->shader->Use();

        SetupShaderUniformValues(window);

        glBindVertexArray(vertexArrayObjectCode);
        glDrawElements(GL_TRIANGLES, GetIndexCount(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
}


void BaseDrawableShape::InitializeBuffers() {
        // https://habr.com/ru/articles/311808/

        glGenVertexArrays(1, &vertexArrayObjectCode);
        glGenBuffers(1, &vertexBufferObjectCode);
        glGenBuffers(1, &elementBufferObjectCode);

        // Привязываем массив и буферы 
        glBindVertexArray(vertexArrayObjectCode);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectCode);
        glBufferData(GL_ARRAY_BUFFER, GetVertexCount() * GetPerVertexNumberCount() * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObjectCode);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetIndexCount() * sizeof(GLuint), indices, GL_STATIC_DRAW);

        // Задаём разметку параметров шейдера в памяти
        SetupShaderParamsLayout();

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // Отвязываемся после завершения настройки
        glBindVertexArray(0);
}