
#ifndef _HASH_SET_H_
#define _HASH_SET_H_




typedef struct HashSet HashSet;
typedef struct HashSetItem HashSetItem;


struct HashSetItem 
{
    void* value;
    HashSetItem* next;
};

struct HashSet 
{
    HashSetItem** buckets;
    size_t capacity;
    size_t size;

    size_t (*hashFunc)(void *key);
    int (*cmpFunc)(void *a, void *b);
};








#endif // _HASH_SET_H_