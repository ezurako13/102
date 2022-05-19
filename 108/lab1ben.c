/* 

The variable names that used in this file have no relation with the ones in the pdf file. 

<?> in the functions means something other than void, you should find the correct type for these functions.

*/

#include <stdio.h>

void age(int x);
unsigned long long int age_calculation(int x);
double trigonometry_calculation(int a, int b, int c);
double sinx(int a, int c);
double cosx(int b, int c);
double tanx(int a, int b);

void trigonometry(int a, int b, int c)
{	//double sinx,cosx,tanx;
 	//sinx,cosx,tanx=trigonometry_calculation(a,b,c);
	printf("Type your triangle lenghts\n");
	printf("a:");
	scanf("%d",&a);
	printf("b:");
	scanf("%d",&b);
	printf("c:");
	scanf("%d",&c);
 	printf("sinx:%lf ",sinx(a,c));
 	printf("cosx:%lf ",cosx(b,c));
 	printf("tanx:%lf ",tanx(a,b));

    return;
}
/*
double trigonometry_calculation(int a, int b, int c)
{
    double sinx=(double)a/c;
    double cosx=(double)b/c;
    double tanx=(double)a/b;
    return sinx,cosx,tanx;
}
*/
double sinx(int a, int c)
{
	return (double)a/c;
}
double cosx(int b, int c)
{
	return (double)b/c;
}
double tanx(int a, int b)
{
	return (double)a/b;
}

void age(int x)
{
	unsigned long long int result = age_calculation(x);
	printf("You are %llu seconds old",result);
    return;
}


unsigned long long int age_calculation(int x)
{
    return (unsigned long long int)365*24*60*60*x;
}


int main()
{	
	int a,b,c,ages;

	printf("\e[1;1H\e[2J");
	

//	trigonometry(a,b,c);
    /*---------------------*/
	printf("\nYour age:");
	scanf("%d",&ages);
	age(ages);


    return 0;
}
