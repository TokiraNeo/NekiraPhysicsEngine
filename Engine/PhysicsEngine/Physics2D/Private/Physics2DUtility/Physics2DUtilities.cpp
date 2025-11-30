/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <MathUtility/MatrixUtilities.hpp>
#include <Physics2DUtility/Physics2DUtilities.hpp>
#include <Rigid2D/Geometry2D/Circle2D.hpp>
#include <Rigid2D/Geometry2D/Line2D.hpp>
#include <Rigid2D/Geometry2D/Rectangle2D.hpp>


NAMESPACE_BEGIN(PHYE::Physics2D)


bool IsPointOnLine2D(const CPoint2D& point, const CLine2D& line, bool includeEdge)
{
    //  二维点是否在二维线段上，这里如果使用y=kx+b的方式判断的话会遇到垂直线段无法处理的问题，所以这里使用向量运算来判断
    // 当点P在线段AB上时，向量AP和向量AB共线(即AP与AB的叉积为0)，并且点P在A和B之间(即0 <= AP·AB <= 1)

    const auto AP = point - line.GetStart();
    const auto AB = line.GetEnd() - line.GetStart();

    // 计算叉积, 判断是否共线.由于是二维向量, 叉积结果是一个标量
    const auto CROSS_PRODUCT = AP ^ AB;
    const bool IS_COLLINEAR = BE::Math::IsNearlyZero(CROSS_PRODUCT);

    // 计算点积, 判断点P是否在A和B之间
    const auto DOT_PRODUCT = AP | AB;
    const bool IS_BETWEEN = includeEdge ? (DOT_PRODUCT >= 0 && DOT_PRODUCT <= 1) : (DOT_PRODUCT > 0 && DOT_PRODUCT < 1);

    return IS_COLLINEAR && IS_BETWEEN;
}

bool IsPointInCircle2D(const CPoint2D& point, const CCircle2D& circle, bool includeEdge)
{
    // 计算点到圆心的距离的平方
    const auto DISTANCE_SQUARED = (point - circle.GetCenter()).SquareMagnitude();

    // 计算圆的半径的平方
    const auto RADIUS_SQUARED = circle.GetRadius() * circle.GetRadius();

    return includeEdge ? (DISTANCE_SQUARED <= RADIUS_SQUARED) : (DISTANCE_SQUARED < RADIUS_SQUARED);
}

bool IsPointInRectangle2D(const CPoint2D& point, const CRectangle2D& rectangle, bool includeEdge)
{
    const auto X_MIN = BE::Math::Min(rectangle.GetOrigin().X(), rectangle.GetEnd().X());
    const auto X_MAX = BE::Math::Max(rectangle.GetOrigin().X(), rectangle.GetEnd().X());

    const auto Y_MIN = BE::Math::Min(rectangle.GetOrigin().Y(), rectangle.GetEnd().Y());
    const auto Y_MAX = BE::Math::Max(rectangle.GetOrigin().Y(), rectangle.GetEnd().Y());

    const bool IS_IN_X =
        includeEdge ? (point.X() >= X_MIN && point.X() <= X_MAX) : (point.X() > X_MIN && point.X() < X_MAX);

    const bool IS_IN_Y =
        includeEdge ? (point.Y() >= Y_MIN && point.Y() <= Y_MAX) : (point.Y() > Y_MIN && point.Y() < Y_MAX);

    return IS_IN_X && IS_IN_Y;
}

bool IsPointInOrientedRectangle2D(const CPoint2D& point, const COrientedRectangle2D& orientedRectangle,
                                  bool includeEdge)
{
    // 将点转换到以矩形中心为原点的坐标系中
    auto translatedPoint = point - orientedRectangle.GetCenter();

    // 旋转矩阵
    auto rotationMatrix = BE::Math::ZRotation3x3(-orientedRectangle.GetAngle());

    // 将点旋转回轴对齐矩形的坐标系
    auto rotatedPoint = BE::Math::TransformPoint2D(translatedPoint, rotationMatrix);

    // 以矩形中心为原点的局部轴对齐矩形
    auto localRectangle = CRectangle2D(CPoint2D(0.0F), orientedRectangle.GetHalfExtents() * 2.0F);

    // 若该点加上矩形的半尺寸后仍在局部轴对齐矩形范围内，则点在矩形内
    auto localVector = rotatedPoint + orientedRectangle.GetHalfExtents();
    auto localPoint = CPoint2D(localVector);

    // 使用轴对齐矩形的点内检测函数
    return IsPointInRectangle2D(localPoint, localRectangle, includeEdge);
}

NAMESPACE_END() // namespace PHYE::Physics2D