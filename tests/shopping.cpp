#include <CppUTest/TestHarness.h>
#include "shopping.h"

TEST_GROUP(Shopping) {};

TEST(Shopping, CanBrowse)
{
    Product products[10];
    browse(products, 10);
    STRCMP_EQUAL_TEXT("Sku", products[0].sku, "Can browse returned wrong sku.");
}