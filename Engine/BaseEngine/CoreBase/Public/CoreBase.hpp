/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#if defined(_WIN32) || defined(_WIN64)

#ifndef COREBASE_API

#ifdef COREBASE_EXPORT
#define COREBASE_API __declspec(dllexport)
#else // #ifdef COREBASE_EXPORT
#define COREBASE_API __declspec(dllimport)
#endif // #ifdef COREBASE_EXPORT

#endif // #ifndef COREBASE_API

#elif defined(__GNUC__) || defined(__clang__)

#ifndef COREBASE_API

#ifdef COREBASE_EXPORT
#define COREBASE_API __attribute__((visibility("default")))
#else // #ifdef COREBASE_EXPORT
#define COREBASE_API
#endif // #ifdef COREBASE_EXPORT

#endif // #ifndef COREBASE_API

#endif // #if defined(_WIN32) || defined(_WIN64)