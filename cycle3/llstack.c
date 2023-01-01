#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int x)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}
void pop()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("Stack empty");
	}
	else
	{
		printf("The element popped is %d\n",top->data);
		top=top->next;
		free(temp);
	}	
}
void peek()
{
	if(top==NULL)
	{
		printf("Stack empty");
	}
	else
	{
		printf("The top element is %d\n",top->data);
	}
}
void display()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("Stack empty");
	}
	temp=top;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}	
}
void main()
{
	int choice,data;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Peek\n4.Display stack\n5.Exit\n");
		printf("Enter choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element:\n");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				pop();
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

