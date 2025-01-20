#include <stdio.h>
#include "linked_list.h"
#include <string.h>



int comparator(const void* string1, const void* string2) 
{
    return strcmp((const char*)string1, (const char*)string2) == 0;
}


int main() 
{
    char a[] = "I hate this Linked List Datastructure";
    linked_list *ll = linked_list_create(a);
    linked_list_add_to_end(ll, "Or maybe I like it");

    printf("%s\n", ll->start->value);
    printf("%s\n", ll->end->value);

    linked_list_remove_from_end(ll);
    linked_list_remove_from_end(ll);
    linked_list_add_to_start(ll, "I have risen from the ground");
    linked_list_node* ln = linked_list_search(ll, "I have risen from the ground", comparator);
    printf("%s\n", ll->end->value);
    printf("%s\n", ln->value);



    return 0;
}