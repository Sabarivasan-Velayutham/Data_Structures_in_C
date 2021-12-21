#include "impl.h"

int main()
{
    struct dictionary *d = NULL;

    struct wordMeaning w1,w2,w3,w4,w5,w6 ; 

    w1.word = "a" ; 
    w1.meaning = "a-meaning" ; 
    d = insert(d, w1) ; 

    w3.word = "abc" ; 
    w3.meaning = "abc-meaning" ; 
    d = insert(d, w3) ;

    w5.word = "abcde" ; 
    w5.meaning = "abcde-meaning" ; 
    d = insert(d, w5) ; 

    w2.word = "ab" ; 
    w2.meaning = "ab-meaning" ; 
    d = insert(d, w2) ; 

    w4.word = "abcd" ; 
    w4.meaning = "abcd-meaning" ; 
    d = insert(d, w4) ; 

    w6.word = "abcdef" ; 
    w6.meaning = "abcdef-meaning" ; 
    d = insert(d, w6) ; 

    display(d);
    printf("\n-----------------------\n") ;

    search(d, "ab") ; 
    printf("\n-----------------------\n") ;
    search(d, "abcdef") ; 
    printf("\n-----------------------\n") ;
    search(d, "xyz") ; 
    printf("\n-----------------------\n") ;
}