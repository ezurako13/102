#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void alphabeticSort(char arr[][MAX_LEN], int n);
void generateTagParser(char temp[], char arr[]);
void bastirArr(char arr[][MAX_LEN], int sayi);

int main()
{
	short int secmeme, cIk=0;

	char arr[100][50]= {"Hamza", "Kerem", "Kamil", "Beyza", "salih"};
	int bos, sayi= 0, sayac= 5;

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		secmeme=0;
		printf("\n\nChoose the operation\n"					//
			   "--------------------------------\n"			//
			   "1. Enter strings\n"							//
			   "2. Zort Strings\n"							//	Menu
			   "3. Tag Parser\n"							//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&secmeme);
		while(getchar() != '\n')

		if(secmeme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secmeme==6) cIk=1;

		if(secmeme==1)
		{
			printf("\nenter the count of how many strings you want to enter...\n");
			scanf("%d", &sayi);

			printf("\nenter the strings...\n");
			for(int i= sayac; i < sayi +sayac; i++)
			{
				scanf("%s", arr[i]);
			}
			sayac += sayi;


		}
		if(secmeme==2)
		{
			printf("\nGiven array is\n", sayac);
			bastirArr(arr, sayac);

			alphabeticSort(arr, sayac);

			printf("\nSorted array is\n", sayac);
			bastirArr(arr, sayac);

		}
		if(secmeme==3)
		{
			char kelime[MAX_LEN]= {};
			char temp[MAX_LEN +4]= {};

			printf("\nEnter a string: ");
			gets(kelime);
			//scanf("%[^\n]%*c", kelime);
			generateTagParser(temp, kelime);
			printf("\n%s\n", temp);
		}
		
		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			//while(getchar() != '\n');
			while(getchar() != '\n') /* nothing happens */;
		}
	}



	return 0;
}

/*	
 *	Function: alphabeticSort
 *	--------------------------------------------
 *	It does:
 *	Sorts given strings of given size by using buble sort
 *	
 *	n: number of strings given by user
 *	
 *	MAX_LEN: maximum lenght of a string
 *	
 *	
 *	returns: nothing
 *	
 */
void alphabeticSort(char arr[][MAX_LEN], int n)
{
	char yedekchar[MAX_LEN]= {};
	int i= 0, o= 0;

	//printf("\n(zort:) n= %d\n", n);


	while(i < n)
	{
		o= 0;
		while(o < n -1 -i)
		{
			//printf("\n(zort:) i= %d o= %d strcmp(arr[o], arr[o +1])= %d\n", i, o, strcmp(arr[o], arr[o +1]));
			if(strcmp(arr[o], arr[o +1]) > 0)
			{
				//printf("\n(zort:) arr[o]= %s arr[o +1]= %s\n", arr[o], arr[o +1]);
				strcpy(yedekchar, arr[o]);
				strcpy(arr[o], arr[o +1]);
				strcpy(arr[o +1], yedekchar);
				/* Code for buble sort */
			}
			o++;
		}
		i++;
	}


}

/*	
 *	Function: generateTagParser
 *	--------------------------------------------
 *	It does:
 *	Adds a spesific tag start and end of a string according to its lenght
 *	
 *	temp: array that we will be working on and also pointer for return
 *	
 *	arr: original array given by user
 *	
 *	
 *	returns: nothing
 *	
 */
void generateTagParser(char temp[], char arr[])
{
	int uzunluk= strlen(arr);
	
	if(uzunluk < 5)
	{
		temp[0]= '<';	
		temp++;
		temp[0]= '<';
		temp++;
		strcpy(temp, arr);
		temp += uzunluk;
		temp[0]= '>';
		temp[1]= '>';
	}
	if(uzunluk >= 5 && uzunluk <= 10)
	{
		temp[0]= '*';	
		temp++;
		strcpy(temp, arr);
		temp += uzunluk;
		temp[0]= '*';
	}
	if(uzunluk > 10)
	{
		temp[0]= '/';	
		temp++;
		temp[0]= '+';
		temp++;
		strcpy(temp, arr);
		temp += uzunluk;
		temp[0]= '+';
		temp[1]= '/';
	}
}

/*	
 *	Function: bastirArr
 *	--------------------------------------------
 *	It does:
 *	Prints given strings
 *		
 *	arr: array, which will be printed, given by user
 *	
 *	sayi: number of strings given by user
 *	
 *	returns: nothing
 *	
 */
void bastirArr(char arr[][MAX_LEN], int sayi)
{
	for(int i= 0; i < sayi; i++)
	{
		printf("%d: %s\n", i, arr[i]);
	}
}

