/*
 * Copyright 2022, Hutton Grabiel
 * Copyright (c) 2018-2022, the SerenityOS developers. (For a mighty helpful existing reference)
 */

#pragma once

namespace DTS {

template <typename Container, typename T>
class Iterator {
public:
    friend Container;

    constexpr bool operator==(Iterator other) const { return m_index == other.m_index; }
    constexpr bool operator!=(Iterator other) const { return m_index != other.m_index; }
    constexpr bool operator<(Iterator other) const { return m_index < other.m_index; }
    constexpr bool operator<=(Iterator other) const { return m_index <= other.m_index; }
    constexpr bool operator>(Iterator other) const { return m_index > other.m_index; }
    constexpr bool operator>=(Iterator other) const { return m_index >= other.m_index; }

    // Prefix
    constexpr Iterator operator++()
    {
        m_index++;
        return *this;
    }

    // Postfix
    constexpr Iterator operator++(int)
    {
        m_index++;
        return *this;
    }

    // Prefix
    constexpr Iterator operator--()
    {
        m_index--;
        return *this;
    }

    // Postfix
    constexpr Iterator operator--(int)
    {
        m_index--;
        return *this;
    }

    constexpr Iterator operator+=(int delta)
    {
        m_index += delta;
        return *this;
    }

    constexpr Iterator operator-=(int delta)
    {
        m_index -= delta;
        return *this;
    }

    constexpr Iterator& operator=(Container& other)
    {
        m_index = other.m_index;
        return *this;
    }

    constexpr T operator*() { return m_container[m_index]; }
    constexpr T const& operator*() const { return m_container[m_index]; }
    constexpr T* operator->() { return *m_container[m_index]; }
    constexpr T const* operator->() const { return *m_container[m_index]; }

private:
    static constexpr Iterator begin(Container& container) { return { container, 0 }; }

    static constexpr Iterator end(Container& container) { return { container, container.size() }; }

    // Allows { container, index } initialization of iterator
    constexpr Iterator(Container& container, size_t index)
        : m_container(container)
        , m_index(index)
    {
    }

    Container& m_container;
    size_t m_index;
};

}
