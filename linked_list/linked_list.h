#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct struct linked_node linked_node;
typedef struct struct linked_list linked_list;


struct linked_node {
	void *value;
	linked_list_node *next;
	linked_list_node *prev;
};

struct linked_list {
	linked_list_node *start;
	linked_list_node *end;
};


void linked_list_add_to_start(linked_list *ll, void *_value);
void linked_liat_add_to_end(linked_list *ll, void *_value);
void linked_list_remove_from_start(linked_list *ll);
void linked_list_remove_from_end(linked_list *ll);
int linked_list_search(void *val);



#endif