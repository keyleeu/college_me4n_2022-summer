#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// ���齺�� ����
Stack* createStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// ������ ��ȭ�������� Ȯ���ϴ� ����					
int isStackFull(Stack* S) {
	// Fill your code
	return 0;

}

// ������ ����������� Ȯ���ϴ� ����			
int isStackEmpty(Stack* S) {
	// Fill your code
	if (S->top == NULL) {
		return 1;
	}

	else {
		return 0;
	}
}

// ������ top�� ��Ҹ� �߰��ϴ� ����			
void push(Stack* S, element x) {
	// Fill your code
	stackNode* node = (stackNode*)malloc(sizeof(stackNode));
	node->data = x;
	node->link = S->top;
	S->top = node;
}

// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����	
element pop(Stack* S) {
	// Fill your code
	if (isStackEmpty(S)) {
		printf("[ERROR] Stack is EMPTY!!");
		return ERROR;
	}
	
	stackNode* node = S->top;
	element value = S->top->data;
	S->top = S->top->link;
	free(node); node = NULL;
	return value;

}

// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����			
element peekStack(Stack* S) {
	// Fill your code
	if (isStackEmpty(S)) {
		return ERROR;
	}
	else {
		return S->top->data;
	}
}

// ������ ��� ��� ��� 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// ���� ����
void clearStack(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


