#include<stdio.h>
#include<stdlib.h>

void createArray(int (*array)[10]);
int main(void)
{
	int matrix[10][10];
	int (*ptr)[10];
	ptr = matrix;
	createArray(ptr);

}

void createArray(int (*array)[10])
{
	//srand(time(NULL));
	int randomNumber = rand () %90 + 10;

	int satir;
	int sutun;
	satir = 0;
	sutun = 0;

	int row;
	int column;
	int flag;
	flag = 0 ;
	while(satir<10)
	{
		while(sutun <10)
		{	
			randomNumber = rand () %90 + 10;
			array[satir][sutun] = randomNumber;
			sutun++;
		}
		satir++;
		sutun = 0;
	}
	satir = 0;
	sutun = 0;
	printf("\n\n");
	while(satir<10)
	{
		while(sutun <10)
		{	
			printf("%d ", array[satir][sutun]);
			sutun++;
		}
		printf("\n");
		satir++;
		sutun = 0;
	}
	printf("\n\n");



	while(flag != 1)
	{
		printf("matrix filled. Which row?\n");
		scanf("%d", &row);
		printf("which column\n");
		scanf("%d", &column);

		if((row > 9 || row < 0) || (column > 10 || column < 0))
			flag++;
		else
		{
			printf("%d\n", array[row][column]);
		}

	}
}