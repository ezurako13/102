#include <stdio.h>

int main()
{
	int a= 0;

	while(a != 19)
	{
		scanf("%d", &a);
		while(getchar() != '\n');
		printf("\na= %d\n", a);
	}

	return 0;
}



/*	stdin



*/