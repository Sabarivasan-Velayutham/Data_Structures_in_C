#include "adt.h"
#include <stdlib.h>
#include<stdio.h>
struct Node *create(char c)
{
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->ch=c;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void construct(struct expTree *t,char *pexp)
{
    while(*pexp!='\0')
    {
        if(*pexp=='+'||*pexp=='*'||*pexp=='-'||*pexp=='/')
        {
            struct Node *n1=pop(t);
            struct Node *n2=pop(t);
            struct Node *n=create(*pexp);
            n->right=n1;
            n->left=n2;
            push(t,n);
        }
        else
        {
            push(t,create(*pexp));
        }
        pexp++;
    }
}
void push(struct expTree *t,struct Node*temp)
{
    t->st->top++;
    t->st->arr[t->st->top]=temp;

}
   
struct Node* pop(struct expTree*t)
{
    return t->st->arr[t->st->top--];
}

void infix(struct Node*n)
{
    if(n->left!=NULL)
        infix(n->left);
    printf("%c ",n->ch);
    if(n->right!=NULL)
        infix(n->right);    
}

void prefix(struct Node*n)
{
    printf("%c ",n->ch);
    if(n->left!=NULL)
        prefix(n->left);
    if(n->right!=NULL)
        prefix(n->right);
}

void postfix(struct Node*n)
{
    if(n->left!=NULL)
        postfix(n->left);
    if(n->right!=NULL)
        postfix(n->right);
    printf("%c ",n->ch);
}