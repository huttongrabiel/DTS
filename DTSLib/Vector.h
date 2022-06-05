/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <iostream>
#include <concepts>

/*
 *  - constructor         X
 *  - destructor          X
 *
 *  - push_back()         X
 *  - insert()            X
 *  - size()              X
 *  - front()             X
 *  - back()              X
 *  - pop_back()          X
 *  - clear()             X
 *  - erase(int)          X
 *  - erase(start, end)   X
 *  - swap()              X
 *
 *  - at()                X
 *  - data()              X
 *
 *  - operator=           X
 *  - operator[]          X
 *  - operator==          X
 */

namespace DTS {

template<typename T>
concept Valid_Sequence_Item =
    requires(T a, T b) {
        { a==b } -> std::convertible_to<bool>;
        { a!=b } -> std::convertible_to<bool>;
        { a>b }  -> std::convertible_to<bool>;
        { a<b }  -> std::convertible_to<bool>;
        { a>=b } -> std::convertible_to<bool>;
        { a<=b } -> std::convertible_to<bool>;
    };

template<Valid_Sequence_Item T>
class Vector {
    T* arr;
    size_t capacity;
public:
    Vector()
    {
        arr = new T[1];
        capacity = 1;
        m_size = 0;
    }

    Vector(const Vector& other) {
        arr = new T[other.m_size];
        capacity = other.capacity;
        m_size = other.m_size;

        for (size_t i = 0; i < other.size(); i++)
            arr[i] = other.arr[i];
    }

    Vector(std::initializer_list<T> const& init_list) {
        arr = new T[init_list.size()];
        for (size_t i = 0; i < init_list.size(); i++) {
            arr[i] = *(init_list.begin() + i);;
        }
        m_size = init_list.size();
        capacity = init_list.size();
    }

    ~Vector()
    {
        delete[] arr;
    }

    [[maybe_unused]] void push_back(T elem)
    {
        if (m_size == capacity) {
            T* temp = new T[2 * capacity];

            for (size_t i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[m_size] = elem;
        m_size++;
    }

    [[maybe_unused]] void replace(T elem, size_t index)
    {
        if (index == capacity)
            push_back(elem);
        else if (index < m_size)
            arr[index] = elem;
    }

    [[maybe_unused]] void insert(T const& elem, size_t index)
    {
        if (index == capacity) {
            push_back(elem);
        }
        else {
            if (m_size == capacity) {
                T* temp = new T[2 * capacity];

                for (size_t i = 0; i < capacity; i++)
                    temp[i] = arr[i];

                delete[] arr;
                capacity*=2;
                arr = temp;
            }

            int pos_encountered = 0;
            T stored_t = arr[index];
            T stored_t2 = arr[index];
            for (size_t i = 0; i < capacity; i++) {
                if (i == index || pos_encountered) {
                    if (!pos_encountered) {
                        arr[i] = elem;
                    }
                    else {
                        stored_t2 = arr[i];
                        arr[i] = stored_t;
                        stored_t = stored_t2;
                    }
                    pos_encountered = 1;
                }
                else {
                    arr[i] = arr[i];
                }
            }

            m_size++;
        }
    };

    [[maybe_unused]] void erase(size_t index)
    {
        int current_position = 0;
        for (size_t i = 0; i < m_size; i++) {
            if (i == index)
                continue;
            arr[current_position] = arr[i];
            current_position++;
        }

        m_size--;
    };

    [[maybe_unused]] void erase(size_t start, size_t end)
    {
        size_t index = 0;
        int erase_count = 0;

        for (size_t i = 0; i < m_size; i++) {
            if (i >= start && i < end) {
                erase_count++;
                continue;
            }
            arr[index] = arr[i];
            index++;
        }

        m_size -= erase_count;
    };

    [[maybe_unused]] T pop_back()
    {
        T* temp = new T[m_size-1];

        auto popped_element = arr[m_size-1];

        for (size_t i = 0; i < m_size-1; i++)
            temp[i] = arr[i];

        delete[] arr;
        arr = temp;
        m_size--;

        return popped_element;
    };

    [[maybe_unused]] void print()
    {
        for (size_t i = 0; i < m_size; i++)
            std::cout << arr[i] << " ";

        std::cout << std::endl;
    }

    [[maybe_unused]] T at(size_t index)
    {
        if (index >= m_size) {
            throw std::out_of_range("Bounds Error in at()");
        }

       return arr[index];
    }

    T& operator[](size_t const& index)
    {
        return arr[index];
    };

    [[maybe_unused]] void swap(Vector& other)
    {
        auto temp = m_size;
        m_size = other.m_size;
        other.m_size = temp;

        auto temp1 = capacity;
        capacity = other.capacity;
        other.capacity = temp;

        T* temp2 = arr;
        arr = other.arr;
        other.arr = temp2;
    }

    [[maybe_unused]] T* data()
    {
        return arr;
    }

    Vector& operator=(const Vector& other)
    {
        if (*this == other)
            return *this;

        if (this->size() != other.size()) {
            T* temp = new T[other.size()];

            for (size_t i = 0; i <= other.size(); i++) {
                temp[i] = other.arr[i];
            }

            delete[] arr;
            arr = temp;
        }
        else {
            for (size_t i = 0; i < other.size(); i++) {
                arr[i] = other.arr[i];
            }
        }

        capacity = other.size();
        m_size = other.size();

        return *this;
    }

    bool operator==(const Vector& other) const
    {
        if (other.m_size != m_size)
           return false;

        for (size_t i = 0; i < m_size; i++)
            if (arr[i] != other.arr[i])
                return false;

        return true;
    }

    [[nodiscard]] size_t max_size() const { return capacity; }

    [[maybe_unused]] void clear() { delete[] arr; arr = new T[1]; m_size = 0; capacity = 1; }

    [[maybe_unused]] T back() { return arr[m_size-1]; }

    [[maybe_unused]] T front() { return arr[0]; }

    [[maybe_unused]][[nodiscard]] size_t size() const { return m_size; }

    [[maybe_unused]][[nodiscard]] bool is_empty() const { return m_size == 0; }

private:
    size_t m_size;

};

}
