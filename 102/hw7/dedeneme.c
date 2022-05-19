#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fonksiyon(FILE *salih);
void fonksiyon2();

int main()
{
	FILE *salih= fopen("wordlist.txt", "r");
	char kelime[31];
	//fscanf(salih, "%s", kelime);
	printf("\nkelime 1: %s\n", kelime);

	//printf("\nxd\n");
	//fonksiyon2();
	fclose(salih);
	fonksiyon(salih);
	//printf("\nxd\n");


	return 0;
}

void fonksiyon(FILE *salih)
{
	salih= fopen("wordlist.txt", "r");
	char *kelime;
	fscanf(salih, "%s", kelime);
	//printf("\nxd\n");
	printf("\nkelime 2: %s\n", kelime);
}

void fonksiyon2()
{
	FILE *salih= fopen("wordlist.txt", "r");
	char kelime[31];
	fscanf(salih, "%s", kelime);
	//printf("\nxd\n");
	printf("\nkelime 3: %s\n", kelime);
	fclose(salih);

}

