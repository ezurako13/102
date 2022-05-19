#include <stdio.h>
#include "util.h"


/* Example decisi in tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return (r);
}

char dt1a(double pl, double pw, double sl, double sw)
{
	if(pl < 2.45)
	{
		return ('s');
	}
	else 
	{
		if(pw >= 1.75)
		{
			return ('v');
		}
		else
		{
			if(pl >= 4.95)
			{
				return ('v');
			}
			else
			{
				if(pw < 1.65)
				{
					return ('c');
				}
				else
				{
					return ('v');
				}
			}
		}

	}
	return 0;
}
char dt1b(double pl, double pw, double sl, double sw)
{
	if(pl < 2.55)
	{
		return ('s');
	}
	else 
	{
		if(pw >= 1.69)
		{
			return ('g');
		}
		else
		{
			if(sl >= 4.85)
			{
				return ('g');
			}
			else
			{
				return ('c');
			}
		}
	}
	return 0;
}

double dt2a(double x1, double x2, double x3, int x4, int x5)
{
	if(x1 < 31.5)
	{
		if(x2 > -2.5)
		{
			return (5.0);
		}
		else
		{
			if(x2 -0.1 <= x1 && x1 <= x2 +0.1)
			{
				return (2.1);
			}
			else
			{
				return (-1.1);
			}
		}
	}
	else
	{
		if(-1 <= x3 && x3 <= 2)
		{
			return (1.4);
		}
		else
		{
			if(x4 && x5)
			{
				return (-2.23);
			}
			else 
			{
				return (11.0);
			}
		}
	}
	return 0;
}
double dt2b(double x1, double x2, double x3, int x4, int x5)
{
	if(12<x1&&x1<22)
	{
		if(x3>(double)5/3)
		{
			return (-2);
		}
		else
		{
			if((x1-0.1<=x3)&&(x3<=x1+0.1))
			{
				return (1.01);
			}
			else
			{
				return (-8);
			}
		}
	}
	else
	{
		if(x4 && x5)
		{
			return (-1);
		}
		else 
		{
			if(-1 <= x2 && x2 <= 2)
			{
				return ((double)-1/7);
			}
			else
			{
				return (0.471404520);		
			}
		}		
	}
	return 0;
}

/* Write the prototype of the functions implementing the decision trees for the third problem */
int dt3a(double oy, double my, int yzm, int ys, int ak)
{
	if(!yzm)
	{
		if(ak > 5)
		{
			return 0;
		}
		else
		{
			if(my < 6)
			{
				return 0;
			}
			else
			{
				if(ys <= 40)
				{
					if(ys <= 10)
					{
						return 0;
					}
					else
					{
						if(yzm)
						{
							return 0;
						}
						else
						{
							return 1;
						}
					}
				}
				else
				{
					return 0;
				}
			}
		}
	}
	else
	{
		return 0;
	}
	return 0;
}
int dt3b(double oy, double my, int yzm, int ys, int ak)
{
	if(1 <= ak && ak <= 5)
	{
		if(ak < 3)
		{
			if(ak < 1)
			{
				return 0;
			}
			else
			{
				if(40 < oy && oy < 80)
				{
					if(10 < ys && ys < 40)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
		}
		else
		{
			if(ak == 3)
			{
				if(40 < oy && oy < 80)
				{
					if(yzm)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	return 0;
}


/* Provide your implementations for all the requested functions here */
