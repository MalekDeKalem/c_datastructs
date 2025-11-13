#include <stdlib.h>
#include <stddef.h>
#include"hash_map.h"



HashMap* createHashMap(size_t (*hashFunc)(void *), int (*cmpFunc)(void *, void *)) {
    HashMap *map = malloc(sizeof(HashMap));
    map->capacity = INIT_CAPACITY;
    map->length = 0;
    map->buckets = calloc(map->capacity, sizeof(HashMapEntry *));
    map->hashFunc = hashFunc;
    map->cmpFunc = cmpFunc;
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
    int hashIndex = map->hashFunc(key) % map->capacity;
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
        HashMapEntry* currEntry = entry;
        HashMapEntry* prevEntry = entry;
        int found = 0;
        while (currEntry != NULL) {
            if (!map->cmpFunc(key, currEntry->key)) {
                currEntry->value = value;
                found = 1;
                break;
            }
            prevEntry = currEntry;
            currEntry = currEntry->next;
        }

        if (!found) {
            HashMapEntry* entry = (HashMapEntry*)malloc(sizeof(HashMapEntry));
            entry->key = key;
            entry->value = value;
            entry->next = NULL;
            prevEntry->next = entry;
        }
    }

    map->length++;
}

void removeHashMapItem(HashMap* map, void* key) {
    int hashIndex = map->hashFunc(key) % map->capacity;
    
    HashMapEntry* firstEntry = map->buckets[hashIndex];
    HashMapEntry* currEntry = firstEntry;
    HashMapEntry* prevEntry = firstEntry;
    int found = 0;

    while (currEntry != NULL) {

        if (map->cmpFunc(currEntry->key, key)) {
            found = 1;
            break;
        }

        prevEntry = currEntry;
        currEntry = currEntry->next;
    }


    if (found) {
        HashMapEntry* next = currEntry->next;
        if (currEntry == firstEntry) {
            if (next != NULL) {
                map->buckets[hashIndex] = next;
            } else {
                map->buckets[hashIndex] = NULL;
            }
        } else {
            if (next != NULL) {
                prevEntry->next = next;
            } else {
                prevEntry->next = NULL;
            }
            if (currEntry == firstEntry) {
                map->buckets[hashIndex] = NULL;
            }
        }

        free(currEntry);
        map->length--;
    }


}

void* getHashMapItem(HashMap* map, void* key) {
    int hashIndex = map->hashFunc(key) % map->capacity;
    HashMapEntry* entry = map->buckets[hashIndex];

    if (entry == NULL) return NULL;

    while (entry != NULL && !map->cmpFunc(entry->key, key)) {
        entry = entry->next;
    }

    if (entry != NULL) {
        return entry->value;
    } else {
        return NULL;
    }
}