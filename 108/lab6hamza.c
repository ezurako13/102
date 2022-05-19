#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void average_finder (int(*matrix)[5],float *summer);
void average_finder1 (int(*matrix1)[9],float *summer1);
void intervew (const char s1, const char s2, char * s3);

int main()
{

int arr1[3][5],arr2[4][9],l1,l2;
float average,average1;
//const char st1[30],st2[30];
char *st= (char*)calloc(2,sizeof(char));
char *st1= (char*)calloc(30,sizeof(char));
char *st2= (char*)calloc(30,sizeof(char));

////////////////////////////////////////3x5 matrix/////////////////////////////////////////////////////////////////////////////////////////////

	average_finder(arr1,&average);
	
	printf("\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d\t",arr1[i][j]);
		 }
			printf("\n");
	}
	printf("average is %f",average);
	
//////////////////////////////////////////////////4x9 matrix//////////////////////////////////////////////////////////////////////////////////////

	average_finder1(arr2,&average1);

	 printf("\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<9;j++)
		{
			printf("%d\t",arr2[i][j]);
		 }
			printf("\n");
	}
	printf("average is %f",average1);
	
//-----------------------------------------------string combination------------------------------------------------------------------------------------
printf("\n");
	printf("first long string");
		scanf("%s",st1);
	printf(" second short string");
		scanf("%s",st2);
	l1=strlen(st1);
	l2=strlen(st2);
		printf("%d %d ",l1,l2);
	if(l1>l2)
	{
	
	intervew (st1[0], st2[0], st);
	printf("%s%s", st, (st+1));
	
	
	}
}
///////////////////////////////////////////////string///////////////////////////////////////////////////////////
void intervew (const char s1, const char s2, char * s3)
{
int l1,l2;
//char s4=(char)calloc(2,sizeof(char));
printf("hamza");
*(s3)=s1;
*(s3+1)=s2;
printf("hamza");
































}
////////////////////////////////////////////////////3x5////////////////////////////////////////////////77
void average_finder (int(*matrix)[5],float *summer)
{
int val=1,sum;
float count=0.0;
printf("\n");
for(int i=0;i<3;i++)
{
	for(int j=0;j<5;j++)
	{
		*( *(matrix+i)+j)=(2*val*val)-3;	
		val++;
		sum=(i+j);
	        if(sum%2==0)
	        {
	         printf("%d ",sum);
	        *summer+= *(*(matrix+i)+j);
	        count++;
	        }
	}
	
}
*summer=(*summer)/count;

}
///////////////////////////////////////////5x9///////////////////////////////////////////////////
void average_finder1 (int(*matrix1)[9],float *summer1)
{
int val=1,sum,count=0;
printf("\n");
for(int i=0;i<4;i++)
{
	for(int j=0;j<9;j++)
	{
		*( *(matrix1+i)+j)=(2*val*val)-3;	
		val++;
		sum=(i+j);
	        if(sum%2==0)
	        {
	        printf("%d ",sum);
	        *summer1+= *(*(matrix1+i)+j);
	        count++;
	        }
	}
	
}
*summer1=(*summer1)/count;

}