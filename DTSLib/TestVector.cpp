/*
 * Copyright 2022, Whuty
 */

#include "Vector.h"
#include <iostream>

int main() {
    DTS::Vector<int> v;

    v.push_back(45);
    v.push_back(16);
    v.insert(8, 1);
    v.insert(4, 0);
    v.insert(18, 3);

    std::cout << "BACK " << v.back() << std::endl;
    std::cout << "SIZE " << v.size() << std::endl;
    std::cout << "POP BACK " << v.pop_back() << std::endl;

    v.print();
}