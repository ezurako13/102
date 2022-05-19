#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define buffersize 5
#define pi 3.14


typedef struct
{
	int x;
	int y;
} cordinate;

typedef struct
{
	cordinate points[2];
	float radius;
	float perimeter;
	float area;
} circle;


void print_struct(circle **cemberler, circle *smallest, int i, int prev);
int is_prime(int sayi);
int next_prime(int sayi);
void factorization(int sayi);
void hesaplama(circle *cemberler, int dairesayisi);

int main()
{
	short int Eyvah, cIk=0;

	int dairesayisi= 0, buffer= buffersize;
	circle *cemberler;

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		Eyvah=0;
		printf("\n\nChoose the operation\n"					//
			   "--------------------------------\n"			//
			   "1. Circles\n"							//
			   "2. Factorization\n"							//	Menu
			   "3. \n"							//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&Eyvah);
		while(getchar() != '\n');

		if(Eyvah==0) printf("\nWhy are you so insistent about entering zeros\n\n");
		if(Eyvah==6) cIk=1;

		if(Eyvah==1)
		{
			printf("\nEnter number of cicles: ");
			scanf("%d", &dairesayisi);
			while(getchar() != '\n');
			
			//dairesayisi= 3;
			
			cemberler= (circle *)calloc(dairesayisi +2, sizeof(circle));


			//cemberler[0].points[0].x= 0;
			//cemberler[0].points[0].y= 8;
			//cemberler[0].points[1].x= 0;
			//cemberler[0].points[1].y= 1;
//
			//cemberler[1].points[0].x= 0;
			//cemberler[1].points[0].y= 0;
			//cemberler[1].points[1].x= 3;
			//cemberler[1].points[1].y= 4;
//
			//cemberler[2].points[0].x= 0;
			//cemberler[2].points[0].y= 0;
			//cemberler[2].points[1].x= 2;
			//cemberler[2].points[1].y= 0;
//
			for(int i= 0; i < dairesayisi; i++)
			{
				printf("\nEnter center point of the circle %d: ", dairesayisi);
				scanf("%d%d", &(cemberler[i].points[0].x), &(cemberler[i].points[0].y));
				while(getchar() != '\n');
				printf("\nEnter passing through point(P) of the circle %d: ", dairesayisi);
				scanf("%d%d", &(cemberler[i].points[1].x), &(cemberler[i].points[1].y));
				while(getchar() != '\n');
			}

			hesaplama(cemberler, dairesayisi);

			//printf("\ncember[0]= %f %f %f\n", cemberler->area, cemberler->perimeter, cemberler->radius);
			printf("\nmain center x, y= %d %d", cemberler->points[0].x, cemberler->points[0].y);
			printf("\nmain P x, y= %d %d\n", cemberler->points[1].x, cemberler->points[1].y);

			circle *smallest= cemberler;

			for(int i= 0; i < dairesayisi; i++)
			{
				print_struct(&cemberler, smallest, 0, 0);
			}

		}
		if(Eyvah==2)
		{
			factorization(99);
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


/* prints smallest circle greater than smallest parameter */
void print_struct(circle **cemberler, circle *smallest, int i, int prev)
{
	printf("\nsmallest radius= %.2f", smallest->radius);
	printf("\n*cemberler radius= %.2f", cemberler[i]->radius);

	printf("\n\n");
	if(cemberler[i]->radius < smallest->radius)
	{
		smallest= cemberler[i];
	}	

	if(cemberler[i]->radius == 0)	printf("\nradius= %.2f", smallest->radius);
	else
	{
		i += 1;
		print_struct(cemberler, smallest, i, 0);
	}
	
}

/* calculates area, peimeter and radius of circles */
void hesaplama(circle *cemberler, int dairesayisi)
{
	double d= 0;
	int x[2]= {}, y[2]= {};

	for(int i= 0; i < dairesayisi; i++)
	{
		x[0]= cemberler[i].points[0].x;
		y[0]= cemberler[i].points[0].y;
		x[1]= cemberler[i].points[1].x;
		y[1]= cemberler[i].points[1].y;
		
		d= sqrt((x[1]- x[0])*(x[1]- x[0]) + (y[1]- y[0])*(y[1]- y[0]));

		cemberler[i].area= (float)(pi *d *d);
		cemberler[i].perimeter= (float)(2 *pi *d);
		cemberler[i].radius= (float)d;
		printf("\narea= %.2f perimeter= %.2f radius= %.2f", cemberler[i].area, cemberler[i].perimeter, cemberler[i].radius);
		printf("\ncenter x, y= %d %d", cemberler[i].points[0].x, cemberler[i].points[0].y);
		printf("\nP x, y= %d %d\n", cemberler[i].points[1].x, cemberler[i].points[1].y);

	}
}

/* Checks if given number is a prime or not */
int is_prime(int sayi)
{
	if (sayi < 2)
		return (0);

	int kontrol= sayi/2;
	
	while (kontrol <= sayi && kontrol > 1)
	{
		if(sayi % kontrol == 0)
			return (0);
		kontrol--;
	}
	return (1);
}

/* Finds and prints the prime multipliers of given number */
void factorization(int sayi)
{
	int sayib2= sayi /2, toplamasal= buffersize, asalsayisi= 0;
	int *asalsayilar= (int*)calloc(toplamasal, sizeof(int));

	/* creates a multiplier array */
	for(int i= 0; i < sayib2; i++)
	{
		if(i == toplamasal)
		{
			asalsayilar= realloc(asalsayilar, toplamasal +buffersize);
			toplamasal += 5;
		}
		if(is_prime(i) == 1)	asalsayilar[asalsayisi++]= i;
	}

	while(sayi > 0)
	{
		if(sayi %(*asalsayilar) == 0)
		{
			printf("sayi= %3d /%3d= %3d\t%3d is multiplier\n", sayi, *asalsayilar, sayi / *asalsayilar, *asalsayilar);
			sayi /= *asalsayilar;
			if(sayi == 0) break;
		}
		else
		{
			asalsayilar++;
		}
	}
}

