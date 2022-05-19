#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define buffer 5

typedef struct book
{
	char title[30];
	char author[50];
	char subject[120];
	int year;
} book;


void list(book *books, int kitapsayisi);
void kitapbas(book *books, int kitapsayisi, int *sira);
int kitapara(char *kitabinozelligi, int kitapsayisi, char *aranacak);
int kitapligibuyut(book **booksunadresi, int kutuphaneboyutu);
void memoriyikopyala(char *dest, char *src ,int boyut);


int main()
{
	short int seksenalti, cIk=0;

	book *books= (book *)calloc(buffer, sizeof(book));
	int kitapsayisi= 0, kutuphaneboyutu= buffer;

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		seksenalti=0;
		printf("\n\nChoose the operation\n"					//
			   "--------------------------------\n"			//
			   "1. Add New Book\n"							//
			   "2. List Books\n"							//	Menu
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&seksenalti);
		while(getchar() != '\n');

		if(seksenalti==6) cIk=1;

		else if(seksenalti==1)
		{
			printf("\nPlease enter book title = ");
			scanf("%[^\n]%*c", books[kitapsayisi].title);

			printf("\nPlease enter book author = ");
			scanf("%[^\n]%*c", books[kitapsayisi].author);

			printf("\nPlease enter book subject = ");
			scanf("%[^\n]%*c", books[kitapsayisi].subject);

			printf("\nPlease enter book year = ");
			scanf("%d", &books[kitapsayisi].year);

			kitapsayisi++;
			//printf("\n(main:) kitapsayisi= %d kitapsayisi %cbufferSize= %d", kitapsayisi, '%', kitapsayisi %bufferSize);
			if(kitapsayisi %buffer == 0)	kutuphaneboyutu= kitapligibuyut(&books, kutuphaneboyutu);
		}
		else if(seksenalti==2)
		{
			list(books, kitapsayisi);
		}
		else
			printf("\nHatali option\n\n");
		
		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			//while(getchar() != '\n');
			while(getchar() != '\n') /* nothing happens */;
		}
	}

	return 0;
}


void list(book *books, int kitapsayisi)
{
	short int nezamandir, cIk=0;

	char bosyer[500];

	int temp;

	int *sira= (int *)calloc(kitapsayisi, sizeof(int));
	int *inx= (int *)calloc(kitapsayisi, sizeof(int));

	for(int i= 0; i < kitapsayisi; i++)	
	{
		sira[i]= i;
		inx[i]= i;
	}

	

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		nezamandir=0;
		printf("\n\nChoose the operation\n"					//
			   "--------------------------------\n"			//
			   "1. Get by Title\n"							//
			   "2. Get by Author\n"							//
			   "3. Get by Subject\n"						//
			   "4. Sorted List by Year (DESC)\n"			//
			   "5. List All Books\n"						//	Menu
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&nezamandir);
		while(getchar() != '\n');

		if(nezamandir==6) cIk=1;

		else if(nezamandir==1)
		{
			printf("Enter a book title = ");
			scanf("%[^\n]%*c", bosyer);
			//while(getchar() != '\n');

			//printf("\n(List:) books[0].title= %llu", books[0].title);
			
			int kacincikitap= kitapara(books[0].title, kitapsayisi, bosyer);
			if(kacincikitap == -1) //Kitap bulamadi demek
				printf("\nTRY AGAIN\n\n");
			else
			{
				printf("Book found\n");
				kitapbas(books +kacincikitap, 1, sira); //O buldugun bir tane kitabi bas
			}
			
			
		}
		else if(nezamandir==2)
		{
			printf("Enter a book author = ");
			scanf("%[^\n]%*c", bosyer);
			//while(getchar() != '\n');

			//printf("\n(List:) books[0].title= %llu", books[0].title);
			
			int kacincikitap= kitapara(books[0].author, kitapsayisi, bosyer);
			if(kacincikitap == -1) //Kitap bulamadi demek
				printf("\nTRY AGAIN\n\n");
			else
			{
				printf("Book found\n");
				kitapbas(books +kacincikitap, 1, sira); //O buldugun bir tane kitabi bas
			}
		}
		else if(nezamandir==3)
		{
			printf("Enter a book subject = ");
			scanf("%[^\n]%*c", bosyer);
			//while(getchar() != '\n');

			//printf("\n(List:) books[0].title= %llu", books[0].title);
			
			int kacincikitap= kitapara(books[0].subject, kitapsayisi, bosyer);
			if(kacincikitap == -1) //Kitap bulamadi demek
				printf("\nTRY AGAIN\n\n");
			else
			{
				printf("Book found\n");
				kitapbas(books +kacincikitap, 1, sira); //O buldugun bir tane kitabi bas
			}
			
			
		}
		else if(nezamandir==4)
		{
			int i = 0, devamke = 1, reg= 0, n= kitapsayisi;

			i= 0;
			while (devamke == 1)
			{
				devamke = 0;
				while (i < n - 1)
				{
					if (  books[ inx[i] ].year <  books[ inx[i+1] ].year )
					{	
						reg= inx[i];
						inx[i]= inx[i +1];
						inx[i +1]= reg;

						devamke = 1;
					}
					i++;
				}
				if (i == n -1)
					i = 0;
				n--;
				//printf("\nxd\n");
			}

			printf("\nList of Books\n"
				   "*****************************");
			kitapbas(books, kitapsayisi, inx);
			
		}
		else if(nezamandir==5)
		{
			printf("\nList of Books\n"
				   "*****************************");
			kitapbas(books, kitapsayisi, sira);
			
		}
		else
			printf("\nHatali option\n\n");
		
		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			//while(getchar() != '\n');
			while(getchar() != '\n') /* nothing happens */;
		}
	}
}


void kitapbas(book *books, int kitapsayisi, int *sira)
{
	int i= 0;

	while(i < kitapsayisi)
	{
		if(kitapsayisi > 1)
			printf("\n%d.Book", i +1);
		printf("Title => %s\n", books[sira[i]].title);
		printf("Author => %s\n", books[sira[i]].author);
		printf("Subject => %s\n", books[sira[i]].subject);
		printf("Year => %d\n", books[sira[i]].year);
		printf("**********************\n");
		i++;
	}
}

int kitapara(char *kitabinozelligi, int kitapsayisi, char *aranacak)
{
	int i= 0;
	int varmi= 0;

	while(i < kitapsayisi)
	{
		//printf("\n(kitapara:) i= %d (kit]gi + i*si]ok)= %llu\n(kit](book)= %s", i, (kitabinozelligi + i*sizeof(book)), (kitabinozelligi + i*sizeof(book)));
		varmi= strcmp(aranacak, (kitabinozelligi + i*sizeof(book)));
		if(varmi == 0) //Kitabi bulunca 0 veriyo
		{
			return i;
		}
		i++;
	}

	return -1;
}

int kitapligibuyut(book **booksunadresi, int kutuphaneboyutu)
{
	book *yenikitaplik= (book *)calloc(kutuphaneboyutu +buffer, sizeof(book));
	memoriyikopyala( (char *)yenikitaplik, (char *)(*booksunadresi), (sizeof(book) *kutuphaneboyutu) );

	//printf("\n(kitapligibuyut:) boyut= %llu kitapkapasitesi +buffer= %d", sizeof(book), kitapkapasitesi +buffer);

	free(*booksunadresi);
	*booksunadresi= yenikitaplik;
	
	return kutuphaneboyutu +buffer;
}

void memoriyikopyala(char *dest, char *src, int boyut)
{
	int i= 0;
	while(i < boyut )
	{
		//if(src[i]==0||(src[i]<127&&src[i]>31))
		//{
			dest[i] = src[i];
			//printf("\ndest[%d]= %c src[%d]= %c ", i, dest[i], i, src[i]);
		//}
		i++;
	}
}



