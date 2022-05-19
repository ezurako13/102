#include <stdio.h>
#include <math.h>

#define PI 3.14f

typedef enum
{
	Triangle= 4, Quadrilateral= 8, Circle= 16, Pyramid= 12, Cylinder= 24,
} Shapes;

typedef enum
{
	Area= 2, Perimeter= 4, Volume= 3,
} Calculators;

int select_shape ();
int select_calc ();
int calculate (int (*shp)(), int (*calc)());
int calc_triangle(int calc);
int calc_quadrilateral(int calc);
int calc_circle(int calc);
int calc_pyramid(int calc);
int calc_cylinder(int calc);
void errorincmp(int shape, int calc);
int checkafter();

/* I don't know why this function still exist in this program */
int main()
{
	
	calculate(select_shape, select_calc);

	return 0;
}

/* Prints options for shapes, allows user to one of the options and returns the selection */
int select_shape ()
{
	int yapma= -5, temp= 0;
	printf("\n\nSelect a shape to calculate:\n"
		   "--------------------------------\n"
		   "1. Triangle.\n"
		   "2. Quadrilateral\n"
		   "3. Circle\n"
		   "4. Pyramid\n"
		   "5. Cylinder\n"
		   "0. Exit\n"
		   "--------------------------------\n"
		   "Input: ");

	scanf("%d", &yapma);
	if(checkafter() == 0)	return -5;
	return yapma;
}

/* Prints options for calculation types, allows user to one of the options and returns the selection */
int select_calc ()
{
	int yapma= -5;
	printf("\n\nSelect calculator:\n"
		   "--------------------------------\n"
		   "1. Area.\n"
		   "2. Perimeter\n"
		   "3. Volume\n"
		   "0. Exit\n"
		   "--------------------------------\n"
		   "Input: ");
	scanf("%d", &yapma);
	if(checkafter() == 0)	return -5;
	return yapma;
}

/* Main calculator function in this program */
int calculate (int (*shp)(), int (*calc)())
{
	short int cIk=0, dosyavar= 0;
	int shape, calculator;

	while (cIk!=1)
	{
		printf("\e[1;1H\e[2J");

		int c;
		shape=-5;
		calculator=-5;
		printf("\nWelcome to the gormetric calculator!\n");

		shape= shp();
		if(shape > 6 || shape < 0)	printf("\nHatali tuslama yaptiniz\n");
		else if(shape != 6 && shape != 0)
		{
			calculator= calc();
			if((calculator > 3 || calculator < 0) && calculator != 6)	printf("\nHatali tuslama yaptiniz\n");
		}
		

		/* Converting inputs into more usable numbers */
		if(1)
		{
		if(shape == 5)	shape= Cylinder;
		if(shape == 4)	shape= Pyramid;
		if(shape == 3)	shape= Circle;
		if(shape == 2)	shape= Quadrilateral;
		if(shape == 1)	shape= Triangle;

		if(calculator == 2)	calculator= Perimeter;
		if(calculator == 3)	calculator= Volume;
		if(calculator == 1)	calculator= Area;

		}


		if(shape == 6 || shape == 0 || calculator == 6 || calculator == 0) cIk=1;
		else if(shape == 31 || calculator == 31)
		{
			printf("\n!![Warning]!! (Gereksiz otuzbir kullanimi)");
		}		

		else if(shape == -5 || calculator == -5);
		else if(shape %calculator != 0)	errorincmp(shape, calculator);
		else
		switch(shape)
		{
			case Triangle:
				
				printf("\nPlease enter three sides of Triangle : \n\n\n");
				while((c= calc_triangle(calculator) )== 0 || c == -1)
				{
					if(c == 0)	printf("\nERROR ! Please enter a valid entry.\n\n\n");
					if(c == -1)	printf("\nERROR ! Please enter a valid triangle.\n\n\n");
				}
				break;
			
			case Quadrilateral:
				
				printf("\nPlease enter four sides of Quadrilateral : \n\n\n");
				while((c= calc_quadrilateral(calculator) )== 0 || c == -1)
				{
					if(c == 0)	printf("\nERROR ! Please enter a valid entry.\n\n\n");
					if(c == -1)	printf("\nERROR ! Please enter a valid quadrilateral.\n\n\n");
				}
				break;
			
			case Circle:
				
				printf("\nPlease enter radius of Circle : \n\n\n");
				while(calc_circle(calculator) == 0)
				{
					printf("\nERROR ! Please enter a valid entry.\n\n\n");
				}
				break;
			
			case Pyramid:
				
				if(calculator == Area)	printf("\nPlease enter base side and slant height of a Pyramid : \n");
				else printf("\nPlease enter base side and height of a Pyramid : \n");
				while(calc_pyramid(calculator) == 0)
				{
					printf("\nERROR ! Please enter a valid entry.\n");
				}
				break;
			
			case Cylinder:
				
				printf("\nPlease enter radius and height of a Cylinder : \n");
				while(calc_cylinder(calculator) == 0)
				{
					printf("\nERROR ! Please enter a valid entry.\n");
				}
				break;
			

		}
		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			while(getchar() != '\n') /* nothing happens */;
			//while(getchar() != '\n');
		}
	}
	if(shape == 6 || calculator == 6)	printf("\nThis is a secret way to exit.\n");

	return 1;
}


/* Calculates calculations for triangle and prints the results */
int calc_triangle(int calc)
{
	/*				Triangle we use
		   /\
        a /  \ b
		 /    \
	    ________
		    c   
	*/
	float a= -5, b= -5, c= -5;
	float cevre, s, alan;


	printf("    \t    /\\     \n"								//
           "  a \t   /  \\ b  \n"								//	This part is for better demonstration
           "    \t  /    \\   \n"								//
           "    \t ________   \n"								//
           "    \t     c      \n");								//
    printf("\033[20D\033[6A        \b\b\b\b\b\b\b\b");			//
	
	scanf("%f", &a);
	if(checkafter() == 0 || a < 0)	
	{
		printf("\033[6B");
		return 0;
	}

	printf("    \t    /\\     \n"								//
           "  %.2f\t   /  \\ b  \n"								//
           "    \t  /    \\   \n"								//	This part is for better demonstration
           "    \t ________   \n"								//
           "    \t     c      \n", a);							//
    printf("\033[20D\033[6A        \b\b\b\b\b\b\b\b");			//
	
	scanf("%f", &b);
	if(checkafter() == 0 || a < 0)	
	{
		printf("\033[6B");
		return 0;
	}

	printf("    \t    /\\     \n"								//
           "  %.2f\t   /  \\ %.2f \n"								//
           "    \t  /    \\   \n"								//	This part is for better demonstration
           "    \t ________   \n"								//
           "    \t     c      \n", a, b);						//
    printf("\033[20D\033[6A        \b\b\b\b\b\b\b\b");			//
	
	scanf("%f", &c);
	
	if(checkafter() == 0 || c < 0)	
	{
		printf("\033[6B");
		return 0;
	}

	printf("    \t    /\\     \n"
           "  %.2f\t   /  \\ %.2f \n"
           "    \t  /    \\   \n"
           "    \t ________   \n"
           "    \t    %.2f      \n", a, b, c);

	float semiperimeter= (a +b +c) /2.0;
	if(semiperimeter <= a || semiperimeter <= b || semiperimeter <= c)	return -1;

	switch(calc)
	{
		case Area:
			/* 𝑯𝒆𝒓𝒐𝒏′𝒔 𝑭𝒐𝒓𝒎𝒖𝒍𝒂 for area calculation */
			s= (a+ b+ c) /2.0f, alan= 0;

			alan= sqrt(s *(s -a) *(s -b) *(s -c));
			printf("\nArea of TRIANGLE : %.2f\n", alan);

			return 1;
		
		case Perimeter:
			/* Perimeter calculation */
			cevre= a +b +c;
			printf("\nPerimeter of TRIANGLE : %.2f\n", cevre);
			
			return 1;

	}
	return 0;
}

/* Calculates calculations for quadrilateral and prints the results */
int calc_quadrilateral(int calc)
{
	/*				Quadrilateral we use
		     b
		 ________ 
        |        |
	   a|        |c
	    |        |
		|________|
		     d
	*/
	float a= -5, b= -5, c= -5, d= -5;
	float cevre, s, alan;



	printf("    \t     b      \n"							//
           "    \t  ________  \n"							//
           "    \t |        | \n"							//
           "  a \t |        | c\n"							//	to show user what they are doing
           "    \t |        | \n"							//
           "    \t  ________  \n"							//
           "    \t      d     \n");							//
    printf("\033[20D\033[8A        \b\b\b\b\b\b\b\b");		//
	
	scanf("%f", &a);
	
	if(checkafter() == 0 || a < 0)	
	{
		printf("\033[7B");
		return 0;
	}
	printf("    \t     b      \n"
           "    \t  ________  \n"
           "    \t |        | \n"
           "  %.2f\t |        | c\n"
           "    \t |        | \n"
           "    \t  ________  \n"
           "    \t      d     \n", a);
    printf("\033[20D\033[8A        \b\b\b\b\b\b\b\b");

	scanf("%f", &b);
	
	if(checkafter() == 0 || b < 0)	
	{
		printf("\033[7B");
		return 0;
	}

	printf("    \t     %.2f     \n"
           "    \t  ________  \n"
           "    \t |        | \n"
           "  %.2f\t |        | c\n"
           "    \t |        | \n"
           "    \t  ________  \n"
           "    \t      d     \n", b, a);
    printf("\033[20D\033[8A        \b\b\b\b\b\b\b\b");
	
	scanf("%f", &c);
	
	if(checkafter() == 0 || c < 0)	
	{
		printf("\033[7B");
		return 0;
	}
	
	printf("    \t     %.2f     \n"
           "    \t  ________  \n"
           "    \t |        | \n"
           "  %.2f\t |        | %.2f\n"
           "    \t |        | \n"
           "    \t  ________  \n"
           "    \t      d     \n", b, a, c);
    printf("\033[20D\033[8A        \b\b\b\b\b\b\b\b");

	scanf("%f", &d);
	
	if(checkafter() == 0 || d < 0)	
	{
		printf("\033[7B");
		return 0;
	}

	printf("    \t     %.2f     \n"
           "    \t  ________  \n"
           "    \t |        | \n"
           "  %.2f\t |        | %.2f\n"
           "    \t |        | \n"
           "    \t  ________  \n"
           "    \t      %.2f    \n", b, a, c, d);


	float semiperimeter= (a +b +c +d) /2.0;
	if(semiperimeter <= a || semiperimeter <= b || semiperimeter <= c || semiperimeter <= d)	return -1;

	switch(calc)
	{
		case Area:
			/* 𝑩𝒓𝒂𝒉𝒎𝒂𝒈𝒖𝒑𝒕𝒂′𝒔 𝑭𝒐𝒓𝒎𝒖𝒍𝒂 for area calculation */
			s= (a+ b+ c +d) /2.0, alan= 0;

			alan= sqrt((s -a) *(s -b) *(s -c) *(s -d));
			printf("\nArea of QUADRILATERAL : %.2f\n", alan);

			return 1;
		
		case Perimeter:
			/* Perimeter calculation */
			cevre= a +b +c +d;
			printf("\nPerimeter of QUADRILATERAL : %.2f\n", cevre);
			
			return 1;

	}
	return 0;
}

/* Calculates calculations for circle and prints the results */
int calc_circle(int calc)
{
	float radius= -5;
	float alan, cevre;

	scanf("%f", &radius);
	
	if(checkafter() == 0 || radius < 0)	return 0;

	switch(calc)
	{
		case Area:
			/* 𝑪𝒊𝒓𝒄𝒖𝒎𝒇𝒆𝒓𝒆𝒏𝒄𝒆 for area calculation */
			alan= 0;

			alan= PI *radius *radius;
			printf("\nArea of TRIANGLE : %.2f\n", alan);

			return 1;
		
		case Perimeter:
			/* Perimeter calculation */
			cevre= 2 *PI *radius;
			printf("\nPerimeter of TRIANGLE : %.2f\n", cevre);
			
			return 1;

	}
	return 0;
}

/* Calculates calculations for pyramid and prints the results */
int calc_pyramid(int calc)
{
	float base= -5, lateral= -5, height= -5;
	float alan, cevre, hacim;

	scanf("%f", &base);
	
	if(checkafter() == 0 || base < 0)	return 0;

	if(calc == Area)
	{
		scanf("%f", &lateral);
		
		if(checkafter() == 0 || lateral < 0)	return 0;
	}
	else
	{
		scanf("%f", &height);
		
		if(checkafter() == 0 || height < 0)	return 0;
	}

	switch(calc)
	{
		case Area:
			/* 𝑺𝒖𝒓𝒇𝒂𝒄𝒆 𝑨𝒓𝒆𝒂 = 𝑳𝒂𝒕𝒆𝒓𝒂𝒍 𝑺𝒖𝒓𝒇𝒂𝒄𝒆 𝑨𝒓𝒆𝒂 + 𝑩𝒂𝒔𝒆 𝑺𝒖𝒓𝒇𝒂𝒄𝒆 𝑨𝒓𝒆𝒂 
								(𝑳 = 𝟐 ∗ 𝒂 ∗ 𝒍 )           (𝑩 = 𝒂𝟐 )		*/
			alan= 0;
			float B= 0, L= 0;

			B= base *base;
			L= 2 *base *lateral;
			alan= B +L;
			printf("\nBase Surface Area of a PYRAMID : %.2f\n", B);
			printf("\nLateral Surface Area of a PYRAMID : %.2f\n", L);
			printf("\nSurface Area of a PYRAMID : %.2f\n", alan);

			return 1;
		
		case Perimeter:
			/* Perimeter of base of Pyramid */

			cevre= 4 *base;
			printf("\nBase Surface Perimeter of a PYRAMID : %.2f\n", cevre);
			
			return 1;
		
		case Volume:
			/* 𝑽𝒐𝒍𝒖𝒎𝒆 = 𝟏/𝟑 ∗ 𝒂𝟐 ∗ 𝒉 */

			hacim= (1.0f/3.0f) *base *base *height;
			printf("\nVolume of a PYRAMID : %.2f\n", hacim);
			
			return 1;

	}
	return 0;

}

/* Calculates calculations for cylinder and prints the results */
int calc_cylinder(int calc)
{
	float radius= -5, height= -5;
	float alan, cevre, hacim;

	scanf("%f", &radius);
	
	if(checkafter() == 0 || radius < 0)	return 0;

	scanf("%f", &height);
	
	if(checkafter() == 0 || height < 0)	return 0;


	switch(calc)
	{
		case Area:
			/*   𝑺𝒖𝒓𝒇𝒂𝒄𝒆 𝑨𝒓𝒆𝒂           𝑳𝒂𝒕𝒆𝒓𝒂𝒍 𝑺𝒖𝒓𝒇𝒂𝒄𝒆 𝑨𝒓𝒆𝒂     𝑩𝒂𝒔𝒆 𝑺𝒖𝒓𝒇𝒂𝒄𝒆 𝑨𝒓𝒆𝒂 
			 (𝟐 ∗ 𝝅 ∗ 𝒓 ∗ (𝒓 + 𝒉))   	    (𝟐 ∗ 𝝅 ∗ 𝒓 ∗ 𝒉 )           (𝝅 ∗ 𝒓𝟐 )		*/
			alan= 0;
			float B= 0, L= 0;

			B= PI *radius *radius;
			L= 2 *PI *radius *height; 
			alan= 2 *PI *radius *(radius +height);
			printf("\nBase Surface Area of a CYLINDER : %.2f\n", B);
			printf("\nLateral Surface Area of a CYLINDER : %.2f\n", L);
			printf("\nSurface Area of a CYLINDER : %.2f\n", alan);

			return 1;
		
		case Perimeter:
			/* Perimeter of base of Cylinder */

			cevre= 2 *PI *radius;
			printf("\nBase Surface Perimeter of a CYLINDER : %.2f\n", cevre);
			
			return 1;

		case Volume:
			/* 𝑽𝒐𝒍𝒖𝒎𝒆 = 𝝅 ∗ 𝒓𝟐 ∗ 𝒉 */

			hacim= PI *radius *radius *height;
			printf("\nVolume of a CYLINDER : %.2f\n", hacim);
			
			return 1;

	}
	return 0;

}

/* Using stirngs to print errors efficiently */
void errorincmp(int shape, int calculator)
{
	char *shp, *calc;

	if		(shape == Triangle)			shp= "triangle";
	else if	(shape == Quadrilateral)	shp= "quadrilateral";
	else if	(shape == Circle)			shp= "circle";
	else if	(shape == Pyramid)			shp= "pyramid";
	else if	(shape == Cylinder)			shp= "cylinder";

	if		(calculator == Area)		calc= "area";
	else if	(calculator == Perimeter)	calc= "perimeter";
	else if	(calculator == Volume)		calc= "volume";

	printf("\nERROR ! You cannot calculate %s of a %s. Please try again.\n", calc, shp);
}

/* Checks buffer after an input if there is invalid input after that or not */
int checkafter()
{
	int temp= 0;
	while( (temp= getchar()) != '\n')
	{
		if(temp != '\n' && temp != ' ' && temp != '\t')
		{
			while(getchar() != '\n');
			return 0;
		}
	}
	return 1;
}
