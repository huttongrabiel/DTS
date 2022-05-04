/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <Vector.h>

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
        // FIXME: Change to return queue.pop_front once we implement deque
        T popped_value = queue.front();
        queue.erase(0);
        return popped_value;
    }

    T pop() const
    {
        // FIXME: Change to return queue.pop_front once we implement deque
        T popped_value = queue.front();
        queue.erase(0);
        return popped_value;
    }

private:
    // FIXME: Change to deque once we implement it
    Vector<T> queue;
};

}
