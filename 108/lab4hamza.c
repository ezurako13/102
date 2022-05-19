#include<stdio.h> 

void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier);
void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3,double* b2, double* b1, double *b0);
int main() {
 
 unsigned int *mucad,*muler;
 unsigned int a,b;
 double A[10];
 //double *a3=&A[8],*a2=&A[0],*a1=&A[1],*a0=&A[2],*b3=&A[3],*b2=&A[4],*b1=&A[5],*b0=&A[6];
 mucad=&a;
 muler=&b;
 printf("write mulcad number");
 scanf("%u",mucad);
 printf("write muler number");
 scanf("%u",muler);


 russian_multiplication ( mucad, muler);
 
 
  printf("%u\n",*mucad);
   printf("%u\n",*muler);
  printf("ilk polinom katsayı");
  scanf("%lf %lf %lf %lf",&A[0],&A[1],&A[2],&A[3]);
  printf("ikinci polinom katsayı");
  scanf("%lf %lf %lf %lf",&A[4],&A[5],&A[6],&A[7]);
  multiply_polynomials (&A[0],&A[1],&A[2],&A[3],&A[4],&A[5],&A[6],&A[7]);
   printf("%.2lfx⁶ + %.2lfx⁵ + %.2lfx⁴ + %.2lfx³ + %.2lfx² + %.2lfx¹ + %.2lf",A[0],A[1],A[2],A[3],A[4],A[5],A[6]);
  }
void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier)
{
unsigned int a,sum=0,*ar,b;
ar=&b;
//printf("%u\n",*multiplier);
//if(*multiplier==1) 
//{
//*multiplicand=*ar;
//}
//*multiplier!=1||
//sum=*multiplicand;
while(*multiplier>=1)
{
	if(*multiplier%2==1)
	{
	sum+=*multiplicand;
	//printf("%u\n",*multiplicand);
	*ar=sum;
	}
if(*multiplier==1) break;
	*multiplicand=2*(*multiplicand);
	
	*multiplier=*multiplier/2;
	
}
*multiplicand=*ar;
}
void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3,double* b2, double* b1, double *b0)
{ 
  double a=*a3,b=*a2,c=*a1,d=*a0,e=*b3,f=*b2,h=*b1,m=*b0;
  *a3=a*e;
  *a2=(a*f)+(b*e);
  *a1=(a*h)+(b*f)+(c*e);
  *a0=(a*m)+(b*h)+(c*f)+(d*e);
  *b3=(b*m)+(c*h)+(d*f);
  *b2=(c*m)+(f*h);
  *b1=d*m;
  //*b0=
  //printf("%lf",*a3);



}