/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#if defined(_WIN32) || defined(_WIN64)

#ifndef PHYSICSBASE_API

#ifdef PHYSICSBASE_EXPORT
#define PHYSICSBASE_API __declspec(dllexport)
#else // #ifdef PHYSICSBASE_EXPORT
#define PHYSICSBASE_API __declspec(dllimport)
#endif // #ifdef PHYSICSBASE_EXPORT

#endif // #ifndef PHYSICSBASE_API

#elif defined(__GNUC__) || defined(__clang__)

#ifndef PHYSICSBASE_API

#ifdef PHYSICSBASE_EXPORT
#define PHYSICSBASE_API __attribute__((visibility("default")))
#else // #ifdef PHYSICSBASE_EXPORT
#define PHYSICSBASE_API
#endif // #ifdef PHYSICSBASE_EXPORT

#endif // #ifndef PHYSICSBASE_API

#endif // #if defined(_WIN32) || defined(_WIN64)