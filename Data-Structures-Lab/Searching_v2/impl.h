#include "adt.h"

void init(struct numberADT *N)
{
	printf("Enter size of array : ");
	scanf("%d",&(N->size));
}

void insertElements (struct numberADT *N, int x[])
{
	for(int i=0;i < N->size;i++)
		N->arr[i]=x[i];
}


int lsearchElement(struct numberADT *N, int key) 
{
	for(int i=0;i<N->size;i++)
		if(N->arr[i]==key)
			return i;
	return -1;
}

void sort(int arr[],int size)
{
	int i,j,temp;
	for (i=0;i<size; ++i) 
    {
        for (j=i+1; j<size; ++j)
        {
            if (arr[i]>arr[j]) 
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}


int bsearchElement(struct numberADT *N, int key)
{
	int front=0,last=N->size,temp;
	
	sort(N->arr,N->size);
	
	while(front<=last)
	{
		temp=(front+last)/2;
		if(N->arr[temp]==key)
			return temp;
		else if(key<N->arr[temp])
			last=temp-1;
		else
			front=temp+1;
	}
	return -1;
}


void display(struct numberADT *N)
{
	printf("Array elements are:");
	for(int i=0;i<N->size;i++)
		printf("%d ",N->arr[i]);
}

