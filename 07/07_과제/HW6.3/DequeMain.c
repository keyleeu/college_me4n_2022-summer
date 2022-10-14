#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main() {
	Deque* DQ;
	element e;
	int i;
	
	printf("== Deque 생성하기==\n");
	DQ = create();
	displayDeque(DQ);
	
	printf("\n== front 삽입 10 ==\n");
	insertFront(DQ, 10);	displayDeque(DQ);
	printf("\n== front 삽입 20 ==\n");
	insertFront(DQ, 20);	displayDeque(DQ);
	printf("\n== rear 삽입 30 ==\n");
	insertRear(DQ, 30);	displayDeque(DQ);
	printf("\n== front 삭제==\n");
	e = deleteFront(DQ);	displayDeque(DQ);
	if(e != ERROR)	printf("삭제 데이터: %d\n", e);
	printf("\n== rear 삭제==\n");
	e = deleteRear(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("삭제 데이터: %d\n", e);
	printf("\n== rear 삽입 40 ==\n");
	insertRear(DQ, 40);	displayDeque(DQ);
	printf("\n== front 삽입 50 ==\n");
	insertFront(DQ, 50);	displayDeque(DQ);
	printf("\n== front 검색==\n");
	e = getFront(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("front 데이터: %d\n", e);
	printf("\n== rear 검색==\n");
	e = getRear(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("rear 데이터: %d\n", e);
	printf("\n== Deque 비우기 ==\n");
	clear(DQ);	displayDeque(DQ);	

	insertFront(DQ, 3);
	insertFront(DQ, 4);
	insertRear(DQ, 5);
	deleteFront(DQ);
	deleteRear(DQ);
	insertFront(DQ, 6);
	deleteRear(DQ);
	e = getRear(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("rear 데이터: %d\n", e);
	insertFront(DQ, 8);
	deleteFront(DQ);
	e = getRear(DQ);		displayDeque(DQ);
	if(e != ERROR)	printf("rear 데이터: %d\n", e);
	
	return 0;
}