/*
 * Copyright 2022, Whuty
 */

#include <catch2/catch_test_macros.hpp>
#include <Vector.h>

TEST_CASE( "Contruction" ) {
    REQUIRE(DTS::Vector<int>().is_empty());
    REQUIRE(DTS::Vector<int>().size() == 0);
}

TEST_CASE( "Ints" ) {
    DTS::Vector<int> v;
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
    REQUIRE(v.is_empty() == 0);

    REQUIRE(v.back() == 3);

    DTS::Vector<int> s;
    s.push_back(3);
    s.push_back(2);
    s.push_back(1);
    // s = {3, 2, 1}

    s.swap(v);
    // s = {7, 1, 2, 3}
    // v = {3, 2, 1}

    REQUIRE(v[0] == 3);
    REQUIRE(v.size() == 3);
    REQUIRE(s[0] == 7);
    REQUIRE(s.size() == 4);

    s.replace(23, 0);
    // s = {23, 1, 2, 3}

    REQUIRE(s[0] == 23);

    REQUIRE(v.front() == 3);

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
    // v = {3, 1}

    REQUIRE(v[1] == 1);
    REQUIRE(v.size() == 2);

    v.push_back(5);
    v.push_back(7);
    // v = {3, 1, 5, 7}

    v.erase(0,2);
    // v = {5,7}

    REQUIRE(v[0] == 5);
    REQUIRE(v.size() == 2);
}

TEST_CASE( "Strings" ) {
    DTS::Vector<std::string> v;
    v.push_back("Hi");
    v.push_back("Happy");
    v.push_back("Friends");
    // v = {"Hi", "Happy", "Friends"}

    REQUIRE(v[1] == "Happy");
    REQUIRE(v.size() == 3);

    v.insert("OH,", 0);
    // v = {"OH,","Hi", "Happy", "Friends"}

    REQUIRE(v[0] == "OH,");
    REQUIRE(v.size() == 4);
    REQUIRE(v.is_empty() == false);

    REQUIRE(v.back() == "Friends");

    DTS::Vector<std::string> s;
    s.push_back("Friends");
    s.push_back("Happy");
    s.push_back("Hi");
    // s = {"Friends", "Happy", "Hi"}

    s.swap(v);
    // s = {"OH,", "Hi", "Happy", "Friends"}
    // v = {"Friends", "Happy", "Hi"}

    REQUIRE(v[0] == "Friends");
    REQUIRE(v.size() == 3);
    REQUIRE(s[0] == "OH,");
    REQUIRE(s.size() == 4);

    s.replace("Well", 0);
    // s = {"Well", "Hi", "Happy", "Friends"}

    REQUIRE(s[0] == "Well");

    REQUIRE(v.front() == "Friends");

    s.clear();
    // s = {}

    REQUIRE(s.size() == 0);
    REQUIRE(s.is_empty());

    s.push_back("Big");
    s.push_back("Swag");
    // s = {"Big", "Swag"}

    REQUIRE(s.at(1) == "Swag");

    REQUIRE(*s.data() == "Big");

    v.erase(1);
    // v = {"Friends", "Hi"}

    REQUIRE(v[1] == "Hi");
    REQUIRE(v.size() == 2);

    v.push_back("How");
    v.push_back("You?");
    // v = {"Friends", "Hi", "How", "You?"}

    v.erase(0,2);
    // v = {"How", "You?"}

    REQUIRE(v[0] == "How");
    REQUIRE(v.size() == 2);
}

