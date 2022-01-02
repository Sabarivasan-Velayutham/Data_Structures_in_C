#include "impl.h"

int main()
{
    struct BST *t = NULL;

    t=insert(t,29);
    t=insert(t,23);
    t=insert(t,4);
    t=insert(t,13);
    t=insert(t,39);
    t=insert(t,31);
    t=insert(t,45);
    t=insert(t,56);
    t=insert(t,49);

    inorder(t);
    printf("-----------------------\n") ;

    // levelorder(t) ; 
    // printf("-----------------------\n") ;
    
    // modified inorder function
    int arr[20] ;
    int *n = (int *)malloc(sizeof(int)) ; 
    mod_inorder(t, arr, n) ; 

    for (int i = 0 ; i < *n ; i++)
        printf("%d ",arr[i]) ; 
    printf("\n-----------------------\n") ;

    // printing minimum value in tree  
    printf("\nMinimum value : %d ", findmin(t) )  ;
    printf("\n-----------------------\n") ; 

    //saerch for an element
    // struct BST *temp = (struct BST *)malloc(sizeof(struct BST));
    // temp = NULL; 
    // struct BST *temp2 = NULL;
    find(t, 13) ;
    find(t, 3) ;
    printf("\n-----------------------\n") ;

    //delete a node 

    printf("\nFirst deletion\n") ;
    delete(t,56) ; 
    inorder(t) ;
    printf("\n-----------------------\n") ; 

    printf("\nSecond deletion\n") ;
    delete(t,49) ;
    inorder(t) ; 
    printf("\n-----------------------\n") ;
    
    printf("\nThird deletion\n") ;
    delete(t,100) ;
    inorder(t) ;   
    printf("\n-----------------------\n") ;
}