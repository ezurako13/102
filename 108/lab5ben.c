#include <stdio.h>
#include <time.h> //This is responsible for randomness
#include <stdlib.h> //This will be used for calloc function
typedef int arr10[10]; //This is for type casting of void pointer returned by calloc function and it may also be unnecessary

void expression0(int x, int *result);
void expression1(int x, int *result);
void expression2(int x, int *result);
void addition(void (*func)(int, int *), int *sum, int n);
void calculation(int *sumArray, int n);
void createArray(int (*array)[10]);


int main()
{
	int sumArray[3]={}, i;                                      //Creating Array for summation in first task and also i
	short int secim=0, cIk=0, bitir=0;                          //They are just for Navigating in menus
	int (*matrix)[10]= (arr10 *)calloc( 10*10, sizeof(int) );   //Creating a pointer to an array of 10 integers in each row and 
	srand(time(0));												           //assing it's address with pointer returned by calloc by allocating
                                                                           //100 integeers of memory address by the way i type casted void * into 
    while (cIk!=1) //Creating Menu for Better Navigation Among Tasks         array pointer which has 10 integers in each row and this may also be unnecessary
    {
        printf("\e[1;1H\e[2J");
        secim=0;
        printf("\n\n\tSelect the Task You Have to Do Right Now\n\n"
               "1. Calculate the Sigma Notation for Three Expressions Below\n\n"
			   "    n                 n                 n         \n"
			   "  Toplam(x2 + 5)    Toplam(2x + 1)    Toplam(x2)  \n"
			   "   x=0               x=0               x=0        \n\n"      
			   "(Expression 0)	  (Expression 1)    (Expression 2)\n\n\n"
            
			   "2. Creation of 2 Dimensional Array and Selection of One of the Elements\n\n"
               "6. Exit\n\n");
        scanf("%hd",&secim);

        if(secim==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        if(secim==6) cIk=1;
        if(secim==1) 
        {   
			/* Declaring array, reading “n”, obtaining the results by using functions, and printing them. Nothing else.*/
			int n=0;
            printf("n= ");
			scanf("%d",&n);
			calculation(sumArray, n);

			for (i=0; i<3; i++)
			{
				printf("\nSum of expression%d: %d\n", i, sumArray[i]);
			}
        }
        if(secim==2)
        {
			printf("\nCreating 2D Array...\n\n");
			createArray(matrix);    //Filling Every Element of Matrix with Random 2 Digit Numbers

			bitir=0;
			while (bitir!=1) //If one of the inputs are invalid, the program will raise an error and terminate
			{
				short int row=0, column=0;  //Creating row and column variables for user input
				bitir=0;
				printf("\n\nEnter Row and Column Number of the Element in the Matrix\n"
					   "Enter in This Format\n"
					   "\nRow(SatIr) Column(Sutun)\n");
				scanf("%hd%hd",&row,&column);
				
				if(row<=10 && row>=0 && column>=0 && column<=10)     //Give Number that user choose if only inputs are valid
					printf("The Element you Choose is %d", matrix[row-1][column-1]);
				else 
				{
					printf("\n\nInvalid input. Terminating the Task...");
					bitir=1;
				}
			}
		}
        if(secim==1 || secim==2 || secim==0) //Press ENTER to continue... is enough explain i think
        {    
            printf("\n\nPress ENTER to continue.... \n");
            while(getchar() != '\n');
            while(getchar() != '\n') /* nothing happens */;
        }
    }


	return 0;
}



void expression0(int x, int *result)
{
	/* calculation of the expression0 for the value of x*/
	*result+= (x*x)+5;
}

void expression1(int x, int *result)
{
	/* calculation of the expression1 for the value of x*/
	*result+= (2*x)+1;
}

void expression2(int x, int *result)
{
	/* calculation of the expression2 for the value of x*/
	*result+= (x*x);
}

void addition(void (*func)(int, int *), int *sum, int n)
{
	/* obtaining the calculations for a single expression and return the result */
	*sum=0;
	for(int x=0; x<=n; x++) func(x, sum);
}

void calculation(int *sumArray, int n)
{
	/* Obtaining the summations and assinging them to sumArray respectively*/
	void *expressionlar[3]= {&expression0, &expression1, &expression2}; //Creating array of function pointers.
	
	for(int i=0; i<3; i++) 
		addition(expressionlar[i], &sumArray[i], n);
}



void createArray(int (*array)[10])
{
	short int i, o;
	
	for(i=0; i<10; i++) 
	{
		printf("\n");
		for (o=0; o<10; o++)
		{
			array[i][o]= rand()%90+10;
			printf("%d ",array[i][o]); //Filling Every Element of Matrix with Random 2 Digit Numbers
		}
	}
}
