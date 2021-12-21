#include "impl.h"
#include <stdlib.h>

int main (void)
{
    struct Queue *q = (struct Queue *) malloc(sizeof( struct Queue)) ;
    init(q, 3) ;
    struct Job j ; 
    // struct Job *j = (struct Job *) malloc(sizeof( struct Job)) ;

    j. no = 1 ; 
    j. cputime = 10 ; 
    enqueue(q, j) ; 

    j. no = 2 ; 
    j . cputime = 20 ;
    enqueue(q, j) ; 

    j . no = 3 ; 
    j . cputime = 30 ;
    enqueue(q, j) ;

    j . no = 4 ; 
    j . cputime = 40 ; 
    enqueue(q, j) ; 
    
    dequeue(q) ;
    dequeue(q) ;
    dequeue(q) ;
    dequeue(q) ;
    
}