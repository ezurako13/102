#include <stdio.h>
#include <math.h>

#define pi 3.1415926535897932384626433832795


typedef struct
{
	double array[3][3];
	double determinant;
} matrix;

typedef struct
{
	double x;
	double y;
	double z;
} vector;

typedef struct
{
	double x[8];    // Coefficens of polinomial
	char constant;  // a char variable indicating constant
	double value;   // its value between [a, b] of the integrated polynomial
} polynomial;

typedef struct
{
	double a[4];
} third_order_polynomial;

void print_matrix(matrix initial_matrix);
void inverse_matrix(matrix *initial_matrix, matrix *inverted_matrix);
void determinant_of_matrix(matrix *initial_matrix);
void matrixDoldur(matrix *matrix);

double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec);
void vector_print(vector A, vector B);

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b);


int main()
{
	short int secme, cIk=0;
	while (cIk!=1)
	{
		printf("\e[1;1H\e[2J");
		secme=0;
		printf("\n\nChoose a Task to Perform\n"
			"1. Inverse Matrix\n"
			"2. Find the Angle Between Two Vectors\n"
			"3. Calculating the Integral of Multiplication of Two Polynomials\n"
			"6. Exit\n\n");
		scanf("%hd",&secme);

		if(secme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secme==6) cIk=1;
		if(secme==1)
		{
			matrix initial_matrix;
			matrixDoldur(&initial_matrix);
			print_matrix(initial_matrix);
			matrix inverted_matrix;
			inverse_matrix(&initial_matrix, &inverted_matrix);
			if(initial_matrix.determinant!=0) print_matrix(inverted_matrix);
			else printf("\nInitial Matrix Has 0 Determinant\n");
		}
		if(secme==2)
		{
			printf("For two given vectors A= [ax,ay,az] and B = [bx,by,bz], \n"
				   "the angle between is given by Angle = arccos A.B        \n"
				   "                                           |A|.|B|      \n");
			vector A=   {1.0,   0.0,    0.0}; // {x,  y,  z}
			vector B=   {0.0,   1.0,    0.0}; // {x,  y,  z}
			vector AxB= {0.0,   31.0,   0.0}; // {x,  y,  z}
			
			vector_print(A, B);
			
			double angleBetweenAB= find_orthogonal(A, B, &AxB);
			printf("\n\nAngle=%.2lf\n", angleBetweenAB);
			
			//Cross Product
			printf("\nAxB(Cross Product)=%.2lfi + %.2lfj + %.2lfk\n", AxB.x, AxB.y, AxB.z);
			
		}
		if(secme==3)
		{
			third_order_polynomial p1=  {1.0,   1.0,   1.0,   1.0}; // {a0, a1,  a2,  a3};
			third_order_polynomial p2=  {1.0,   1.0,   1.0,   2.0}; // {b0, b1,  b2,  b3};
			int a= 0;
			int b= 0;
			printf("\n\nEnter the Interval\na= ");
			scanf("%d",&a);
			printf("b= ");
			scanf("%d",&b);

			polynomial carpIlmIsPolinom= get_integral(p1, p2, a, b);
			printf("\n\nBelirli integralin cevabI= %lf\n", carpIlmIsPolinom.value);
			
		}
		
		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			while(getchar() != '\n');
			while(getchar() != '\n') /* nothing happens */;
		}
	}

return 0;
}



void print_matrix(matrix initial_matrix)
{
	int center= (33*2-22-8)/2;
	printf("\n\n");
	for(int i=0; i<3; i++)
	{
		for(int o=0; o<3; o++)
		{
			if(o==0) printf("%*.4lf  ", center, initial_matrix.array[i][o]);
			else printf("%.4lf  ", initial_matrix.array[i][o]);
		}
		printf("\n\n");
	}
}

void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix)
{
	determinant_of_matrix(initial_matrix);
	printf("\nDeterminant= %lf\n\n\n", initial_matrix->determinant);
	if(initial_matrix->determinant==0) return;

	double det= initial_matrix->determinant;
	double (*mi)[3]= initial_matrix->array;
	double (*mp)[3]= inverted_matrix->array;

	mp[0][0]=  (mi[1][1]*mi[2][2] - mi[1][2]*mi[2][1])*(1/det);
	mp[1][0]= -(mi[1][0]*mi[2][2] - mi[1][2]*mi[2][0])*(1/det);
	mp[2][0]=  (mi[1][0]*mi[2][1] - mi[1][1]*mi[2][0])*(1/det);
	mp[0][1]= -(mi[0][1]*mi[2][2] - mi[0][2]*mi[2][1])*(1/det);
	mp[1][1]=  (mi[0][0]*mi[2][2] - mi[0][2]*mi[2][0])*(1/det);
	mp[2][1]= -(mi[0][0]*mi[2][1] - mi[0][1]*mi[2][0])*(1/det);
	mp[0][2]=  (mi[0][1]*mi[1][2] - mi[0][2]*mi[1][1])*(1/det);
	mp[1][2]= -(mi[0][0]*mi[1][2] - mi[0][2]*mi[1][0])*(1/det);
	mp[2][2]=  (mi[0][0]*mi[1][1] - mi[0][1]*mi[1][0])*(1/det);
	
}  

void determinant_of_matrix(matrix* initial_matrix)
{
	double (*mx)[3]= initial_matrix->array;

	initial_matrix->determinant= 
	( mx[0][0] *(mx[1][1]*mx[2][2] -mx[1][2]*mx[2][1]) ) - 
	( mx[0][1] *(mx[1][0]*mx[2][2] -mx[1][2]*mx[2][0]) ) + 
	( mx[0][2] *(mx[1][0]*mx[2][1] -mx[1][1]*mx[2][0]) );
}

void matrixDoldur(matrix *matrix)
{
	matrix->array[0][0]=2.0    ;
	matrix->array[0][1]=1.0    ;
	matrix->array[0][2]=0.0    ;
	matrix->array[1][0]=1.0    ;
	matrix->array[1][1]=-1.0   ;
	matrix->array[1][2]=1.0    ;
	matrix->array[2][0]=3.0    ;
	matrix->array[2][1]=2.0    ;
	matrix->array[2][2]=1.0    ;
}



double find_orthogonal(vector vec_1, vector vec_2, vector *output_vec)
{
	double A= sqrt((vec_1.x*vec_1.x) + (vec_1.y*vec_1.y) + (vec_1.z*vec_1.z));
	double B= sqrt((vec_2.x*vec_2.x) + (vec_2.y*vec_2.y) + (vec_2.z*vec_2.z));
	vector AB= {vec_1.x*vec_2.x, vec_1.y*vec_2.y, vec_1.z*vec_2.z};

	output_vec->x= vec_1.y*vec_2.z - vec_1.z*vec_2.y;
	output_vec->y= vec_1.x*vec_2.z - vec_1.z*vec_2.x;
	output_vec->z= vec_1.x*vec_2.y - vec_1.y*vec_2.x;

	//Angle between two vectors
	double angle= acos((AB.x + AB.y + AB.z) / (A*B))*180/pi;
	return angle;
}

void vector_print(vector A, vector B)
{
	printf("\nA=%.2lfi + %.2lfj + %.2lfk\n", A.x, A.y, A.z);
	printf("\nB=%.2lfi + %.2lfj + %.2lfk\n", B.x, B.y, B.z);
}



polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b)
{
	polynomial carpIlmIsPolinom={};
	carpIlmIsPolinom.constant= 'c'; //neden bilmiyorum
	double *x= carpIlmIsPolinom.x;
	
	int i, o;  //Polinomlari carpIyoruz arkadaslar
	for(i=0; i<4; i++) for(o=0; o<4; o++) carpIlmIsPolinom.x[i+o]+= (p1.a[i]) * (p2.a[o]) ;
	//printf("\nCarpim polinomu= %.1lfx^6 + %.1lfx^5 + %.1lfx^4 + %.1lfx^3 + %.1lfx^2 + %.1lfx + %.1lf"
	//       ,x[6], x[5], x[4], x[3], x[2], x[1], x[0]);

	//Evet arkadaslar, burda da integral alIyoruz
	for(i=6; i>=0; i--) carpIlmIsPolinom.x[i+1]= (carpIlmIsPolinom.x[i]/(i+1));
	printf("\n\nintegrallenmis polinom= %.2lfx^7 + %.2lfx^6 + %.2lfx^5 + %.2lfx^4 + %.2lfx^3 + %.2lfx^2 + %.2lfx"
		   ,x[7], x[6], x[5], x[4], x[3], x[2], x[1]);

	//Belirli integralin degeri
	for(i=0; i<8; i++) carpIlmIsPolinom.value+= carpIlmIsPolinom.x[i] * (pow((double)b,i) - pow((double)a,i));
	

	return carpIlmIsPolinom;
}


