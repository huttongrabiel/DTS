/*
 * Copyright 2022, Hutton Grabiel
 */

#include <catch2/catch_test_macros.hpp>
#include <Stack.h>

TEST_CASE( "POP" ) {
    DTS::Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    REQUIRE( s.pop() == 3 );
    REQUIRE( s.pop() == 2 );
    REQUIRE( s.pop() == 1 );

    REQUIRE( s.empty() );
}

TEST_CASE( "PUSH" ) {
    DTS::Stack<std::string> s;

    s.push("hello");
    s.push("world");

    REQUIRE( s.top() == "world" );
    s.pop();
    REQUIRE( s.top() == "hello" );
    s.pop();
}

TEST_CASE( "TOP" ) {
    DTS::Stack<size_t> s;

    s.push(3);
    s.push(7);

    REQUIRE( s.top() == 7 );
    s.pop();
    REQUIRE( s.top() == 3 );
}

TEST_CASE( "SIZE" ) {
    DTS::Stack<char> s;

    s.push('a');
    s.push('b');
    s.push('c');

    REQUIRE( s.size() == 3 );
}