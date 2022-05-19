#include <stdio.h>
//#include "utils.c"
#include "utils.h"

int main()
{
	short int secme, cIk=0;
	while (cIk!=1)
	{
		printf("\e[1;1H\e[2J");
		secme=0;
		printf("\n\nChoose a Task to Perform\n"
			"1. Part1 Find nth Divisible\n"
			"2. Part2 Create a new customer by identity number\n"
			"3. Part3 Check login\n"
			"6. Exit\n\n");
		scanf("%hd",&secme);

		if(secme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secme==6)
		{
			printf("\e[1;1H\e[2J");
			cIk=1;
		}
		if(secme==1)
		{    
			int fist= 0, seccond= 0, divisor= 0, f_i= 0;
			
			printf("\nEnter the first integer: ");
			scanf("%d",&fist);
			printf("\nEnter the second integer: ");
			scanf("%d",&seccond);
			printf("\nEnter the divisor: ");
			scanf("%d",&divisor);
			
			f_i= find_divisible(fist, seccond, divisor);
			if(f_i == -1)	printf("\nThere is not any integer between %d and %d can be divided by %d"
									, fist, seccond, divisor);
			else	printf("\nThe first integer between %d and %d can be divided by %d is %d"
							, fist, seccond, divisor, f_i);

			if(f_i != -1)
			{
				int next= 0, nth_next= 0;

				printf("\n\nEnter the number how many next: ");
				scanf("%d",&next);

				nth_next= find_nth_divisible(next, f_i, divisor);
				if(nth_next > seccond)	nth_next = -999;

				if(nth_next == -999)	printf("\nNo possible to find %d%s divisible between %d and %d can be divided by %d"
												, next, th(next), fist, seccond, divisor);
				else	printf("\nThe %d%s integer between %d and %d can be divided by %d is %d"
								, next, th(next), fist, seccond, divisor, nth_next);
			}


		}
		if(secme==2)
		{
			int password= 1;
			char sifre[5]= {};
			char id[12]= {};

			printf("\nWrite id number\n");
			scanf("%11s",id);
			if(validate_identity_number(id) == 0)	printf("\nerror\n");
			else	
			{
				printf("\nsuccess\n");
				printf("\nWrite password\n");
				scanf("%4s",sifre);

				for(int xd= 0; xd < 4 && sifre[xd] != '\0'; xd++)	
					password= (password *10) +sifre[xd] -48;

				if(password > 99999 || password < 10000) printf("\nerror\n");
				else
				{
					printf("\nsuccess\n");
					create_customer(id, password);
				}	
			
			}

		}
		if(secme==3)
		{
			int password= 1;
			char sifre[5]= {};
			char id[12]= {};
			float amount= 0;

			printf("\nEnter your identity number: ");
			scanf("%11s",id);
			printf("\nEnter your password: ");
			scanf("%4s",sifre);

			for(int xd= 0; xd < 4 && sifre[xd] != '\0'; xd++)	
					password= (password *10) +sifre[xd] -48;

			if( check_login(id, password) == 0)	printf("\nInvalid identity number or password\n");
			else
			{
				printf("\nLogin Successful\n");

				printf("\nEnter your withdraw amount: ");
				scanf("%f",&amount);
				printf("\nWithdrawable amount is: %d\n", withdrawable_amount(amount));
			}

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
