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

bool IsNearlyZero(float value, float epsilon = 1E-6F);

bool IsNearlyZero(double value, double epsilon = 1E-12);

bool IsNearlyEqual(float a, float b, float epsilon = 1E-6F);

bool IsNearlyEqual(double a, double b, double epsilon = 1E-12);

float Sqrt(float value);

double Sqrt(double value);

NAMESPACE_END() // namespace BE::Math