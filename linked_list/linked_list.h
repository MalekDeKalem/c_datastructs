#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct struct linked_node linked_node;
typedef struct struct linked_list linked_list;


struct linked_node {
	void *value;
	linked_node *next;
};

struct linked_list {
	linked_node *tail;
	linked_node *head;
};


void linked_node_add(linked_list *ll, void *_value);
void linked_node_pop(linked_list *ll);
void linked_node_remove(void* val);



#endif