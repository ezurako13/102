#include<stdio.h>
#include<math.h>

void theory_of_everything(void);
int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);
void write_file(int number);
int isprime(int a);
void print_file(void);
void sort_file(void);

int main(void)
{
	theory_of_everything();

}

void theory_of_everything(void)
{
	int bayrak = 0; // it is also flag but i have the variable which name is flag;
	int gorev2_sayi;
	int secim;
	int num1;
	int num2;
	int karar;
	int flag;
	int cevap;
	int temp ;// temporary variable for if n1> n2 
	cevap = 0;
	do
	{
		printf("Select operation\n1. Calculate sum/multiplication between\n2. Calculate prime numbers\n3. Show number sequence in file\n4. Sort number sequence in file.\n0. For exit\n");
		scanf("%d", &secim);
	
			if(secim == 1)
			{
				printf("Please enter '0' for sum, '1' for multiplication\n");
				scanf("%d",&karar);
				switch (karar)
				{
					case 0:
						printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
						scanf("%d",&flag);
						if(flag != 0 || flag != 1)
						{
							while(flag != 1 && flag != 0)
							{
							printf("it is invalid. please try again \n");
							scanf(" %d ",&flag);
							}
						}
						do
						{
							printf("Please enter two different number:\nNumber 1:");
							scanf("%d",&num1);
							printf("\nNumber 2:");
							scanf("%d",&num2);
						}
						while(num1 < 0 || num2 <0);
						if(num1>num2)
						{
							temp = num1;
							num1= num2;
							num2 = temp;
						}
						temp = num1;
						while(sum(temp,num2,flag) != 0 && !(temp >= num2))
						{
							cevap +=sum(temp,num2,flag);
							temp = sum(temp,num2,flag);
									printf("%d+",temp);
						}
						printf("\b = %d\n\n",cevap);
						write_file(cevap);
						cevap = 0;
						break;


					case 1:
						printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
						scanf("%d",&flag);
						if(flag != 0 || flag != 1)
						{
							while(flag != 1 && flag != 0)
							{
							printf("it is invalid. please try again \n");
							scanf(" %d ",&flag);
							}
						}
						do
						{
							printf("Please enter two different number:\nNumber 1:");
							scanf("%d",&num1);
							printf("\nNumber 2:");
							scanf("%d",&num2);
						}
						while(num1 < 0 || num2 <0);
	
						if(num1>num2)
						{
							temp = num1;
							num1= num2;
							num2 = temp;
						}
						temp = num1;
						cevap = 1;
						while(multi(temp,num2,flag) != 1)
						{
							cevap *=multi(temp,num2,flag);
							temp = multi(temp,num2,flag) ;
							printf("%d * ",temp);
						}
						printf("\b\b = %d\n\n",cevap);
						write_file(cevap);
						break;
	
				}	
		}
		else if(secim == 2)
		{
			int checking;
			checking = 0;
			for(;bayrak != 1;)
			{
				printf("give an positive integer\n");
				scanf("%d",&gorev2_sayi);
				if(gorev2_sayi > 1)
					bayrak++;
			}
			if(gorev2_sayi != 2)
				gorev2_sayi -= 1;
			int baslangic;
			for(baslangic = 2;baslangic <= gorev2_sayi; baslangic++)
			{
				checking = isprime(baslangic);
				//printf("checking == %d ||| gorev2_sayi %d\n",checking,gorev2_sayi);
				if(checking == 0)
					printf("%d is prime\n",baslangic);
				else
				{
					printf("%d is not a prime number, it is dividible by %d\n", baslangic,checking);
					checking = 0;
				}
			}
		}

		else if(secim == 3)
		{
			print_file();
		}
		else if(secim == 4)
		{
			sort_file();
		}

	}
	while(secim != 0);
}

int sum(int n1, int n2, int flag)
{
	if(n1 +2>= n2 )
		return 0;
	if(n1 %2 != flag)
	{
		n1 += 1;
	//printf("%d ",n1);
		return n1;
	}
	if(n2 %2 != flag)
		n2 -= 1;
	if(n1  %2 == flag && !(n1>n2))
	{
		return n1+2;
	}
	return 0;
}

int multi(int n1, int n2, int flag)
{
	if(n1+2 > n2 )
		return 1;
	if(n1 %2 != flag)
	{
		n1 += 1;
	//	printf("%d ",n1);
		return n1;
	}
	if(n2 %2 != flag)
		n2 -= 1;
	if(n1  %2 == flag && !(n1+2>=n2))
	{
		return n1+2;
	}
	return 1;
}

void	write_file(int number)
{
	FILE * ptr;
	ptr = fopen("result.txt","a");
	fprintf(ptr, "%d ",number);
	fclose(ptr);
}

int isprime(int a)
{
	int c;
	double temp;
	double kok;
	kok = sqrt((double )a);
	int i;
	int flag = 0;
	for(i = 2; i<=(int)kok; i++)
	{
		//printf("kok = %d", (int)kok);
		if(a% i == 0)
			return i;
	}
	return 0;
}

void print_file(void)
{
	int temp;
	FILE * ptr;
	ptr = fopen("result.txt","r");
	while(!feof(ptr))
	{
		fscanf(ptr,"%d",&temp);
		printf("%d ",temp);
	}
	fclose(ptr);
}

void sort_file(void)
{
	FILE *ptr;
	FILE *iki;
	FILE * isaret;
	FILE * okuma;
	ptr = fopen("result.txt","r");
	iki = fopen("result.txt","r");
	isaret = fopen("temp.txt","a");
	okuma = fopen("temp.txt","r");
	int max=0;
	int min1;
	int min2;
	int min3;
	int res_int;
	int iki_int;
	int temp_int;
	int okuma_int;
	int ayni = 0;
	int flag_1 = 0;
	int flag_2 = 0;
	int flag_3 = 0;
	int position;
	int gecici;
	int girdi_1, girdi_2,girdi_3;
	girdi_1= 0;
	int counter = 0; 
	do
	{
		fscanf(ptr,"%d",&res_int);
		if(res_int>max)
			max=res_int;
	}
	while(!feof(ptr));
	rewind(ptr);
	min1 = max;
	min2 = max;
	min3 = max;
	while(counter< 3)
	{
		while(!feof(ptr))
		{

			fscanf(ptr,"%d",&temp_int);


			while(!feof(iki))
			{
				fscanf(iki,"%d ",&iki_int);
				if(min1 > iki_int && flag_1 == 0)
				{
					min1 = iki_int;
					flag_1++;

					
				}
				if (min2 > iki_int && iki_int >= min1)
				{
					if(iki_int ==min1)
					{
						ayni++;
						position=ftell(iki);
						fscanf(iki,"%d",&gecici);
						while(!feof(iki))
						{
							if(gecici == min2)
								ayni++;
							fscanf(iki,"%d",&gecici);
						}
						if(ayni >1)
							min2 = min1;
						fseek(iki,position,SEEK_SET);
						flag_1 = 0;
					}
					else
					{
						min2 = iki_int;
						flag_2++;
						flag_1 = 0;
					}
					ayni = 0;
				}
				if(min3 > iki_int  && iki_int >min2)
				{

					min3 = iki_int;
					flag_3++;	
					flag_1 = 0;
				}
				//printf("min1 = %d\n min2 = %d\n min3 = %d\n",min1,min2,min3);
			}
			rewind(iki);
			printf("min1 = %d\n min2 = %d\n min3 = %d\n",min1,min2,min3);
			rewind(isaret);
			rewind(okuma);
			while(!feof(okuma))
			{
				//rewind(isaret);
				fscanf(okuma,"%d ", &okuma_int);
				if(okuma_int == min1)
					girdi_1 = 1;
				if(okuma_int == min2)
					girdi_2++;
				if (okuma_int == min3)
					girdi_3++;
			}
			rewind(okuma);
			if(girdi_1 == 0)
				fprintf(isaret,"%d ",min1);
			printf("\n(%d)",girdi_1);
			girdi_1 = 0;
			if(girdi_2 == 0)
				fprintf(isaret,"%d ",min2);
			girdi_2 = 0;

			if(girdi_3 == 0)
				fprintf(isaret,"%d ",min3);
			girdi_3 = 0;
	
		}
		rewind(ptr);


		counter++;
	}
	fclose(iki);
	fclose(ptr);
	fclose(isaret);
	fclose(okuma);
}

