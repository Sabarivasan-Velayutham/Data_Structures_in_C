#include "impl.h"
#include <stdlib.h>

int main (void)
{
    struct Stack *s1 = (struct Stack *) malloc(sizeof( struct Stack)) ;  
    struct Stack *s2 = (struct Stack *) malloc(sizeof( struct Stack)) ; 

    init(s1, 5) ;
    init(s2, 5) ;

    push(s1, 5) ; 
    push(s1, 4) ; 
    push(s1, 3) ; 
    push(s1, 2) ;
    push(s1, 1) ;  

    push(s2, 10) ; 
    push(s2, 9) ; 
    push(s2, 8) ; 
    push(s2, 7) ;
    push(s2, 6) ;

    int score = 0 , count =0 , max = 20 , temp ; 
    while (score < max)
    {
        printf("\nChoose Stack 1 or Stack 2 : ") ; 
        scanf ("%d" , &temp) ; 
        if (temp==1)
        {
            count++ ; 
            score += gettop(s1) ; 
            pop(s1) ; 
        }

        else if (temp==2)
        {
            count++ ;
            score += gettop(s2) ; 
            pop(s2) ; 
        }  
    }

    printf("Score : %d",count) ; 
}