#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array_list.h"



int comparator(void* a, void* b) {
    return (int)(intptr_t)a == (int)(intptr_t)b;
}


int main() {

    ArrayList* list = createArrayListWithCapacity(10, comparator);

    return 0;
}