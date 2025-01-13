#include <stdio.h>
#include "bst_tree.h"



int main()
{
	bst_node* root = bst_create(50);
	bst_add(root, 30);
	bst_add(root, 20);
	bst_add(root, 40);
	bst_add(root, 70);
	bst_add(root, 60);
	bst_add(root, 80);
	bst_node* temp = bst_min(root);
	bst_node* tmp = bst_max(root);

	bst_in_order(root);
	printf("\n");
	bst_pre_order(root);
	printf("\n");
	bst_post_order(root);
	printf("\n");
	printf("Minimum Value in Tree is: %d \n", temp->val);
	printf("Maximum Value in Tree is: %d \n", tmp->val);

	bst_node* deleted = bst_remove(root, 70);
	bst_in_order(root);
	printf("\n");
	printf("Root has val: %d \n", deleted->val);

	printf("Is the number 70 present in the tree... ");
	if (bst_search(root, 70)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}


