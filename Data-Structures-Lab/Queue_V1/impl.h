
#include "adt.h"
#include <stdio.h>

void init (struct Queue *q , int limit) 
{
    q -> size = limit ; 
    q -> f = -1 ; 
    q -> r = -1 ; 
}

int isFull(struct Queue *q)
{
    if ( q -> r == q -> size-1)
        return 1 ; 
    return 0 ; 
} 

int isEmpty(struct Queue *q)
{
    if ( q -> f == -1 )
        return 1 ; 
    return 0 ;
}  

void enqueue (struct Queue *q , int data )
{
    if (isFull(q))
        printf("\nQueue is full ....") ; 
    else
    {
        if (q -> f == -1 )
            q -> f = 0 ; 
        q -> r++ ; 
        q -> arr[q -> r] = data ; 
        printf("\nAdded element : %d", q -> arr[q -> r]) ; 
    }
} 

void dequeue (struct Queue *q )
{
    if (isEmpty(q))
        printf("\nQueue is empty ....") ; 
    else
    {
        printf("\nDeleted element : %d", q -> arr[q -> f]) ;
        q -> f++ ; 
        if (q -> f > q -> r)
            q -> f = q -> r = -1;
    }
} 
