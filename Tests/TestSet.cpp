/*
 * Copyright 2022, Hutton Grabiel
 */

#include <catch2/catch_test_macros.hpp>
#include <Set.h>

TEST_CASE( "Construct Set" ) {
    REQUIRE(DTS::Set<int>().is_empty());
    REQUIRE(DTS::Set<int>().size() == 0);
    REQUIRE(DTS::Set<std::string>().is_empty());
    REQUIRE(DTS::Set<std::string>().size() == 0);
}

TEST_CASE( "Basic Function Tests" ) {
    DTS::Set<int> set;

    set.insert(3);
    set.insert(5);
    // set = {3, 5}

    REQUIRE( set.count(3) );
    REQUIRE( set.count(5) );

    REQUIRE( set.contains(3) );
    REQUIRE( set.contains(5) );
    REQUIRE( !set.contains(1) );

    REQUIRE( set.find(3) !=  set.end() );
    REQUIRE( set.find(4) == set.end() );

    set.insert(7);
    set.insert(0);
    // set = {0, 3, 5, 7}

    REQUIRE( set.size() == 4 );

    set.clear();
    // set = {}

    REQUIRE( set.size() == 0 );

    set.insert(3);
    set.insert(5);
    // set = {3, 5}

    // 5 is the value NOT the index
    set.erase(5);
    // set = {3}

    REQUIRE( set.size() == 1);

    // should not insert a 3 because there is already one in the set
    set.insert(3);

    REQUIRE( set.size() == 1);

    auto const data = set.data();

    REQUIRE( *data == 3 );

    set.insert(8);
    set.insert(9);

    set.erase(3);

    REQUIRE( set.find(3) == set.end() );
}

TEST_CASE( "Set Strings" ) {
    DTS::Set<std::string> set;

    set.insert("zoo");
    set.insert("ant");

    REQUIRE( set.find("ant") < set.find("zoo") );

    set.insert("zoo");

    REQUIRE( set.size() == 2);

    REQUIRE( *set.data() == "ant" );
}