#include <stddef.h>
#include <stdlib.h>
#include "hash_set.h"



HashSet* createHashSet(int (*cmpFunc)(void *a, void *b), size_t (*hashFunc)(void *key)) {
    HashSet* set = malloc(sizeof(HashSet));
    set->capacity = INIT_CAPACITY;
    set->size = 0;
    set->cmpFunc = cmpFunc;
    set->hashFunc = hashFunc;
    set->buckets = calloc(set->capacity, sizeof(HashSetItem *));
    return set;
}

HashSet* createHashSetWithCapacity(int (*cmpFunc)(void *a, void *b), size_t (*hashFunc)(void *key), size_t initialcapacity) {
    HashSet* set = malloc(sizeof(HashSet));
    set->capacity = initialcapacity;
    set->size = 0;
    set->cmpFunc = cmpFunc;
    set->hashFunc = hashFunc;
    set->buckets = calloc(set->capacity, sizeof(HashSetItem *));
    return set;
}



int addHashSetItem(HashSet* set, void* item) {
    size_t hashIndex = set->hashFunc(item) % set->capacity;



    set->size++;
    return 1;
}