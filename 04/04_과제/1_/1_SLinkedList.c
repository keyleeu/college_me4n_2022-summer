#include <stdio.h>
#include <stdlib.h>
#include "1_SLinkedList.h"

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
	// 새 노드에 데이터 저장
	newNode->data = x;
	
	// 공백 리스트인 경우
	if(L->head == NULL){
	newNode->link = NULL;
	L->head = newNode;
	}
	// 첫 번째 노드로 삽입되는 경우
	else if(pre == NULL){
		newNode->link = L->head;
		L->head = newNode;
	}
	// 중간 노드로 삽입되는 경우
	else{
		newNode->link = pre->link;
		pre->link = newNode;
	}
	// 데이터 개수 증가
	L->length++;

}

void insertFirst(linkedList* L, element x) {

	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = L->head;
	L->head = newNode;

}

void insertLast(linkedList* L, element x) {

	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = x;
	newNode->link = NULL;

	if(L->head == NULL)
		L->head = newNode;
	else{
		temp = L->head;
		while(temp->link != NULL)
			temp = temp->link;
			temp->link = newNode;
	}
	L->length++;

}

int delete(linkedList* L, listNode* p) {

	listNode* pre;
	
	// 공백 리스트인 경우
	if(L->head == NULL) return FALSE;
	// 삭제할 노드가 없는 경우
	if(p == NULL) return FALSE;
	// 첫 번째 노드가 삭제할 노드인 경우
	if(L->head == p) {
		L->head = p->link;
		free(p);
	}
	// 그 이외의 경우
	else {
		pre = L->head;
		while(pre->link != p) {
			pre = pre->link;
			if(pre == NULL) return FALSE;
		}
	pre->link = p->link;
	free(p);
	}
	// 데이터 개수 감소
	L->length--;

	return TRUE;
}

listNode* search(linkedList* L, element x) {

	listNode* temp = L->head;
	
	while(temp != NULL) {
		if(temp->data == x)
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
	while(p != NULL) {
		printf("%d", p->data);
		p = p->link;
		if(p != NULL) printf(", ");
	}
	printf(")\n");
}

void clear(linkedList* L) {
	listNode* p;
	while(L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}