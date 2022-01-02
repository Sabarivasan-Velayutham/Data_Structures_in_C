

#include "adt.h"
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void insertend(struct poly *h,int coeff,int exp)
{
    struct poly *temp=(struct poly *)malloc(sizeof(struct poly));
    temp->coeff=coeff;
    temp->exp=exp;
    if(h->next==NULL)
    {
        temp->next = h->next;
        h->next = temp;
    }

    else
    {
        struct poly *ptr = h->next;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        temp->next=NULL;
        ptr->next=temp;
    }
}

struct poly * addition(struct poly *h1 , struct poly *h2)
{
    struct poly *p1,*p2;
    struct poly *p3=(struct poly *)malloc(sizeof(struct poly));
    p1=h1;
    p2=h2;

    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->exp>p2->exp)
        {
            insertend(p3,p1->coeff,p1->exp);
            p1=p1->next;
        }

        else if(p1->exp<p2->exp)
        {
            insertend(p3,p2->coeff,p2->exp);
            p2=p2->next;
        }
        
        else
        {
            insertend(p3,p2->coeff+p1->coeff,p2->exp);
            p2=p2->next;
            p1=p1->next;
        }
    }

    if(p1!=NULL)
    {
        while(p1!=NULL)
        {
            insertend(p3,p1->coeff,p1->exp);
            p1=p1->next;
        }
    }

    if(p2!=NULL)
    {
        while(p2!=NULL)
        {
            insertend(p3,p2->coeff,p2->exp);
            p2=p2->next;
        }
    }
    return p3;
}

struct poly * multiply(struct poly *h1,struct poly *h2)
{
    struct poly *p1,*p2;
    struct poly *p3=(struct poly *)malloc(sizeof(struct poly));
    p1=h1;
    p2=h2;
    while(p1!=NULL)
    {
        while(p2!=NULL)
        {
            insertend(p3,(p1->coeff)*(p2->coeff),p1->exp+p2->exp);
            p2=p2->next;
        }
        p1=p1->next;
        p2=h2;
    }
return p3;
}

int degree(struct poly *header)
{
    int max=header->next->exp;struct poly *ptr=header;
    while(ptr!=NULL)
    {
        if(ptr->exp>max)
            max=ptr->exp;
            
        ptr=ptr->next;
    }
 return max;
}

struct poly * simplify(struct poly *h1)
{
    struct poly *p1,*p3=(struct poly *)malloc(sizeof(struct poly));;
    int n=degree(h1);
    for(int i=n;i>=0;i--)
    {
    p1=h1;int m=0;;
    while(p1!=NULL)
    { 
        if(p1->exp==i)
            m=m+p1->coeff;
        p1=p1->next;
    }
    insertend(p3,m,i);
 }
return p3;
}

int evaluate(struct poly *h )
{
    printf("\nenter value of x : ");
    int x;
    scanf("%d",&x);
    int sum=0;
    struct poly *ptr=h->next;
    while(ptr!=NULL)
    {
        sum+=ptr->coeff*pow(x,ptr->exp);
        ptr=ptr->next;
    }
    return sum;
}

void display(struct poly *header)
{
    struct poly *ptr=header->next;
    if(header->next==NULL)
    {printf("empty...");}

    else
    {
        while(ptr!=NULL)
        {
            printf("%d x^%d ,",ptr->coeff,ptr->exp);
            ptr=ptr->next;
        }
    }
    printf("\n");
}