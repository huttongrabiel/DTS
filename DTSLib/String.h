/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once
#include <Iterator.h>

namespace DTS {

class String {
public:
    String()
    {
        m_arr = new char[1];
        m_size = 0;
    }

    String(const char* arr)
    {
        m_arr = arr;
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

    String& operator=(const char* arr)
    {
        if (m_arr == arr)
           return *this;

        m_arr = arr;
        return *this;
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
