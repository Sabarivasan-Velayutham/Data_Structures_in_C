#include "impl.h"
#include<stdio.h>
#include<stdlib.h>

void path(city *c,char x,char y)
{
    qll *q = BFS(c,x);
    qll *ptr = q;
    
    int f=0;
    while(q->f)
    {
        if((q->f->data)==(y-'A'))
        {
            f=1;
            break;
        }
        q->f = q->f->nxt;
    }
    if(f)
    {
        printf("\nExists");
    }
    else printf("\nDoesnt Exist");
}

void concomp(city *c)
{
    int v[c->vtx];
    for(int i=0;i<c->vtx;i++)v[i]=0;
    int n = c->vtx;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            int flag=1;
            qll *q = BFS(c,(char)i+65);
            node *ptr;
            ptr = q->f;
            while(ptr)
            {
                if(v[ptr->data]==1)
                {
                    flag=0;
                    break;
                }
                else v[ptr->data]=1;
                ptr = ptr->nxt;
            }
            if(flag)
            {
                display(q);
                printf("\n");
            }
        }
    }
}

int main()
{
    city *c = (city *)malloc(sizeof(city));
    create(c);
    dis(c);
    printf("Path Checking:\n");
    path(c,'D','F');
    path(c,'F','B');
    printf("\n");
    printf("Connected Components:\n");
    concomp(c);
    return 0;
}