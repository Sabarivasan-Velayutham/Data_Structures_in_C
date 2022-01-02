#include "queue.h"
#include "stack.h"
#include "adt.h"
#include<stdio.h>
#include<stdlib.h>

void create(city *c)
{
    printf("Enter the no of vertices:");
    scanf("%d",&c->vtx);
    int ch=1;
    do{
        char edge[2];
        printf("Enter edge:");
        scanf("%s",edge);
        c->adj[edge[0]-'A'][edge[1]-'A']=1;
        printf("\nWanna continue?");
        scanf("%d",&ch);
    }while(ch);
}

void dis(city *c)
{
    printf("\nAdjacency Matrix\n");
    for(int i=0;i<c->vtx;i++)
    {
        for(int j=0;j<c->vtx;j++)printf("%d ",c->adj[i][j]);
        printf("\n");
    }
}

qll *BFS(city *c,char x)
{
    int vis[100];
    for(int i=0;i<100;i++)  vis[i]=0; 

    qll *bfs = (qll *)malloc(sizeof(qll));
    bfs->f = bfs->r = NULL;
    qll *q = (qll *)malloc(sizeof(qll));
    q->f = q->r = NULL;

    enq(bfs,x-'A');
    vis[x-'A'] = 1;
    enq(q,x-'A');
    while(!isEmpty(q))
    {
        int uv = deq(q);
        for(int i=0;i<c->vtx;i++){
            if(!vis[i] && c->adj[uv][i])
            {
                vis[i] = 1;
                enq(bfs,i);
                enq(q,i);
            }
        }
    }
    return bfs;
}

void DFS(city *c,char x)
{
    printf("\nDFS\n");
    int vis[100];
    for(int i=0;i<100;i++)vis[i]=0;
    printf("%c ",x);
    vis[x-'A'] = 1;
    stack *st;
    st = NULL;
    push(&st,x-'A');
    while(!empty(st))
    {
        int uv = top(st);
        int f=0;
        for(int i=0;i<c->vtx;i++)
        {
            if(!vis[i] && c->adj[uv][i])
            {
                vis[i] = 1;
                printf("%c ",i+65);
                push(&st,i);
                f=1;
                break;
            }
        }
        if(f==0)pop(&st);
    }    
    printf("\n");
}