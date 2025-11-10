#ifndef HashMap_H
#define HashMap_H

#define INIT_CAPACITY 16
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

typedef struct HashMap HashMap;
typedef struct HashMapEntry HashMapEntry;

struct HashMapEntry
{
    void* key;
    void* value;
    HashMapEntry* next;
};

struct HashMap 
{
    HashMapEntry** buckets;
    size_t capacity;
    size_t length;

    size_t (*hashFunc)(void *key);
    int (*cmpFunc)(void *a, void *b);
};



void addHashMapItem(HashMap *, void *, void *);
void removeHashMapItem(HashMap *, void *);
void* getHashMapItem(HashMap *, void *);
HashMap* createHashMap(size_t (*hashFunc)(void *), int (*cmpFunc)(void *, void *));
void destroyHashMap(HashMap *);

#endif
