/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <Math.hpp>

NAMESPACE_BEGIN(BE::Math)


/**
 * @brief Check if a floating-point number is nearly zero
 * @param value The floating-point number to check
 * @param epsilon The tolerance level for comparison (default is 1E-6 for float, 1E-12 for double)
 */
MATH_API bool IsNearlyZero(float value, float epsilon = 1E-6F);
MATH_API bool IsNearlyZero(double value, double epsilon = 1E-12);

/**
 * @brief Check if two floating-point numbers are nearly equal
 * @param a The first floating-point number
 * @param b The second floating-point number
 * @param epsilon The tolerance level for comparison (default is 1E-6 for float, 1E-12 for double)
 */
MATH_API bool IsNearlyEqual(float a, float b, float epsilon = 1E-6F);
MATH_API bool IsNearlyEqual(double a, double b, double epsilon = 1E-12);

/**
 * @brief Square Root
 */
MATH_API float  Sqrt(float value);
MATH_API double Sqrt(double value);

/**
 * @brief Cosine (in Radians)
 */
MATH_API float  Cos(float radians);
MATH_API double Cos(double radians);

/**
 * @brief Sine (in Radians)
 */
MATH_API float  Sin(float radians);
MATH_API double Sin(double radians);

/**
 * @brief Arc Cosine (in Radians)
 */
MATH_API float  ACos(float value);
MATH_API double ACos(double value);

/**
 * @brief Arc Sine (in Radians)
 */
MATH_API float  ASin(float value);
MATH_API double ASin(double value);

/**
 * @brief Arc Tangent2 (in Radians)
 */
MATH_API float  ATan2(float y, float x);
MATH_API double ATan2(double y, double x);

/**
 * @brief Arc Tangent (in Radians)
 */
MATH_API float  RadiansToDegrees(float radians);
MATH_API double RadiansToDegrees(double radians);

/**
 * @brief Degrees to Radians
 */
MATH_API float  DegreesToRadians(float degrees);
MATH_API double DegreesToRadians(double degrees);

/**
 * @brief Minimum of two values
 */
template <typename T>
static constexpr T Min(T a, T b)
{
    return (a < b) ? a : b;
}

/**
 * @brief Maximum of two values
 */
template <typename T>
static constexpr T Max(T a, T b)
{
    return (a > b) ? a : b;
}

/**
 * @brief Clamp a value between a minimum and maximum range
 */
template <typename T>
static constexpr T Clamp(T value, T min, T max)
{
    return (value < min) ? min : ((value > max) ? max : value);
}

/**
 * @brief Mapping a value from one range to another
 *
 */
template <typename T>
static constexpr T Mapping(T value, T inMin, T inMax, T outMin, T outMax)
{
    if constexpr (IsNearlyZero(inMax - inMin))
    {
        return outMin; // Avoid division by zero
    }
    return outMin + ((value - inMin) * (outMax - outMin) / (inMax - inMin));
}

/**
 * @brief Linear Interpolation between two values
 * @param a The start value
 * @param b The end value
 * @param t The interpolation factor (0.0 to 1.0)
 */
template <typename T>
static constexpr T Lerp(T a, T b, float t)
{
    t = Clamp(t, 0.0F, 1.0F);
    return a + ((b - a) * t);
}

NAMESPACE_END() // namespace BE::Math