/*
 * Copyright 2022, Whuty
 */

#pragma once

#include <stdlib.h>
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

    void insert(T elem, int pos)
    {
        if (pos == capacity) {
            push_back(elem);
        }
        else {
           T *temp = new T[2 * capacity];

            for (int i = 0; i < capacity + 1; i++) {
                if (i == pos) {
                    temp[i] == elem;
                    continue;
                }
                temp[i] == arr[i];
            }


            delete[] arr;
            capacity *= 2;
            arr = temp;
            m_size++;
        }
    };

    [[maybe_unused]] void pop_back()
    {
        T* temp = new T[m_size-1];

        for (int i = 0; i < m_size-1; i++)
            temp[i] == arr[i];

        delete[] arr;
        arr = temp;
        m_size--;
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

    T back() { return arr[m_size-1]; }

    size_t size() const { return m_size; }

    bool is_empty() const { return m_size == 0; }

private:
    size_t m_size;

};

}