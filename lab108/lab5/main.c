#include <stdio.h>

void external_display(int array[], size_t size);
void display(int matris[][3]);
void convolutional_filter();
int multiplication(int matris[3][3]);
int trace(int matris[][3]);

int main()
{
    short int secmeme, cIk=0;

    while (cIk!=1)
    {
        //printf("\e[1;1H\e[2J");
        secmeme=0;
        printf("\n\nChoose the matrix operation,\n"			//
               "--------------------------------\n"			//
			   "1. Convolutional Filter for 1D array\n"		//
               "2. Multiplication\n"						//	Menu
               "3. Trace\n"									//
               "4. Traspose\n"								//
			   "5. Exit\n"									//
               "--------------------------------\n"			//
			   "Enter your choice: ");						//
        scanf("%hd",&secmeme);

        if(secmeme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        if(secmeme==6 || secmeme==5) 
		{
			cIk=1;
			break;
		}
        if(secmeme==1)
        {   
			convolutional_filter();
			printf("\n\nPress ENTER to continue.... \n");
            //while(getchar() != '\n');
            while(getchar() != '\n') /* nothing happens */;
			continue;
        }


		int matris1[3][3]= {0}, matris2[3][3]= {0};
		printf("First Matrix:\n");
		for(int i= 0; i < 3; i++)	
		{
			for(int o= 0; o < 3; o++)	
			{
				scanf("%d", &matris1[i][o]);
			}
		}
		printf("Second Matrix:\n");
		for(int i= 0; i < 3; i++)	
		{
			for(int o= 0; o < 3; o++)	
			{
				scanf("%d", &matris2[i][o]);
			}
		}


        if(secmeme==2)
        {
			int temp= 0;
			int trcmtx[3][3];

			for(int i= 0; i < 3; i++)	
			{
				for(int o= 0; o < 3; o++)	
				{
					temp= 0;
					for(int a= 0; a < 3; a++)	
					{
						temp += matris1[i][a] *matris2[a][o];

					}
					trcmtx[i][o]= temp;
				}
				
			}
			printf("Multiplication of matrix:");
			display(trcmtx);
        }
        if(secmeme==3)
        {
			int trace1= 0, trace2= 0;
			trace1= trace(matris1);
			trace2= trace(matris2);
			
			printf("\nTrace of first matrix:");
			display(matris1);
			printf("\nTrace of matrix is: %d", trace1);
			printf("\nTrace of second matrix:");
			display(matris2);
			printf("\nTrace of matrix is: %d", trace2);
        }
        if(secmeme==4)
        {
			int temp= 0;
			int trcmtx1[3][3];
			int trcmtx2[3][3];



			for(int i= 0; i < 3; i++)	
			{
				for(int o= 0; o < 3; o++)	
				{
					//copying array
					trcmtx1[i][o]= matris1[i][o];
				}
			}
			//manually changing indicies
			trcmtx1[0][1]= matris1[1][0];
			trcmtx1[0][2]= matris1[2][0];	
			trcmtx1[1][0]= matris1[0][1];
			trcmtx1[1][2]= matris1[2][1];
			trcmtx1[2][0]= matris1[0][2];
			trcmtx1[2][1]= matris1[1][2];

			printf("\nTranspose of the first matrix:\n");
			display(trcmtx1);
			for(int i= 0; i < 2; i++)	
			{
				for(int o= 0; o < 3; o++)	
				{
					//copying array
					trcmtx2[i][o]= matris2[i][o];
				}
			}
			//manually changing indicies
			trcmtx2[0][1]= matris2[1][0];
			trcmtx2[0][2]= matris2[2][0];
			trcmtx2[1][0]= matris2[0][1];
			trcmtx2[1][2]= matris2[2][1];
			trcmtx2[2][0]= matris2[0][2];
			trcmtx2[2][1]= matris2[1][2];

			printf("\nTranspose of the second matrix:\n");
			display(trcmtx2);
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

void convolutional_filter()
{
	int array[10]= {0}, newarray[8]= {0};
	printf("1D array\n");
	for(int a= 0; a < 10; a++)
	{
		scanf("%d", array +a);	//asking user for 1d array
	}
	/* some sort of operations */
	
	for(int a= 1; a < 9; a++)
	{
		//Sliding kernel and adding three multiplications
		newarray[a -1] += array[a -1] *-1;
		newarray[a -1] += array[a] *1;
		newarray[a -1] += array[a +1] *-1;
	}


	external_display(array, sizeof(array) /sizeof(int));
	printf("\nConvolutional Filter Result:\n");
	external_display(newarray, sizeof(newarray) /sizeof(int));
}

void external_display(int array[], size_t size)
{						/* array printer */
	for(int i= 0; i < size; i++)	
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

}


void display(int matris[][3])
{							/* matrix printer */
	printf("\n");
	for(int i= 0; i < 3; i++)	
	{
		for(int o= 0; o < 3; o++)	
		{
			printf("%d\t", matris[i][o]);
		}
		printf("\n");
	}
}

int multiplication(int matris[3][3])
{

	

}

int trace(int matris[][3])
{
	int trace1= 0;
	for(int i= 0; i < 3; i++)	
	{
		for(int o= 0; o < 3; o++)	
		{
			if(i == o)	trace1 += matris[i][o];
		}
	}
	return trace1;

}
