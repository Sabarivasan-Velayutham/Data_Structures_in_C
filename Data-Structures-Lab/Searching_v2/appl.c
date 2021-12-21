#include<stdio.h>
#include<stdlib.h>
#include "impl.h"


int main()
{
	int arr[100],n,x=0;
	int choice,temp,output;
	struct numberADT *N;
	N=(struct numberADT*)malloc(sizeof(struct numberADT));
	
	int ans[10][2];

	init(N);
	
	printf("Enter array elements:");
	for(int i=0;i<N->size;i++)
	{
		scanf("%d",&N->arr[i]);
	}
	
	display(N);
	
	printf("\nMenu\n1.Second Occurence\n2.Frequncy\n3.2 List same or not\n4.Pair of elements with a given difference");
	printf("\nEnter choice:");
	choice=0;
	scanf("%d",&choice);
	
	while(choice>=1 && choice<=4)
	{
		if(choice==1)
		{
			printf("Enter Element to be searched:");
			scanf("%d",&temp);
			output = secondElement(N,temp);
			if(output == -1)
				printf("No element found");
			else
				printf("Position of the second element is %d",output);
		}
		else if(choice==2)
		{
			printf("Enter Element who's frequency to be found:");
			scanf("%d",&temp);
			output = frequency(N,temp);
			if(output == 0)
				printf("No element found");
			else
				printf("Frequency is %d",output);
		}
		else if(choice==3)
		{
			struct numberADT *N1;
			N1=(struct numberADT*)malloc(sizeof(struct numberADT));
			printf("Enter second array elements:");
			for(int i=0;i < N->size;i++)
			{
				scanf("%d",&(N->arr[i]));
			}
			isSame(N,N1);
		}
		else if(choice ==4)
		{
			printf("Enter the difference:");
			scanf("%d",&temp);
			x=0;
			difference(N,ans,temp,&x);
			
			printf("\nThe Pairs are :");
			for(int i=0;i<x;i++)
				printf("[%d %d]\n",ans[i][0],ans[i][1]);
		}
		
		printf("\nEnter choice:");
		scanf("%d",&choice);
	}
}

int secondElement(struct numberADT *N, int key)
{
	int front=0,last=N->size,temp;
	
	sort(N->arr,N->size);
	
	while(front<=last)
	{
		temp=(front+last)/2;
		if(N->arr[temp]==key)
		{
			if(N->arr[temp-1]==key)
				return temp-1;
			else if(N->arr[temp]==key)
				return temp+1;
		}
		else if(key<N->arr[temp])
			last=temp-1;
		else
			front=temp+1;
	}
	return -1;
}

int frequency(struct numberADT *N,int key)
{
	int count=0,i=0;
	for(i=0;i<N->size;i++)
		if(N->arr[i]==key)
			count++;
	return count;
}


void isSame(struct numberADT *N1,struct numberADT *N2)
{
	sort(N1->arr,N1->size);
	sort(N2->arr,N2->size);
	
	int i=0,temp=0;
	
	if(N1->size == N2->size)
		for(i=0;i<N1->size;i++)
			if(N1->arr[i]!=N2->arr[i])
			{
				printf("Both list of elements are not same");
				temp=1;
				break;
			}
	if(temp==0)
		printf("Both list are Same");
}
	
void difference(struct numberADT *N,int ans[10][2], int key,int *x)
{
	
	sort(N->arr,N->size);
	*x=0;
	for(int i=0;i<N->size;i++)
		for(int j=i+1;j<N->size;j++)
			if(N->arr[i]-N->arr[j]==key || N->arr[j]-N->arr[i]==key)
			{
				
				ans[*x][0]=N->arr[i];
				ans[*x][1]=N->arr[j];
				(*x)++;
			}
	
}





	
