#include <CppUTest/TestHarness.h>

extern "C"
{
    #include "Window.h"
}

TEST_GROUP(Window)
{
};

TEST(Window, WritesText)
{
	WindowStruct_t window;
	Init_Window(&window);
    CHECK_EQUAL(80, window.Width);
}