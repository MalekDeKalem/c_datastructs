#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct linked_list_node linked_list_node;
typedef struct linked_list linked_list;
typedef int (*comparator_func)(const void *, const void *); 


struct linked_list_node {
	void *value;
	linked_list_node *next;
	linked_list_node *prev;
};

struct linked_list {
	linked_list_node *start;
	linked_list_node *end;
};

linked_list* linked_list_create();  
void linked_list_add_to_start(linked_list *, void *);
void linked_list_add_to_end(linked_list *, void *);
void linked_list_remove_from_start(linked_list *);
void linked_list_remove_from_end(linked_list *);
linked_list_node* linked_list_search(linked_list *,void *, comparator_func);



#endif