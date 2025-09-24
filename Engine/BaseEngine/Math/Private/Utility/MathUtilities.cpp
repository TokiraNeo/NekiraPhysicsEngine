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

NAMESPACE_BEGIN(BE::Math)

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

constexpr float Cos(float radians)
{
    return std::cos(radians);
}

constexpr double Cos(double radians)
{
    return std::cos(radians);
}

constexpr float Sin(float radians)
{
    return std::sin(radians);
}

constexpr double Sin(double radians)
{
    return std::sin(radians);
}

constexpr float ACos(float radians)
{
    return std::acos(radians);
}

constexpr double ACos(double radians)
{
    return std::acos(radians);
}

constexpr float ASin(float radians)
{
    return std::asin(radians);
}

constexpr double ASin(double radians)
{
    return std::asin(radians);
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

NAMESPACE_END() // namespace BE::Math