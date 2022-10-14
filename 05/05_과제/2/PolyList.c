#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"

polyList* initList() {
	polyList* PL = (polyList*)malloc(sizeof(polyList));
	PL->head = NULL;
	PL->last = NULL;
	return PL;
}

void appendTerm(polyList* PL, float coef, int exp) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->coef = coef;
	newNode->exp = exp;
	newNode->link = NULL;
	if(PL->head == NULL){
		PL->head = newNode;
	}
	else{
		PL->last->link = newNode;
	}
	PL->last = newNode;
}

polyList* addPoly(polyList* A, polyList* B) {
	polyList* C = initList();
	Node* p = A->head;
	Node* q = B->head;
	int sum;

	while (p != NULL && q != NULL)
	{
		if(p->exp == q->exp){
			sum = p->coef + q->coef;
			if(sum != 0){
				appendTerm(C, sum, p->exp);
			}
			p = p->link;
			q = q->link;
		}
		else if(p->exp > q->exp){
			appendTerm(C, p->coef, p->exp);
			p = p->link;
		}
		else{
			appendTerm(C, q->coef, q->exp);
			q = q->link;
		}
	}
	while (p != NULL)
	{
		appendTerm(C, p->coef, p->exp);
		p = p->link;
	}
	while (q != NULL)
	{
		appendTerm(C, q->coef, q->exp);
		q = q->link;

	}
	return C;
}

void displayPoly(polyList* PL) {
	Node* p = PL->head;
	for(; p; p=p->link) {
		printf("%3.0fx^%d", p->coef, p->exp);
		if(p->link != NULL)
			printf(" +");
	}
	printf("\n");
}