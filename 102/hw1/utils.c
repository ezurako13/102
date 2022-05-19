#include <stdio.h>

int find_divisible(int x, int y, int z)
{
	if(y < x) return -1;

	while(x <= y)
	{
		if(x %z == 0) return x;
		x++;
	}

	return -1;
}

int find_nth_divisible(int n, int f_I, int z)
{
	while(n > 0)
	{
		f_I++;
		if(f_I %z == 0) n--;
	}
	return f_I;
}

char *th(int sonbasamak)
{
	if(sonbasamak %100 > 20)  sonbasamak %= 10;

	if		(sonbasamak == 1)	return "st";
	else if	(sonbasamak == 2)	return "nd";
	else if	(sonbasamak == 3)	return "rd";
	else						return "th";
}

int validate_identity_number(char identity_number[])
{
	char id[12];
	int i= 0;
	for(i= 0; i < 11; i++)
	{
		id[i] = identity_number[i];
		if(id[i] == '\0' || id[i] < '0' || id[i] > '9')	return 0;
		id[i] -= '0';
	}
	if(id[0] == 0)	
		return 0;

	if( (7* (id[0] +id[2] +id[4] +id[6] +id[8])
	 - (id[1] +id[3] +id[5] +id[7]) ) %10 != id[9])
		return 0;

	if( (id[0] +id[1] +id[2] +id[3] +id[4] +id[5] +id[6]
	 +id[7] +id[8] +id[9]) %10 != id[10])
		return 0;

	return 1;
}

void yaznaber(int sayi, char *array)
{
	if(sayi > 9)
		yaznaber(sayi /10, array -1);
	*array= (sayi %10) +48;

}

int create_customer(char identity_number[], int password)
{
	FILE *dosya;
	dosya= fopen("customeraccount.txt", "w");

	char sifre[6]= {};
	yaznaber(password, sifre +4);
	sifre[6]= '\0';
	fprintf(dosya, "%s,%s", identity_number, sifre+1);
	fclose(dosya);
	return 0;
}

int check_login(char identity_number[], int password)
{
	FILE *dosya;
	dosya= fopen("customeraccount.txt", "r");
	int i= 0, c, sifre= 1;

	while( (c= getc(dosya)) != ',')
	{
		if(identity_number[i] != c)	return 0;
		i++;
		//printf("\nid[%d]= %c c= %c", i, identity_number[i], c);
	}
	
	while( (c= getc(dosya)) != EOF)
	{
		sifre= (sifre *10) +c -48;
		//printf("\nsifre= %d c= %c", sifre, c);
	}

	if(sifre != password)	return 0;

	fclose(dosya);
	return 1;
}

int withdrawable_amount(float cash_amount)
{
	if(cash_amount < 0)	return 0;

	float cekilebilecek= cash_amount;
	while(cash_amount >= 50)
		cash_amount -= 50;
	while(cash_amount >= 20)
		cash_amount -= 20;
	while(cash_amount >= 10)
		cash_amount -= 10;
	return (float)(cekilebilecek - cash_amount);
}
