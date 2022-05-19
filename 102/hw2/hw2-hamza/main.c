#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {

	int choose,x4,x5;
	double  PL,PW,SL,SW,x1,x2,x3;
	printf("MENU\n"
					"\t1.P1\n"
					"\t2.P2\n"
					"\t3.P3\n"
						"choose\n");
	scanf("%d%*c",&choose);
	if(choose==1)
	{
		printf("\nwrite values for PL,PW,SL,SW\n");
		scanf("%lf %lf %lf %lf%*c", &PL,&PW,&SL,&SW);
		char res=dt1a(PW,PL,SL,SW);
		if(res=='s')
				printf("Setosa\n");
		if(res=='v')
				printf("Virginica\n");
		if(res=='c')
				printf("Versicolor\n");
		printf("\nwrite values for PL,PW ,SL,SW\n");	
		scanf("%lf %lf %lf %lf%*c",&PL,&PW, &SL,&SW);
	char res1=dt1b(PW,PL,SL,SW);
		if(res1=='s')
				printf("Setosa\n");
		if(res1=='v')
				printf("Virginica\n");
		if(res1=='c')
				printf("Versicolor\n");
}
  if(choose==2)
{
	printf("Write x1,x2 and x3 values:");
	scanf("%lf %lf %lf%*c",&x1,&x2,&x3);
	printf("write binary x4 x5 values(just 0 or 1):");
	scanf("%d %d%*c",&x4,&x5);
	double res2=dt2a(x1,x2,x3,x4,x5);
	//printf("Result is %.2lf\n",res2);
	printf("Write x1,x2 and x3 values:");
	scanf("%lf %lf %lf%*c",&x1,&x2,&x3);
	printf("write binary x4 x5 values(just 0 or 1):");
	scanf("%d %d%*c",&x4,&x5);
	double res3=dt2b(x1,x2,x3,x4,x5);
	//printf("Result is %.2lf\n",res3);
	int a=(res2-res3);
		if(a<0)
				a*=-1;
		if(res2==res3)
			printf("%lf\n",res2);
			if(CLOSE_ENOUGH>=a)
				printf("%lf\n",(res2+res3)/2);
			else
					printf("first resulr=%lf  second result=%lf\n",res2,res3);		
			
}
    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */

    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */

    return 0;
}
