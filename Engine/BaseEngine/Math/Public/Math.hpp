/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#if defined(_WIN32) || defined(_WIN64)

#ifndef MATH_API

#ifdef MATH_EXPORT
#define MATH_API __declspec(dllexport)
#else // #ifdef MATH_EXPORT
#define MATH_API __declspec(dllimport)
#endif // #ifdef MATH_EXPORT

#endif // #ifndef MATH_API

#elif defined(__GNUC__) || defined(__clang__)

#ifndef MATH_API

#ifdef MATH_EXPORT
#define MATH_API __attribute__((visibility("default")))
#else // #ifdef MATH_EXPORT
#define MATH_API
#endif // #ifdef MATH_EXPORT

#endif // #ifndef MATH_API

#endif // #if defined(_WIN32) || defined(_WIN64)
