#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

void create(city *c)
{
    // int n ; 
    printf("enter no of vertices  : ");
    scanf("%d",&c->vtx);
    for (int i = 0  ; i < c->vtx ; i++) 
        for (int j = 0  ; j < c->vtx ; j++) c->adj[i][j] = 0 ; 
    int ch = 1 ;
    char edge[2] ; 
    do
    {
        printf("enter vertices : ");
        scanf("%s",edge);
        c->adj[edge[0]-'A'][edge[1]-'A'] = 1 ; 
        printf("wanna continue ..");
        scanf("%d",&ch);
    }
    while(ch);
}

void display(city *c)
{
    for (int i = 0  ; i < c->vtx ; i++) 
    {
        for (int j = 0  ; j < c->vtx ; j++) printf("%d ",c->adj[i][j])  ;
        printf("\n");
    }
}

void bfs(city *c , char x )
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    init(q,50);
    int visit[50];
    for (int i = 0 ; i <50 ; i++) visit[i] = 0 ;
    printf("%c ",x);
    visit[x-'A'] = 1 ; 
    enqueue (q , x-'A' ) ; 
    while(!isEmpty(q))
    {
        int y = dequeue(q) ; 
        for (int i = 0 ; i < c->vtx ; i++)
        {
            if (!visit[i] && c->adj[y][i])
            {
                visit[i] = 1 ; 
                printf("%c ",65+i);
                enqueue(q,i); 
            }
        }
    }
    printf("\n");
}

void dfs(city *c,char x)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    initStack(s,50);
    int visit[50];
    for (int i = 0 ; i <50 ; i++) visit[i] = 0 ;
    printf("%c ",x);
    visit[x-'A'] = 1 ; 
    push(s,x-'A') ; 
    printf("100");
    while(isStackEmpty(s)!=0)
    {
        printf("200");
        int y = gettop(s) ;
        int flag = 0 ;  
        for (int i = 0 ; i < c->vtx ; i++)
        {
            // int flag = 0 ; 
            if (!visit[i] && c->adj[y][i])
            {
                visit[i] = 1 ; 
                printf("%c ",65+i);
                push(s,i); 
                flag = 1 ; 
                break;
            }
            // else pop(s) ; 
        }
        if (flag == 0 ) pop(s) ; 
    }
    printf("\n");
}
