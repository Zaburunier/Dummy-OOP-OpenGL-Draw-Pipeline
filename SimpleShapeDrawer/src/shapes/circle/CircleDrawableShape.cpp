#include "CircleDrawableShape.h"


CircleDrawableShape::CircleDrawableShape(GLfloat radius, GLfloat* rectVertices, BaseDrawableShape::FillSettings fillSettings, BaseDrawableShape::OutlineSettings outlineSettings) : 
        RectangleDrawableShape(rectVertices, fillSettings, outlineSettings, ".\\src\\shapes\\circle\\CircleShader.vertex", ".\\src\\shapes\\circle\\CircleShader.fragment") {
        centerPoint = CalculateCentroid(rectVertices);
        this->radius = radius;
}


CircleDrawableShape::~CircleDrawableShape() {
        free(centerPoint);
}


void CircleDrawableShape::Draw(GLFWwindow *window) {
        bool wasTransparencyEnabled = glIsEnabled(GL_BLEND);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        
        RectangleDrawableShape::Draw(window);

        if (!wasTransparencyEnabled)
                glDisable(GL_BLEND);
}


void CircleDrawableShape::SetupShaderParamsLayout() {
        RectangleDrawableShape::SetupShaderParamsLayout();
}


void CircleDrawableShape::SetupShaderUniformValues(GLFWwindow* window) {
        RectangleDrawableShape::SetupShaderUniformValues(window);

        this->shader->SetFloat("radius", radius);
        this->shader->SetFloat3("centerPoint", centerPoint);

        int windowWidth = 0, windowHeight = 0;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        this->shader->SetInt2("windowSize", windowWidth, windowHeight);
}


GLfloat* CircleDrawableShape::CalculateCentroid(GLfloat* vertices) {
        GLfloat *result = static_cast<GLfloat*>(calloc(3, sizeof(GLfloat)));

        int count = GetVertexCount();

        for (int i = 0; i < count; i = i + 1) {
                result[0] += vertices[i * 3];
                result[1] += vertices[i * 3 + 1];
                result[2] += vertices[i * 3 + 2];
        }

        result[0] /= static_cast<float>(count);
        result[1] /= static_cast<float>(count);
        result[2] /= static_cast<float>(count);

        return result;
}
