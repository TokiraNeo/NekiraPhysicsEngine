/**
 * GPL-3.0 License
 *
 * Copyright (C) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

/* ====-------------------------------------------==== */
#ifndef KINDER_SMALL_FLOAT
#define KINDER_SMALL_FLOAT 1E-6F
#endif
/* ====-------------------------------------------==== */



/* ====-------------------------------------------==== */
#ifndef KINDER_SMALL_DOUBLE
#define KINDER_SMALL_DOUBLE 1E-12
#endif
/* ====-------------------------------------------==== */



/* ====-------------------------------------------==== */
/// 命名空间快捷宏，用于简化命名空间的定义和使用。
#ifndef NAMESPACE_BEGIN
#define NAMESPACE_BEGIN(name)                                                                                          \
    namespace name                                                                                                     \
    {
#endif

#ifndef NAMESPACE_END
#define NAMESPACE_END() }
#endif
/* ====-------------------------------------------==== */
