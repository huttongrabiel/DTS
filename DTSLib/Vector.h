/*
 * Copyright 2022, Whuty
 */

#pragma once

#include <iostream>

/*
 * Vectors have
 *  - constructor
 *  - destructor
 *  - operator=
 *  -
 *
 *  - push_back()
 *  - insert()
 *  - size()
 *  - front()
 *  - back()
 *  - pop_back()
 *  - empty()
 *  - clear()
 *  - insert()
 *  - erase()
 *  - swap()
 *
 *  - at()
 *  - operator[]
 *  - front()
 *  - back()
 *  - data()
 *
 *  - operator==
 */

namespace DTS {

template<typename T>
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

    ~Vector()
    {
        delete[] arr;
    }

    [[maybe_unused]] void push_back(T elem)
    {
        if (m_size == capacity) {
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[m_size] = elem;
        m_size++;
    }


    [[maybe_unused]] void replace(T elem, int pos)
    {
        if (pos == capacity)
            push_back(elem);
        else if (pos < m_size)
            arr[pos] = elem;
    }

    [[maybe_unused]] void insert(T elem, int pos)
    {
        if (pos == capacity) {
            push_back(elem);
        }
        else {
            if (m_size ==  capacity) {
                T* temp = new T[2 * capacity];

                for (int i = 0; i < arr[i]; i++)
                    temp[i] = arr[i];

                delete[] arr;
                capacity*=2;
                arr = temp;
            }

            int pos_encountered = 0;
            T stored_t = arr[pos];
            T stored_t2 = arr[pos];
            for (int i = 0; i < capacity; i++) {
                if (i == pos || pos_encountered) {
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

    [[maybe_unused]] T pop_back()
    {
        T* temp = new T[m_size-1];

        auto popped_element = arr[m_size-1];

        for (int i = 0; i < m_size-1; i++)
            temp[i] = arr[i];

        delete[] arr;
        arr = temp;
        m_size--;

        return popped_element;
    };

    [[maybe_unused]] void print()
    {
        for (int i = 0; i < m_size; i++)
            std::cout << arr[i] << " ";

        std::cout << std::endl;
    }

    T operator[](int pos)
    {
        if (pos >= m_size)
            return {};

        for (int i = 0; i < m_size; i++) {
            if (i == pos)
                return arr[i];
        }
    };

    [[maybe_unused]] T back() { return arr[m_size-1]; }

    [[maybe_unused]] T front() { return arr[0]; }

    [[maybe_unused]][[nodiscard]] size_t size() const { return m_size; }

    [[maybe_unused]][[nodiscard]] bool is_empty() const { return m_size == 0; }

private:
    size_t m_size;

};

}