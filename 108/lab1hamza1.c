#include<stdio.h>
void triangle();
void second();


int main()
{
    int a=0;
    printf("\e[1;1H\e[2J");
    printf("task 1\n");
    triangle();
    printf("task 2\n",a);
    second();
 


    return 0;
}

void triangle()

{
    double a,b,c;
    double sinx,cosx,tanx;
	
    printf("write edges afer wrte hyp:");
	scanf("%lf %lf %lf",&a,&b,&c);
	printf("a=%lf\n",a);
	printf("b=%lf\n",b);
	printf("c=%lf\n",c);
	sinx=a/c;
	cosx=b/c;
	tanx=a/b;
	printf("sinx=%0.3lf\n",sinx);
	printf("cosx=%0.3lf\n",cosx);
	printf("tanx=%0.3lf\n",tanx);
	


    return ;
}

void  second()
{


    double age,sec;
	printf("write your age ");
	scanf("%lf",&age);
	sec=365*24*60*60*age;
	printf("%lf",sec);
    return;
}