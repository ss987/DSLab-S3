 #include<stdio.h>

 typedef struct
 {
	 int coeff;
	 int exp;
 }poly;
 int readPoly(poly a[],int start,int end)
 {
	int i;

	printf("\n Enter the Coefficient and exponent in increasing order\n");
	for(i=start;i<=end;i++)
	{
		printf("   Enter the Coefficient %d: ",i+1);
		scanf("%d",&a[i].coeff);
		printf("      Enter the exponent %d: ",i+1);
		scanf("%d",&a[i].exp);        
	}
	
 }
int addPoly(poly a[],poly sum[],int sA,int eA,int sB,int eB,int sD,int *end)
 {
	int i=0,j=0;
	int eD=*end;
    while(sA<=eA && sB <= eB){
        if(a[sA].exp < a[sB].exp)
        {
            a[eD].exp = a[sA].exp;
            a[eD].coeff = a[sA].coeff;
            sA++;
            eD++;
        }
        else if (a[sA].exp > a[sB].exp)
        {
            a[eD].exp = a[sB].exp;
            a[eD].coeff = a[sB].coeff;
            sB++;
            eD++;
        }
        else 
        {
            a[eD].exp = a[sB].exp;
            a[eD].coeff = a[sA].coeff + a[sB].coeff;
            sA++;
            sB++;
            eD++;
        }
    }

    while (sA<=eA)
    {
        a[eD].exp = a[sA].exp;
        a[eD].coeff = a[sA].coeff;
        sA++;
        eD++;
    }

    while (sB<=eB)
    {
        a[eD].exp = a[sB].exp;
            a[eD].coeff = a[sB].coeff;
            sB++;
            eD++;
    }
    *end = eD-1;
}
void printPoly(poly a[],int start,int end)
{
    int i;
    for(i=start;i<end;i++)
    {
        printf("%dx^%d + ",a[i].coeff,a[i].exp);
    }
    printf("%dx^%d \n",a[i].coeff,a[i].exp);
}
    

void main()
{
    poly a[100],sum[100];
    int n1,n2,sA,eA,sB,eB,sD,eD;
    printf("Enter no. of terms of first polynomial : ");
    scanf("%d",&n1);
    sA = 0;
    eA = n1-1;  
    readPoly(a,sA,eA); 
    printPoly(a,sA,eA); 
    printf("Enter no. of terms of second polynomial : ");    
    scanf("%d",&n2);
    sB = n1;
    eB = n1+n2-1;
    readPoly(a,sB,eB);
    printPoly(a,sB,eB);
    sD = n1+n2;
    eD = sD;    
    addPoly(a,sum,sA,eA,sB,eB,sD,&eD);    
    printf("Sum is : ");
    printPoly(a,sD,eD);
}

	

	
		
	

 

 
