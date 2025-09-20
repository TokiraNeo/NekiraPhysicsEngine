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
float Sqrt(float value);
double Sqrt(double value);

/**
 * @brief Arc Cosine (in Radians)
 */
float ACos(float value);
double ACos(double value);

/**
 * @brief Arc Sine (in Radians)
 */
float ASin(float value);
double ASin(double value);

/**
 * @brief Arc Tangent (in Radians)
 */
float RadiansToDegrees(float radians);
double RadiansToDegrees(double radians);

/**
 * @brief Degrees to Radians
 */
float DegreesToRadians(float degrees);
double DegreesToRadians(double degrees);