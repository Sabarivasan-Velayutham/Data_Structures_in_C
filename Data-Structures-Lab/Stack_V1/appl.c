#include "impl.h"
#include <stdlib.h>

int main (void)
{
    struct Stack *s = (struct Stack *) malloc(sizeof( struct Stack)) ;  
    init(s, 3) ;  
    // struct node *n = (struct node *) malloc(sizeof(struct node)) ;
    push(s, 10) ; 
    push(s, 20) ; 
    push(s, 30) ; 
    push(s, 40) ; 
    gettop(s) ; 
    pop(s); 
    gettop(s) ;
    pop(s); 
    gettop(s) ;
    pop(s); 
    gettop(s) ; 

}