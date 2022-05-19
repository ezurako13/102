#include<stdio.h>

int main()
{
	int a;
	for(int i=0;i<20;i++)
	{
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&a);
		while(getchar() != '\n');
		fflush(stdin);
		fflush(stdout);
		printf("\n%d\n",a);
		fflush(stdout);
		fflush(stdin);

	}
return 0;
}