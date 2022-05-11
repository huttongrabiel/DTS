/*
 * Copyright 2022, Hutton Grabiel
 */

#include <catch2/catch_test_macros.hpp>
#include <QuickSort.h>
#include <Vector.h>
#include <Deque.h>

TEST_CASE( "Quick Sort on Vector" ) {
    DTS::Vector<int> v;
    v.push_back(3);
    v.push_back(0);
    v.push_back(39);
    v.push_back(15);

    DTS::QuickSort::quickSort(v);

    REQUIRE( v[0] == 0 );
    REQUIRE( v[1] == 3 );
    REQUIRE( v[2] == 15 );
    REQUIRE( v[3] == 39 );
}

TEST_CASE( "Quick Sort on Deque" ) {
    DTS::Deque<int> d;
    d.push_front(8);
    d.push_front(93);
    d.push_back(3);
    d.push_back(0);
    d.push_back(39);
    d.push_back(15);

    DTS::QuickSort::quickSort(d);

    REQUIRE( d[0] == 0 );
    REQUIRE( d[1] == 3 );
    REQUIRE( d[2] == 8 );
    REQUIRE( d[3] == 15 );
    REQUIRE( d[4] == 39 );
    REQUIRE( d[5] == 93 );
}

TEST_CASE( "Quick Sort on String Vector" ) {
    DTS::Vector<std::string> v;
    v.push_back("abc");
    v.push_back("adc");
    v.push_back("zba");
    v.push_back("bdc");

    DTS::QuickSort::quickSort(v);

    REQUIRE( v[0] == "abc" );
    REQUIRE( v[1] == "adc" );
    REQUIRE( v[2] == "bdc" );
    REQUIRE( v[3] == "zba" );
}
