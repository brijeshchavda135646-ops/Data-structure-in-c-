WRITE A PROGRAM WITH FOLOWING OPERATION IN QUEUE
INSERT DELETE DISPLAY EXIT 

#include <stdio.h>;
#include <conio.h>;

int queue[size];
int front = -1, rear = -1;
void insert()
{
	int a;
	if(rear == size-1)
	{
		printf("overflow");
	}
	else
	{
		printf("Enter the number:");
		scanf("%d",&a);
		if(front == -1)
		{
			front = 0;
		}
		rear++;
		queue[rear] = a;
	}
}
void delete()
{
	if (front == -1)
	{
		printf("underflow");
	}
	else
	{
		printf("deleted element = %d",queue[front]);
		front ++;
		if(front>rear)
		{
			front = -1;
			rear = -1;
		}
	}
}
void display()
{
	int i;
	if(front == -1)
	{
		queue is empty
	}
	else
	{
		for(i = front; i<=rear; i++)
		{
			printf("%d",queue[i]);
		}
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("1.insert\n2.delete\n3.display\n4.exit");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: create();
			break;
		
			case 2: delete();
			break;

			case 3: display();
			break;

			case 4: exit(0);
			break;
	
			default:
			printf("wrong value");
		}
	}
}
