#include<stdio.h>
#include<stdlib.h>     
#include<ctype.h>     
#include<string.h>
#define MAX 50
char stack[MAX];
int top = -1;
void stackFull()
{
	fprintf(stderr,"Stack full, cannot add element");	
}
void stackEmpty()
{
	fprintf(stderr,"Stack empty");	
}
char pop()
{	
	if(top==-1)
		stackEmpty();
	else
	return stack[top--];	
}
void push(char item)
{	
	if (top>=MAX-1)
		stackFull();
	stack[++top]=item;
}
int isoperator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;
	push('(');                               
	strcat(infix_exp,")");               
	i=0;
	j=0;
	item=infix_exp[i];
	while(item != '\0')        
	{
		if(item == '(')
		{
			push(item);
		}		
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              
			j++;
		}
		else if(isoperator(item) == 1)        
		{
			x=pop();
			while(isoperator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);	
			push(item);                 
		}
		else if(item == ')')        
		{
			x = pop();                   
			while(x != '(')                
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}
		i++;
		item = infix_exp[i]; 
	}	
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0'; 
}
void main()
{
	char infix[MAX], postfix[MAX];
	printf("\nEnter Infix expression : ");
	gets(infix);
	InfixToPostfix(infix,postfix);                   
	printf("Postfix Expression: ");
	puts(postfix);                     
}





















