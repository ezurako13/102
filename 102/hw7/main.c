#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define boy 15
#define bosluk '.'
#define yy 0
#define xx 1
#define NUMKELIME 7

typedef enum 
{
	sag, sagyukari, yukari, solyukari, sol, solasagi, asagi, sagasagi
} yonler;

typedef struct directions
{
	int y;
	int x;
} directions;

char randomHarflerTahtasi[boy][boy]= {};
char renklerTahtasi[boy][boy]= {};
int kacincikelime= 1;


void yazdir(char board[][boy]);
char *giveRandomKelime(char *kelime, int *kullanilanlar, int kelimeSayisi);
void randomKelimeYerlestir(char board[][boy], directions *yon, int *kullanilanlar);
int placeWord(char board[][boy], char *kelime, int len, int x, int y);
int findWord(char board[][boy], char *kelime, directions *yon, int yer[]);
void game(char board[][boy], directions *yon);


int main()
{
	short int Eyvah, cIk=0;

	char board[boy][boy]= {};
	int kullanilanlar[200]= {};

	directions yon[8]= {{0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}};

	//for(int i= 0; i < 8; i++)
		//printf("\nyon[i].y= %2d  yon[i].x= %2d", yon[i].y, yon[i].x);


	srand(time(0));

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		Eyvah=0;
		printf("\n\nChoose a operation\n"					//
			   "--------------------------------\n"			//
			   "1. Build Board\n"							//
			   "2. Random kelime yerlestir\n"				//	Menu
			   "3. Play\n"							//
			   "4. \n"									//
			   "5. \n"								//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&Eyvah);
		while(getchar() != '\n');

		if(Eyvah==0) printf("\nWhy are you so insistent about entering zeros\n\n");
		if(Eyvah==6) cIk=1;

		if(Eyvah==1)
		{
			for(int i= 0; i < boy; i++)
				for(int o= 0; o < boy; o++)
				{
					randomHarflerTahtasi[i][o]= rand() %('z' -'a') +'a';
					board[i][o]= bosluk;
				}
			yazdir(board);

		}
		if(Eyvah==2)
		{
			for(int i= 0; i < NUMKELIME; i++)
			{
				randomKelimeYerlestir(board, yon, kullanilanlar);
			}
			yazdir(board);


		}
		if(Eyvah==3)
		{
			game(board, yon);
		}
		if(Eyvah==4)
		{
			
		}
		if(Eyvah==5)
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


char *giveRandomKelime(char *kelime, int *kullanilanlar, int kelimeSayisi)
{
	FILE *list= fopen("wordlist.txt", "r");
	int rastgele= 0;

	
	do
		rastgele= rand() %50;
	while(kullanilanlar[rastgele] == 1);
	
	kullanilanlar[rastgele]= 1;

	for(int i= 0; i < rastgele; i++)
		while(getc(list) != '\n');

	fscanf(list, "%s", kelime);
	//printf("\nxd\n");

	fclose(list);
	return kelime;
}

void yazdir(char board[][boy])
{
	printf("\n\n");
	printf("   ");
	for(int o= 0; o < boy; o++)
		printf("\033[1;36m%-2d\033[0m", o);
	printf("\n");
	
	for(int i= 0; i < boy; i++)
	{
		for(int o= -1; o < boy; o++)
		{
			if(o == -1) printf("\033[1;36m%2d \033[0m", i);
			else if(renklerTahtasi[i][o] > 0)	printf("\033[1;31m%-2d\033[0m", renklerTahtasi[i][o]);
			else	printf("%-2d", renklerTahtasi[i][o]);
		}
		printf("\n");
	}

	printf("\n\n");
	printf("   ");
	for(int o= 0; o < boy; o++)
		printf("\033[1;36m%-2d\033[0m", o);
	printf("\n");


	for(int i= 0; i < boy; i++)
	{
		for(int o= -1; o < boy; o++)
		{
			if(renklerTahtasi[i][o] == 1)	printf("\033[1;32m");
			if(renklerTahtasi[i][o] == 2)	printf("\033[1;33m");
			if(renklerTahtasi[i][o] == 3)	printf("\033[1;34m");
			if(renklerTahtasi[i][o] == 4)	printf("\033[1;35m");
			if(renklerTahtasi[i][o] == 5)	printf("\033[1;36m");
			if(renklerTahtasi[i][o] == 6)	printf("\033[1;33m");
			if(renklerTahtasi[i][o] == 7)	printf("\033[1;35m");
			if(o == -1) printf("\033[1;36m%2d \033[0m", i);
			else if(board[i][o] == 'X')	printf("\033[1;31m%c \033[0m", board[i][o]);
			else if(renklerTahtasi[i][o] > 28)	printf("\033[1;35m%c \033[0m", board[i][o]);
			else if(renklerTahtasi[i][o] > 21)	printf("\033[1;34m%c \033[0m", board[i][o]);
			else if(renklerTahtasi[i][o] > 14)	printf("\033[1;33m%c \033[0m", board[i][o]);
			else if(renklerTahtasi[i][o] > 7)	printf("\033[1;32m%c \033[0m", board[i][o]);
			//else if(renklerTahtasi[i][o] <= 7 && renklerTahtasi[i][o] > 0)	printf("\033[1;31m%c \033[0m", board[i][o]);
			else if(board[i][o] != bosluk)	printf("%c \033[0m", board[i][o]);
			//else	printf("%c ", board[i][o]);
			else if(board[i][o] == '.')	printf("\033[0m%c ", randomHarflerTahtasi[i][o]);
			else	printf("\033[0m%c ", board[i][o]);
		}
		printf("\n");
	}
}

void randomKelimeYerlestir(char board[][boy], directions *yon, int *kullanilanlar)
{
	char kelime[10];
	int place[2], yer[2], hafiza= 0, temp= 0, temper= 0, yazamadim= 0, sayac= 0;
	int secilenyon= rand() %8;
	int kelimeSayisi= 0;

	FILE *list= fopen("wordlist.txt", "r");
	while(feof(list) == 0)
	{
		//printf("\naaa");
		if( (temp= getc(list)) == '\n' )	kelimeSayisi++;
		if(temp == EOF)
		{
			kelimeSayisi++;
			if(hafiza == '\n')	kelimeSayisi--;
		}	
		hafiza= temp;
	}

	//printf("\nkelimeSayisi= %d\n", kelimeSayisi);

	fclose(list);

	sprintf(kelime, "tavuklar");

	giveRandomKelime(kelime, kullanilanlar, kelimeSayisi);
	printf("\nkelime 2: %s", kelime);

	int len= strlen(kelime);

	do
	{
		yazamadim= 0;
		sayac++;
		//printf("\n%d\n", sayac);

		do
		{
			place[yy]= rand() %boy;
			place[xx]= rand() %boy;

			//printf("\ntemp= %d", temp);
			//printf("\ntemper= %d", temper);
			//printf("\nplace[yy]= %d len= %d, yon[secilenyon].y= %d"
			//		, place[yy], 	len, 	 yon[secilenyon].y);
			//printf("\nplace[xx]= %d len= %d, yon[secilenyon].x= %d\n"
			//		, place[xx], 	len, 	 yon[secilenyon].x);

		} while( (temp= place[yy] +(len *yon[secilenyon].y)) >= boy || temp < 0
			||   (temper= place[xx] +(len *yon[secilenyon].x)) >= boy || temper < 0);


		for(int i= 0; i < len && yazamadim != 1 && sayac < 100; i++)
		{
			yer[yy]= place[yy] +(i *yon[secilenyon].y);
			yer[xx]= place[xx] +(i *yon[secilenyon].x);

			if(board[yer[yy]][yer[xx]] == kelime[i] || board[yer[yy]][yer[xx]] == bosluk)
			{
				if(board[yer[yy]][yer[xx]] != kelime[i])
				{
					board[yer[yy]][yer[xx]]= kelime[i];
					renklerTahtasi[yer[yy]][yer[xx]]= kacincikelime;
				}
			}
			else
			{
				//printf("\nboard[yer[yy]][yer[xx]]= %c kelime[i]= %c\n", board[yer[yy]][yer[xx]], kelime[i]);
				for(int o= i -1; o >= 0; o--)
				{
					if(renklerTahtasi[place[yy] +(o *yon[secilenyon].y)][place[xx] +(o *yon[secilenyon].x)] == kacincikelime)
					{
						board[place[yy] +(o *yon[secilenyon].y)][place[xx] +(o *yon[secilenyon].x)] = bosluk;
						renklerTahtasi[place[yy] +(o *yon[secilenyon].y)][place[xx] +(o *yon[secilenyon].x)] = 0;
					}
				}
				yazamadim= 1;
			}
		}
		
	} while(yazamadim == 1 && sayac < 100);

	printf("(%d, %d)", place[yy], place[xx]);
	kacincikelime++;

}

int findWord(char board[][boy], char *kelime, directions *yon, int yer[])
{
	int lens= strlen(kelime), secilenyon= sag, dogruKelime= 0;

	//printf("\n");

	for(secilenyon= sag; secilenyon <= sagasagi; secilenyon++)
	{
		//printf("secilenyon= %d\n", secilenyon);
		if(yer[yy] +(lens *yon[secilenyon].y) < 15 && yer[xx] +(lens *yon[secilenyon].x) < 15)
		{
			dogruKelime= 1;
			for(int i= 0; i < lens; i++)
			{
				//printf("board[y +i][x +i]= %c kelime[i]= %c\n"
				//, board[yer[yy] +(i *yon[secilenyon].y)][yer[xx] +(i *yon[secilenyon].x)], kelime[i]);

				if(board[yer[yy] +(i *yon[secilenyon].y)][yer[xx] +(i *yon[secilenyon].x)] != kelime[i])	
					dogruKelime= 0;
			}
			//printf("\n");
			if(dogruKelime == 1)
			{
				for(int i= 0; i < lens; i++)
					board[yer[yy] +(i *yon[secilenyon].y)][yer[xx] +(i *yon[secilenyon].x)]= 'X';
				return 1;
			}
		}

	}

	return 0;
}

void game(char board[][boy], directions *yon)
{
	int gameover= 0, lefts= 3, points= 0, kalankelime= NUMKELIME;
	int yer[2]= {};
	char kelime[100]= {};

	yazdir(board);
	
	while(gameover != 1)
	{
		yer[yy]= 0;
		yer[xx]= 0;

		printf("\nEnter cordinates and word: ");
		scanf("%d%d", &yer[yy], &yer[xx]);
		scanf("%s", kelime);
		while(getchar() != '\n');

		if(strcmp(kelime, ":q") == 0)
			gameover= 1;
		else
		{
			if(findWord(board, kelime, yon, yer) == 0)
			{
				lefts--;
				if(lefts == 0)
					gameover= 1;
				else
					printf("\nWrong choice! You have only %d lefts.\n", lefts);
				
			}
			else
			{
				kalankelime--;
				if(kalankelime == 0)	gameover= 1;
				points += 2;
				if(gameover != 1)
					yazdir(board);
				printf("\nFounded! You got 2 points. Your total points: %d\n", points);
			}
		}
	}
	
	yazdir(board);
	printf("\nGame is over! Your total points is %d\n", points);
}
