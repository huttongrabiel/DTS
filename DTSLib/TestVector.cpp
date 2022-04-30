/*
 * Copyright 2022, Whuty
 */

#include "Vector.h"
#include <iostream>

int main() {
    DTS::Vector<int> v;

    if (v.is_empty())
        std::cout << "EMPTY" << std::endl;

    v.push_back(45);
    v.push_back(16);

    std::cout << v[0] << std::endl;
    std::cout << "BACK " << v.back() << std::endl;
    std::cout << "SIZE " << v.size() << std::endl;

    v.print();
}