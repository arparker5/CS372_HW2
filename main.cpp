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
#include <iterator>
#include "catch.h"
using std::cout;
using std::endl;
using std::string;
using std::stoi;

int stringcalc(string s)
{
    if(s.empty())     //empty string returns 0
        return 0;
    int digcount = 0;
    int delimcount = 0;
    for(int i = 0; i < s.length(); ++i) { //
        if (isdigit(s[i]))
            digcount++;
        if(s[i] == ',' || s[i] == ' '){
            if(isdigit(s[i+1]) && isdigit(s[i-1])){
                ++delimcount;
            }
        }
    }
    if(digcount == s.length())
        return stoi(s);
    if ((delimcount == 1 || delimcount == 2) && digcount == s.length()-1){
        string num1, num2;
        for(const auto i : s){
            if(i != ',' && i != ' ')
                num1 += i;
            else {
                num2 = num1;
                num1 = "";
            }
        }
        return stoi(num1) + stoi(num2);
    }

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
    REQUIRE( stringcalc("2") == 2);
}

TEST_CASE( "Two numbers, comma delimited, returns the sum", "[stringcalc]" ) {
    REQUIRE( stringcalc("23,8") == 31 );
    REQUIRE( stringcalc("9,1") == 10 );
    REQUIRE( stringcalc("5,2") == 7 );
    REQUIRE( stringcalc("23,3") == 26 );
}

TEST_CASE( "Two numbers, newline delimited, returns the sum", "[stringcalc]" ) {
    REQUIRE( stringcalc("23 12") == 35 );
    REQUIRE( stringcalc("17 4") == 21 );
    REQUIRE( stringcalc("6 0") == 6 );
    REQUIRE( stringcalc("34 2") == 36 );
}