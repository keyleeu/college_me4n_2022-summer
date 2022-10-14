#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef int element;
typedef struct{
    element list[MAX_SIZE];
    int length;
}ArrayListType;

void error(char *message)
{
	printf("%s\n", message);
}

void init(ArrayListType *L)
{
	L->length = 0;
}

int isEmpty(ArrayListType* L){
    return L->length == 0;
}

int isFull(ArrayListType* L){
    return L->length == MAX_SIZE;
}

void display(ArrayListType *L)
{
	int i;
	printf("===Print Lists===\n");
	for (i=0; i<L->length; i++)
		printf("ArrayList[%d]: %d\n", i, L->list[i]);
}

void insert(ArrayListType *L, int pos, element item){
    int i;
    if( isFull(L) )
        error("List is Full!");
    else if( (pos < 0) || (pos > L->length) )
        error("Index Error");
    else{
        for( i=(L->length-1); i>=pos; i--)
            L->list[i+1] = L->list[i];
        L->list[pos] = item;
        L->length++;
    }
		printf("%d, %d\n", pos, item);
}

element delete(ArrayListType *L, int pos){
    int i;
    element item;
	printf("%d, %d\n", pos, item);
    if( isEmpty(L) )
        error("List is Empty!");
    else if( (pos < 0) || (pos >= L->length) )
        error("Index Error");
    else{
        item = L->list[pos];
            for( i=pos; i<L->length-1; i++)
        L->list[i] = L->list[i+1];
        L->length--;
    return item;
    }
}

int main(){
    ArrayListType* a;

	a = (ArrayListType *)malloc(sizeof(ArrayListType));
	a->length = 0;

    if(isEmpty(a))
        printf("list가 비어있습니다\n");
    else
        printf("list가 비어있지 않습니다\n");
    
    insert(a,0,10);
    insert(a,0,50);
    insert(a,2,30);
    display(a);

    if(isEmpty(a))
        printf("list가 가득 차 있습니다\n");
    else
        printf("list가 가득 차 있지 않습니다\n");

    delete(a,1);
    delete(a,0);
    display(a);
    free(a);
}