#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



linked_list* linked_list_create(void *_value) 
{
	linked_list* ll = (linked_list*)malloc(sizeof(linked_list));
	ll->start = malloc(sizeof(linked_list_node));
	ll->start->value = _value;
	ll->end = ll->start;
	return ll;
}

void linked_list_add_to_end(linked_list *ll, void *_value)
{
	if (ll->start == NULL) {
		ll->start = malloc(sizeof(linked_list_node));
		ll->end = ll->start;
	} else {
        ll->end->next = malloc(sizeof(linked_list_node));
        ll->end->next->prev = ll->end; 
        ll->end = ll->end->next;
	}
    ll->end->value = _value;
    ll->end->next = NULL;  
	return;
}


void linked_list_add_to_start(linked_list *ll, void *_value)
{
	if (ll->start == NULL) {
		ll->start = malloc(sizeof(linked_list_node));
		ll->end = ll->start;
	} else {
		ll->start->prev = malloc(sizeof(linked_list_node));
		ll->start->prev->next = ll->start;
		ll->start = ll->start->prev;
	}
	ll->start->value = _value;
	ll->start->prev = NULL;
	return;
}


typedef int (*comparator_func)(const void *, const void *); 

// int linked_list_search(linked_list *ll, void *val, comparator_func cmp) {
//     linked_list_node *node = ll->start;
//     while (node) {
//         if (cmp(node->value, val) == 0) {
//             return 1; 
//         }
//         node = node->next;
//     }
//     return 0; 
// }

void linked_list_remove_from_start(linked_list *ll) {
    if (ll == NULL || ll->start == NULL) return; 

    linked_list_node *temp = ll->start; 

    if (ll->start->next != NULL) {
        ll->start = ll->start->next;
        ll->start->prev = NULL;     
    } else {
        ll->start = NULL;
        ll->end = NULL;  
    }

    free(temp);
	return;
}

void linked_list_remove_from_end(linked_list *ll)
{
	if (ll == NULL || ll->start == NULL) return;

	linked_list_node *temp = ll->end;

	if (ll->end->prev != NULL) {
		ll->end = ll->end->prev;
		ll->end->next = NULL;
	} else {
		ll->start = NULL;
		ll->end = NULL;
	}

	free(temp);
	return;
}