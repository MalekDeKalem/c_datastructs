
#include <stdlib.h>
#include "array_list.h"





ArrayList* createArrayList() {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->capacity = INIT_CAPACITY;
    list->data = calloc(list->capacity * sizeof(void*));
    list->size = 0;
    return list;
}


ArrayList* createArrayList(size_t initcapacity) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->capacity = initcapacity;
    list->data = calloc(list->capacity * sizeof(void*));
    list->size = 0;
    return list;
}

void addArrayListItem(ArrayList* list, void* item) {

    if (list->size >= list->capacity) {
        list->capacity *= 2;
        void** tmp = realloc(list->data, sizeof(void*) * list->capacity);

        if (!tmp) {
            fprintf(stderr, "ArrayList memory allocation failed!\n");
            exit(1);
        }

        list->data = tmp;
    }

    list->data[list->size-1] = item;
    list->size++;
}