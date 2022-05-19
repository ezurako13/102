#include <stdio.h>
#include <string.h>

void reverse(char str[], char reversed[], int i);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r);

int main()
{
	short int secmeme, cIk=0;

	//char str[]= "salihlihamza";
	char str[]= "12321";
	int size= sizeof(str);
	char reversed[sizeof(str)]= {};

	
	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		secmeme=0;
		printf("\n\nChoose the operation\n"					//
			   "--------------------------------\n"			//
			   "1. Reverse String\n"							//
			   "2. Check Palindrome\n"							//	Menu
			   "3. Merge Zort\n"							//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&secmeme);
		while(getchar() != '\n')

		if(secmeme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secmeme==6) cIk=1;

		if(secmeme==1)
		{
			reverse(str, reversed, strlen(str));
			printf("\nstr= %s\nreversed= %s\n", str, reversed);
		}
		if(secmeme==2)
		{
			int pL= 1;

			/* Checking palindrome */
			for(int i= 0; i < size; i++)
				if(str[0] != reversed[0])	pL= 0;

			if(pL == 1)	printf("\nPalindrome!\n");
			else	printf("\nnot!\n");
		}
		if(secmeme==3)
		{
			int arr[]= {1, 30, 3, 6, 15, 9};
			printf("\narr= \n");
			for(int a= 0; a < sizeof(arr) /4; a++)
				printf("%d, ", arr[a]);
			printf("\n");

			mergeSort(arr, 0, 5);
			printf("\n\nsorted= \n");
			for(int a= 0; a < sizeof(arr) /4; a++)
				printf("%d, ", arr[a]);
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

/* Assigns reversed version of the str[] into reversed[] using recursion */
void reverse(char str[], char reversed[], int i)
{

	//if(str >= str +i -1)	return;
	if(i == 0)	return;

	reversed[i -1]= str[0];

	/* Calling funcrion with next indexes */
	reverse(str +1, reversed, i -1);

}

/* Merge Sort */
void mergeSort(int arr[], int l, int r)
{
	/* Cutting into two pieces */
	if(r -l > 2)	
	{
		mergeSort(arr, l, r /2);
		mergeSort(arr, l +(r /2), r);
	}
	/* Merging back */
	merge(arr, l, r /2, r);
	
	printf("\narrin= \n");
	for(int a= 0; a < 6; a++)
		printf("%d, ", arr[a]);


}

/* Merge two subarrays L and M intro arr */
void merge(int arr[], int p, int q, int r)
{
	/* Create L <- A[p..q] and M <- A[q+1..r] */
	int n1= q -p +1;
	int n2= r -q;

	int L[n1], M[n2];

	for(int i= 0; i < n1; i++)
		L[i]= arr[p +i];

	for(int o= 0; o < n2; o++)
		M[o]= arr[q +1 +o];

	/* Maintain current index of subarrays and and amin array */
	int i, j, k;
	i= 0;
	j= 0;
	k= p;

	/* Untill we reach either end of L or M, pick larger among
	elements L and M and place them in correct position ar A[p..r] */
	while(i < n1 && j < n2)
	{
		if(L[i] <= M[j])
		{
			arr[k]= L[i];
			i++;
		}
		else
		{
			arr[k]= M[j];
			j++;
		}
		k++;
	}

	/* When we ren out of elements in either L or M,
	pick up the remaining elements and put in A[p..r] */
	while(i < n1)
	{
		arr[k]= L[i];
		i++;
		k++;
	}

	while(j < n2)
	{
		arr[k]= M[j];
		j++;
		k++;
	}
}

