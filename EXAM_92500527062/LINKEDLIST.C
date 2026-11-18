leetcode
program no.203
remove linked list elements(marks 10)

#include<stdio.h>;
#include<conio.h>;
#include<stdlib.h>;

struct node
{
	int data;
	struct node *next; 
};
struct node* head = NULL;
void create()
{
	newnode=(struct node *)malloc(size of(struct node));
	newnode->data=data;
	newnode->next=NULL;
}

void main()
{
	int ch;
	while(1)
	{
		printf("1.insert\n2.delete\n3.exit");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: create();
			break;
		
			case 2: delete();
			break;
			
			case 3: exit(0);
			
			default:
			printf("wrong value");
		}
	}
}
