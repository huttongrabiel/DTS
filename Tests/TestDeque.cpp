/*
 * Copyright 2022, Hutton Grabiel
 */

#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <Deque.h>

TEST_CASE( "Contruct Deque" ) {
REQUIRE(DTS::Deque<int>().is_empty());
REQUIRE(DTS::Deque<int>().size() == 0);
}

TEST_CASE( "Basic Tests" ) {
    DTS::Deque<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    // v = {1, 2, 3}

    REQUIRE(v[1] == 2);
    REQUIRE(v.size() == 3);

    v.insert(7, 0);
    // v = {7, 1, 2, 3}

    REQUIRE(v[0] == 7);
    REQUIRE(v.size() == 4);
    REQUIRE(v.is_empty() == false);

    REQUIRE(v.back() == 3);

    DTS::Deque<int> s;
    s.push_back(3);
    s.push_back(2);
    s.push_back(1);
    // s = {3, 2, 1}

    s.clear();
    // s = {}

    REQUIRE(s.size() == 0);
    REQUIRE(s.is_empty());

    s.push_back(23);
    s.push_back(61);
    // s = {23, 61}

    REQUIRE(s.at(1) == 61);

    REQUIRE(*s.data() == 23);

    v.erase(1);
    // v = {7, 2, 3}

    REQUIRE(v[1] == 2);
    REQUIRE(v.size() == 3);

    v.push_back(5);
    v.push_back(7);
    // v = {7, 2, 3, 5, 7}

    v.erase(0,2);
    // v = {3, 5, 7}

    REQUIRE(v[0] == 3);
    REQUIRE(v.size() == 3);
}

TEST_CASE( "Deque specific functions" ) {
    DTS::Deque<std::string> s;

    s.push_front("hi");
    s.push_back("bye");

    REQUIRE( s.front() == "hi" );
    REQUIRE( s.back() == "bye");

    s.pop_front();

    REQUIRE( s.front() == "bye" );
}