#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"


ArrayList* createArrayList(int (*cmpFunc)(void *, void *)) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->capacity = INIT_CAPACITY;
    list->data = calloc(list->capacity, sizeof(void*));
    list->size = 0;
    list->cmpFunc = cmpFunc;
    return list;
}


ArrayList* createArrayListWithCapacity(size_t initcapacity, int (*cmpFunc)(void *, void *)) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->capacity = initcapacity;
    list->data = calloc(list->capacity, sizeof(void*));
    list->size = 0;
    list->cmpFunc = cmpFunc;
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

    list->data[list->size] = item;
    list->size++;
}

void removeAtIndexArrayListItem(ArrayList* list, size_t index) {

    if (!list || list->size == 0) return;

    if (list->size <= index) {
        fprintf(stderr, "Index out of bounds for the ArrayList\n");
        exit(1);
    }

    void* toDelete = list->data[index];

    for (int i = index; i < list->size-1; i++) {
        list->data[i] = list->data[i+1];
    }

    list->size--;
    list->data[list->size] = NULL;

    free(toDelete);
}


void removeArrayListItem(ArrayList* list, void* item) {

    if (!list || list->size == 0) return;

    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->cmpFunc(item, list->data[i])) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        void* toDelete = list->data[index];
        
        for (int i = index; i < list->size-1; i++) {
            list->data[i] = list->data[i+1];
        }

        list->size--;
        list->data[list->size] = NULL;
        free(toDelete);
    }
}

int containsArrayListItem(ArrayList* list, void* item) {

    if (!list || list->size == 0) return 0;

    for (int i = 0; i < list->size; i++) {
        if (list->cmpFunc(item, list->data[i])) return 1;
    }

    return 0;
}

void* getArrayListItem(ArrayList* list, size_t index) {

    if (!list || list->size == 0) return NULL;

    if (index >= list->size) {
        fprintf(stderr, "Index out of bounds cant access\n");
        exit(1);
    }

    return list->data[index];
}

