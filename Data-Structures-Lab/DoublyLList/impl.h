#include "adt.h" 
#include<stdio.h> 
#include<stdlib.h> 

void display(struct list *l) 
{ 
 struct list *ptr=l; 
 if(ptr==NULL) 
 { 
    printf("list empty"); 
 } 
 else 
 { 
    printf("\nheader<>"); 
    while(ptr!=NULL) 
    { 
    printf("%c<>",ptr->c); 
    ptr=ptr->next; 
    } 
 } 
} 

struct list *insertfront(struct list *l,char c) 
{ 
 struct list *temp=(struct list *)malloc(sizeof(struct list));  
 temp->c=c; 
  
 temp->next=l; 
 l=temp; 
 temp->prev=NULL; 
 return l; 
} 

void insertend(struct list *l,char c) 
{ 
 struct list *temp=(struct list *)malloc(sizeof(struct list));  
 temp->c=c; 
 struct list *l1=l; 
 while(l1->next!=NULL) 
 { 
 l1=l1->next; 
 } 
 temp->next=NULL; 
 l1->next=temp; 
 temp->prev=l1; 
  
} 

void insertmiddle(struct list *l,char c,char d) 
{ 
 struct list *temp=(struct list *)malloc(sizeof(struct list)); 
  temp->c=d; 
 struct list *l1=l; 
 while(l1!=NULL) 
 { 
    if(l1->c==c) 
    {  
    temp->next=l1->next; 
    l1->next=temp; 
    temp->prev=l1; 
    break; 
    } 
 l1=l1->next; 
 } 
} 

struct list * deletion(struct list *l,char d) 
{ 
 int flag=0; 
 if(l==NULL) 
 { 
 printf("list empty,deletion not possible"); 
 } 
 else 
 { 
 struct list *l1;l1=l; 
 while(l1!=NULL)
 { 
    if(l1->c==d) 
    { 
    flag=1; 
    break; 
    }   
 l1=l1->next; 
 } 

 if(flag==1) 
 { 
    if(l1==l) 
    {  
    l=l->next; 
    l->prev=NULL; 
    return l; 
 } 
 else if(l1->next==NULL) 
 { 
 l1->prev->next=NULL; 
 return l; 
 } 
 else 
 { 
 l1->prev->next=l1->next; 
 l1->next->prev=l1->prev; 
 return l; 
 } 
 } 
 if(flag==0) 
 { 
 printf("\nelement not found,deletion not possible");  } 
 } 
} 

void search(struct list *l,char c) 
{ 
 struct list *ptr=l;int index=1; 
 while(ptr!=NULL) 
 { 
    if(ptr->c==c) 
    { 
    printf("\nelement found at %d position ",index);  break; 
    } 
    index++; 
    ptr=ptr->next; 
 } 
}

void pal(struct list *l) 
{ 
 struct list *s,*e;s=l,e=l;int flag=0; 
 while(e->next!=NULL) 
 { 
 e=e->next; 
 } 
 while(s!=e && e!=s->prev) 
 { 
    if(s->c!=e->c) 
    { 
    flag=1; 
    } 
    s=s->next;e=e->prev; 
 } 
 if(flag==1) 
 { 
 printf("\nnot a palindrome"); 
 } 
 if(flag==0) 
 { 
 printf("\nit is a palindrome"); 
 } 
} 

void sep(struct list *l) 
{ 
 struct list *h1=NULL,*h2=NULL; 
 struct list *ptr=l; 
 while(ptr!=NULL) 
 { 
 if(ptr->c=='a' ||ptr->c=='e' ||ptr->c=='i' ||ptr->c=='o' ||ptr->c=='u' ) 
    h1=insertfront(h1,ptr->c); 
 else 
    h2=insertfront(h2,ptr->c); 
 ptr=ptr->next; 
 } 
printf("\nvowels:") ;display(h1);printf("\nconsonants:");display(h2); 
}

void swap(struct list *l,int k) 
{ 
 int i=1;struct list *ptr=l;struct list *l1,*l2; 
 while(ptr!=NULL) 
 { 
    if(i==k) 
    { 
    l1=ptr; 
    } 
    i++;
    l2=ptr; 
    ptr=ptr->next; 
 } 
 int j=i; 
 while(j!=i-k+1) 
 { 
    l2=l2->prev; 
    j--; 
 } 
 char q=l1->c; 
 l1->c=l2->c; 
 l2->c=q; 
} 
