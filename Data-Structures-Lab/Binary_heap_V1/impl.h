#include "adt.h"
#include<stdio.h>

void init(struct priorityQueueADT *p,int s)
{
    p->size=s;
    p->ctptr=0;
    p->elt[p->ctptr]=-10;
}

void insert(struct priorityQueueADT *p,int d)
{
    p->ctptr++;
    p->elt[p->ctptr]=d;
    for(int i=p->ctptr;p->elt[i/2]>d;i=i/2)
    {
        p->elt[i]=p->elt[i/2];
        p->elt[i/2]=d;
    }
}

int delete(struct priorityQueueADT *p)
{
    int min=p->elt[1],child=1;
    p->elt[1]=p->elt[p->ctptr];
    p->ctptr--;
    for(int i=1;2*i<=p->ctptr;i=child)
    {
        child=2*i;
        if(p->elt[child]<p->elt[i]||p->elt[child+1]<p->elt[i])
        {
            if(p->elt[child+1]<p->elt[child])
                child++;
            int t=p->elt[i];
            p->elt[i]=p->elt[child];
            p->elt[child]=t;
        }
    }
    return min;
}

void display(struct priorityQueueADT *p)
{
    for(int i=1;i<=p->ctptr;i++)
    {
        printf("\t%d",p->elt[i]);
    }
}