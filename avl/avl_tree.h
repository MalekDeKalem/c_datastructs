#ifndef _AVL
#define _AVL

typedef struct avl_node avl_node;

struct avl_node {
    int val;
    int height;
    avl_node *left;
    avl_node *right;
};

avl_node* avl_create(int val);
int avl_max(int a, int b);
void avl_destruct_node(avl_node *node);
int balance(avl_node* node); 

void avl_pre_order(avl_node* root);
void avl_in_order(avl_node* root);
void avl_post_order(avl_node* root);

void avl_add(avl_node* node);
avl_node* avl_remove(int val, avl_node* root);

avl_node* ll_rotation(avl_node *root);
void avl_rr_rotation(avl_node *root);
void avl_lr_rotation(avl_node *root);
void avl_rl_rotation(avl_node *root);


void avl_destroy(avl_node* root);


#endif