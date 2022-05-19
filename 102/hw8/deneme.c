#include <stdio.h>


void ziyaDeniyor(int *ptr, int *arr);



int main()
{
	char array[30]= {};
	int *arr= NULL;

	int *ptr= &arr;

	char arraylen= *(&array +1) -array;

	int len= *(&array +1) -array;


	printf("\n\narray= %lld\n\n&array= %lld\n\n*(&array +1)= %lld", array, &array, *(&array +1));
	printf("\n\n\n*(&array +1) -array= %d\n\n", arraylen);

	ziyaDeniyor(&ptr);

	return 0;
}

void ziyaDeniyor(int *ptr,int *arr)
{
	arr=(int*)malloc(8*sizeof(int));
	ptr=(int*)malloc(8*sizeof(int));
	ptr=&arr;
}

