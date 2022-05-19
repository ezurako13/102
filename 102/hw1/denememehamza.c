double f2(double x, double y);
double f3(double x);

double f1(double x,double y)
{
	double a,b;
	a= f2(x,y);
	b= f3(a);
	return f2(a,b);
}

double f2(double x, double y)
{
	double a, b, c;
	a=x+y;
	b=x-y;
	c=a*b;
	return c;
}

double f3(double x)
{
	double a;
	a=x*x*x;
	return a;
}

void main()
{
	double x=1.0, y=2.0, z;
	z=f1(x+0.5,y);
}