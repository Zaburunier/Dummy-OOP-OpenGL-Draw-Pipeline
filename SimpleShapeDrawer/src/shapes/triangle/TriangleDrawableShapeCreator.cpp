#include "TriangleDrawableShapeCreator.h"
#include "TriangleDrawableShape.h"




BaseDrawableShape* TriangleDrawableShapeCreator::CreateWithRandomScreenSpaceParams() {
        // Подготовим вершины
        GLfloat* vertices = GenerateVertices();

        BaseDrawableShape::FillSettings fillSettings(1.0, BaseDrawableShape::FillSide::FromEdge);
        BaseDrawableShape::OutlineSettings outlineSettings(0.1, BaseDrawableShape::OutlineSide::Inner);

        return new TriangleDrawableShape(vertices, fillSettings, outlineSettings);
}


GLfloat* TriangleDrawableShapeCreator::GenerateVertices() {
        GLfloat* result = new GLfloat[18];

        float maxValue = static_cast<float>(RAND_MAX),
                denominator = maxValue - 0.0;

        srand((unsigned int)time(NULL) - 4);

        float xCoord1 = -1 + 2 * (maxValue - std::rand()) / denominator,
              yCoord1 = -1 + 2 * (maxValue - std::rand()) / denominator,
              xCoord2 = -1 + 2 * (maxValue - std::rand()) / denominator,
              yCoord2 = -1 + 2 * (maxValue - std::rand()) / denominator,
              xCoord3 = -1 + 2 * (maxValue - std::rand()) / denominator,
              yCoord3 = -1 + 2 * (maxValue - std::rand()) / denominator,
              zCoord = (maxValue - std::rand()) / denominator;

        // Вершина 1 (положение и цвет)
        result[0] = xCoord1;
        result[1] = yCoord1;
        result[2] = zCoord;

        result[3] = 1.0f;
        result[4] = 0.6f;
        result[5] = 1.0f;

        // Вершина 2 (положение и цвет)
        result[6] = xCoord2;
        result[7] = yCoord2;
        result[8] = zCoord;

        result[9] = 0.3f;
        result[10] = 1.0f;
        result[11] = 0.8f;

        // Вершина 3 (положение и цвет)
        result[12] = xCoord3;
        result[13] = yCoord3;
        result[14] = zCoord;

        result[15] = 0.95f;
        result[16] = 0.5f;
        result[17] = 0.2f;

        return result;
}
