#include "element.h"

#include <stdio.h>
#include <limits.h>

void element_print(Element element) {
    printf("%d", element);
}

Element element_null(void) {
    return INT_MIN;
}