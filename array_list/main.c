#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array_list.h"



int comparator(void* a, void* b) {
    return (int)(intptr_t)a == (int)(intptr_t)b;
}


int main() {

    ArrayList* list = createArrayListWithCapacity(10, comparator, NULL);

    addArrayListItem(list, (int*) 10);
    addArrayListItem(list, (int*)17);
    addArrayListItem(list, (int*)13);
    addArrayListItem(list, (int*)12);
    addArrayListItem(list, (int*)19);


    printf("List has that size: %ld\n", list->size);
    int sum = 0;
    for (int i = 0; i < list->size; i++) {
        sum+=(int)(intptr_t)getArrayListItem(list, i);
    }

    printf("Sum of all the items in the list: %d\n", sum);

    sum = 0;
    removeAtIndexArrayListItem(list, 0);
    for (int i = 0; i < list->size; i++) {
        sum+=(int)(intptr_t)getArrayListItem(list, i);
    }

    printf("This is the sum after removing first element: %d\n", sum);
    printf("List has that size: %ld\n", list->size);



    return 0;
}