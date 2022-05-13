/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once
#include <Iterator.h>
#include <Vector.h>

namespace DTS {

class String {
public:
    String() = default;

    String(const char* other)
    {
        while (*other != 0) {
            m_string.push_back(*other);
            other++;
        }
    }

    [[nodiscard]] size_t length() const { return size(); }

    [[nodiscard]] size_t size() const { return m_string.size(); }

    char front() noexcept
    {
        return m_string.front();
    }

    const char* data()
    {
        return m_string.data();
    }

    void swap(String& other)
    {
        String temp = other;
        other = *this;
        *this = temp;
    }

    void swap(String&& other)
    {
        String temp = other;
        other = *this;
        *this = temp;
    }

    void push_back(char value)
    {
        m_string.push_back(value);
    }

    char at(const size_t index)
    {
        if (index > length()) {
            throw std::out_of_range("Index out of Range");
        }

        return m_string[index];
    }

    using Iterator = DTS::Iterator<DTS::String, char>;

    Iterator begin() { return Iterator::begin(*this); }
    Iterator end() { return Iterator::end(*this); }

    String& operator=(String const& arr)
    {
        if (m_string == arr.m_string)
           return *this;

        m_string = arr.m_string;
        return *this;
    }

    bool operator==(const String& other) const
    {
        if (this->m_string == other.m_string)
            return true;

        return false;
    }

    char operator[](size_t const& index)
    {
        return m_string[index];
    }

private:
    DTS::Vector<char> m_string;
};

}
