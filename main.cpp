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
#include <cstdlib>
#include <ctype.h>
#include "catch.h"
using std::string;
using std::stoi;

int stringcalc(string s)
{
    if(s.empty())
        return 0;
    int count = 0;
    for(auto i : s)
        if (isdigit(i))
            count++;
    if(count == s.length() || (count == s.length()-1 && s[0] == '-'))
        return stoi(s);
    return 0;
}

TEST_CASE( "An empty string returns zero", "[stringcalc]" ) {
REQUIRE( stringcalc("") == 0 );

}

TEST_CASE( "A single number returns the value", "[stringcalc]" ) {
    REQUIRE( stringcalc("23") == 23 );
    REQUIRE( stringcalc("9") == 9 );
    REQUIRE( stringcalc("1203") == 1203 );
    REQUIRE( stringcalc("87") == 87 );
}

