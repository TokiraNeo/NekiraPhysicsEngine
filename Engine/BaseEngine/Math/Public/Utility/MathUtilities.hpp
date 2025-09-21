/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once



/**
 * @brief Check if a floating-point number is nearly zero
 * @param value The floating-point number to check
 * @param epsilon The tolerance level for comparison (default is 1E-6 for float, 1E-12 for double)
 */
constexpr bool IsNearlyZero(float value, float epsilon = 1E-6F);
constexpr bool IsNearlyZero(double value, double epsilon = 1E-12);

/**
 * @brief Check if two floating-point numbers are nearly equal
 * @param a The first floating-point number
 * @param b The second floating-point number
 * @param epsilon The tolerance level for comparison (default is 1E-6 for float, 1E-12 for double)
 */
constexpr bool IsNearlyEqual(float a, float b, float epsilon = 1E-6F);
constexpr bool IsNearlyEqual(double a, double b, double epsilon = 1E-12);

/**
 * @brief Square Root
 */
constexpr float  Sqrt(float value);
constexpr double Sqrt(double value);

/**
 * @brief Arc Cosine (in Radians)
 */
constexpr float  ACos(float value);
constexpr double ACos(double value);

/**
 * @brief Arc Sine (in Radians)
 */
constexpr float  ASin(float value);
constexpr double ASin(double value);

/**
 * @brief Arc Tangent (in Radians)
 */
constexpr float  RadiansToDegrees(float radians);
constexpr double RadiansToDegrees(double radians);

/**
 * @brief Degrees to Radians
 */
constexpr float  DegreesToRadians(float degrees);
constexpr double DegreesToRadians(double degrees);

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