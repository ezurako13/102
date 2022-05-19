#include <stdio.h>

int main()
{			
	int a= 13;
	char *c;
	int sonraki;
    

	
	for(int n= a; n < a +2; n++)
	{
		for(int tkcf= 0; tkcf < 2; tkcf++)
		{
			if(tkcf == 0)	c= "cift";		//	0 -> cift
			else			c= "tek";		//	1 -> tek 


			sonraki= n +(n %2) +tkcf;
			if(tkcf == 0 && n %2 == 0)	sonraki += 2;


			printf("\n%d'den sonraki ilk %s sayi= %d\n", n, c, sonraki);
		}
	}


return 0;
}