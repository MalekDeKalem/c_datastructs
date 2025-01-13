#include <stdio.h>
#include <stdlib.h>
#include "bst_tree.h"

bst_node* bst_create(int val) 
{
	bst_node *newnode = (bst_node*)malloc(sizeof(bst_node));
	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void bst_destruct_node(bst_node *node) 
{

	if (node != NULL) {
		free(node);
		node = NULL;
	}
}

void bst_in_order(bst_node *root)
{
	if (root != NULL) {
		bst_in_order(root->left);
		printf("%d ", root->val);
		bst_in_order(root->right);
	}
}

void bst_pre_order(bst_node *root)
{
	if (root != NULL) {
		printf("%d ", root->val);
		bst_pre_order(root->left);
		bst_pre_order(root->right);
	}
}

void bst_post_order(bst_node *root)
{
	if (root != NULL) {
		bst_post_order(root->left);
		bst_post_order(root->right);
		printf("%d ", root->val);
	}
}

bst_node* bst_min(bst_node *root) 
{
	if (root->left == NULL) {
		return root;
	} else {
		return bst_min(root->left);
	}
}

bst_node* bst_max(bst_node *root) 
{
	if (root->right == NULL) {
		return root;
	} else {
		return bst_max(root->right);
	}
}

int bst_search(bst_node *root, int target)
{
	if (root == NULL) 
		return 0;

	if (target == root->val) 
		return 1;

	if (target < root->val) {
		return bst_search(root->left, target);
	} else {
		return bst_search(root->right, target);
	}
}

void bst_add(bst_node *root, int val) 
{
    if (val < root->val) {
        if (root->left == NULL) {
            root->left = bst_create(val);
        } else {
            bst_add(root->left, val);
        }
    } else {
        if (root->right == NULL) {
            root->right = bst_create(val);
        } else {
            bst_add(root->right, val);
        }
    }
}

bst_node* bst_remove(bst_node *root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (val < root->val) {
        root->left = bst_remove(root->left, val);
    } else if (val > root->val) {
        root->right = bst_remove(root->right, val);
    } else {

        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;  
        }

        if (root->left == NULL) {
            bst_node *temp = root->right;
            free(root);
            return temp;  
        } else if (root->right == NULL) {
            bst_node *temp = root->left;
            free(root);
            return temp; 
        }

        bst_node *temp = bst_min(root->right);  
        root->val = temp->val; 
        root->right = bst_remove(root->right, temp->val);  
    }

    return root; 
}

void bst_destroy(bst_node* root) 
{
	if (root == NULL)
		return;

	bst_destroy(root->left);
	bst_destroy(root->right);

	free(root);
}
