/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#if defined(_WIN32) || defined(_WIN64)

#ifndef CORE_API

#ifdef CORE_EXPORT
#define CORE_API __declspec(dllexport)
#else // #ifdef CORE_EXPORT
#define CORE_API __declspec(dllimport)
#endif // #ifdef CORE_EXPORT

#endif // #ifndef CORE_API

#elif defined(__GNUC__) || defined(__clang__)

#ifndef CORE_API

#ifdef CORE_EXPORT
#define CORE_API __attribute__((visibility("default")))
#else // #ifdef CORE_EXPORT
#define CORE_API
#endif // #ifdef CORE_EXPORT

#endif // #ifndef CORE_API

#endif // #if defined(_WIN32) || defined(_WIN64)