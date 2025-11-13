#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#define INIT_CAPACITY 16


typedef struct ArrayList ArrayList;

struct ArrayList 
{
    void** data;
    size_t size;
    size_t capacity;
};



ArrayList* createArrayList();
ArrayList* createArrayList(size_t);
void addArrayListItem(ArrayList *, void *);
void removeAtIndexArrayListItem(ArrayList *, size_t);
void removeArrayListItem(ArrayList *, void *);
void* getArrayListItem(ArrayList *, size_t);
int containsArrayListItem(ArrayList *, void *);
void printArrayList(ArrayList *);


#endif // ARRAYLIST_H