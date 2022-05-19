#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
	short int secme, cIk=0;
	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		secme=0;
		printf("\n\nChoose a Problem to Solve\n"
			"1. First problem\n"
			"2. Second problem\n"
			"3. Third problem\n"
			"6. Exit\n\n");
		scanf("%hd",&secme);

		if(secme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secme==6) cIk=1;
		if(secme==1)
		{
			int  PL, PW, SL, SW;
			char ilksonuc= 0, ikincisonuc= 0;

			printf("\nEnter PL: ");
			scanf("%d%*c",&PL);
			printf("\nEnter PW: ");
			scanf("%d%*c",&PW);
			printf("\nEnter SL: ");
			scanf("%d%*c",&SL);
			printf("\nEnter SW: ");
			scanf("%d%*c",&SW);
			
			ilksonuc= dt1a(PW,PL,SL,SW);
			ikincisonuc= dt1b(PW,PL,SL,SW);
			
			if(ilksonuc != ikincisonuc)
			{
				if(ilksonuc=='s')
				{
					printf("\nSetosa");
				}
				if(ilksonuc=='v')
				{
					printf("\nVirginica");
				}
				if(ilksonuc=='c')
				{
					printf("\nVersicolor");
				}
			}
			if(ikincisonuc=='s')
			{
				printf("\nSetosa");
			}
			if(ikincisonuc=='v')
			{
				printf("\nVirginica");
			}
			if(ikincisonuc=='c')
			{
				printf("\nVersicolor");
			}
		}
		if(secme==2)
		{
			double x1, x2, x3, ilksonuc= 0, ikincisonuc= 0;
			int x4, x5;

			printf("\nEnter x3: ");
			scanf("%lf%*c",&x1);
			printf("\nEnter x2: ");
			scanf("%lf%*c",&x2);
			printf("\nEnter x3: ");
			scanf("%lf%*c",&x3);
			printf("\nEnter x4(just 0 or 1): ");
			scanf("%d%*c",&x4);
			printf("\nEnter x5(just 0 or 1): ");
			scanf("%d%*c",&x5);

			ilksonuc= dt2a(x1,x2,x3,x4,x5);
			ikincisonuc= dt2b(x1,x2,x3,x4,x5);

			int fark= (ilksonuc -ikincisonuc);

			if(fark < 0)
			{
				fark *= -1;
			}
			if(ilksonuc == ikincisonuc)
			{
				printf("%lf\n",ikincisonuc);
			}
			if(CLOSE_ENOUGH >= fark)
			{
				printf("%lf\n", (ilksonuc+ikincisonuc) /2);
			}
			else
			{
				printf("\nFirst result= %lf\nSecond result=%lf", ilksonuc, ikincisonuc);		
			}

		}
		if(secme==3)
		{
			double oy, my;
			int yzm, ys, ak, ilksonuc= 0, ikincisonuc= 0;

			printf("\nEnter oxygen consantration(reel): ");
			scanf("%lf",&oy);
			printf("\nEnter magnetosphere density(reel): ");
			scanf("%lf",&my);
			printf("\nEnter if there is toxic substances on the surface(just 0 or 1): ");
			scanf("%d",&yzm);
			printf("\nEnter surface temperature(int): ");
			scanf("%d",&ys);
			printf("\nEnter atmosphere density(int): ");
			scanf("%d",&ak);
			
			ilksonuc= dt3a(oy, my, yzm, ys, ak);
			ikincisonuc= dt3b(oy, my, yzm, ys, ak);

			if(ilksonuc != ikincisonuc)
			{
				if(ilksonuc == 1)
					printf("This planet is habitable");
				else
					printf("This planet is habitable");
			}

			if(ikincisonuc == 1)
					printf("This planet is habitable");
				else
					printf("This planet is habitable");
		}
		
		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			while(getchar() != '\n') /* nothing happens */;
		}
	}


	return 0;
}