#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode* llink;
    struct ListNode* rlink;
}listNode;

typedef struct LinkedList{
    listNode* head;
    int length;
}linkedList;


void insertFirst(linkedList *L, element x){

    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x; // 실습 오타 newNode.data
    if(L->head == NULL){
        newNode->rlink = NULL;
        newNode->llink = NULL;
        L->head = newNode;
    }
    else{
        newNode->llink = NULL;
        newNode->rlink = L->head;
        newNode->rlink->llink = newNode;
        L->head = newNode;
    }
    L->length++;

}

void insertLast(linkedList* L, element x){

    listNode* newNode;
    listNode* temp; // 새로운 메모리가 필요한게 아닌 주소를 가지기위해 준거라 따로 malloc 안해줘도됨
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x; // 실습 오타 newNode.data
    newNode->rlink = NULL;
    if(L->head == NULL){
        newNode->llink = NULL;
        L->head = newNode;
    }
    else{
        temp = L->head;
        while(temp->rlink != NULL){
            temp = temp->rlink;
        }
        newNode->llink = temp;
        temp->rlink =  newNode;
    }
    L->length++;

}

void insert(linkedList* L, listNode* pre, element x){

    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    if(L->head == NULL){
        newNode->rlink = NULL;
        newNode->llink = NULL;
        L->head = newNode;
    }
    else if(pre == NULL){
        newNode->llink = NULL;
        newNode->rlink = L->head;
        L->head = newNode;
    }
    else{
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        if(newNode->rlink != NULL){
            newNode->rlink->llink = newNode;
        }
    }

}

int delete(linkedList* L, listNode* p){

    if(L->head == NULL)
        return FALSE;
    if(p == NULL)
        return FALSE;
    if(p->llink == NULL){
        L->head = p->rlink;
    }
    else{
        p->llink->rlink = p->rlink;
    }
    if(p->rlink != NULL){
        p->rlink->llink = p->llink;
    }
    free(p);
    L->length--;
    return TRUE;

}