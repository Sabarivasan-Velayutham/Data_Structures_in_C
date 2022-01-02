#include "impl.h"
#include<stdlib.h>
#include<ctype.h>

int evaluate(struct Node *n)
{
    if(!isalnum(n->ch))
    {
        if(n->ch=='+')
            return evaluate(n->left) + evaluate(n->right);
        else if(n->ch=='-')
            return evaluate(n->left) - evaluate(n->right);
        else if(n->ch=='*')
            return evaluate(n->left) * evaluate(n->right);
        else
            return evaluate(n->left) / evaluate(n->right);
    }
    return n->ch-'0';
}

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
    printf("\n%d",evaluate(t->st->arr[t->st->top]));

}