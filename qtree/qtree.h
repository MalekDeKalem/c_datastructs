#ifndef Q_TREE_H
#define Q_TREE_H

typedef struct q_tree_node q_tree_node;
typedef struct q_tree q_tree;


struct q_tree_node {
	struct _point {
		int x;
		int y;
	} *point;

	void *val;
};


struct q_tree {
	int width;
	int height;
	int capacity;
	q_tree_node *root;
	q_tree *tr;
	q_tree *tl;
	q_tree *br;
	q_tree *bl;
};

q_tree* q_tree_create();
q_tree_node* q_tree_create_node();
void q_tree_add(q_tree_node *);
q_tree_node* q_tree_search(int, int);
void q_tree_remove(q_tree_node *);

#endif
