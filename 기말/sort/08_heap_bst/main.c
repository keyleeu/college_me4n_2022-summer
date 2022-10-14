#include <stdio.h>
void treeSort(int a[], int n);

int main(void) {
	int i, list[9] = { 32, 20, 23, 14, 12, 16, 15, 10, 7 };
	int size = sizeof(list) / sizeof(list[0]); 	// list 배열의 원소 개수
	printf("\n정렬할 원소 : ");
	for (i = 0; i <= size - 1; i++) printf(" %d", list[i]);
		printf("\n\n <<<<< 트리 정렬 수행 >>>>>> \n\n");
	treeSort(list, size);  // 트리 정렬 함수 호출

	getchar(); return 0;
}