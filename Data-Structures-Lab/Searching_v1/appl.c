#include "impl.h"

int main()
{
    struct numberADT *n ;
    n=(struct numberADT*)malloc(sizeof(struct numberADT));
    int list[] = {0,1,2,3,4,5,6,7,8,9} ; 
    init(n) ; 
    insertElements(n, list) ; 
    printf("Display elements...\n") ; 
    display(n) ; 

    printf("\n%d",linearsearch(n, 3)) ;
    printf("\n%d",linearsearch(n, 9)) ;
    printf("\n%d",linearsearch(n, 10)) ;

    printf("\n----------------------------------");

    printf("\n%d",binarysearch(n, 3,0,9)) ;
    printf("\n%d",binarysearch(n, 9,0,9)) ;
    printf("\n%d",binarysearch(n, 10,0,9)) ;
    
}