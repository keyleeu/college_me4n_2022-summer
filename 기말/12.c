#include <stdio.h>

void com(int n){
    int i, x=0;
    for(i=0; i < n; i++){
        printf("1\n");
        for(j=0; j< i; j++)
            x = x+j;
            printf("2\n");
    }
}

void main(){
    com(7);