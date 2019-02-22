/*
 * Andrew Parker
 * CS 372
 * TDD Kata
 * Dr. Hartman
 * 2/25/19
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <string>
#include "catch.h"
using std::string;

int stringcalc(string s)
{
    if(s.empty())
        return 0;
}

TEST_CASE( "An empty string returns zero", "[stringcalc]" ) {
REQUIRE( stringcalc("") == 0 );

}

