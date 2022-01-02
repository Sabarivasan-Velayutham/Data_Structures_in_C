#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack *nxt;
}stack;

void push(struct stack **t,int x)
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = x;
    temp->nxt = *t;
    *t = temp;
}

int empty(struct stack *t)
{
    return t==NULL;
}

void pop(struct stack **t)
{
    if(!empty(*t))*t = (*t)->nxt;
}

int top(struct stack *t)
{
    if(!empty(t))
        return t->data;
}