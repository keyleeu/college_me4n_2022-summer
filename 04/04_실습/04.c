#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode* link;
}listNode;

typedef struct LinkedList{
    listNode* head;
    int length;
}linkedList;


void insertFirst(linkedList* L, element x){

    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    newNode->link = L->head;

    L->head = newNode;
    L->length++;

}

void insertLast(linkedList* L, element x){

    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    if(L == NULL){
        L->head = newNode;
    }
    else{
        temp = L->head;
        while (temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;    
    }
    L->length++;

}

void insert(linkedList* L, listNode* pre, element x){
    
    listNode* newNode;
    newNode->data = x;
    newNode = (listNode*)malloc(sizeof(listNode));
    if(L == NULL){
        newNode->link = NULL;
        L->head = newNode;
    }
    else if(pre == NULL){
        newNode->link = L->head;
        L->head = newNode;
    }
    else{
        newNode->link = pre->link;
        pre->link = newNode;
    }
    L->length++;

}

void delete(linkedList* L, listNode* p){

	listNode* p;

	if(L->head == NULL) return FALSE;
	if(p == NULL) return FALSE;

	if(L->head == p) {
		L->head = p->link;
		free(p);
	}
	else {
		pre = L->head;
		while(pre->link != p) {
			pre = pre->link;
			if(pre == NULL) return FALSE;
		}
		pre->link = p->link;
		free(p);
	}
	L->length--;
	return TRUE;
    
}