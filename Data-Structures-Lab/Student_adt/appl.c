#include "impl.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char option; //To store y/n
	listADT l;
	int choice;
	student s;
	initialise(&l);

	int regnum;
	listADT name_list;
	char name[25];
	student *ps;

	do
	{
		printf("\n\t\t\tAPPLICATION MAIN MENU");
		printf("\n1)Add a record at the front.");
		printf("\n2)Add a record at the end.");
		printf("\n3)Add a record after a register no.");
		printf("\n4)List all the students.");
		printf("\n5)List the details of students based on name.");
		printf("\n6)Delete a record using regno.");
		printf("\n7)List the students who have passed.");
		printf("\n8)Print the no of students who have scored first class marks.");
		printf("\n9)Exit program");

		/*computeResult() is used implicitly after record
		addition to generate results*/
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: input(&s);
				insertFront(&l,s);
				computeResult(&l);
				break;

			case 2: input(&s);
				insertEnd(&l,s);
				computeResult(&l);
				break;

			case 3: printf("\nEnter the register number after which record is to be added: ");
				scanf("%d",&regnum);
				input(&s);
				insertRegNo(&l,s,regnum);
				computeResult(&l);
				break;

			case 4: printf("\nList of students: ");
				display(l);
				break;

			case 5: printf("\nEnter a name: ");
				scanf(" %[^\n]",name);
				name_list = searchName(l,name);
				printf("\nThe generated name list is: ");
				display(name_list);
				break;
			case 6: printf("\nEnter the register number to be deleted: ");
				scanf("%d",&regnum);
				Delete(&l,regnum);
				break;

			case 7: ps = listResult(l);
				printf("\nList of students who have passed are:");
				while(strcmp(ps->name,"NULL")!=0)
				{
				printf("\n%ld %s %f %c",ps->regno,ps->name,ps->total,ps->result);
				ps++;
				}
				break;
				
			case 8: printf("\nThe no of students who have scored first class marks = %d",listClass(l));
				break;
			case 9: exit(0);
			default: printf("\nWrong choice. Try again.");
		}//End of switch..case

		printf("\n\nDo you want to continue(Enter y/n)? ");
		scanf(" %c",&option);

	}while(option == 'y'); //End of do..while
}
