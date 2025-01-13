#include <stdio.h>
#include <stdlib.h>
#include "bst_tree.h"


avl_node* avl_create(int val)
{
    avl_node *root = (avl_node*)malloc(sizeof(avl_node));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;
    return root;
}

avl_node* avl_min(avl_node *root) 
{
	if (root->left == NULL) {
		return root;
	} else {
		return avl_min(root->left);
	}
}

avl_node* avl_max(int a, int b)
{
	if (root->right == NULL) {
		return root;
	} else {
		return avl_max(root->right);
	}
}

void avl_destruct_node(avl_node *node)
{
    if (node != NULL) {
        free(node);
        node = NULL;
    }
}

int balance(avl_node* node) 
{
    if (node == NULL) 
        return 0;

    return node->left->height - node->right->height;
}

void avl_pre_order(avl_node* root) 
{
    if (root != NULL) {
        printf("%d", root->val);
        avl_pre_order(root->left);
        avl_pre_order(root->right);
    }    
}

void avl_in_order(avl_node* root)
{
    if (root != NULL) {
        avl_in_order(root->left);
        printf("%d", root->val);
        avl_in_order(root->right);
    }
}

void avl_post_order(avl_node* root)
{
    if (root != NULL) {
        avl_post_order(root->left);
        avl_post_order(root->right);
        printf("%d", root->val);
    }
}

avl_node* ll_rotation(avl_node *root)
{
    avl_node* a = root->right;
    avl_node* b = a->left;
    a->left = root;
    root->right = b;
    root->height = avl_max(root->left->height, root->right->height) + 1;
    a->height = avl_max(a->left->height, a->right->height) + 1;
    return a;
}



void avl_destroy(avl_node* root)
{
    if (root == NULL)
        return;

    avl_destroy(root->left);
    avl_destroy(root->right);

    free(root);
}
