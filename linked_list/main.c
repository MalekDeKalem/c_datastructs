#include <stdio.h>
#include "linked_list.h"
#include <string.h>






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
    printf("%s\n", ll->end->value);


    return 0;
}