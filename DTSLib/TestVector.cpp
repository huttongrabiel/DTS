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
    std::cout << "BACK " << v.back() << std::endl;
    std::cout << "FRONT " << v.front() << std::endl;
    v.clear();
    v.push_back(5);
    v.insert(3, 0);
    v.push_back(14);
    v.push_back(20);

    v.print();

    v.erase(0, 2);

    v.print();
}