struct Queue
{
    int arr[50] ; 
    int f , r ,size; 
};

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
        printf("\nQueue is full ....\n") ; 
    else
    {
        if (q -> f == -1 )
            q -> f = 0 ; 
        q -> r++ ; 
        q -> arr[q -> r] = data ; 
        
       // printf("\nAdded element : %d", q -> arr[q -> r]) ; 
    }
} 

int dequeue (struct Queue *q )
{
    if (isEmpty(q))
    {
        // printf("\nQueue is empty ....") ;
        return 0 ;  
    }
    else
    {
        int ans = q -> arr[q -> f] ; 
        // printf("\nDeleted element : %d", ) ;
        q -> f++ ; 
        if (q -> f > q -> r)
            q -> f = q -> r = -1;
        return ans ; 
    }
} 

