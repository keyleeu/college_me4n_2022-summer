#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}listNode;

typedef struct LinkedList {
	listNode* head;
	int length;
}linkedList;

linkedList* initList() {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	L->length = 0;
	return L;
}

int getLength(linkedList* L) {
	return L->length;
}

void insert(linkedList* L, listNode* pre, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;

	if (L->head == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
	L->length++;
}

void insertFirst(linkedList* L, element x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = L->head;
	L->head = newNode;
	L->length++;
}

void insertLast(linkedList* L, element x) {
	listNode* newNode, * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = NULL;
	if (L->head == NULL)
		L->head = newNode;
	else {
		temp = L->head;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = newNode;
	}
	L->length++;
}

int delete(linkedList* L, listNode* p) {
	listNode* pre;

	if (L->head == NULL) return FALSE;
	if (p == NULL) return FALSE;
	if (L->head == p) {
		L->head = p->link;
		free(p);
	}
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
			if (pre == NULL) return FALSE;
		}
		pre->link = p->link;
		free(p);
	}
	L->length--;
	return TRUE;
}

listNode* search(linkedList* L, element x) {
	listNode* temp = L->head;
	while (temp != NULL) {
		if (temp->data == x)
			return temp;
		else
			temp = temp->link;
	}
	return temp;
}

void displayList(linkedList* L) {
	listNode* p;

	printf("L=(");
	p = L->head;
	while (p != NULL) {
		printf("% d", p->data);
		p = p->link;
		if (p != NULL) printf(",");
	}
	printf(")\n");
}

int main(void)
{
	linkedList* root;
	root = initList();

	insertLast(root, 10);
	insertLast(root, 20);
	insertLast(root, 30);

	insertFirst(root, 0);

	// search hint
	listNode* pre;
	listNode* cur;
	pre = NULL;
	cur = root->head;
	while (cur != NULL) {
		if (cur->data == 20)
			break;
		else {
			pre = cur;
			cur = cur->link;
		}
	}
	displayList(root);
	printf("pre : %d  // cur : %d\n", pre->data, cur->data);

	insert(root, pre, 40);
	delete(root, pre);
	displayList(root);
	return 0;
}