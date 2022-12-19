#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node 
{
	char name[20];
	char Address[100];
	int ID;
	int birth_day;
	int birth_month;
	int birth_year;
	char Phone_number[15];
	int Science_grade ;

	struct node * link;
}node;

node * head = NULL;

void voidAddNewSt(void);
void voidPrintList(void);
void voidDeleteSt(int IDCpy);
void voidStudentEdit(int IDCpy);
void voidSetStudentGrades(void);
void voidRank(void);
void voidHelpPrint(int IDCpy);


int main()
{
	
	int input =0,IDToDelete=-1,IDToEdit=-1,flag=0;
	
	while(1)
	{
		printf("#######################");
		printf("choose one of the following options:\n");
		printf("To add a New Student                                  Enter '1'\n");
		printf("To view all Students                                  Enter '2'\n");
		printf("To Delete a  Student                                  Enter '3'\n");
		printf(" To Update Student grades                             Enter '4'\n");
		printf("To Update Student                                     Enter '5'\n");
		printf("To print the  the Students in ascending order         Enter '7'\n");
		printf("To Exist the School App                               Enter '6'\n");


		scanf("%d",&input);
		switch(input)
		{
			case 1:
				voidAddNewSt();
				break;

			case 3:
				printf("Enter the ID of Student which you want to delete\n");
				scanf("%d",IDToDelete);
				voidDeleteSt(IDToDelete);
				break;

			case 2:
				voidPrintList();
				break;

			case 4:
				voidSetStudentGrades();
				break;

			case 5:
				printf("Enter the ID of Student which you want to Edit\n");
				scanf("%d",IDToEdit);
				voidStudentEdit(IDToEdit);

				break;

			case 6:
				flag=1;
				break;
			
			case 7:
				voidRank();
				break;
				

			default:
				printf("Wrong input\n");

				break;
		}

		if(flag==1)
		{
		break ;
		}		
	}
	



	return 0;
}
void voidSetStudentGrades(void)
{
	node * current = head;
	while(current!=NULL)
	{
		printf("Please insert the grade of Student with ID %d\n",current->ID);
		scanf("%d",&current->Science_grade);
		current=current->link;
	}
}
void voidPrintList(void)
{
	node * current = head;
	if(current==NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		
		while(current!=NULL)
		{
			printf("Name: %s\n",current->name);
			printf("ID : %d\n",current->ID);
			printf("Phone number :%s\n",current->Phone_number);
			printf("birth_day : %d / %d / %d\n",current->birth_day,current->birth_month,current->birth_year);
			printf("The grade of Computer science = %d \n\n",current->Science_grade);
			current = current->link;
		}
	
	}
}
void voidStudentEdit(int IDCpy)
{
	node * current = head;
	int flag =0;
	while(current!=NULL)
	{

		if(current->ID==IDCpy)
		{
		
		printf("Enter The new name: ");		
		scanf("%s",&current->name);
		printf("Enter The new Birth day the month then year: \n");
		scanf("%d",&current->birth_day);
		scanf("%d",&current->birth_month);
		scanf("%d",&current->birth_year);
		printf("Enter The new Phone number: ");		
		scanf("%s",&current->Phone_number);
		printf("Enter The new Address: ");		
		scanf("%s",&current->Address);
			flag=1;
			break;
		}

		current=current->link;

	}
	if(flag==0)
	{
		printf("Invalid ID or The list is empty \n");
	}
}
void voidDeleteSt(int IDcpy)
{
	node * current = head;
	node * prevCurrent = current;
	int flag =0,count=0;
	while(current!=NULL)
	{

		if(current->ID==IDcpy)
		{
			if(count==0)
			{
				head=current->link;
				current->link=NULL;
				free(current);

				flag=1;
				break;
			}
			else
			{
				prevCurrent->link=current->link;
				current->link=NULL;
				free(current);


				flag = 1;
				break;
			}
		}
		count++;

		prevCurrent=current;
		current=current->link;

	}
	if(flag==0)
	{
		printf("Invalid ID or The list is empty \n");
	}
}
void voidAddNewSt(void)
{
	node * temp = (node *)malloc(sizeof(node));
	temp->Science_grade = -1;
	if(head==NULL)
	{
		head = temp ;
		temp -> link= NULL;

		printf("Enter your ID: ");
		scanf("%d",&temp->ID);

		printf("Enter your name: ");		
		scanf("%s",&temp->name);

		printf("Enter your age day the month then year: \n");
		scanf("%d",&temp->birth_day);
		scanf("%d",&temp->birth_month);
		scanf("%d",&temp->birth_year);
		

		printf("Enter your Phone number: ");		
		scanf("%s",&temp->Phone_number);

		printf("Enter your Address: ");		
		scanf("%s",&temp->Address);

	}
	else
	{
		temp->link = head;
		head = temp;
		printf("Enter your ID: ");
		scanf("%d",&temp->ID);
		printf("Enter your name: ");		
		scanf("%s",&temp->name);

		printf("Enter your age day the month then year: ");
		scanf("%d",&temp->birth_day);
		scanf("%d",&temp->birth_month);
		scanf("%d",&temp->birth_year);


		printf("Enter your Phone number: ");		
		scanf("%s",&temp->Phone_number);

		printf("Enter your Address: ");		
		scanf("%s",&temp->Address);

	}

}
void voidRank(void)
{
	node * current = head;
	int count =0,swapped=0,i=0,j,temp;
	while(current!=NULL)
	{
		count++;
		current=current->link;
	}
	printf("%d\n",count);


	int * IDArr =(int*)malloc(sizeof(int)*count);
	int * ScoreArr =(int*)malloc(sizeof(int)*count);

	current=head;
	while(current!=NULL)
	{
		IDArr[i]=current->ID;
		ScoreArr[i]=current->Science_grade;

		current=current->link;
		i++;
	}
	while(swapped!=1)
	{
		swapped=1;
		for(j=0;j<count-1;j++)
		{
			if(ScoreArr[j]>ScoreArr[j+1])
			{ //swap
				temp=ScoreArr[j];
				ScoreArr[j]=ScoreArr[j+1];
				ScoreArr[j+1]=temp;

				temp=IDArr[j];
				IDArr[j]=IDArr[j+1];
				IDArr[j+1]=temp;

				swapped=0;
			}
		}
		i++;
	}
	for(i=0;i<count;i++)
	{
		voidHelpPrint(IDArr[i]);
	}
}
void voidHelpPrint(int IDCpy)
{
	
	node * current = head;
	while(current!=NULL)
	{

		if(current->ID==IDCpy)
		{
		
			printf("Name: %s\n",current->name);
			printf("ID : %d\n",current->ID);
			printf("Phone number :%s\n",current->Phone_number);
			printf("birth_day : %d / %d / %d\n",current->birth_day,current->birth_month,current->birth_year);
			printf("The grade of Computer science = %d \n\n",current->Science_grade);
			
			break;
		}

		current=current->link;

	}	
}
