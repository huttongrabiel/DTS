/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <Vector.h>

namespace DTS {

template<typename T>
class Deque {

public:

    Deque() = default;
    ~Deque() = default;

    [[nodiscard]] size_t size() const { return deque.size(); }

    [[nodiscard]] size_t max_size() const { return deque.max_size(); }

    [[nodiscard]] bool is_empty() const { return deque.is_empty(); }

    T back() { return deque.back(); }

    T front() { return deque.front(); }

    void push_back(T& value)
    {
        deque.push_back(value);
    }

    void push_back(const T&& value)
    {
        deque.push_back(value);
    }

    T pop_back()
    {
        deque.pop_back();
    }

    void insert(T value, size_t index)
    {
        deque.insert(value, index);
    }

    void erase(size_t index)
    {
        deque.erase(index);
    }

    void erase(size_t start, size_t end)
    {
        deque.erase(start, end);
    }

    void clear()
    {
        deque.clear();
    }

    T* data()
    {
        return deque.data();
    }

    T at(size_t index)
    {
        return deque.at(index);
    }

    void replace(T elem, size_t index)
    {
       deque.replace(elem, index);
    }

    void push_front(T& value)
    {
        deque.insert(value, 0);
    }

    void push_front(const T&& value)
    {
        deque.insert(value, 0);
    }

    T pop_front()
    {
        T front = deque.front();
        deque.erase(0);
        return front;
    }

    T pop_front() const
    {
        T front = deque.front();
        deque.erase(0);
        return front;
    }

    T operator[](size_t index)
    {
        return deque[index];
    }

private:
    Vector<T> deque;
};

}