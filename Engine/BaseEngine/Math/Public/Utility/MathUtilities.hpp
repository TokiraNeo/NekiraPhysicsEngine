/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>

NAMESPACE_BEGIN(BE::Math)

/**
 * @brief Check if a floating-point number is nearly zero
 * @param value The floating-point number to check
 * @param epsilon The tolerance level for comparison (default is 1E-6 for float, 1E-12 for double)
 */
bool IsNearlyZero(float value, float epsilon = 1E-6F);
bool IsNearlyZero(double value, double epsilon = 1E-12);

/**
 * @brief Check if two floating-point numbers are nearly equal
 * @param a The first floating-point number
 * @param b The second floating-point number
 * @param epsilon The tolerance level for comparison (default is 1E-6 for float, 1E-12 for double)
 */
bool IsNearlyEqual(float a, float b, float epsilon = 1E-6F);
bool IsNearlyEqual(double a, double b, double epsilon = 1E-12);

/**
 * @brief Square Root
 */
float  Sqrt(float value);
double Sqrt(double value);

/**
 * @brief Cosine (in Radians)
 */
float  Cos(float radians);
double Cos(double radians);

/**
 * @brief Sine (in Radians)
 */
float  Sin(float radians);
double Sin(double radians);

/**
 * @brief Arc Cosine (in Radians)
 */
float  ACos(float value);
double ACos(double value);

/**
 * @brief Arc Sine (in Radians)
 */
float  ASin(float value);
double ASin(double value);

/**
 * @brief Arc Tangent (in Radians)
 */
float  RadiansToDegrees(float radians);
double RadiansToDegrees(double radians);

/**
 * @brief Degrees to Radians
 */
float  DegreesToRadians(float degrees);
double DegreesToRadians(double degrees);

/**
 * @brief Minimum of two values
 */
template <typename T>
constexpr T Min(T a, T b)
{
    return (a < b) ? a : b;
}

/**
 * @brief Maximum of two values
 */
template <typename T>
constexpr T Max(T a, T b)
{
    return (a > b) ? a : b;
}

/**
 * @brief Clamp a value between a minimum and maximum range
 */
template <typename T>
constexpr T Clamp(T value, T min, T max)
{
    return (value < min) ? min : ((value > max) ? max : value);
}

/**
 * @brief Mapping a value from one range to another
 *
 */
template <typename T>
constexpr T Mapping(T value, T inMin, T inMax, T outMin, T outMax)
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
constexpr T Lerp(T a, T b, float t)
{
    t = Clamp(t, 0.0F, 1.0F);
    return a + ((b - a) * t);
}

NAMESPACE_END() // namespace BE::Math