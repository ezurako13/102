#include <stdio.h>

int main()
{
	int aa= 360;
	int a= 360;
	int bb= 1104;
	int b= 1104;
	int *n= &a;
	int *d= &b;
	int i= 0;
    int ebob;
    while(++i<=*n && i<=*d) if(*n%i == 0 && *d%i == 0) ebob= i;
    *n/= ebob;
    *d/= ebob;
	printf("\n\n%d\\%d  ->  %d\\%d\n\n", aa, bb, *n, *d);
	printf("\nebob=%d\n", ebob);
	return 0;
}
