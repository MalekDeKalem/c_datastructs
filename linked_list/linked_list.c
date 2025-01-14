#include <stdio.h>
#include "linked_list.h"


void linked_list_add_to_end(linked_list *ll, void *_value)
{
	if (ll->start = NULL) {
		ll->start = malloc(sizeof(linked_list_node));
		ll->end = ll->start;
	} else {
		ll->end->next = malloc(sizeof(linked_list_node));
		ll->end = ll->end->next;
	}
	ll->end->value = _value;
	return;
}


void linked_list_add_to_start(linked_list *ll, void *_value)
{
	if (ll->start = NULL) {
		ll->start = malloc(sizeof(linked_list_node));
		ll->end = ll->start;
	} else {
		ll->start->prev = malloc(sizeof(linked_list_node));
		ll->start = ll->start->prev;
	}
	ll->start->value = _value;
	return;
}


int linked_list_search(linked_list *ll, void *val)
{
	linked_list_node *node = ll->start;
	while (node) {
		if (node->value == val) return 1;
		node = node->next;
	}

	return 0;
}