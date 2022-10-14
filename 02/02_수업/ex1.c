#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int num;
    int x;
    int y;
    struct Listnode *link;
}listnode;

listnode* first;
listnode* cur;

void main(){
    srand(100);
    int i;
    for (int i = 0; i <100; i++)
    {
        if (i == 0){
            first = (listnode*)malloc(sizeof(listnode));
            first->num = i + 1;
            first->x = rand() % 10;
            first->y = rand() % 10;
            first->link = NULL;
            cur = first;
        }
        else{
            cur->link = (listnode*)malloc(sizeof(listnode));
            cur = cur->link;
            cur->num = i + 1;
            cur->x = rand() % 10;
            cur->y = rand() % 10;
            cur->link = NULL;
        }
    }

    cur = first;
    for (i = 0; i < 76; i++)
        cur = cur->link;

    printf("%d번째 노드의 (x, y) =(%d, %d)\n", cur->num, cur->x, cur->y);

}
// 결과값 자체는 for문에 대해서 기존 값 자체가 달라질수 있기 떄문에 결과가 다르다고 많은 생각 할 필요 없다
