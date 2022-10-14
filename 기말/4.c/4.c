#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
	int key;
	struct BinaryTreeNode* left, * right;
}BinTree;

BinTree* root = NULL;

BinTree* createBT(int num) {
	BinTree* root = (BinTree*)malloc(sizeof(BinTree));
	root->key = num;
	root->left = NULL;
	root->right = NULL;
	return root;
}

BinTree* searchBST(BinTree* bt, int x) {
	BinTree* p = bt;
    printf("2");
	while (p != NULL) {
		if (x == p->key) 
			return p;
		if (x < p->key) {
			return searchBST(p->left, x);
		}
		else {
			return searchBST(p->right, x);
		}
	}
	printf("ERROR : 찾는 키가 없습니다\n");
	return NULL;
}

BinTree* insertBST(BinTree* node, int x) {
	if (node == NULL) {
		BinTree* newNode = (BinTree*)malloc(sizeof(BinTree));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}

	if (x < node->key){
		node->left = insertBST(node->left, x);
	}
	else if (x > node->key){
		node->right = insertBST(node->right, x);
	}
	else {
		printf("ERROR: 이미 같은 키가 있습니다.\n");
		return node;
	}
	return node;
}

void deleteBST(BinTree* bt, int x) {
	BinTree* p = NULL;
	BinTree* parent = NULL;
	BinTree* q = NULL;

	// 삭제할 노드와 부모노드 찾기.
	p = searchBST(bt, x);
	parent = root;
	while (parent != NULL)
	{
		if (parent->right == p || parent->left == p)
			break;
		if (parent->key > x) {
			parent = parent->left;
		}
		else {
			parent = parent->right;
		}
	}
	
	// 삭제할 노드가 없는 경우
	if (p == NULL) {
		printf("삭제할 노드가 없습니다.\n");
		return;
	}

	// CASE 1 : 삭제할 노드의 차수가 0인 경우
	if (p->left == NULL && p->right == NULL) {
		if (parent->left == p)
			parent->left = NULL;
		else
			parent->right = NULL;
	}

	// CASE 2 : 삭제할 노드의 차수가 1인 경우
	else if (p->left == NULL || p->right == NULL) {
		if (p->left != NULL) {
			if (parent->left == p)
				parent->left = p->left;
			else
				parent->right = p->left;
		}
		else {
			if (parent->left == p)
				parent->left = p->right;
			else
				parent->right = p->right;
		}
	}

	// CASE 3 : 삭제할 노드의 차수가 2인 경우
	else if (p->left != NULL && p->right != NULL) {
		q = p->left;
		while (q->right != NULL) {
			q = q->right;
		}
		p->key = q->key;
		deleteBST(p->left, q->key);
	}
	return;
}

void BST_print(BinTree* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->key);
    BST_print(root->left);
    BST_print(root->right);
}


int main()
{
	root = insertBST(root, 67);
	insertBST(root, 32);
	insertBST(root, 78);
	insertBST(root, 17);
	insertBST(root, 45);
	insertBST(root, 24);
	insertBST(root, 36);
	insertBST(root, 56);
	insertBST(root, 33);
    insertBST(root, 41);

	BST_print(root);

    searchBST(root, 33);
}