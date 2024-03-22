#include "CircleDrawableShapeCreator.h"
#include "CircleDrawableShape.h"


BaseDrawableShape* CircleDrawableShapeCreator::CreateWithRandomScreenSpaceParams() {
        float radius = 0.18f,
              minRectSize = 2.0f * radius;

        // Подготовим вершины
        GLfloat* rectVertices = RectangleDrawableShapeCreator::GenerateVertices(minRectSize, minRectSize, minRectSize, minRectSize);

        BaseDrawableShape::FillSettings fillSettings(1.0, BaseDrawableShape::FillSide::FromEdge);
        BaseDrawableShape::OutlineSettings outlineSettings(0.1, BaseDrawableShape::OutlineSide::Inner);

        return new CircleDrawableShape(radius, rectVertices, fillSettings, outlineSettings);
}
