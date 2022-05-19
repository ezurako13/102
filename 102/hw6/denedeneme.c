#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fonksiyon(char **onur);
void salih(char **onur);

int main()
{
	srand(time(0));
	char kerem[7][5]= {"onur", "beyza", "salih", "hamza", "zehra", "irem", "kerem"};

	char (*onur)[5]= (char (*)[5])kerem;

	//char **onur= (char **)kerem;


	printf("\n");
	//for(int i= 0; i < 7; i++)
	{
		for(int o= 0; o < 10; o++)
		{
			//printf("%c", onur[i][o]);
			printf("%d", rand()%6 +1);
			printf("\n");

		}
	}

	//fonksiyon(onur);





	return 0;
}

void fonksiyon(char **onur)
{
	printf("\n");


	for(int i= 0; i < 7; i++)
	{
		for(int o= 0; o < 5; o++)
		{
			printf("%c", onur[i][o]);

		}
		printf("\n");
	}
}

