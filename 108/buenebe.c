#include<stdio.h>
#include<stdlib.h>
int *sum(int *a,int *b);

int main() 
{
    int a=3,b=4;
    int *c=sum(&a,&b);
    //c=
    printf("%d",*c);

}

int *sum(int *a,int* b)
{
	int *c= (int *)malloc(sizeof(int));
    *c= (*a) + (*b);
	return c; 
}