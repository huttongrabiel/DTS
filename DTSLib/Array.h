/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <iostream>

namespace DTS {

template<typename T, size_t Size>
struct Array {
    using ValueType = T;
    using Reference = T&;
    using ConstReference = T const&;

    T arr[Size];

    [[nodiscard]] constexpr size_t size() const { return Size; }

    [[nodiscard]] constexpr bool empty() const { return size() == 0; }

    constexpr void fill(const T& u) {
        for (size_t i = 0; i < Size; i++) {
            arr[i] = u;
        }
    }

    constexpr T* data()
    {
        return arr;
    }

    constexpr T const* data() const
    {
        return arr;
    }

    constexpr Reference at(size_t index)
    {
        if (index >= Size)
            throw std::out_of_range("Bounds Error");

        return arr[index];
    }

    constexpr ConstReference at(size_t index) const
    {
        if (index >= Size)
           throw std::out_of_range("Bounds Error");

        return arr[index];
    }

    constexpr Reference front()
    {
        return arr[0];
    }

    constexpr ConstReference front() const
    {
        return arr[0];
    }

    constexpr Reference back()
    {
        return arr[Size-1];
    }

    constexpr ConstReference back() const
    {
        return arr[Size-1];
    }

    constexpr void swap(Array& other)
    {
        auto temp = *this;
        *this = other;
        other = temp;
    }

    [[nodiscard]] constexpr bool operator==(const Array<T, Size>& other) const
    {
        for (int i = 0; i < Size; i++)
            if (arr[i] != other[i])
                return false;

        return true;
    }

    constexpr Reference operator[](size_t index)
    {
        return arr[index];
    }

    constexpr ConstReference operator[](size_t index) const
    {
        return arr[index];
    }
};

}