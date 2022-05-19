#include <stdio.h>


void x_star_display(int height);
void diamond_star_display(int height);
void multiplication_table_display(int size);
void is_palindrome_integer(int n);


int main()
{
    short int secmeme, cIk=0;

    do
    {
        //printf("\e[1;1H\e[2J");
        secmeme=0;
        printf("\nEnter option 1 to x_star_display\n"
			   "Enter option 2 to diamond_star_display\n"
			   "Enter option 3 to multiplication_table_display\n"
			   "Enter option 4 to to palindrome check number\n"
			   "Enter option -1 to exit!\n");
        scanf("%hd",&secmeme);

		
		int height, size, palindrome;

		switch(secmeme)
		{
			case 0: 
				printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");

			case -1: 
				cIk= 1;
				break;
			case 6: 
				cIk= 1;
				break;
			case 1:

				height= 0;
				printf("Enter an odd integer as the height:");
				scanf("%d", &height);
				x_star_display(height);	
				break;	
			
			case 2:

				height= 0;
				printf("Enter an odd integer as the height:");
				scanf("%d", &height);
				diamond_star_display(height);
				break;
			
			case 3:
			
				size= 0;
				printf("Enter an integer as the size:");
				scanf("%d", &size);
				multiplication_table_display(size);
				break;
			
			case 4:
				
				palindrome= 0;
				printf("Enter an integer as the palindrome:");
				scanf("%d", &palindrome);
				is_palindrome_integer(palindrome);
				break;
			

		}
		if(cIk != 1)
		{
			printf("\n\nPress ENTER to continue.... \n");
			while(getchar() != '\n');
			while(getchar() != '\n') /* nothing happens */;
		}

    } while (cIk!=1);



	return 0;
}


void x_star_display(int height)
{
	int x, y;

	for(y= 1; y <= height; y++)
	{
		printf("\n");
		for(x= 1; x <= height; x++)
		{
			if( x +y == height +1 || x -y == 0)	printf("*");
			else	printf(" ");
		}

	}

}

void diamond_star_display(int height)
{
	int x, y;

	for(y= 1; y <= height; y++)
	{
		printf("\n");
		for(x= 1; x <= height; x++)
		{
			if( x -y == (height /2 ) ||  y -x == (height /2 ) ||  x +y == height/2 +2  ||  y +x == height +height /2 +1)	printf("*");
			else	printf(" ");
		}

	}

}

void multiplication_table_display(int size)
{
	if(size == 0)	return;

	int temp= size *size, tab= 1;
	while(temp > 0)
	{
		temp /= 10;
		tab++;
	}
	printf("\ntab= %d\n", tab);

	int x, y;

	printf("\t");

	for(y= -1; y <= size; y++)
	{
		if(y == 0)	
		{
			printf("\n");
			for(int a= 0; a < 8 +tab *size; a++)	printf("-");
		}
		if(y > 0)	printf("\n%d*\t", y);

		for(x= 1; x <= size; x++)
		{
			if(y == -1)	printf("%*d", tab, x);
			if(y > 0)
			{
				printf("%*d", tab, x *y);
			}
		}
	}
}

void is_palindrome_integer(int n)
{
	int basamaksayisi= 0, temp= n, bastan= 0, sondan= 0, palindrome= 1, sayi= n;

	while(temp > 0)
	{
		temp /= 10;
		basamaksayisi++;
	}
	//printf("\nbasamaksayisi= %d\n", basamaksayisi);

	for(int i= 1; i <= basamaksayisi /2; i++)
	{
		sondan= n %10;

		temp= n;
		for(int o= i; o <= basamaksayisi -i; o++)
		{
			temp /= 10;
			//printf("\nsayi= %d\n", temp);
		}
		bastan= temp %10;
		//printf("\nbastan= %d sondan= %d\n", bastan, sondan);
		n /= 10;
		if(bastan != sondan)	palindrome= 0;
	}
	if(palindrome == 1)	printf("%d is a palindrome.", sayi);
	else	printf("%d is not a palindrome.", sayi);

}
