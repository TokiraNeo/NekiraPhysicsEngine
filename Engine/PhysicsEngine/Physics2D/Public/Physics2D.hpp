/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#if defined(_WIN32) || defined(_WIN64)

#ifndef PHYSICS2D_API

#ifdef PHYSICS2D_EXPORT
#define PHYSICS2D_API __declspec(dllexport)
#else // #ifdef PHYSICS2D_EXPORT
#define PHYSICS2D_API __declspec(dllimport)
#endif // #ifdef PHYSICS2D_EXPORT

#endif // #ifndef PHYSICS2D_API

#elif defined(__GNUC__) || defined(__clang__)

#ifndef PHYSICS2D_API

#ifdef PHYSICS2D_EXPORT
#define PHYSICS2D_API __attribute__((visibility("default")))
#else // #ifdef PHYSICS2D_EXPORT
#define PHYSICS2D_API
#endif // #ifdef PHYSICS2D_EXPORT

#endif // #ifndef PHYSICS2D_API

#endif // #if defined(_WIN32) || defined(_WIN64)