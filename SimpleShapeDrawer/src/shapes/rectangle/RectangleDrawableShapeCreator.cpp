#include <random>

#include "RectangleDrawableShapeCreator.h"
#include "RectangleDrawableShape.h"


BaseDrawableShape* RectangleDrawableShapeCreator::CreateWithRandomScreenSpaceParams() {
        // Подготовим вершины
        GLfloat* vertices = GenerateVertices();

        BaseDrawableShape::FillSettings fillSettings(1.0, BaseDrawableShape::FillSide::FromEdge);
        BaseDrawableShape::OutlineSettings outlineSettings(0.1, BaseDrawableShape::OutlineSide::Inner);

        return new RectangleDrawableShape(vertices, fillSettings, outlineSettings);
}


void SortAndClampNumberPair(float& value1, float& value2, float minDistance, float maxDistance) {
        std::pair<float, float> minMaxPair = std::minmax(value1, value2);
        value1 = minMaxPair.first;
        value2 = minMaxPair.second;

        if (value2 - value1 > maxDistance) {
                value2 = value1 + maxDistance;
        } else if (value2 - value1 < minDistance) {
                value1 = value2 - minDistance;
        }
}


GLfloat* RectangleDrawableShapeCreator::GenerateVertices(float minWidth, float maxWidth, float minHeight, float maxHeight) {
        GLfloat* result = new GLfloat[12];

        float maxValue = static_cast<float>(RAND_MAX),
              denominator = maxValue - 0.0;

        srand((unsigned int)time(NULL) - 2);

        float xCoord1 = -1 + 2 * (maxValue - std::rand()) / denominator,
              yCoord1 = -1 + 2 * (maxValue - std::rand()) / denominator,
              xCoord2 = -1 + 2 * (maxValue - std::rand()) / denominator,
              yCoord2 = -1 + 2 * (maxValue - std::rand()) / denominator,
              zCoord = (maxValue - std::rand()) / denominator;

        // Соблюдаем заданные ограничения на размеры прямоугольника
        SortAndClampNumberPair(xCoord1, xCoord2, minWidth, maxWidth);
        SortAndClampNumberPair(yCoord1, yCoord2, minHeight, maxHeight);

        // Вершина 1
        result[0] = xCoord1;
        result[1] = yCoord1;
        result[2] = zCoord;

        // Вершина 2
        result[3] = xCoord2;
        result[4] = yCoord1;
        result[5] = zCoord;

        // Вершина 3
        result[6] = xCoord2;
        result[7] = yCoord2;
        result[8] = zCoord;

        // Вершина 4
        result[9] = xCoord1;
        result[10] = yCoord2;
        result[11] = zCoord;

        return result;
}
