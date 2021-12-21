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

void quad_insert(hash *h,int x)
{
	int probes=0;
	int si = x%(h->sz);
	int idx=si,v=si;
	do{
		if(!h->ht[si])
        {
			h->ht[si]=x;
			break;
		}
		else
        {
            probes++;
			si = (v+probes*probes)%(h->sz);
		}
	}while(idx!=si);

	printf("probes:%d\n",probes);
}

void doubl_insert(hash *h,int x)
{
	int probes=0;
	int h1 = x%(h->sz);
    int h2 = 7-(x%7) ; 

        if (!h->ht[h1])  h->ht[h1] = x ;  
        
        // if collision occurs
        else
        {
            int i = 1;
            while (1) 
            {
                // get newIndex
                int newIndex = (h1 + i * h2) % h->sz;
                if (!h->ht[newIndex] ) 
                {
                    h->ht[newIndex] = x;
                    break;
                }
                i++;
            }
	    }

	printf("probes:%d\n",probes);
}


void display(hash *h)
{
	for(int i=0;i<h->sz;i++)
    {
		if(h->ht[i]!=0)  printf("%d->%d\n",i,h->ht[i]);
		else             printf("%d->No element\n",i);
	}
}

int find(hash *h,int x)
{
	int probes=0;
	int si = x%(h->sz);
	int idx=si;
	do{
		if(h->ht[si]==x)
			return 1;
		else
        {
			si = (si+1)%(h->sz);
			probes++;
		}
	}while(idx!=si);

    return 0;
}

void range(hash *h,int l,int r)
{
    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        cnt+=find(h,i);
    }
    printf("\ncount : %d\n",cnt);
}


int main(void) 
{
	hash *h1,*h2;
	h1 = (hash *)malloc(sizeof(hash));
	init(h1,10);
    h2 = (hash *)malloc(sizeof(hash));
	init(h2,10);

	quad_insert(h1,23);
	quad_insert(h1,45);
	quad_insert(h1,69);
	quad_insert(h1,87);
	quad_insert(h1,48);
    quad_insert(h1,67);
	quad_insert(h1,54);
	quad_insert(h1,66);
	quad_insert(h1,53);

//     (Quadratic Probing)
        // 0 →
        // 1 →67
        // 2 →53
        // 3 →23
        // 4 →54
        // 5 →45
        // 6 →66
        // 7 →87
        // 8 →48
        // 9 →69


    display(h1) ; 

    printf("\n--------------------------------\n") ; 

    doubl_insert(h2,23);
	doubl_insert(h2,45);
	doubl_insert(h2,69);
	doubl_insert(h2,87);
	doubl_insert(h2,48);
    doubl_insert(h2,67);
	doubl_insert(h2,54);
	doubl_insert(h2,66);
	doubl_insert(h2,53);

    // (Double Hashing)
    //     0 →67
    //     1 →
    //     2 →53
    //     3 →23
    //     4 →54
    //     5 →45
    //     6 →66
    //     7 →87
    //     8 →48
    //     9 →69

    
	display(h2);
    range(h1,40,60);
}