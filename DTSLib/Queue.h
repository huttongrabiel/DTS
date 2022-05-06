/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <Deque.h>

namespace DTS {

template<typename T>
class Queue {

public:
    Queue() = default;
    ~Queue() = default;

    [[nodiscard]] size_t size() const { return queue.size(); }

    [[nodiscard]] bool is_empty() const { return queue.is_empty(); }

    T front() { return queue.front(); }

    T front() const { return queue.front(); }

    T back() { return queue.back(); }

    T back() const { return queue.back(); }

    void push(T value) { queue.push_back(value); }

    void push(T value) const { queue.push_back(value); }

    T pop()
    {
        return queue.pop_front();
    }

    T pop() const
    {
        return queue.pop_front();
    }

private:
    Deque<T> queue;
};

}
