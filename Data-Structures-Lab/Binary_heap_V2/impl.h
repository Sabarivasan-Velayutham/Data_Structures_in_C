#include "adt.h"
#include<stdio.h>
void init(struct priorityQueueADT *p,int s)
{
    p->size=s;
    p->ctptr=0;
    p->d[p->ctptr].sal_amt=-10;
}

void insert(struct priorityQueueADT *p,struct data d)
{
    p->ctptr++;
    p->d[p->ctptr]=d;
    for(int i=p->ctptr;p->d[i/2].sal_amt>d.sal_amt;i=i/2)
    {
        p->d[i]=p->d[i/2];
        p->d[i/2]=d;
    }
}

struct data del(struct priorityQueueADT *p)
{
    int child=1;
    struct data min=p->d[1];
    p->d[1]=p->d[p->ctptr];
    p->ctptr--;
    for(int i=1;2*i<=p->ctptr;i=child)
    {
        child=2*i;
        if(p->d[child].sal_amt<p->d[i].sal_amt||p->d[child+1].sal_amt<p->d[i].sal_amt)
        {
            if(p->d[child+1].sal_amt<p->d[child].sal_amt)
                child++;
            struct data t=p->d[i];
            p->d[i]=p->d[child];
            p->d[child]=t;
        }
    }
    return min;
}
void display(struct priorityQueueADT *p)
{
    for(int i=1;i<=p->ctptr;i++)
    {
        printf("(%c,%d)\t",p->d[i].emp_id,p->d[i].sal_amt);
    }
}