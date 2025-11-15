
#ifndef _HASH_SET_H_
#define _HASH_SET_H_

#define INIT_CAPACITY 16



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



HashSet* createHashSet((*cmpFunc)(void *a, void *b), size_t (*hashFunc)(void *key));
HashSet* createHashSet((*cmpFunc)(void *a, void *b), size_t (*hashFunc)(void *key), size_t);
int addHashSetItem(HashSet *, void *);
int removeHashSetItem(HashSet *, void *);
int containsHashSetItem(HashSet *, void *);
int isEmptyHashSet(HashSet *);




#endif // _HASH_SET_H_