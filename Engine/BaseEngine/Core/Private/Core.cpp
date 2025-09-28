/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#include <Math.hpp>
#include <Utility/MatrixUtilities.hpp>

void Func()
{
    SMatrix3 mat = SMatrix3::Identity();
    SMatrix2 mat2 = SMatrix2::Identity();
    SMatrix4 mat4 = SMatrix4::Identity();

    SMatrix3 rot3 = BE::Math::ZRotation3x3<float>(90.0F);
}