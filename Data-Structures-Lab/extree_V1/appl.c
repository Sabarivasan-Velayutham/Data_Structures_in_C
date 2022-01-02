#include "impl.h"
#include<stdlib.h>
int main()
{
    struct Node*t1,*t2,*t3;
    struct AddrStackADT *st=(struct AddrStackADT*)malloc(sizeof(struct AddrStackADT));

    st->size=3;
    st->top=-1;

    t1=(struct Node*)malloc(sizeof(struct Node));
    t2=(struct Node*)malloc(sizeof(struct Node));
    t3=(struct Node*)malloc(sizeof(struct Node));

    t1->ch='a';
    t1->left=t1->right=NULL;
    push(t1,st);

    t2->ch='b';
    t2->left=t2->right=NULL;
    push(t2,st);  

    t3->ch='c';
    t3->left=t3->right=NULL;
    push(t3,st); 
           
    display(st);    
    return 0;  
}