#include <CppUTest/TestHarness.h>

extern "C"
{
    #include "Shape.h"
}

TEST_GROUP(Shape)
{
};

TEST(Shape, CreatesLine)
{
	ShapeStruct_t shape;
	Init_Shape(&shape);
    CHECK_EQUAL(25, shape.Origin);
}