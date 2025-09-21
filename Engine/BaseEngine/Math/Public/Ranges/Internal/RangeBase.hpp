/**
 * MIT License
 *
 * Copyright (c) 2025 TokiraNeo (https://github.com/TokiraNeo)
 *
 * For more detail, please refer to the LICENSE file in the root directory of this project.
 */

#pragma once

#include <CoreMacros.hpp>
#include <EASTL/type_traits.h>
#include <Utility/MathUtilities.hpp>


NAMESPACE_BEGIN(BE::Math)

NAMESPACE_BEGIN(TRangeInternal)

/// Concept for TRange<>
template <typename T>
concept TRangeConcept = eastl::is_floating_point_v<T> || eastl::is_integral_v<T>;

NAMESPACE_END() // namespace BE::Math::TRangeInternal

/// TRange<>
template <typename T>
    requires TRangeInternal::TRangeConcept<T>
struct TRange final
{
private:
    T    MinValue;
    T    MaxValue;
    char IncludeMin; // 0: Exclude, 1: Include
    char IncludeMax; // 0: Exclude, 1: Include
public:
    ~TRange() = default;

    constexpr TRange();
    constexpr TRange(T minValue, T maxValue, char includeMin = 0, char includeMax = 0);

    TRange(const TRange& other);
    TRange(TRange&& other) noexcept;

    TRange& operator=(const TRange& other);
    TRange& operator=(TRange&& other) noexcept;

    bool operator==(const TRange& other) const;
    bool operator!=(const TRange& other) const;

    bool Contains(T value) const;

    T Clamp(T value) const;
};



/* ====-------------------------------------------==== */
// Implementation of TRange<>
/* ====-------------------------------------------==== */

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
constexpr TRange<T>::TRange() : MinValue(0), MaxValue(0), IncludeMin(0), IncludeMax(0)
{}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
constexpr TRange<T>::TRange(T minValue, T maxValue, char includeMin, char includeMax)
    : MinValue(minValue), MaxValue(maxValue), IncludeMin(includeMin), IncludeMax(includeMax)
{
    static_assert(minValue <= maxValue, "MinValue must be less than or equal to MaxValue.");
}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
TRange<T>::TRange(const TRange& other)
    : MinValue(other.MinValue), MaxValue(other.MaxValue), IncludeMin(other.IncludeMin), IncludeMax(other.IncludeMax)
{}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
TRange<T>::TRange(TRange&& other) noexcept
    : MinValue(other.MinValue), MaxValue(other.MaxValue), IncludeMin(other.IncludeMin), IncludeMax(other.IncludeMax)
{
    other.MinValue = 0;
    other.MaxValue = 0;
    other.IncludeMin = 0;
    other.IncludeMax = 0;
}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
TRange<T>& TRange<T>::operator=(const TRange& other)
{
    if (this != &other)
    {
        MinValue = other.MinValue;
        MaxValue = other.MaxValue;
        IncludeMin = other.IncludeMin;
        IncludeMax = other.IncludeMax;
    }
    return *this;
}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
TRange<T>& TRange<T>::operator=(TRange&& other) noexcept
{
    if (this != &other)
    {
        MinValue = other.MinValue;
        MaxValue = other.MaxValue;
        IncludeMin = other.IncludeMin;
        IncludeMax = other.IncludeMax;

        other.MinValue = 0;
        other.MaxValue = 0;
        other.IncludeMin = 0;
        other.IncludeMax = 0;
    }
    return *this;
}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
bool TRange<T>::operator==(const TRange& other) const
{
    // We may have a FloatRange, so we use IsNearlyEqual for comparison
    return IsNearlyEqual(MinValue, other.MinValue) && IsNearlyEqual(MaxValue, other.MaxValue)
           && (IncludeMin == other.IncludeMin) && (IncludeMax == other.IncludeMax);
}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
bool TRange<T>::operator!=(const TRange& other) const
{
    return !(*this == other);
}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
bool TRange<T>::Contains(T value) const
{
    const bool B_GREATER_THAN_MIN = (IncludeMin == 0) ? (value > MinValue) : (value >= MinValue);
    const bool B_LESS_THAN_MAX = (IncludeMax == 0) ? (value < MaxValue) : (value <= MaxValue);
    return B_GREATER_THAN_MIN && B_LESS_THAN_MAX;
}

template <typename T>
    requires TRangeInternal::TRangeConcept<T>
T TRange<T>::Clamp(T value) const
{
    return Clamp<T>(value, MinValue, MaxValue);
}

NAMESPACE_END() // namespace BE::Math