/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Utility/MathUtilities.hpp>
#include <cmath>
#include <numbers>


constexpr bool IsNearlyZero(float value, float epsilon)
{
    return std::abs(value) <= epsilon;
}

constexpr bool IsNearlyZero(double value, double epsilon)
{
    return std::abs(value) <= epsilon;
}

constexpr bool IsNearlyEqual(float a, float b, float epsilon)
{
    return std::abs(a - b) <= epsilon;
}

constexpr bool IsNearlyEqual(double a, double b, double epsilon)
{
    return std::abs(a - b) <= epsilon;
}

constexpr float Sqrt(float value)
{
    return std::sqrt(value);
}

constexpr double Sqrt(double value)
{
    return std::sqrt(value);
}

constexpr float ACos(float value)
{
    return std::acos(value);
}

constexpr double ACos(double value)
{
    return std::acos(value);
}

constexpr float ASin(float value)
{
    return std::asin(value);
}

constexpr double ASin(double value)
{
    return std::asin(value);
}

constexpr float RadiansToDegrees(float radians)
{
    return radians * (180.0F / std::numbers::pi_v<float>);
}

constexpr double RadiansToDegrees(double radians)
{
    return radians * (180.0 / std::numbers::pi_v<double>);
}

constexpr float DegreesToRadians(float degrees)
{
    return degrees * (std::numbers::pi_v<float> / 180.0F);
}

constexpr double DegreesToRadians(double degrees)
{
    return degrees * (std::numbers::pi_v<double> / 180.0);
}