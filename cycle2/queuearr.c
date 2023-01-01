#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX],front=-1,rear=-1;
void enqueue(int data)
{
	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=data;
	}
	else if(rear==(MAX-1))
	{
		printf("Queue full");
	}
	else
	{
		rear++;
		queue[rear]=data;
	}
}
void dequeue()
{
	if(front==-1&&rear==-1)
	{
		printf("Queue empty");
	}
	else if(rear==front)
	{
		printf("The element deleted is %d\n",queue[front]);
		rear=-1;
		front=-1;
	}
	else
	{
		printf("The element deleted is %d\n",queue[front]);
		front++;
	}	
}
void peek()
{
	if(front==-1&&rear==-1)
	{
		printf("Queue empty");
	}
	else
	{
		printf("The front element is %d\n",queue[front]);
	}
}
void display()
{
	int i;
	if(front==-1&&rear==-1)
	{
		printf("Queue empty");
	}
	for(i=front;i<(rear+1);i++)
	{
		printf("%d\n",queue[i]);
	}
}
void main()
{
	int choice,data;
	while(1)
	{
		printf("1.Insert element\n2.Delete element\n3.Peek\n4.Display queue\n5.Exit\n");
		printf("Enter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element:\n");
				scanf("%d",&data);
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("Enter valid choice");
		}		
	}
}
