#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 7
#define HData int

typedef struct {
	HData heap[MAX_SIZE];
	int numOfData;
}Heap;

int isEmpty(Heap* h)
{
	if (h->numOfData == 0)
		return 1;
	else
		return 0;
}

int getParentIdx(int idx) {
	return idx / 2;
}

void insertHeap(Heap* h, HData x) {
	if (h->numOfData == MAX_SIZE) {
		printf("ERROR: Heap is FULL!!\n");
		return;
	}
	int idx = h->numOfData + 1;
	while (idx != 1) {
		if (x > h->heap[getParentIdx(idx)]) {
			h->heap[idx] = h->heap[getParentIdx(idx)];
			idx = getParentIdx(idx);
		}
		else break;
	}
	h->heap[idx] = x;
	h->numOfData++;
}

HData deleteHeap(Heap* h) {
	if (isEmpty(h)) {
		printf("ERROR: Heap is EMPTY!!\n");
		return 0;
	}
	HData item = h->heap[1];
	HData lastVal = h->heap[h->numOfData];
	int parentIdx = 1;
	int childIdx = 2;
	while (childIdx <= h->numOfData) {
	if ((childIdx < h->numOfData) && (h->heap[childIdx] < h->heap[childIdx + 1]))
		childIdx++;
	if (lastVal >= h->heap[childIdx]) break;
	else {
		h->heap[parentIdx] = h->heap[childIdx];
		parentIdx = childIdx;
		childIdx = childIdx * 2;
	}
}
h->heap[parentIdx] = lastVal;
h->numOfData--;
return item;
}

void printHeap(Heap* h) {
	int i;
	printf("Heap : ");
	for (i = 1; i <= h->heap[MAX_SIZE]; i++)
		printf("[%d] ", h->heap[i]);
}

int main() {
	Heap* root = (Heap*)malloc(sizeof(Heap));
	root->numOfData = 0;

	insertHeap(root, 1);
	insertHeap(root, 2);
	insertHeap(root, 3);
	insertHeap(root, 4);
	insertHeap(root, 5);
	insertHeap(root, 6);

	printHeap(root);

	printf("idx 순서\n");
	for (int i = 1; i < MAX_SIZE; i++)
		printf("%d // ", root->heap[i]);

	printf("\n\n");

	printf("deleteHeap 순서\n");
	for (int i = 1; i < MAX_SIZE; i++){
		printf("%d // ", deleteHeap(root));
	}

}