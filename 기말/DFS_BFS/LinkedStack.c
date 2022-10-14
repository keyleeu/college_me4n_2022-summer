#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

// 공백스택 생성
Stack* createStack() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

// 스택이 포화상태인지 확인하는 연산					
int isStackFull(Stack* S) {
	// Fill your code
	return 0;

}

// 스택이 공백상태인지 확인하는 연산			
int isStackEmpty(Stack* S) {
	// Fill your code
	if (S->top == NULL) {
		return 1;
	}

	else {
		return 0;
	}
}

// 스택의 top에 요소를 추가하는 연산			
void push(Stack* S, element x) {
	// Fill your code
	stackNode* node = (stackNode*)malloc(sizeof(stackNode));
	node->data = x;
	node->link = S->top;
	S->top = node;
}

// 스택에서 마지막에 저장된 요소 삭제 및 반환하는 연산	
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

// 스택에서 마지막에 저장된 요소를 반환하는 연산			
element peekStack(Stack* S) {
	// Fill your code
	if (isStackEmpty(S)) {
		return ERROR;
	}
	else {
		return S->top->data;
	}
}

// 스택의 모든 요소 출력 			
void displayStack(Stack* S) {
	stackNode* p = S->top;
	printf("STACK [ ");
	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");
}

// 스택 비우기
void clearStack(Stack* S) {
	stackNode* p;
	while(S->top) {
		p = S->top;
		S->top = S->top->link;
		free(p);
		p = NULL;
	}
}				


