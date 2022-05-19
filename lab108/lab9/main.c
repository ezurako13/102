#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define THREE_MIN(a, b, c) MIN(MIN(a, b), b)

int *findMaximimDistance(int  distanceOfCirclec[], int start, int end);
int recursiveMinStrDiff(char str1[], char str2[], int m, int n);


int main()
{
	short int Eyvah, cIk=0;

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		Eyvah=0;
		printf("\n\nChoose the operation\n"					//
			   "--------------------------------\n"			//
			   "1. Find Maximim Distance\n"							//
			   "2. Recursive Min Str Diff\n"							//	Menu
			   "3. \n"							//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&Eyvah);
		while(getchar() != '\n')

		if(Eyvah==0) printf("\nWhy are you so insistent about entering zeros\n\n");
		if(Eyvah==6) cIk=1;

		if(Eyvah==1)
		{
			int distanceOfCities[]= {20, 56, 18, 45, 40};
			int numberfo= sizeof(distanceOfCities) /4;
			printf("\nnumber= %d\n", numberfo);

			int *retarray= findMaximimDistance(distanceOfCities, 0, numberfo -1);
			printf("\ndistances= %d, %d\n", retarray[0], retarray[1]);
			
		}
		if(Eyvah==2)
		{
			printf("\nTHREE_MIN(9, 6, 7)= %d\n", THREE_MIN(9, 6, 7));

			char str1[]= "intention";
			char str2[]= "execution";

			char str3[]= "monday";
			char str4[]= "sunday";

			//char str5[]= "sunday";
			//char str6[]= "saturday";

			char str7[]= "tesla";
			char str8[]= "test";

			printf("\n%s %s", str1, str2);
			printf("\nsonuc= %d\n", recursiveMinStrDiff(str1, str2, strlen(str1), strlen(str2)));
			printf("\n%s %s", str3, str4);
			printf("\nsonuc= %d\n", recursiveMinStrDiff(str3, str4, strlen(str3), strlen(str4)));
			//printf("\n%s %s", str5, str6);
			//printf("\nsonuc= %d\n", recursiveMinStrDiff(str5, str6, strlen(str5), strlen(str6)));
			printf("\n%s %s", str7, str8);
			printf("\nsonuc= %d\n", recursiveMinStrDiff(str7, str8, strlen(str7), strlen(str8)));
			
		}
		if(Eyvah==3)
		{
			
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


/* Finds maximum and minimum value of given int array and returns it */
int *findMaximimDistance(int  distanceOfCirclec[], int start, int end)
{
	int *sonuc= NULL;
	
	/* If function call part is done creates an integer array and assigns initial values */
	if(start == end)
	{
		sonuc= (int *)calloc(2, sizeof(int));
		sonuc[0]= distanceOfCirclec[start];
		sonuc[1]= distanceOfCirclec[end];
	}

	/* Calls function again and again untill its indices are pointing same position */
	else
	{
		sonuc= findMaximimDistance(distanceOfCirclec, start +1, end);
	}

	/* Compares returned limits and updates them to the correct one in necessary */
	if(distanceOfCirclec[start] > sonuc[0])	sonuc[0]= distanceOfCirclec[start];
	if(distanceOfCirclec[start] < sonuc[1])	sonuc[1]= distanceOfCirclec[start];

	return sonuc;
}

/* Compares two strings and returnes minimum number of operations to convert str1 into str2 */
int recursiveMinStrDiff(char str1[], char str2[], int m, int n)
{
	/* Checking that if the inputs are correct or not */
	if((str1 == NULL || *str1 ==  '\0') && str2 != NULL)	return strlen(str2);
	if((str2 == NULL || *str2 ==  '\0') && str1 != NULL)	return strlen(str1);
	if(str1 == NULL && str2 == NULL) return 0;


	/* retun result */
	if(m == 0)	return n;
	if(n == 0)	return m;

	else
	{
		if(str1[m -1] == str2[n -1])	return recursiveMinStrDiff(str1, str2, m -1, n -1);
		if(str1[m -1] != str2[n -1])
		{
			if(m == n)	
			{
				printf("\nReplace %c with %c", str1[m -1], str2[n -1]);
				return 1 + recursiveMinStrDiff(str1, str2, m -1, n -1);
			}
			if(m > n)	
			{
				printf("\nRemove %c", str1[m -1]);
				return 1 + recursiveMinStrDiff(str1, str2, m -1, n);
			}
			if(m < n)
			{
				printf("\nAdd %c", str2[n -1]);
				return 1 + recursiveMinStrDiff(str1, str2, m, n -1);
			}
		}
	}
}
