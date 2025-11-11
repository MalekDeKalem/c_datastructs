
#include"hash_map.h"





HashMap* createHashMap(size_t (*hashFunc)(void *), int (*cmpFunc)(void *, void *)) {
    HashMap *map = malloc(sizeof(HashMap));
    map->capacity = INIT_CAPACITY;
    map->length = 0;
    map->buckets = calloc(map->capacity, sizeof(HashMapEntry *));
    map->hashFunc = hash_func;
    map->cmpFunc = cmp_func;
    return map;
}

void destroyHashMap(HashMap* map) {
    for (size_t i = 0; i < map->length; i++) {
        HashMapEntry* entry = map->buckets[i];
        while (entry != NULL) {
            HashMapEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

void addHashMapItem(HashMap* map, void* key, void* value) {
    int hashIndex = map->hashFunc(key);
    HashMapEntry* entry = map->buckets[hashIndex];
    if (entry == NULL) {
        // Allocate Memory for new Entry
        HashMapEntry* entry = (HashMapEntry*)malloc(sizeof(HashMapEntry));
        entry->key = key;
        entry->value = value;
        entry->next = NULL;
        map->buckets[hashIndex] = entry;
    } else {
        // Update 
    }
}