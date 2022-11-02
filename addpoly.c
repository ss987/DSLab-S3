#include<stdio.h>
#define MAX 100 
 typedef struct
 {
	 int coeff;
	 int exp;
 }poly;
 poly a[MAX];
 int readPoly(int start,int end)
 {
	int i;

	printf("\n Enter the Coefficient and exponent\n");
	for(i=start;i<=end;i++)
	{
		printf("   Enter the Coefficient : ");
		scanf("%d",&a[i].coeff);
		printf("      Enter the exponent : ");
		scanf("%d",&a[i].exp);        
	}
	
 }
int compare(int c,int b)
{
    if(c>b)
        return 1;
    if(c==b)
        return 0; 
    if(b>c)
        return -1; 
}
void printPoly(int start,int end)
{
    int i;
    for(i=start;i<end;i++)
    {
        printf("%dx^%d + ",a[i].coeff,a[i].exp);
    }
    printf("%dx^%d \n",a[i].coeff,a[i].exp);
}
  
int addPoly(int sA,int eA,int sB,int eB,int sD,int *end)
 {
	int i=0,j=0,p;
	int eD=*end;
    while(sA<=eA && sB <= eB)
    {
    	p=compare(a[sA].exp, a[sB].exp);
        
        if(p==-1)
        {
            a[eD].exp = a[sA].exp;
            a[eD].coeff = a[sA].coeff;
            sA++;
            eD++;
            
        }
        else if (p==0)
        {
            a[eD].exp = a[sB].exp;
            a[eD].coeff = a[sA].coeff + a[sB].coeff;
            sA++;
            sB++;
            eD++;
           
        }
        else if (p==1)
        {
            a[eD].exp = a[sB].exp;
            a[eD].coeff = a[sB].coeff;
            sB++;
            eD++;
            
        }        
               
    }

    for(;sA<=eA;sA++)
    {
        a[eD].exp = a[sA].exp;
        a[eD].coeff = a[sA].coeff;
        sA++;
        eD++;
    }

    for(;sB<=eB;sB++)
    {
        a[eD].exp = a[sB].exp;
            a[eD].coeff = a[sB].coeff;
            sB++;
            eD++;
    }
    *end = eD-1;
   
}
  

void main()
{
    
    int n1,n2,sA,eA,sB,eB,sD,eD;
    printf("Enter no. of terms of first polynomial : ");
    scanf("%d",&n1);
    sA = 0;
    eA = n1-1;  
    readPoly(sA,eA); 
    printPoly(sA,eA); 
    printf("Enter no. of terms of second polynomial : ");    
    scanf("%d",&n2);
    sB = n1;
    eB = n1+n2-1;
    readPoly(sB,eB);
    printPoly(sB,eB);
    sD = n1+n2;
    eD = sD;    
    addPoly(sA,eA,sB,eB,sD,&eD);    
    printf("Sum is : ");
    printPoly(sD,eD);
}
