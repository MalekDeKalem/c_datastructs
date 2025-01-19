#include <stdio.h>
#include "linked_list.h"
#include <string.h>






int main() 
{
    char a[] = "I hate this Linked List Datastructure";
    linked_list *ll = linked_list_create(a);

    printf("%s\n", ll->start->value);

    return 0;
}