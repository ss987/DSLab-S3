#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int x)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	if(front==NULL && rear==NULL)
	{
		front=newnode;
		rear=newnode;		
	}
	else 
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	if(front==NULL && rear==NULL)
	{
		printf("Queue empty");
	}
	else if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		printf("The element deleted is %d\n",front->data);
		struct node* temp;
		temp=front;
		front=front->next;
		free(temp);
	}
}
void display()
{
	if(front==NULL && rear==NULL)
	{
		printf("Queue empty");
	}
	else
	{
		struct node* temp;
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void peek()
{
	if(front==NULL && rear==NULL)
	{
		printf("Queue empty");
	}
	else
	{
		printf("The front element is %d\n",front->data);
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
