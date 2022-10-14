#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode* left, * right;
}BinTree;

BinTree* createBT(int num) {
	BinTree* root = (BinTree*)malloc(sizeof(BinTree));
	root->data = num;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void inorderTraverse(BinTree* root)
{
	if (root != NULL) {
		inorderTraverse(root->left);
		printf("%d\n", root->data);
		inorderTraverse(root->right);
	}
	return;
}

void preorderTraverse(BinTree* root)
{
	if (root != NULL)
	{
		printf("%d\n", root->data);
		preorderTraverse(root->left);
		preorderTraverse(root->right);
	}
	return;
}

void postorderTraverse(BinTree* root)
{
	if (root != NULL)
	{
		postorderTraverse(root->left);
		postorderTraverse(root->right);
		printf("%d\n", root->data);
	}
	return;
}

void main() {
	BinTree* root;
	root = createBT(1);
	root->left = createBT(2);
	root->right = createBT(3);

	printf("inorderTraverse\n");
	inorderTraverse(root);
	printf("\n");

	printf("preorderTraverse\n");
	preorderTraverse(root);
	printf("\n");

	printf("postorderTraverse\n");
	postorderTraverse(root);
	printf("\n");
	return;
}