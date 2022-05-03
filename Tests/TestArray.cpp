/*
 * Copyright 2022, Hutton Grabiel
 */

#include <catch2/catch_test_macros.hpp>
#include <Array.h>
#include <stdlib.h>

TEST_CASE( "Empty" ) {
    DTS::Array<long int, 0>  arr = {};

    REQUIRE( arr.empty() );
    REQUIRE( arr.size() == 0);
}

TEST_CASE( "String" ) {
    DTS::Array<std::string, 3> arr = {"hi", "hey", "hola"};

    REQUIRE( arr.empty() == false );
    REQUIRE( arr.size() == 3 );
    REQUIRE( arr.back() == "hola" );
    REQUIRE( arr.front() == "hi" );
    REQUIRE( arr.at(1) == "hey" );
}

TEST_CASE( "Int" ) {
    DTS::Array<int, 4> arr = {5, 2, 14, 4};

    REQUIRE( arr.empty() == false );
    REQUIRE( arr.size() == 4 );
    REQUIRE( arr.back() == 4 );
    REQUIRE( arr.front() == 5 );
    REQUIRE( arr.at(2) == 14 );
}

TEST_CASE( "Fill" ) {
    DTS::Array<std::string, 8> arr;
    arr.fill("j");

    REQUIRE( arr.size() == 8);
    REQUIRE( arr.at(1) == "j");
    REQUIRE( arr.at(3) == "j");
    REQUIRE( arr.back() == "j");
    REQUIRE( arr.front() == "j");
}

TEST_CASE( "Swap" ) {
    DTS::Array<int, 3> first = {1, 2, 3};
    DTS::Array<int, 3> second = {4, 5, 6};

    first.swap(second);

    REQUIRE( first.front() == 4);
    REQUIRE( second.front() == 1);

}