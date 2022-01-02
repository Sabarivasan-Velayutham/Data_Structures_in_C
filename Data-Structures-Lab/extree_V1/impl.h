// #include "adt.h"
// #include <stdio.h>

// void init (struct Stack *s , int limit) 
// {
//     s -> size = limit ; 
//     s -> top = -1 ;  
// }

// int isFull(struct Stack *s) 
// {
//     if (s -> top < s-> size)
//         return 1 ; 
//     else
//         return 0 ; 
// }

// int isEmpty(struct Stack *s)
// {
//     if (s -> top != -1)
//         return 1 ; 
//     else
//         return 0 ; 
// }

// void push (struct Stack *s , struct node *n) 
// {
//     s->top++;
//     if (isFull(s)==0)
//     {
//         printf("\nStack is full ...") ; 
// 	s -> top-- ; 
//     }

//     else
//     {
//         s -> data[s -> top] = n ; 
//         // printf("\nData :  %d " , s -> data[s -> top]) ;
//     }
// } 

// void pop (struct Stack *s) 
// {
    
//     if (isEmpty(s)==0)
//         printf("\nStack is empty ...") ; 
//     else
//          s -> top-- ;
// } 

// int gettop(struct Stack *s)
// {
//     if (isEmpty(s)==0)
//         printf("\nStack is empty ...") ;
//     else 
//     	printf ("\nTop : %d"  , s -> data[s -> top] )  ; 
// }

// // void construct(extree *t, char *postfixexp) 
// // void inorder(extree *t) 
// // void preorder(extree *t) 
// // void postorder(extree *t) 

#include "adt.h"
#include <stdlib.h>
#include<stdio.h>
void push(struct Node *node,struct AddrStackADT *st)
{
    st->top++;
    st->arr[st->top]=node;
}
   
void pop(struct AddrStackADT *st)
{
    st->top--;
}

void display(struct AddrStackADT*st)
{
    int t=st->top;
    for(;t>=0;t--)
    {
        printf("%c\n",st->arr[t]->ch);
    }
}