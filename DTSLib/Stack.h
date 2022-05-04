/*
 * Copyright 2022, Hutton Grabiel
 */

#pragma once

#include <Vector.h>

namespace DTS {

template<typename T>
class Stack {

public:
    Stack() = default;
    ~Stack() = default;

    [[nodiscard]] bool empty() const { return stack.is_empty(); }

    [[nodiscard]] size_t size() const { return stack.size(); }

    void push(T value)
    {
        stack.push_back(value);
    }

    void push(const T& value) const
    {
        stack.push_back(value);
    }

    T top()
    {
        return stack.back();
    }

    T top() const
    {
        return stack.back();
    }

    T pop()
    {
        return stack.pop_back();
    }

    T pop() const
    {
        return stack.pop_back();
    }

private:
    Vector<T> stack;
};

}
