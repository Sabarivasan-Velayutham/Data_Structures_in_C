#include<stdio.h>
#include<stdlib.h>

typedef struct Hash
{
	int ht[100];
	int sz;
}hash;

void init(hash *h,int x)
{
	h->sz = x;
	for(int i=0;i<h->sz;i++) h->ht[i]=0;
}

void insert(hash *h,int x)
{
	int probes = 0  ; 
    int h1 = x%(h->sz);
    int h2 = 7-(x%7) ;
    int temp = h1 ; 
    do 
    {
        if (!h->ht[h1]) 
        {
            h->ht[h1] = x ;
            break ; 
        }
        else
        {
            probes++;
            h1 = (h1+probes*h2)%(h->sz); 
        } 
    }
    while(temp!=h1) ;
    printf("probes : %d\n",probes) ;  
}

void display(hash *h)
{
	for (int i = 0 ; i < h->sz ; i++)
    {
        if (h->ht[i]==0) printf("%d->no element ...\n",i) ; 
        else printf("%d->%d\n",i,h->ht[i]);
    }
}

void find(hash *h,int x)
{
	int probes = 0  ; 
    // int ind = x%(h->sz);
    int h1 = x%(h->sz);
    int h2 = 7-(x%7) ;
    int temp = h1 ; 
    do 
    {
        if (h->ht[h1]==x) 
        {
            printf("eleement found\n");
            // h->ht[h1] = x ;
            break ; 
        }
        else
        {
            probes++;
            h1 = (h1+probes*h2)%(h->sz);
            // ind = (temp+probes*probes)%(h->sz) ; 
        } 
    }
    while(temp!=h1) ;
    printf("probes : %d\n",probes) ;  
}

void doublehash(hash *h,int x)
{
	int probes = 0  ; 
    int ind = x%(h->sz);
    int temp = ind ; 
    do 
    {
        if (!h->ht[ind]) 
        {
            h->ht[ind] = x ;
            break ; 
        }
        else
        {
            probes++;
            // ind = (temp+probes*probes)%(h->sz) ; 
        } 
    }
    while(temp!=ind) ;
    printf("probes : %d\n",probes) ;  
}

int main(void) 
{
    // 23, 45, 69, 87, 48, 67, 54, 66,53
    // 0 →67
    // 1 →53
    // 2 →
    // 3 →23
    // 4 →54
    // 5 →45
    // 6 →66
    // 7 →87
    // 8 →48
    // 9 →69
	hash *h = (hash *)malloc(sizeof(hash));
	init(h,10);

	insert(h,23);
	insert(h,45);
	insert(h,69);
	insert(h,87);
	insert(h,48);
    insert(h,67);
	insert(h,54);
	insert(h,66);
	insert(h,53);

	display(h);

	find(h,69);
    find(h,67); 

    find(h,10);
    find(h,20);
}