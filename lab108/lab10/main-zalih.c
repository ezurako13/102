#include <stdio.h>

// void printtable(char arr[26][26])
// {
// 	int i = 0,j = 0, k = 0;
// 	for(i = 0;i < 26; i++)
// 	{
// 		for(j = 0; j < 26; j++)     //plaintext-keystream alphabet table initialization with two for loops
// 		{
// 			printf("%c ",arr[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

// char encrypt(char arr[26][26], int b, int c)
// {
// 	char a = arr[b][c];
// 	return a; 
// }
// int decrypt(char arr[26][26], char a, int b)
// {
	
// }

// int search(char a)
// {
// 	int i;
// 	for(i = 0; i < 26; i++)
// 	{
// 		if(a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i])
// 			break;
// 	}
// 	return i;
// }

int main()
{
	char arr[26][26]= {};                       //plaintext- keystream table
	char row[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0,j = 0, k = 0;

	//for(i = 0;i < 26; i++)
	//{
	//    for(j = i,k = 0; j < i || k < 26; j++, k++)     //plaintext-keystream alphabet table initialization with two for loops
	//    {
	//        if(j == 26)
	//                j = 0;
	//        arr[i][k] = row[j];
	//    }
	//}
	//printtable(arr);
	
	char plaintext[10]= "ABC";
	char key[10]= "ABC";
	char ciphertext[256]= {};

	printf("\nEnter the plaintext:");
	char c;
	for(i = 0; i < 3; i++)
	{
		c = getchar();
		if(c == '\n')   c= getchar();
		plaintext[i] = c;
		printf("%c",plaintext[i]);
	}
	while(getchar() != '\n');

	printf("\nEnter the key:\n");
	int i1 = 0;
	char c1;// = getchar();
	for(i = 0; i < 3; i++)
	{
		c = getchar();
		if(c == '\n')   c= getchar();
		key[i] = c;
		printf("%c",key[i]);
	}
//-----------------------------------------------------------------------------------------------------
	int textlen = 0, keylen = 0;
	i = 0;
	//while(plaintext[i])                 //getting the lengths so that we can know which one is longer
		textlen++;
	i = 0;
	//while(plaintext[i])
		keylen++;

	if(keylen > textlen)
	{
		key[textlen] = '\0';
	}
	else if(keylen < textlen)
	{
			for(j = keylen, i = 0; i < keylen && j < textlen; j++, i++)     //j is for text, i is for key.
			{
				plaintext[j] = key[i];
				if(i == keylen -1)
					i = 0;
			}
	}
	int a = 0, b = 0;
	for(i = 0; i < keylen; i++)
	{
		//a = search(plaintext[i]);
	}

	return 0;
}