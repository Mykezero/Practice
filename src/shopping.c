#include "shopping.h"
#include <stdlib.h>
#include <string.h>


void browse(struct Product products[], int length)
{
    struct Product product;
    strcpy(product.sku, "Sku");
    products[0] = product;
}