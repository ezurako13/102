#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cy 0
#define cx 1
#define renk1 "\033[1;33m"
#define renk2 "\033[1;34m"
#define solduvar ':'
#define sagduvar ':'
#define taban '.'
#define wdt 30		//Width
#define hgt 15		//Height

void initializeMap(char area[][wdt]);
void printMap(char area[][wdt]);
int dice ();
char startGame();
void kaydet(int y, int x, int sonikiyer[][2]);
int sonrakiadim(int player[2], char area[][wdt], int zar, int sonikiyer[][2], char indicator);
int birimyuru(int yer[2], char area[][wdt], int sonikiyer[][2]);
int kosullarisagla(int y, int x, char area[][wdt]);
void placeplayer(int player[2], char area[][wdt], int sonikiyer[][2], char indicator);


int main()
{
	short int secmeme, cIk=0;

	srand(time(0));

	char area[hgt][wdt]= {};
	/*
	char area[15][30]={"..............................",
					   ":1            X              :",
					   ":_.......................... :",
					   ": :2      X       X        : :",
					   ": :_.................X.... : :",
					   ": : :                    :X: :",
					   ": : :                    : : :",
					   ": : :                    : :X:",
					   ": : :                    : : :",
					   ": : :                    : : :",
					   ": : ......................X: :",
					   ": :        X       X       : :",
					   ": .......................... :",
					   ":              X             :",
					   "..............................",};
	*/

	int alanVar= 0, playing= 0;
	int player1[2], player2[2];
	char baslayan= 0, kazanan= 0;
	int sonikiyer1[2][2]= {}, sonikiyer2[2][2]= {};

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		secmeme=0;
		printf("\n\nChoose a operation\n"					//
			   "--------------------------------\n"			//
			   "1. Initialize map\n"						//
			   "2. Print map\n"								//	Menu
			   "3. Start game\n"							//
			   "4. Play\n"									//
			   "5. Deneme\n"								//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&secmeme);
		while(getchar() != '\n');

		if(secmeme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secmeme==6) cIk=1;

		if(secmeme==1)
		{
			initializeMap(area);
			player1[cx]= 1;
			player1[cy]= 1;
			player2[cx]= 3;
			player2[cy]= 3;

			playing= 0;
			alanVar= 1;
		}
		if(secmeme==2)
		{
			if(alanVar == 1)	printMap(area);
			else	printf("\nThe map hasn't been initialized yet.\n");
		}
		if(secmeme==3)
		{
			if(alanVar == 0)	printf("\nThe map hasn't been initialized yet.\n");
			else if(playing == 1)	printf("\nThe game has already been started.\n");
			else
			{
				printf("\nTo start game, players should dice and" 
		   			   "decide who is going start first according to it...\n");

				while( (baslayan= startGame()) == 0)
					printf("\nSame dice value... Please try again.");

				if(baslayan == '1')			printf("\n \033[1;33m*** PLAYER 1 will start game... ***\033[0m");
				else if(baslayan == '2')	printf("\n \033[1;34m*** PLAYER 2 will start game... ***\033[0m");

				playing= 1;
			}

		}
		if(secmeme==4)
		{
			int bitti= 0, zar= dice();
			if(playing == 0)	printf("\nThe game hasn't been started yet.\n");
			else if(alanVar == 0)	printf("\nThe map hasn't been initialized yet.\n");
			else
			{
				placeplayer(player1, area, sonikiyer1, '1');
				placeplayer(player2, area, sonikiyer2, '2');
				printMap(area);
				if(baslayan == '2')
				{
					printf("\n%sPLAYER 2... press enter to dice%s", renk2, "\033[0m");
					while(getchar() != '\n') /* nothing happens */;

					zar= dice();
					printf("%sDICE: %d%s\n", "\033[1;34m", zar, "\033[0m");

					bitti= sonrakiadim(player2, area, zar, sonikiyer2, '2');

				}
				while(bitti != 1)
				{
					printf("\n%sPLAYER 1... press enter to dice%s", renk1, "\033[0m");
					while(getchar() != '\n') /* nothing happens */;

					zar= dice();
					printf("%sDICE: %d%s\n", renk1, zar, "\033[0m");

					bitti= sonrakiadim(player1, area, zar, sonikiyer1, '1');

					if(bitti == 1)
						kazanan= '1';

					else
					{
						if(baslayan == '2')
						printMap(area);

						printf("\n%sPLAYER 2... press enter to dice%s", renk2, "\033[0m");
						while(getchar() != '\n') /* nothing happens */;
						
						zar= dice();
						printf("%sDICE: %d%s\n", "\033[1;34m", zar, "\033[0m");

						bitti= sonrakiadim(player2, area, zar, sonikiyer2, '2');

						if(bitti == 1)	
							kazanan= '2';
					}
					if(baslayan == '1')
						printMap(area);
				}

				if(kazanan == '1')			printf("\n \033[1;33m*** PLAYER 1 WON THE GAME ***\033[0m\n");
				else if(kazanan == '2')		printf("\n \033[1;34m*** PLAYER 2 WON THE GAME ***\033[0m\n");
				printMap(area);
				
				playing= 1;
				alanVar= 0;
			}

		}
		if(secmeme==5)
		{
			int c= 0;
			int bitti= 0, sayac= dice();
			if(alanVar == 0)	printf("\nThe map hasn't been initialized yet.\n");
			else
			{
				printMap(area);
				while(c != '6')
				{
					while( (c= getchar() ) != '\n' && c != '6') /* nothing happens */;
					if(c == '6')	break;
					placeplayer(player1, area, sonikiyer1, ' ');
					for(int a =0; a < 1 && bitti != 1; a++)
					{
						bitti= birimyuru(player1, area, sonikiyer1);

					}
					placeplayer(player1, area, sonikiyer1, '1');
					printMap(area);
					if(bitti == 1)	printf("\nkazandin len helal len sana\n");
					else	printf("\nf*ck you\n");
				}
				while(getchar() != '\n');
				
			}
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

/* Creating alphabetical table */
void initializeMap(char area[][wdt])
{
	for(int y= 0; y < hgt; y++)
	{
		for(int x= 0; x < wdt; x++)
		{
			if(y == 1 && x == 1)	area[y][x]= '1';
			else if(y == 3 && x == 3)	area[y][x]= '2';
			else if( (y == 2 && x == 1) || (y == 4 && x == 3))	area[y][x]= '_';
			
			else if( ((y == 3 || y == hgt -4) && (x == wdt /2 -wdt /4  +2|| x == wdt/2 +wdt /4 -4) ) || 
					 (x == wdt -4 && (y == (hgt *2) /3 -hgt /3 || y == hgt -hgt /3) ) || 
					 (y == 1 && x == wdt /2 -1) || 
					 (y == hgt /2 && x == wdt -2) || 
					 (y == hgt -2 && x == wdt /2 -1))		area[y][x]= 'X';

			else if( (y == 0 || y == hgt -1) || 
				     ( (y == 2 || y == hgt -3) && (x > 1 && x < wdt -2) ) || 
			         ( (y == 4 || y == hgt -5) && (x > 3 && x < wdt -4) ) )	area[y][x]= taban;

			else if( (x == 0 || x == wdt -1) || 
					 ( (x == 2 || x == wdt -3) && (y > 1 && y < hgt -3) ) || 
					 ( (x == 4 || x == wdt -5) && (y > 3 && y < hgt -5) ) )	
			{
				if(x < hgt /2)	area[y][x]= solduvar;
				else	area[y][x]= sagduvar;
			}

			else	area[y][x]= ' ';
		}
	}
}

/*	penalty points:
		o For Player 1 -> (1, 14), (7, 28) and (13, 14)
		o For Player 2 -> (3, 10), (3, 18), (5, 26), (10, 26), (11, 10) and (11, 18)
*/

/* Prints the game area */
void printMap(char area[][wdt])
{
	for(int y= 0; y < hgt; y++)
	{
		for(int x= 0; x < wdt; x++)
		{
			//if( (y == 2 && x == 1) || (y == 4 && x == 3))	area[y][x]= '_';
			if(area[y][x] == '1')			printf("%s%c%s", renk1, '1', "\033[0m");
			else if(area[y][x] == '2')		printf("%s%c%s", renk2, '2', "\033[0m");
			else if(area[y][x] == '_')		printf("%s%c%s", "\033[1;32m", '_', "\033[0m");
			else if(area[y][x] == 'X')		printf("%s%c%s", "\033[1;31m", 'X', "\033[0m");
			//else if(area[y][x] == taban)	printf("%s%c%s", "\033[0m", taban, "\033[0m");
			//else if(area[y][x] == solduvar)	printf("%s%c%s", "\033[0m", solduvar, "\033[0m");
			//else if(area[y][x] == sagduvar)	printf("%s%c%s", "\033[0m", sagduvar, "\033[0m");
			else							printf("%c", area[y][x]);
		}
		printf("\n");
	}
}

/* Returns a random integer in a range of [1,6] */
int dice ()
{
	return rand() %6 +1;
}

/* Decides (according to dice numbers) and returns the # of the player
who will start the game. */
char startGame()
{
	//  plyr1    plyr2          
	int zar1= 0, zar2= 0;

	printf("\n%sPLAYER 1... press enter to dice%s", renk1, "\033[0m");
	//while(getchar() != '\n');
	while(getchar() != '\n') /* nothing happens */;

	zar1= dice();
	printf("%sDICE: %d%s\n", renk1, zar1, "\033[0m");

	printf("\n%sPLAYER 2... press enter to dice%s", renk2, "\033[0m");
	//while(getchar() != '\n');
	while(getchar() != '\n') /* nothing happens */;

	zar2= dice();
	printf("%sDICE: %d%s\n", renk2, zar2, "\033[0m");
	
	if(zar1 > zar2)	return '1';

	if(zar2 > zar1)	return '2';

	return 0;
}

void kaydet(int y, int x, int sonikiyer[][2])
{
	sonikiyer[0][cy]= sonikiyer[1][cy];
	sonikiyer[0][cx]= sonikiyer[1][cx];
	sonikiyer[1][cy]= y;
	sonikiyer[1][cx]= x;
}

int sonrakiadim(int player[2], char area[][wdt], int zar, int sonikiyer[][2], char indicator)
{
	int bitti= 0;
	placeplayer(player, area, sonikiyer, ' ');
	for(int a =0; a < zar && bitti != 1; a++)
	{
		bitti= birimyuru(player, area, sonikiyer);
	}
	placeplayer(player, area, sonikiyer, indicator);
	return bitti;
}

int birimyuru(int yer[2], char area[][wdt], int sonikiyer[][2])
{
	kaydet(yer[cy], yer[cx], sonikiyer);

	int sonuc= 0;
	//printf("\n(birimyuru:) yer[cx]= %d \tyer[cy]= %d", yer[cx], yer[cy]);
	
		
	if(yer[cx] > wdt /2 && area[yer[cy]][yer[cx] +1] == sagduvar)	//Saginda : varsa ve sagdaysan
	{
		//printf("\tR :");
		if(area[yer[cy] +1][yer[cx]] == taban)	//Altinda . varsa
			sonuc= kosullarisagla(yer[cy], --yer[cx], area);	//Move left
		else	//Altinda . yoksa
			sonuc= kosullarisagla(++yer[cy], yer[cx], area);	//Move down
	}
	else if(area[yer[cy]][yer[cx] -1] == solduvar)	//Solunda : varsa ve soldaysan
	{
		//printf("\tL :");
		if(area[yer[cy] -1][yer[cx]] == taban)	//Ustunde . varsa
			sonuc= kosullarisagla(yer[cy], ++yer[cx], area);	//Move right
		else
			sonuc= kosullarisagla(--yer[cy], yer[cx], area);	//Move up
	}
	else if(yer[cy] < hgt /2 && area[yer[cy] -1][yer[cx]] == taban)	//Ustunde . varsa ve yukardaysan
	{
		//printf("\tU :");
		sonuc= kosullarisagla(yer[cy], ++yer[cx], area);	//Move right
	}

	else if(area[yer[cy] +1][yer[cx]] == taban)	//Altinda . varsa ve alttaysan
	{
		//printf("\tD :");
		sonuc= kosullarisagla(yer[cy], --yer[cx], area);	//Move left
	}

	return sonuc;

}

int kosullarisagla(int y, int x, char area[][wdt])
{
	if(area[y][x] == '_')
		return 1;

	return 0;
}

void placeplayer(int player[2], char area[][wdt], int sonikiyer[][2], char indicator)
{
	if(area[player[cy]][player[cx]] == 'X')
	{
		if(indicator == '1')	printf("%sPenalty for player 1...\n%s", renk1, "\033[0m");
		if(indicator == '2')	printf("%sPenalty for player 2...\n%s", renk2, "\033[0m");
		player[cy]= sonikiyer[0][cy];
		player[cx]= sonikiyer[0][cx];
	}
	//if(area[player[cy]][player[cx]] == '_');
	area[player[cy]][player[cx]]= indicator;
}
