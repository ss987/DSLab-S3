#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;
char exp[MAX]; 
void stackFull()
{
	fprintf(stderr,"Stack full, cannot add element");
	
}
void stackEmpty()
{
	fprintf(stderr,"Stack empty");
	
}
int pop()
{
	
	if(top==-1)
		stackEmpty();
	else
	return stack[top--];
	
}
void push(int item)
{
	
	if (top>=MAX-1)
		stackFull();
	stack[++top]=item;
}
void expeval(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;
    push('(');                               
    strcat(postfix,")");  
    
    for (i = 0; postfix[i] != ')'; i++) 
    {
        ch = postfix[i];
        if (isdigit(ch)) 
        {
            
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        {
        
            A = pop();
            B = pop();

            switch (ch) 
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            
            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

void main()
{
	
	printf("Enter postfix expression\n");
	gets(exp);
	expeval(exp);
	
}

































