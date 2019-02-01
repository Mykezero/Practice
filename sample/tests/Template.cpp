#include <CppUTest/TestHarness.h>

extern "C"
{
    // Add includes here.
}

TEST_GROUP(Template)
{
};

TEST(Template, FirstTest)
{
    CHECK_TRUE_TEXT(true, "This test is incomplete.");
}