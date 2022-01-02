

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

void display(struct Queue *q)
{
    if (isEmpty(q))
        printf("\nQueue is empty ....") ; 

    else 
    {
        for (int i = q -> f ; i <= q -> r ; i++)
        { 
            printf("\nJob no. : %d", (q -> arr[i]). no) ;
            printf("\nJob cpu_time : %d", (q -> arr[i]). cputime) ;
            printf("\n..................................") ; 
        }
    }
}

void enqueue (struct Queue *q , struct Job j )
{
    if (isFull(q))
        printf("\nQueue is full ....") ; 
    else
    {
        if (q -> f == -1 )
            q -> f = 0 ; 
        q -> r++ ; 
        q -> arr[q -> r] = j ; 
        printf("\nAdded job no. : %d", (q -> arr[q -> r]). no) ;
        printf("\nAdded job cpu_time : %d", (q -> arr[q -> r] ). cputime) ; 
    }
} 

void dequeue (struct Queue *q )
{
    if (isEmpty(q))
        printf("\nQueue is empty ....") ; 
    else
    {
        printf("\nDeleted job no. : %d", (q -> arr[q -> f] ).no) ;
        q -> f++ ; 
        display(q) ;
        if (q -> f > q -> r)
            q -> f = q -> r = -1;
    }
     
} 
