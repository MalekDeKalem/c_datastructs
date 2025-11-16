#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_set.h"

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

    HashSet* set = createHashSet(stringComparator, stringHash);

    return 0;
}