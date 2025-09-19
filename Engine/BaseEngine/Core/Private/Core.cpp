/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Core.hpp>

int main()
{
    SVector position(0.0F);

    position += SVector(1.0F, 2.0F, 3.0F);

    position ^= SVector(1.0F, 5.0F, 2.0F);

    auto dot = position | FORWARD_VECTOR;
}