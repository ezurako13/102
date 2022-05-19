#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_table(char table[][26]);
void yaz_tahta(char table[][26]);
char encryption(char harf, char key, char table[][26]);
char decryption(char harf, char key, char table[][26]);

int main()
{
	short int secmeme, cIk=0;

	char table[26][26]= {};
	char key[200]= "CBA", keystream[200]= {};
	char text[200]= "ENUMERATED";
	char ciphertext[200]= {}, plaintext[200]= {};
	int keyuzun= 3, textuzun= 10;

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		secmeme=0;
		printf("\n\nChoose the matrix operation,\n"			//
			   "--------------------------------\n"			//
			   "1. Create table 2D\n"						//
			   "2. Tahtayi yazdir\n"						//	Menu
			   "3. Change key\n"							//
			   "4. Change text\n"								//
			   "5. Encryption\n"								//
			   "7. Decryption\n"								//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		scanf("%hd",&secmeme);

		if(secmeme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secmeme==6) cIk=1;

		if(secmeme==1)
		{
			char c;
			while(getchar() != '\n');
			for(int i = 0; i < 3; i++)
			{
				c = getchar();
				if(c == '\n')   c= getchar();
				plaintext[i] = c;
				printf("%c",plaintext[i]);
			}
			create_table(table);
		}
		if(secmeme==2)
		{
			yaz_tahta(table);
		}
		if(secmeme==3)
		{
			//printf("\nEnter key lenght\n");
			//scanf("%d", keyuzun);
			
			printf("\nEnter a key which consist of %d capital alphabethic characters\n", keyuzun);
			while(getchar() != '\n');
			for(int i= 0; i < keyuzun; i++)
			{
				key[i]= getchar();
				if(key[i] == '\n')	key[i]= getchar();
			}
		}
		if(secmeme==4)
		{
			//printf("\nEnter text lenght\n");
			//scanf("%d", textuzun);

			while(getchar() != '\n');
			for(int i= 0; i < textuzun; i++)
			{
				text[i]= getchar();
			}
		}
		if(secmeme==5)
		{
			int o= 0, i= 0;
			for(i= 0; i < textuzun; i++)
			{
				keystream[i]= key[o];
				o++;
				if(o >= keyuzun)	o= 0;
				//printf("%c", keystream[i]);
			}
			printf("\n\ntext:\n");
			for(i= 0; i < textuzun; i++)	printf("%c", text[i]);
			printf("\n\nkeystream:\n");
			for(i= 0; i < textuzun; i++)	printf("%c", keystream[i]);
			

			printf("\n\nciphertext:\n");
			for(i= 0; i < textuzun; i++)	/* Encryption for every letter */
			{
				ciphertext[i]= encryption(text[i], keystream[i], table);
				printf("%c", ciphertext[i]);
			}


		}
		if(secmeme==7)
		{
			int i= 0;
			printf("\n\nciphertext:\n");
			for(i= 0; i < textuzun; i++)	printf("%c", ciphertext[i]);

			printf("\n\nplaintext:\n");
			for(i= 0; i < textuzun; i++)	/* Encryption for every letter */
			{
				plaintext[i]= decryption(ciphertext[i], keystream[i], table);
				printf("%c", plaintext[i]);
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
void create_table(char table[][26])
{
	char alph= 'A';
	for(int i= 0; i < 26; i++)
	{
		for(int o= 0; o < 26; o++)
		{
			table[i][o]= alph;
			alph++;
			if(alph > 'Z')	alph= 'A';	/* fixing overflows */
		}
		alph++; /* Sliding letters in every row */
	}
}

/* Printing table */
void yaz_tahta(char table[][26])
{
	for(int i= 0; i < 26; i++)
	{
		for(int o= 0; o < 26; o++)
		{
			printf("%c ", table[i][o]);
		}
		printf("\n");
	}
}

/* finding corresponding char in table according to harf and key and return it */
char encryption(char harf, char key, char table[][26])
{	/* finding corresponding char in table according to harf and key and return it */
	//printf("\n(encryption:) harf= %c key= %c table[...]= %c", harf, key, table[key -'A'][harf -'A']);
	return table[key -'A'][harf -'A'];
	return '0';
}

/* finding corresponding char in table according to harf and key and return it */
char decryption(char harf, char key, char table[][26])
{
	int i;
	for(i= 0; i < 26; i++)	/* to find corresponding leter in table */
	{
		if(table[key -'A'][i] == harf)
		{
			//printf("\n(decryption:) harf= %c key= %c table[...]= %c", harf, key, table[key -'A'][i]);
			return i +'A';
		}	

	}
	return '0';
}

