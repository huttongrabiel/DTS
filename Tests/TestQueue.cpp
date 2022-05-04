/*
 * Copyright 2022, Hutton Grabiel
 */

#include <catch2/catch_test_macros.hpp>
#include <Queue.h>

TEST_CASE( "Test Queue" ) {
    DTS::Queue<int> s;

    s.push(3);
    s.push(7);

    REQUIRE( s.front() == 3 );
    REQUIRE( s.back() == 7 );

    REQUIRE( s.pop() == 3);

    REQUIRE( s.size() == 1);

    s.pop();

    REQUIRE( s.size() == 0);
    REQUIRE( s.is_empty() );

    s.push(8);
    s.push(9);

    REQUIRE( s.front() == 8 );
    REQUIRE( s.back() == 9 );
}