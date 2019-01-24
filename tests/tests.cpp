#include <CppUTest/TestHarness.h>

extern "C"
{
    #include "sample.h"
}

TEST_GROUP(Sample)
{
};

TEST(Sample, FirstTest)
{
    int result = test();
    CHECK_EQUAL(1, result);
}