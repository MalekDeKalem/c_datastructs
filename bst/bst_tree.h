#ifndef _BST
#define _BST



typedef struct bst_node bst_node;


struct bst_node 
{
	int val;
	bst_node *left;
	bst_node *right;
};



bst_node* bst_create(int val); 
void bst_destruct_node(bst_node *node); 

void bst_in_order(bst_node *root);
void bst_pre_order(bst_node *root);
void bst_post_order(bst_node *root);

bst_node* bst_min(bst_node *root); 
bst_node* bst_max(bst_node *root);

int bst_search(bst_node *root, int target);
void bst_add(bst_node *root, int val);
bst_node* bst_remove(bst_node *root, int val);
void bst_destroy(bst_node* root);



#endif
