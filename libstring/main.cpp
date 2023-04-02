#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include "string.h"

TEST_CASE("libstring TEST")
{
    SUBCASE("Constructors")
    {
        string str1 = "example str";
        string str2("example str");
        string str3 = string("example str");
        CHECK(str1 == "example str");
        CHECK(str2 == "example str");
        CHECK(str3 == "example str");
    }
    SUBCASE("CASE2")
    {
        string str = "strstr";
        REQUIRE(str.size() == 6);
        SUBCASE("sub")
        {
            CHECK(str == "strstr");
        }
    }
}