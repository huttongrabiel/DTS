/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <iostream>

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

        for (int i = 0; i < other.size(); i++)
            arr[i] = other.arr[i];
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

    [[maybe_unused]] void replace(T elem, int index)
    {
        if (index == capacity)
            push_back(elem);
        else if (index < m_size)
            arr[index] = elem;
    }

    [[maybe_unused]] void insert(T elem, int index)
    {
        if (index == capacity) {
            push_back(elem);
        }
        else {
            if (m_size ==  capacity) {
                T* temp = new T[2 * capacity];

                for (int i = 0; i < capacity; i++)
                    temp[i] = arr[i];

                delete[] arr;
                capacity*=2;
                arr = temp;
            }

            int pos_encountered = 0;
            T stored_t = arr[index];
            T stored_t2 = arr[index];
            for (int i = 0; i < capacity; i++) {
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

    [[maybe_unused]] void erase(int index)
    {
        int current_position = 0;
        for (int i = 0; i < m_size; i++) {
            if (i == index)
                continue;
            arr[current_position] = arr[i];
            current_position++;
        }

        m_size--;
    };

    [[maybe_unused]] void erase(int start, int end)
    {
        int index = 0;
        int erase_count = 0;

        for (int i = 0; i < m_size; i++) {
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

    [[maybe_unused]] T at(int index)
    {
        if (index >= m_size) {
            throw std::out_of_range("Bounds Error in at()");
        }

       return arr[index];
    }

    T operator[](int index)
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
        if (this->size() != other.size()) {
            T* temp = new T[other.size()];

            for (int i = 0; i <= other.size(); i++) {
                temp[i] = other.arr[i];
            }

            delete[] arr;
            arr = temp;
        }
        else {
            for (int i = 0; i < other.size(); i++) {
                arr[i] = other.arr[i];
            }
        }

        capacity = other.size();
        m_size = other.size();

        return *this;
    }

    bool operator==(const Vector& other)
    {
        if (other.m_size != m_size)
           return false;

        for (int i = 0; i < m_size; i++)
            if (arr[i] != other.arr[i])
                return false;

        return true;
    }

    [[maybe_unused]] void clear() { delete[] arr; arr = new T[1]; m_size = 0; capacity = 1; }

    [[maybe_unused]] T back() { return arr[m_size-1]; }

    [[maybe_unused]] T front() { return arr[0]; }

    [[maybe_unused]][[nodiscard]] size_t size() const { return m_size; }

    [[maybe_unused]][[nodiscard]] bool is_empty() const { return m_size == 0; }

private:
    size_t m_size;

};

}