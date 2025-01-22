#ifndef HASH_MAP_H
#define HASH_MAP_H

#define INIT_CAPACITY 16
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

typedef struct hash_map hash_map;
typedef struct hash_map_bucket hash_map_bucket;
typedef struct hash_map_iterator hash_map_iterator;

struct hash_map_buckets
{
    void *key;
    void *value;
};

struct hash_map 
{
    buckets *hash_map_buckets;
    size_t capacity;
    size_t length;
};

struct hash_map_iterator
{
    void* key;
    void* value;
    hash_map* map;
    size_t index;
};


void hash_map_add(hash_map *, void *, void *);
void hash_map_remove(hash_map *, void *);
void* hash_map_get(hash_map *, void *);
hash_map* hash_map_create(void *, void *);
hash_map_iterator hash_map_iter(hash_map *);
bool hash_map_next(hash_map_iterator* iter);


#endif
