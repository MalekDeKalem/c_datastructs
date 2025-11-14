#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#define INIT_CAPACITY 16


typedef struct ArrayList ArrayList;

struct ArrayList 
{
    void** data;
    size_t size;
    size_t capacity;
    int (*cmpFunc)(void *a, void *b);
};



ArrayList* createArrayList(int (*cmpFunc)(void *, void *));
ArrayList* createArrayList(size_t, int (*cmpFunc)(void *, void *));
void addArrayListItem(ArrayList *, void *);
void removeAtIndexArrayListItem(ArrayList *, size_t);
void removeArrayListItem(ArrayList *, void *);
void* getArrayListItem(ArrayList *, size_t);
int containsArrayListItem(ArrayList *, void *);



#endif // ARRAYLIST_H