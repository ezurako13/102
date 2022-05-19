#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void expression0 (int x, int *result);
void expression1(int x, int *result);
void expression2 (int x, int *result);
void addition (void (*func)(int, int *), int *sum, int n);
void calculation (int *sumarray, int n);
void createArray(int (*array)[10]);


int main ()
 {
		
		int sumar[3];
		int matrix[10][10];
		int n,a,b;
		printf("n:");
		scanf("%d",&n);
		//printf("1hamza\n");
		calculation(sumar,n);
		printf(" expression0 is :%d\n",sumar[0]);
		printf(" expression1 is :%d\n",sumar[1]);
		printf(" expression2 is :%d\n",sumar[2]);
		createArray(matrix);
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
			printf("%d ",matrix[i][j]);
			
			}
		printf("\n\n");
		}
		printf("Which element of the matrix do you want to reach?\n");
		printf("i=");
		scanf("%d",&a);
		printf("j:");
		scanf("%d",&b);
		printf("%d. row %d. column of the matrix is %d",a,b,matrix[a-1][b-1]);

	}	
	
	

void calculation (int *sumarray, int n)
{

addition (expression0, &sumarray[0],  n);
//printf("%d",sumarray[0]);
 addition (expression1,  &sumarray[1],  n);
 addition (expression2, &sumarray[2],  n);

}
void addition (void (*func)(int, int *), int *sum, int  n)
{
//printf("3hamza\n");
//int *result1=(int *)malloc(sizeof(int));
//sum=result1;
 func(n,sum);
 //printf("%d reel2 \n",*sum);

}
void expression0 (int x, int *result)
{
int sum=0;

	for (int i=0;i<=x;i++)
	{
	sum+=(i*i)+5;
	}
	*result=sum;

}
void expression1 (int x, int *result)
{
int sum=0;

	for (int i=0;i<=x;i++)
	{
	sum+=(2*i)+1;
	}
	*result=sum;

}
void expression2 (int x, int *result)
{
int sum=0;

	for (int i=0;i<=x;i++)
	{
	sum+=(i*i);
	}
	*result=sum;

}
void createArray(int (*array)[10])
{
int randomNumber ;
srand (time(NULL));
for(int i=0;i<10;i++)
{
	for(int j=0;j<10;j++)
	{//printf("hamza");
	randomNumber = rand () %90 + 10;
	//printf("%d\n",randomNumber);
	*(*(array + i) + j)=randomNumber;
	
	
	}
//printf("hamza");
 printf("\n\n");
 
}








}