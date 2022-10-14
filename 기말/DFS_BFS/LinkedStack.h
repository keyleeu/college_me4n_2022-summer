#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

#define ERROR 123456789
#define TRUE 1
#define FALSE 0

typedef int element;

// Stack�� ��� ������ ����ü�� ����
typedef struct StackNode {
	element data;
	struct StackNode* link;
}stackNode;

// Stack�� ������ ���(���� �ֱٿ� ���Ե� ���)�� ��Ÿ���� top�� ����ü�� ���� 
typedef struct LinkedStack {
	stackNode* top;
}Stack;

Stack* createStack();					// ���齺�� ����
int isStackFull(Stack* S);				// ������ ��ȭ�������� Ȯ���ϴ� ����
int isStackEmpty(Stack* S);				// ������ ����������� Ȯ���ϴ� ����
void push(Stack* S, element x);		// ������ top�� ��Ҹ� �߰��ϴ� ����
element pop(Stack* S);				// ���ÿ��� �������� ����� ��� ���� �� ��ȯ�ϴ� ����
element peekStack(Stack* S);				// ���ÿ��� �������� ����� ��Ҹ� ��ȯ�ϴ� ����
void displayStack(Stack* S);		// ������ ��� ��� ���
void clearStack(Stack* S);				// ���� ���� 

#endif


