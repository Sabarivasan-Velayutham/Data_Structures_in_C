#include "impl.h"
#include<stdlib.h>
int main()
{
    struct expTree *t=(struct expTree*)malloc(sizeof(struct expTree));
    char arr[100]="45*6+";
    char *c=arr;

    t->st=(struct AddrStackADT *)malloc(sizeof(struct AddrStackADT));
    t->node=(struct Node *)malloc(sizeof(struct Node));
    t->st->top=-1;

    construct(t,c);
    infix(t->st->arr[t->st->top]);
    printf("\n");

    prefix(t->st->arr[t->st->top]);
    printf("\n");
    
    postfix(t->st->arr[t->st->top]);

}