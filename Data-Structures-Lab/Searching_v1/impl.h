#include "adt.h"
#include <stdio.h>
#include <stdlib.h>

void init (struct numberADT *n)
{
    n-> size=10;
}

void insertElements(struct numberADT *n,int x[])
{
    for (int i = 0 ; i <10 ; i++)
    {
        n -> arr[i] = x[i] ; 
    }
}

int linearsearch(struct numberADT *n, int key)
{
    for (int i = 0 ; i<10 ; i++)
    {
        if ( n -> arr[i]==key)
            return i ; 
    }
    return -1 ; 
}

int binarysearch(struct numberADT *n, int key,int low , int high)
{
    if (low <= high)
    {
        int mid = (low+high)/2 ; 
        if (n -> arr[mid] == key)
            return mid ; 
        else if (n -> arr[mid] < key)
            return binarysearch(n,key,mid+1,high) ; 
        else
            return binarysearch(n,key,low,high-1) ;
    }
    return -1 ; 
}

void display(struct numberADT *n)
{
    for (int i = 0 ; i<10 ; i++)
        printf("%d ", n -> arr[i]) ; 
    printf("\n") ; 
}
    // • void insertElements (numberADT *N, int x[10])– To copy the elements from x to the 
    //                                                                             array in numberADT    