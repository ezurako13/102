#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
	*n3 = n1*d2 + n2*d1;
	*d3 = d1*d2;
	fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) 
{
	*n3 = n1*d2 - n2*d1;
	*d3 = d1*d2;
	fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) 
{
	*n3= n1*n2;
	*d3= d1*d2;
	fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) 
{
	*n3= n1*d2;
	*d3= n2*d1;
	fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) 
{
	int i= 0;
	int ebob= 1;
	int num= *n, den= *d; /* Creating copy of *n and *d */
	
	if(num<0)	num*= (-1);	/* Simplifying our calculations for ebob */
	if(den<0)	den*= (-1);
	while(++i<=num && i<=den)	if(num%i == 0 && den%i == 0)	ebob= i; /* ebob */
	*n/= ebob;
	*d/= ebob;	/* Simplifying */
	if(*d<0)
	{
		*n *= (-1);
		*d *= (-1);
	}
} /* end fraction_div */
