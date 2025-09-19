/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Utility/MathUtilities.hpp>
#include <cmath>


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
