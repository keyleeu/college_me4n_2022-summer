#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int HData;

typedef struct{
    HData heap[MAX_SIZE];
    int numOfData;
}Heap;

int isEmpty(Heap* h) {
    if (h->numOfData == 0)
        return 1;
    else
	    return 0;
}

int getParentIdx(int idx){
    return (idx/2);
}

void insertHeap(Heap* h, HData x){
    int idx;
	if(h->numOfData == MAX_SIZE){
        return;
	}
	idx = h->numOfData + 1;
    while(idx != 1){
        if(x > h->heap[getParentIdx(idx)]){
            h->heap[idx] = h->heap[getParentIdx(idx)];
            idx = getParentIdx(idx);
        }
    }
    h->heap[idx] = x;
    h->numOfData++;
}

HData deleteHeap(Heap* h){
    if(isEmpty(h)){
        printf("error");
        return 0;
    }
    HData item = h->heap[1];
    HData lastVal = h->heap[h->numOfData];
    int parentidx = 1;
    int childidx = 2;

    while(childidx <= h->numOfData){
        if((childidx < h->numOfData) && (h->heap[childidx] < h->heap[childidx+1])){
            childidx++;
        }
        if(lastVal >= h->heap[childidx]){
            break;
        }
        else{
            h->heap[parentidx] = h->heap[childidx];
            parentidx = childidx;
            childidx = childidx * 2;
        }
    }
    
    h->heap[parentidx] = lastVal;
    h->numOfData--;
    return item;
}

void main(){
    Heap* root = (Heap*)malloc(sizeof(Heap));

    printf("idx 순서\n");
    for
}