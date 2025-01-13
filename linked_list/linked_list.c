#include <stdio.h>
#include "linked_list.h"


linked_list_add(linked_list *ll, void *_value)
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
