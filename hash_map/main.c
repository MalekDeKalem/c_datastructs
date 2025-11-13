#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hash_map.h"


int stringComparator(void* a, void* b) {
    return strcmp((char*) a, (char*) b) == 0;
}

size_t stringHash(void* key) {
    char* strKey = (char*) key;
    char c;
    int i = 0;
    size_t hash = FNV_OFFSET;
    while ((c = *strKey++) != '\0') {
        hash ^= c;
        hash *= FNV_PRIME;
    }
    return hash;
}


int main() {
    HashMap* map = createHashMap(stringHash, stringComparator);
    addHashMapItem(map, "Black", (void*)(intptr_t)123);
    addHashMapItem(map, "Pink", (void*)(intptr_t)252);
    addHashMapItem(map, "Green", (void*)(intptr_t)345);
    addHashMapItem(map, "Beige", (void*)(intptr_t)635);
    addHashMapItem(map, "Hotpink", (void*)(intptr_t)1252);

    int value1 = (int)(intptr_t) getHashMapItem(map, "Hotpink");
    int value2 = (int)(intptr_t) getHashMapItem(map, "Beige");
    int value3 = (int)(intptr_t) getHashMapItem(map, "Green");
    int value4 = (int)(intptr_t) getHashMapItem(map, "Pink");
    int value5 = (int)(intptr_t) getHashMapItem(map, "Black");

    printf("This is the value to the key: %d", value1);
    printf("This is the value to the key: %d", value2);
    printf("This is the value to the key: %d", value3);
    printf("This is the value to the key: %d", value4);
    printf("This is the value to the key: %d", value5);

    removeHashMapItem(map, "Beige");

    int nonexist = (int)(intptr_t) getHashMapItem(map, "Beige");
    printf("\nThis item should not exist: %d", nonexist);

    destroyHashMap(map);
    return 0;
}
