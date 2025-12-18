/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once


#include <CoreMacros.hpp>
#include <Physics2D.hpp>

NAMESPACE_BEGIN(PHYE::Physics2D)

// Forward Declarations
class CPoint2D;
class CLine2D;
class CCircle2D;
class CRectangle2D;
class COrientedRectangle2D;

/**
 * @brief Check if a Point2D is on a Line2D segment.
 * @param point The point to check.
 * @param line The line segment to check against.
 * @param includeEdge Whether to include the edge of the line segment in the check.
 * @return true if the point is on the line segment, false otherwise.
 */
PHYSICS2D_API bool IsPointOnLine2D(const CPoint2D& point, const CLine2D& line, bool includeEdge = true);

/**
 * @brief Check if a Point2D is in a Circle2D(includes the edge).
 * @param point The point to check.
 * @param circle The circle to check against.
 * @param includeEdge Whether to include the edge of the circle in the check.
 * @return true if the point is in the circle, false otherwise.
 */
PHYSICS2D_API bool IsPointInCircle2D(const CPoint2D& point, const CCircle2D& circle, bool includeEdge = true);

/**
 * @brief Check if a Point2D is in a Rectangle2D(includes the edge).
 * @param point The point to check.
 * @param rectangle The rectangle to check against.
 * @param includeEdge Whether to include the edge of the rectangle in the check.
 * @return true if the point is in the rectangle, false otherwise.
 */
PHYSICS2D_API bool IsPointInRectangle2D(const CPoint2D& point, const CRectangle2D& rectangle, bool includeEdge = true);

/**
 * @brief Check if a Point2D is in an OrientedRectangle2D(includes the edge).
 * @param point The point to check.
 * @param orientedRectangle The oriented rectangle to check against.
 * @param includeEdge Whether to include the edge of the oriented rectangle in the check.
 * @return true if the point is in the oriented rectangle, false otherwise.
 */
PHYSICS2D_API bool IsPointInOrientedRectangle2D(const CPoint2D& point, const COrientedRectangle2D& orientedRectangle,
                                                bool includeEdge = true);

NAMESPACE_END() // namespace PHYE::Physics2D