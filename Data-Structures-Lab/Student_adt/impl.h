#include <stdio.h>
#include "adt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(student *s)
{
	printf("\nEnter the regno: ");
	scanf("%ld",&s->regno);

	printf("\nEnter the name: ");
	scanf(" %[^\n]",s->name);

	printf("\nEnter mark1,mark2,mark3: ");
	scanf("%f %f %f",&s->mark1,&s->mark2,&s->mark3);
}

void display(listADT l)
{
	for(int i=0;i<l.n;i++)
	{
		printf("\n%ld %s %f %c",l.arr[i].regno,l.arr[i].name,l.arr[i].total,l.arr[i].result);
	}
}

void initialise(listADT *l)
{
	l->n = 0;
}

void insertFront(listADT *l, student s)
{	
	l->n+=1; //Increasing the size of list
	int size = l->n;

	//Shifting the records to create space in the front
	for(int i=size-2;i>=0;i--)
		l->arr[i+1] = l->arr[i];

	l->arr[0] = s; //Placing the record at the right location
}

void insertEnd(listADT *l, student s)
{
	l->n+=1;
	int size =l->n;
	l->arr[size-1] = s;
}

void insertRegNo(listADT *l, student s, int regNum)
{
	int location;
	int flag=0;
	for(int i=0; i<=l->n;i++)
	{
		if(l->arr[i].regno == regNum)
		{
			flag=1;
			location = i; //Storing the location of the required record
			break;
		}
	}

	if(flag==0)
	{
		printf("\nERROR: Regno not found.");
		return;
	}
	else
	{
		l->n+=1; //Increasing the size of list

		for(int i=l->n-2;i>location;i--)
		{
			l->arr[i+1] = l->arr[i];
		}

		l->arr[location+1] = s;
	}
}

listADT searchName(listADT l, char name[])
{
	int location;
	int flag =0;

	listADT name_list;
	initialise(&name_list);

	for(int i=0; i<=l.n;i++)
	{
		if(strcmp(l.arr[i].name,name)==0)
		{
			insertEnd(&name_list,l.arr[i]);
		}
	}
	
	return name_list;
}

void Delete(listADT *l, int regNum)
{
	int location;
	int flag=0;
	for(int i=0; i<=l->n;i++)
	{
		if(l->arr[i].regno == regNum)
		{
			flag=1;
			location = i; //Storing the location of the required record
			break;
		}
	}
	
	if(flag==0)
	{
		printf("\nERROR: Regno not found. Could not delete.");
		return;
	}
	
	else
	{
		for(int i=location+1;i<l->n;i++)
			l->arr[i-1] = l->arr[i];

		l->n-=1; //Reducing the size of list by 1
		printf("\nSuccessfully deleted the record! ");
	}
}

void computeResult(listADT *l)
{
	for(int i=0;i<l->n;i++)
	{
		/*Here P denotes pass and F denotes fail*/
		l->arr[i].total = l->arr[i].mark1 + l->arr[i].mark2 + l->arr[i].mark3;

		if(l->arr[i].total>=180) //Since 60% of 300 = 180
			l->arr[i].result = 'P';

		else
			l->arr[i].result = 'F';
	}
}

student* listResult(listADT l)
{
	/*Function to list the students who have passed*/
	/*Function returns a pointer to the array of structures containing the details of students who have passed*/
	student *s = (student*) malloc(sizeof(student));
	int k=0;

	for(int i=0;i<l.n;i++)
	{
		if(l.arr[i].result=='P')
		{
			*(s+k) = l.arr[i];
			k++;
			s = realloc(s,(k+1)*sizeof(student));
		}
	}
	
	strcpy((s+k)->name ,"NULL"); //To mark the termination of the array
	return s;
}

int listClass(listADT l)
{
	/*Greater than 70% marks is considered as first class
	Therefore total should be greater than 210 (0.7*300 = 210)*/
	int count = 0;
	for(int i=0;i<l.n;i++)
	{
		if(l.arr[i].total>=210)
			count++;
	}

	return count;
}
