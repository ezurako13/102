#include <stdio.h>
#include <math.h>

void gcd_calculator();
long long gcd(long long herif1, long long herif2);
void lcm_calculator();
long long lcm(long long herif1, long long herif2);
void write_file(long long sonuc);
long long read_file(int i);
double calculate_mean();
void standart_deviation_calculator();
double sdc();

int kactane= 7;


int main()
{
    short int secmeme, cIk=0;

    while (cIk!=1)
    {
        //printf("\e[1;1H\e[2J");
        secmeme=0;
        printf("\n\nEnter the calculator type\n"
            " 1. Greatest Common Divisor\n"
            " 2. Least Common Multiple via GCD\n"
            " 3. Standart Deviation Calculator\n"
			" 6. Exit\n"
            " ....................................\n ");
        scanf("%hd",&secmeme);

        if(secmeme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        if(secmeme==6) cIk=1;
        if(secmeme==1)
        {   
			gcd_calculator();			
        }
        if(secmeme==2)
        {
            lcm_calculator();
        }
        if(secmeme==3)
        {
            standart_deviation_calculator();
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


void gcd_calculator()
{
	long long sayi1= 0, sayi2= 0, sonuc= 0;
	
	printf("Please enter two different number:\n");
    printf("1. Number 1: ");
	scanf("%lld",&sayi1);
    printf("2. Number 2: ");
	scanf("%lld",&sayi2);

	sonuc= gcd(sayi1, sayi2);
    printf("GCD of two numbers: %lld", sonuc);
	write_file(sonuc);
	kactane++;
}

long long gcd(long long herif1, long long herif2)
{
	int i= 0;
	int ebob= 1;
	
		/* Calculating ebob */

	while(++i <= herif1 && i <= herif2)	
		if(herif1 %i == 0 && herif2 %i == 0)	
			ebob= i; /* ebob */

	return ebob;
}


void lcm_calculator()
{
	long long sayi1= 0, sayi2= 0, sonuc= 0;
	
	printf("Please enter two different number:\n");
    printf("1. Number 1: ");
	scanf("%lld",&sayi1);
    printf("2. Number 2: ");
	scanf("%lld",&sayi2);

	sonuc= lcm(sayi1, sayi2);
    printf("LCM of two numbers: %lld", sonuc);
	write_file(sonuc);
	kactane++;
}

long long lcm(long long herif1, long long herif2)
{
	return (herif1 *herif2) /gcd(herif1, herif2);
}


double calculate_mean()
{
	long long toplam= 0, okunan= 0;
	double mean= 0;
	int i= 0;

	while(i <= kactane)
	{
		toplam += okunan;
		okunan= read_file(i);
		i++;
	}
	
	mean= (double)toplam /kactane;
	return mean;
}

void standart_deviation_calculator()
{
	double sonuc= 0;
	int i= 0, bos= 0;

	kactane= 0;
	FILE *dosya= fopen("dosya.txt", "r");
	while(feof(dosya) == 0)
	{
		fscanf(dosya, "%d ", &bos);
		kactane++;
		printf("\n %d. Number: %lld", i +1, read_file(i));
		i++;
	}
	fclose(dosya);
	//printf("\n(std_ctor:) kactane= %d", kactane);


	sonuc= sdc();
	printf("\nMean: %.0lf", calculate_mean());
	printf("\nTotal Count: %d", kactane);
	printf("\nStandart Deviation : %.2lf", sonuc);

}

double sdc()
{
	long long sayi= 0, karelertoplm= 0, mean= 0;
	int i= 0;

	mean= calculate_mean();

	while(i < kactane)
	{
		sayi= read_file(i);
		karelertoplm+= (sayi - mean) *(sayi - mean);
		//printf("\n(sdc:) kar= %lld sayi= %lld", karelertoplm, sayi);
		i++;
	}


	return sqrt( ((double)karelertoplm /kactane) );
}


void write_file(long long sonuc)
{
	FILE *dosya= fopen("dosya.txt", "a+");

	fprintf(dosya, "%lld ", sonuc);
	
	fclose(dosya);
}

long long read_file(int i)
{
	int a= 0;
	long long okunan= 0;
	FILE *dosya= fopen("dosya.txt", "r");

	while(a <= i)
	{
		fscanf(dosya, "%lld ", &okunan);
		a++;
	}

	fclose(dosya);

	if(okunan != EOF)
		return okunan;
	return -1;
}

