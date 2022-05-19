#include<stdio.h>
#include<math.h>
void standart(void);
void area(void);
void temper(void);
void integer(void);
void complex(void);
void complex2(void);
void complex3(void);
void addition(void);
void multiplication(void);
int adresult1(int b,int c);
int mulresult1(int b,int c);
void rect();
void tring();
void circle();
double per2(double x,double y,double z);
double ar2(double a,double b,double c);
int per1(int x,int y);
int ar1(int a,int b);
int ar3(int b);
int per3(int b);
double res1( double x);
double res2( double x);
void FK(void);
void KF(void);
	void mulresult2(int b,int c,int d,int e);
	void adresult2(int *b,int *c,int d,int e);
		//int complex(int a,int b,int c,int d);

int main(){

int a;

printf("1.standart calculator\n");
printf("2.area&perimeter calculator\n");
printf("3.temperature calculator\n");
printf("- - - - - - - - - - - - - - - -\n");
printf("enter calcuşlator type:");
scanf("%d",&a);
printf("- - - - - - - - - - - - - - - -\n");
//res=sqrt(y);
if(a==1) standart();
if(a==2) area();
if(a==3)temper();
else printf("unvalid choose..."); 

}
void standart(void)
	{
		int a;
		printf("1.integer:\n");
		printf("2.complex:\n");
	printf("- - - - - - - - - - - - - - - -\n");
		printf("Enter the number type:");
	printf("- - - - - - - - - - - - - - - -\n");
		scanf("%d",&a);
		if(a==1) integer();
		if(a==2) complex();
		else printf("unvalid chosee:");


	}
void integer(void)
	{
		int a;
		printf("1.addition:\n");
		printf("2.multiplication:\n");
	printf("- - - - - - - - - - - - - - - -\n");
		printf("enter calculaton type:");
		printf("- - - - - - - - - - - - - - - -\n");
		scanf("%d",&a);
		if(a==1) addition();
		//if(a==2)multiplication();
		else printf("unvalid choose:");
	}
void addition(void)
	{
		int num1 ,num2,result;
		printf("write your first number:");
		scanf("%d",&num1);
		printf("write your second number:");
		scanf("%d",&num2);
		result=adresult1(num1,num2);
		printf("your result is %d\n",result);


	}
	void multiplication(void)
	{
		int num1 ,num2,result;
		printf("write your first number:");
		scanf("%d",&num1);
		printf("write your second number:");
		scanf("%d",&num2);
		result=mulresult1(num1,num2);
		printf("your result is %d\n",result);


	}
int adresult1(int b,int c)
	{
		int res=0;
		res=b+c;
		return res;


	}
int mulresult1(int b,int c)
	{
		int res;
		res=b*c;
		return res;

	}
	void complex(void)
	{
	int a;
		printf("1.addition:\n");
		printf("2.multiplication\n");
		printf("enter calculaton type:");
		scanf("%d",&a);
		if(a==1) complex2();
		if(a==2) complex3();
		else printf("unvalid choose:");
	}
	void complex2()
	{
		int num1,num2,com1,com2;
		printf("write first number (frst real):");
		scanf("%d %d",&num1,&com1);
		printf("write second number (frst real):");
		scanf("%d %d",&num2,&com2);
		adresult2(num1,com1,num2,com2);
	
	}
	void complex3()
	{
		int *num1,*num2,com1,com2;
		printf("write first number (frst real):");
		scanf("%d %d",num1,&com1);
		printf("write second number (frst real):");
		scanf("%d %d",num2,&com2);
		mulresult2(num1,com1,num2,com2);
		printf("result is %d + %di \n",*num1,*num2);
	}
	void adresult2(int *b,int *c,int d,int e)
	{
	int *k,*l;
	*k=b+d;
	*l=c+e;
	
	
	}
	void mulresult2(int b,int c,int d,int e)
	{
		int k,l,m,n,z;
		k=b*d;
		l=c*d;
		m=b*e;
		n=(c*e);
		z=k-n;
			printf("result is %d + %di \n",z,l+m);
	}
	void area(void)
	{
	int a;
		printf("1.retangle:\n");
		printf("2.triangle:\n");
		printf("3.circle:\n");	
		printf("choose ypur shape");
		scanf("%d",&a);
		printf("- - - - - - - - - - - - - - - -\n");
		if(a==1) rect();
	    if(a==2)tring();
		if(a==3)circle();
		else printf("unvalid chosee:");
	}
	void rect()
	{
	int L1,L2,res1,res2;
	printf("write long side");
	scanf("%d",&L1);
	printf("write short side");
	scanf("%d",&L2);
	res1=per1(L1,L2);
	printf("perimeter is %d\n",res1);
	res2=ar1(L1,L2);
	printf("area is %d\n",res2);
	
	
	}
	int per1(int x,int y)
	{
		int res;
		res=2*(x+y);
		return res;
	}
	int ar1(int a,int b)
	{
		int res;
		res=b*a;
		return res;

	}	
	void tring()
	{
	double L1,L2,L3;
	double res1,res2;
	printf("write  side");
	scanf("%lf",&L1);
	printf("write  side");
	scanf("%lf",&L2);
	printf("write  side");
	scanf("%lf",&L3);
	res1=per2(L1,L2,L3);
	printf("perimeter is %lf\n",res1);
	res2=ar2(L1,L2,L3);
	printf("area is %lf\n",res2);
	
	
	}
	double per2(double x,double y,double z)
	{
		double res;
		res=x+y+z;
		return res;
	}
	double ar2(double a,double b,double c)
	{
		double res,x,y;
		
		x=(a+b+c)/2;
		y=x*(x-a)*(x-b)*(x-c);
		res = sqrt(y) ;
		return res;

	}	
	void circle()
	{
	
	int rad,res1,res2;
	printf("write radius :");
	scanf("%d",&rad);
	res1=per3(rad);
	printf("permeter is %d\n",res1);
	res2=ar3(rad);
	printf("area is %d\n",res2);

	}
	int per3(int a)
	{
	
	int res;
	res=2*3*a;
	return res ;
	}
	int ar3(int b)
	{
	
	int res;
	res=3*b*b;
	return res;
	}
	void temper(void)
        { 
        int a;
	printf("fahrenhait to kelvin:\n");
	printf("kelvin to fahrenheit:\n");
	printf("- - - - - - - - - - - - - - - -\n");
	printf("choose");
	scanf("%d",&a);
	if(a==1) FK();
	if(a==2) KF();
	else printf("unvalid chosee:");
	}
	void FK()
	{
	//int D;
	double A,D;
	printf("write your deegrees");
	scanf("%lf",&D);
	printf("- - - - - - - - - - - - - - - -\n");
	A=res1(D);
	printf("%lf K\n",A);
	
	
	}
	void KF()
	{
	//int D;
	double A,D;
	printf("write your deegrees");
	scanf("%lf",&D);
	printf("- - - - - - - - - - - - - - - -\n");
	A=res2(D);
	printf("%lf F\n",A);
	
	
	}
	double res1( double x)
	{
	double res ,a,b,c;
	
	res=(0.5555)*(x-32)+273.15;
	return res;
	
	
	
	
	}
	double res2( double x)
	{
	double res ,a,b,c;
	
	res=(9.0/5.0)*(x-273.15)+32;
	return res;
	
	
	
	
	
	}