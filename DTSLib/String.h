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

    [[nodiscard]] size_t capacity() const { return m_string.max_size(); }

    char front() noexcept
    {
        return m_string.front();
    }

    void clear()
    {
        m_string.clear();
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

    void insert(size_t position, String&& value)
    {
        for (auto item : value) {
            m_string.insert(item, position);
            position++;
        }
    }

    void replace(size_t index, String&& value)
    {
        size_t temp_index = 0;
        size_t result_length = value.size()+index;
        for (size_t i = index; i < result_length; i++) {
            char val;
            i >= index ? val = value[temp_index] : val = m_string[temp_index];

            temp_index++;

            if (i < size())
                m_string.replace(val, i);
            else
                m_string.push_back(val);
        }
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

    DTS::String substr(size_t const& start_index, size_t&& strlen)
    {
        if (start_index > this->size())
            throw std::out_of_range("Start index of substring cannot be greater than size of string!");

        if (strlen + start_index > this->size())
            strlen = this->size() - start_index;

        DTS::String str = "";
        for (size_t i = start_index; i < strlen+start_index; i++) {
            str.push_back(this->m_string[i]);
        }
        return str;
    }

    using Iterator = DTS::Iterator<DTS::String, char>;

    Iterator begin() { return Iterator::begin(*this); }
    Iterator end() { return Iterator::end(*this); }

    Iterator max_element(Iterator begin, Iterator const& end)
    {
        Iterator max_element = begin;
        while (begin != end) {
            if (*begin > *max_element)
                max_element = begin;
            begin++;
        }

        return max_element;
    }

    void to_upper()
    {
        for (size_t i = 0; i < length(); i++) {
            if (is_lower(m_string[i]))
                m_string[i] = m_string[i] - 32;
        }
    }

    void to_lower()
    {
        for (size_t i = 0; i < length(); i++) {
            if (is_upper(m_string[i]))
                m_string[i] = m_string[i] + 32;
        }
    }

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

    String operator+(String& other)
    {
        for (auto val : other) {
            m_string.push_back(val);
        }

        return *this;
    }

    String operator+(String&& other)
    {
        for (auto val : other) {
            m_string.push_back(val);
        }

        return *this;
    }

    char& operator[](size_t const& index)
    {
        return m_string[index];
    }

private:
    DTS::Vector<char> m_string;

    static bool is_lower(char&& letter)
    {
        if (letter < 123 && letter > 96)
            return true;

        return false;
    }

    [[nodiscard]] static bool is_lower(char const& letter)
    {
        if (letter < 123 && letter > 96)
            return true;

        return false;
    }

    static bool is_upper(char&& letter)
    {
        if (letter < 91 && letter > 64)
            return true;

        return false;
    }

    [[nodiscard]] static bool is_upper(char const& letter)
    {
        if (letter < 91 && letter > 64)
            return true;

        return false;
    }
};

}
