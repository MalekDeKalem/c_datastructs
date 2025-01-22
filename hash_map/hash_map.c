
#include"hash_map.h"





hash_map* hash_map_create() 
{
    hash_map* map = malloc(sizeof(hash_map));
    if (map == NULL) return NULL;
    map->length = 0;
    map->capacity = INIT_CAPACITY;

    map->buckets = calloc(sizeof(hash_map_bucket));
    if (map->buckets == NULL) {
        free(map);
        return NULL;
    }

    return map;
}


void hash_map_destroy(hash_map* map)
{
    for (size_t i = 0; i < map->capacity; i++)
        free((void*)map->buckets[i].key);

    free(map->buckets);
    free(map);
}