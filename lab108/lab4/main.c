#include <stdio.h>

void menu1();
void menu2();
void menu3();
int total(int (*mult)(int, int), int (*sum)(int, int));
void print_days(int day);
void readOrderFile(void (*print_days)(int), int id, int day);
int mult(int a, int b);
int sum(int a, int b);


typedef enum 
{
	sunday, monday, tuesday, wedensday, thursday, friday, saturday,
} Days;

typedef enum 
{
	harddisk, monitor, keyboard, mouse,
} Products;

typedef enum 
{
	buy= 1, orders, prices, exit,
} Selections;

typedef enum 
{
	hd= 2, mnt= 5, key= 3, mos= 10,
} Prices;

typedef enum 
{
	dolar= 4 , euro= 5 , pound= 9 , peso= 10,
} Currencies;

int main()
{
	short int secmeme, cIk=0, buymenu;

	do
	{
		//printf("\e[1;1H\e[2J");
		secmeme=0;
		printf("\nWelcome to the TechMarket.\n"
			   " 1. Buy Product\n"
			   " 2. Orders\n"
			   " 3. All Orders Prices\n"
			   " 4. EXIT\n"
			   " ---------------------------\n ");
		scanf("%hd",&secmeme);
		

		switch(secmeme)
		{
			case 0: 
				printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");

			case exit: 
				cIk= 1;
				break;
			case 6: 
				cIk= 1;
				break;

			case buy:

				menu1();
				
				break;	
			
			case orders:

				menu2();
				break;
			
			case prices:
			
				menu3();
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


void menu1()
{
	short int buymenu= 0, day= 0;

	printf("\nSelect your program:\n"
		" 0. Harddisk\n"
		" 1. Monitor\n"
		" 2. Keyboard\n"
		" 3. Mouse\n"
		" ---------------------------\n ");
	scanf("%hd",&buymenu);
	
	if(buymenu > 3 || buymenu < 0)	
	{
		printf("\nHatali tuslama yaptiniz.\n\n");
		return;
	}

	printf("Select your arrival day[0-6]:\n"
		   " Sunday, Monday, Tuesday, Wedensday, Thursday, Friday, Saturday\n"
		   " ---------------------------\n ");
	scanf("%hd",&day);

	if(day > 6 || day < 0)
	{
		printf("\nHatali tuslama yaptiniz.\n\n");
		return;
	}

	FILE *dosya= fopen("orders.txt", "a");

	fprintf(dosya, "%d %d ", buymenu, day);
	fclose(dosya);

}

void menu2()
{
	int day, id;
	FILE *dosya= fopen("orders.txt", "r");
	while(feof(dosya) == 0)
	{
		fscanf(dosya, "%d %d ", &id, &day);
		readOrderFile(print_days, id, day);
	}
	
	fclose(dosya);
		
}

void menu3()
{
	int day, id, totalx= 0;
	FILE *dosya= fopen("orders.txt", "r");
	while(feof(dosya) == 0)
	{
		fscanf(dosya, "%d %d ", &id, &day);
		readOrderFile(print_days, id, day);
	}
	
	fclose(dosya);
	printf("\nTotal prices: %d TL\n", total(mult, sum));
}

void print_days(int day)
{
	if(day == 0)	printf("%s", "Sunday\n");
	if(day == 1)	printf("%s", "Monday\n");
	if(day == 2)	printf("%s", "Tuesday\n");
	if(day == 3)	printf("%s", "Wedensday\n");
	if(day == 4)	printf("%s", "Thursday\n");
	if(day == 5)	printf("%s", "Friday\n");
	if(day == 6)	printf("%s", "Saturday\n");
}

void readOrderFile(void (*print_days)(int), int id, int day)
{
	printf("ProductID: %d, ", id);
	print_days(day);
}

int mult(int a, int b)
{
	return a *b;
}

int sum(int a, int b)
{
	return a +b;
}

int total(int (*mult)(int, int), int (*sum)(int, int))
{
	int day, id, toplam= 0;
	FILE *dosya= fopen("orders.txt", "r");
	while(feof(dosya) == 0)
	{
		fscanf(dosya, "%d %d ", &id, &day);
		if(id == 0)	toplam= sum(toplam, mult(hd, dolar));
		if(id == 1)	toplam= sum(toplam, mult(mnt, euro));
		if(id == 2)	toplam= sum(toplam, mult(key, pound));
		if(id == 3)	toplam= sum(toplam, mult(mos, peso));
	}
	
	fclose(dosya);
	return toplam;
}
