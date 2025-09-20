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


bool IsNearlyZero(float value, float epsilon)
{
    return std::abs(value) <= epsilon;
}

bool IsNearlyZero(double value, double epsilon)
{
    return std::abs(value) <= epsilon;
}

bool IsNearlyEqual(float a, float b, float epsilon)
{
    return std::abs(a - b) <= epsilon;
}

bool IsNearlyEqual(double a, double b, double epsilon)
{
    return std::abs(a - b) <= epsilon;
}

float Sqrt(float value)
{
    return std::sqrt(value);
}

double Sqrt(double value)
{
    return std::sqrt(value);
}

float ACos(float value)
{
    return std::acos(value);
}

double ACos(double value)
{
    return std::acos(value);
}

float ASin(float value)
{
    return std::asin(value);
}

double ASin(double value)
{
    return std::asin(value);
}

float RadiansToDegrees(float radians)
{
    return radians * (180.0F / std::numbers::pi_v<float>);
}

double RadiansToDegrees(double radians)
{
    return radians * (180.0 / std::numbers::pi_v<double>);
}

float DegreesToRadians(float degrees)
{
    return degrees * (std::numbers::pi_v<float> / 180.0F);
}

double DegreesToRadians(double degrees)
{
    return degrees * (std::numbers::pi_v<double> / 180.0);
}