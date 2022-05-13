/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once
#include <Iterator.h>

namespace DTS {

class String {
public:
    String() = default;

    String(const char* other)
    {
        m_arr = other;
        m_size = 0;
        for (auto it = m_arr; *it != 0; it++) {
            m_size++;
        }
    }

    [[nodiscard]] size_t length() const { return m_size; }

    [[nodiscard]] size_t size() const { return length(); }

    char front() noexcept
    {
        return m_arr[0];
    }

    const char* data()
    {
        return m_arr;
    }

    void swap(String& other)
    {
        String temp = other;
        other = *this;
        *this = temp;
    }

    char at(const size_t index)
    {
        if (index > length()) {
            throw std::out_of_range("Index out of Range");
        }

        return m_arr[index];
    }

    using Iterator = DTS::Iterator<String, char>;

    Iterator end() { return Iterator::end(*this); }
    Iterator begin() { return Iterator::begin(*this); }

    String& operator=(String const& arr)
    {
        if (this == &arr)
           return *this;

        m_arr = arr.m_arr;
        m_size = arr.m_size;
        return *this;
    }

    bool operator==(const String& other) const
    {
        if (this->m_arr == other.m_arr)
            return true;

        return false;
    }

    bool operator==(String&& other) const
    {
        if (this->m_arr == other.m_arr)
            return true;

        return false;
    }

    char operator[](size_t const& index) const
    {
        return m_arr[index];
    }

private:
    const char* m_arr;
    size_t m_size;
};

}
