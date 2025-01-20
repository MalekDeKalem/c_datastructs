#ifndef HASH_MAP_H
#define HASH_MAP_H

#define INIT_CAPACITY 16
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

typedef struct hash_map hash_map;
typedef struct hash_map_bucket hash_map_bucket;

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


void hash_map_add(hash_map *, void *, void *);
void hash_map_remove(hash_map *, void *);
void* hash_map_get(hash_map *, void *);
hash_map* hash_map_create(void *, void *);


#endif
