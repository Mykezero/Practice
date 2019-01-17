#include <CppUTest/TestHarness.h>

extern "C"
{
   // Include your test files here.
   //#include "sample.h"
}

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
   FAIL("Fail me!");
}