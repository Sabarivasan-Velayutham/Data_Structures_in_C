#include "impl.h"
#include <stdlib.h>

int main (void)
{
    struct Queue *q = (struct Queue *) malloc(sizeof( struct Queue)) ;
    init(q, 3) ;

    enqueue(q, 1) ; 
    enqueue(q, 2) ; 
    enqueue(q, 3) ; 
    enqueue(q, 4) ; 
    enqueue(q, 5) ;
    
    dequeue(q) ;
    dequeue(q) ;
    dequeue(q) ;
    dequeue(q) ;
    dequeue(q) ;
     
}