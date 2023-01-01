#include<stdio.h>
#include<stdlib.h>
#define size 10
int stack[size];
int top=-1;
int stackfull() {
	if (top >= size - 1)
	return 1;
	else
	return 0;
}

void push(int item) {
	if(stackfull()==1){
	printf("\nStack Full");
	}
	else{
	stack[++top] = item;
	}
}

int stackempty() {
	if (top == -1)
	return 1;
	else
	return 0;
}

int pop() {
	int item;
	if(stackempty()==1){
	printf("\nStack Empty");
	}
	else{
	item = stack[top--];	
	return (item);
	}
}

void display() {
	int i;
	if (stackempty())
	printf("\nStack Empty");
	else {
		for (i = top; i >= 0; i--)
		printf("\n%d", stack[i]);
	}
}
int main()
{
	int item, choice;
	do {

		printf("\n\n1.Push \n2.Pop \n3.Display \n4.Exit\n");
		printf("\nEnter Your Choice : ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
			    printf("\nEnter the item to be pushed : ");
			    scanf("%d", &item);
			    push(item);
			    break;
			case 2:
			    item = pop();
			    printf("\nThe popped element is %d", item);			
			    break;
			case 3:
			    display();
			    break;
			case 4:
			    exit(0);
		}
	} while (1);
	return 0;
} 














