#include <stdio.h>
#include <string.h>

#define x 0
#define y 1


typedef struct
{
	float a[2];
	float b[2];
	float c[2];
	float egim;
} line;

typedef struct
{
	float midterm;
	float final;
	float homework;
	float average;
} grades;

typedef struct
{
	char name[40];
	int ID;
	grades grades;
} students;

typedef struct
{
	char name[40];
	char platforms[20][40];
	int platformsayisi;
	float score;
} games;


void dogruAl(line *dogru);
char *th(int sonbasamak);
void yazdirstdnt(students xd);
int idvarmi(students stdnt[], int ogrenci, int id);
void sonuclar(games gm[], int oyun, char *platformlar[40], int sayiofplarform);
int platformvarmi(char *platformlar[40], int sayiofplarform, char *platform);

int main()
{
	short int sacma, cIk=0;
	students stdnt[1024];
	int ogrenci= 0;
	games gm[1024];
	int oyun= 0;
	char *platformlar[40];
	int sayiofplatform= 0;
	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		sacma=0;
		printf("\n\nChoose a Task to Perform\n"
			"1. Calculate both slope and y coordinate of the third point\n"
			"2. Add students and calculate grades\n"
			"3. Choose a student by id number and show information\n"
			"4. Game library\n"
			"6. Exit\n\n");
		scanf("%hd",&sacma);

		if(sacma==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(sacma==6) cIk=1;
		if(sacma==1)
		{    
			line dogru;
			dogruAl(&dogru);

			printf("x3= ");
			scanf("%f",&dogru.c[x]);
			dogru.c[y]= (dogru.egim*dogru.c[x]) + (dogru.a[y] - (dogru.egim*dogru.a[x]));
			printf("\n\nSlope of the Line is %f\n", dogru.egim);
			printf("\ny3= %f\n", dogru.c[y]);

		}
		if(sacma==2)
		{
			int kactane= 0;
			printf("\nEnter number of students you want to add\n");
			scanf("%d",&kactane);
			kactane += ogrenci;
			while(ogrenci < kactane)
			{
				printf("\nEnter name of the %d%s student:", ogrenci +1, th(ogrenci +1));
				fflush(stdin);
				scanf("%[^\n]%*c", stdnt[ogrenci].name);

				int id= 0, varmi= 0;
				printf("\nEnter id of %s:", stdnt[ogrenci].name);
				
				do
				{
					scanf("%d", &id);
					varmi= idvarmi(stdnt, ogrenci, id);
					if(varmi)	printf("\nThis id has already been used. Please enter another id\n");
				}
				while(varmi);

				stdnt[ogrenci].ID= id;

				printf("\nEnter midterm grade of %s:", stdnt[ogrenci].name);
				scanf("%f", &stdnt[ogrenci].grades.midterm);
				printf("\nEnter homework grade of %s:", stdnt[ogrenci].name);
				scanf("%f", &stdnt[ogrenci].grades.homework);
				printf("\nEnter final grade of %s:", stdnt[ogrenci].name);
				scanf("%f", &stdnt[ogrenci].grades.final);

				stdnt[ogrenci].grades.average= (stdnt[ogrenci].grades.midterm +stdnt[ogrenci].grades.homework +stdnt[ogrenci].grades.final) /3;
				printf("\nAverage of student's grades is %f\n", stdnt[ogrenci].grades.average);
				ogrenci++;
			}
			//printf("\nogrenci= %d kactane= %d\n", ogrenci, kactane);
		}
		if(sacma==3)
		{
			int i= 0;
			int nthid= 0;
			int girdi= 0;
			printf("\nEnter id of the student you want to check: ");
			scanf("%d", &nthid);

			//printf("\n3ogrenci= %d i= %d\n", ogrenci, i);
			//yazdirstdnt(stdnt[i]);

			while(i < ogrenci)
			{
				//printf("\nstdnt[i].ID= %d nthid= %d\n", stdnt[i].ID, nthid);
				if(nthid == stdnt[i].ID)
				{
					yazdirstdnt(stdnt[i]);
					i= ogrenci;
					girdi= 1;
				}
				i++;
			}

			if(girdi != 1) printf("\nThere isn't such a student\n");

		}
		if(sacma==4)
		{
			//Oyun sayisi
			int kactane= 0;
			printf("\nEnter number of games you want to add\n");
			//scanf("%d",&kactane);
			kactane= 2;
			
			kactane += oyun;

			while(oyun < kactane)
			{
				//Name
				printf("\nEnter name of the %d%s game: ", oyun +1, th(oyun +1));
				//fflush(stdin);
				//scanf("%[^\n]%*c", gm[oyun].name);
				if(oyun == 0)	strcpy(gm[oyun].name, "breath of the wild");
				if(oyun == 1)	strcpy(gm[oyun].name, "windwaker hd");
				printf("%s", gm[oyun].name);

				//Platform sayisi
				int i= 0;
				printf("\nEnter number of platforms %s can be played: ", gm[oyun].name);
				//scanf("%d", &gm[oyun].platformsayisi);
				gm[oyun].platformsayisi= 2;
				printf("%d", gm[oyun].platformsayisi);

				//Platformlar
				while(i < gm[oyun].platformsayisi)
				{
					
					printf("\nEnter the %d%s platform: ", i +1, th(i +1));
					//fflush(stdin);
					//scanf("%[^\n]%*c", gm[oyun].platforms[i]);
					if(i == 0 && oyun == 0) strcpy(gm[oyun].platforms[i], "ps5");
					if(i == 0 && oyun == 1) strcpy(gm[oyun].platforms[i], "switch");
					if(i == 1 && oyun == 0) strcpy(gm[oyun].platforms[i], "wii u");
					if(i == 1 && oyun == 1) strcpy(gm[oyun].platforms[i], "ps5");
					printf("%s", gm[oyun].platforms[i]);

					if(platformvarmi(platformlar, sayiofplatform, gm[oyun].platforms[i]) == 0)
					{
						platformlar[sayiofplatform]= gm[oyun].platforms[i];
						sayiofplatform++;
					}
					//printf("\ni= %d oyun= %d sayiofplatform= %d\n", i, oyun, sayiofplatform);
					i++;
				}

				//Score
				printf("\nEnter score of %s:", gm[oyun].name);
				//scanf("%f", &gm[oyun].score);
				if(oyun == 0)	gm[oyun].score= 9.21;
				if(oyun == 1)	gm[oyun].score= 7.56;
				printf("%.3f\n", gm[oyun].score);

				oyun++;
			}
			//for(int a= 0; a < 4; a++)	printf("platformlar[%d]= %s\n", a, platformlar[a]);
			//printf("\noyun= %d sayiofplatform= %d\n", oyun, sayiofplatform);
			sonuclar(gm, oyun, platformlar, sayiofplatform);
			//printf("\nxd\n");
		}

		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			while(getchar() != '\n');
			while(getchar() != '\n') /* nothing happens */;
		}
	}


return 0;
}



void dogruAl(line *dogru)
{
	printf("\nx1= ");
	scanf("%f",&dogru->a[x]);
	printf("y1= ");
	scanf("%f",&dogru->a[y]);
	printf("x2= ");
	scanf("%f",&dogru->b[x]);
	printf("y2= ");
	scanf("%f",&dogru->b[y]);
	
	dogru->egim= (dogru->b[y]-dogru->a[y]) / (dogru->b[x]-dogru->a[x]);
}

char *th(int sonbasamak)
{
	if(sonbasamak %100 > 20)  sonbasamak %= 10;

	if		(sonbasamak == 1)	return "st";
	else if	(sonbasamak == 2)	return "nd";
	else if	(sonbasamak == 3)	return "rd";
	else						return "th";
}

void yazdirstdnt(students xd)
{
	printf("\n");
	printf("\nName-Surname: %s", xd.name);
	printf("\nID: %d", xd.ID);
	printf("\nMidterm grade: %f", xd.grades.midterm);
	printf("\nHomework grade: %f", xd.grades.homework);
	printf("\nFinal grade: %f", xd.grades.final);
	printf("\nAverage grade: %f", xd.grades.average);
	printf("\n");
}

int idvarmi(students stdnt[], int ogrenci, int id)
{
	while(--ogrenci >= 0)
	{
		if(stdnt[ogrenci].ID == id)	return 1;
	}

	return 0;
}

void sonuclar(games gm[], int oyun, char *platformlar[40], int sayiofplarform)
{
	float ortalama= 0;
	int i= -1;
	int o= 0;

	while(++i < oyun)
		ortalama += gm[i].score;
	ortalama /= oyun;

	printf("\n");
	printf("\nAverage of the scores of the games: %.3f\n", ortalama);

	i= 0;
	while(i < sayiofplarform)
	{
		o= 0;
		printf("\n\n%s games: ", platformlar[i]);
		while(o < oyun)
		{
			//printf("\ngm[o].name= %s gm[o].platformsayisi= %d gm[o].platforms= %s", gm[o].name, gm[o].platformsayisi, gm[o].platforms[o]);
			int varmi= platformvarmi((char **)gm[o].platforms, gm[o].platformsayisi, platformlar[i]);
			//printf("\nxda\n");
			
			//printf("\noyun= %d o= %d i= %d sayiof= %d", oyun, o, i, sayiofplarform);
			if(varmi)
			{
				if(o == 0)
					printf("%s", gm[o].name);
				else if(o != oyun -1)
					printf(", %s", gm[o].name);
					
			}
			printf("%s.", gm[o].name);
			o++;
		}
		i++;
	}
	printf("\n");
}

int platformvarmi(char *platformlar[40], int sayiofplarform, char *platform)
{
	int i= 0;
	//printf("\nplatformlar= ");
	//for(int a= 0; a < 4; a++)	printf("platformlar[%d]= %s\n", a, platformlar[a]);
	while(i < sayiofplarform)
	{
		//printf("%s	", platformlar[i]);
		//printf("\ni= %d sayiof= %d platformlar[i]= %s platform= %s\n", i, sayiofplarform, platformlar[i], platform);
		//printf("strcmp(platform, platformlar[i])= %d\n\n\n", strcmp(platform, platformlar[i]));
		if(strcmp(platform, platformlar[i]) == 0)	return 1;
		//printf("\nxxdd\n");
		i++;
	}
	//printf("tavuk\n");

	return 0;
}
