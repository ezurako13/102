#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct matrix
{
	double dizi[3][3];
	double determinant;

}matrix;

typedef struct polynomial_result
{
	double x6;
	double x5;
	double x4;
	double x3;
	double x2;
	double x1;
	char sabit;
 	
}polynomial;
typedef struct third_order_polynomial
{
	double x3;
	double x2;
	double x1;
	char sabit;
}third_order_polynomial;
typedef struct vector
{
	double x;
	double y;
	double z;
}vector;

void	print_matrix(matrix eleman);
void	inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix);
polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b);
double ust(polynomial p1,int a);
double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec);
int main()
{	
	int i;
	int j;
	i = 0;
	j = 0;
	matrix erisim;
	matrix initial;
	matrix inverted;
	while(i<3)
	{
		while(j<3)
		{
			erisim.dizi[i][j]= rand() %10;
			j++;
		}
		i++;
		j = 0;
	}
	print_matrix(erisim);
/**********************************************************************************/
	inverse_matrix(&erisim, &inverted);
	print_matrix(inverted);
/************************************************************************************/
	polynomial ne_Yazim_mk= {5,7,9,2,1,5,'c'};
	third_order_polynomial ilk;
	third_order_polynomial ikinci;
	int ust_aralik;
	int alt_aralik;
	printf("first integral x^3\n");
	scanf("%lf",&ilk.x3);
	printf("first integral x^2\n");
	scanf("%lf",&ilk.x2);
	printf("first integral x^1\n");
	scanf("%lf",&ilk.x1);
	printf("first integral const\n");
	scanf("%c",&ilk.sabit);
	scanf("%c",&ilk.sabit);
	printf("second integral x^3\n");
	scanf("%lf",&ikinci.x3);
	printf("second integral x^2\n");
	scanf("%lf",&ikinci.x2);
	printf("second integral x^1\n");
	scanf("%lf",&ikinci.x1);
	printf("second integral const\n");
	scanf("%c",&ikinci.sabit);
	scanf("%c",&ikinci.sabit);
	printf("upper boundy\n");
	scanf("%d",&ust_aralik);
	printf("lower boundy\n");
	scanf("%d",&alt_aralik);
	ne_Yazim_mk=get_integral(ilk, ikinci, ust_aralik,alt_aralik);
	printf("integral sonucu %lf\n",ne_Yazim_mk.x6);
	/**************************************************************************************/
	vector vec_1 = {3,0,0};
	vector vec_2= {0,4,0};
	double deneme;
	vector* output_vec;
	vector carpim;
	output_vec = &carpim;
	deneme = find_orthogonal(vec_1,vec_2, output_vec);
	printf("%lf\n", deneme);
	printf("%lfx, %lfy, %lfz", output_vec->x,output_vec->y,output_vec->z);
}

void	print_matrix(matrix eleman)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while(i<3)
	{
		while(j<3)
		{
			printf("%.4f    ",eleman.dizi[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}

}
void	inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix)
{
	/*******************************************************************/
	float determinant_1 = (*initial_matrix).dizi[0][0] * (((*initial_matrix).dizi[1][1] * (*initial_matrix).dizi[2][2]) - ((*initial_matrix).dizi[1][2] * (*initial_matrix).dizi[2][1]));
	float determinant_2 = (*initial_matrix).dizi[0][1] * (((*initial_matrix).dizi[1][0] * (*initial_matrix).dizi[2][2]) - ((*initial_matrix).dizi[1][2] * (*initial_matrix).dizi[2][0]));
	float determinant_3 = (*initial_matrix).dizi[0][2] * (((*initial_matrix).dizi[1][0] * (*initial_matrix).dizi[2][1]) - ((*initial_matrix).dizi[1][1] * (*initial_matrix).dizi[2][0]));
	initial_matrix->determinant = determinant_1 -determinant_2 + determinant_3;
	printf("\n%.4f\n",(*initial_matrix).determinant);
	float temp;
	int i;
	int j;
	i = 0;
	j = 0;
	(*inverted_matrix).dizi[0][0] = (((*initial_matrix).dizi[1][1] * (*initial_matrix).dizi[2][2]) - ((*initial_matrix).dizi[1][2] *(*initial_matrix).dizi[2][1]));
	(*inverted_matrix).dizi[0][1] = (-1)*((((*initial_matrix).dizi[1][0] * (*initial_matrix).dizi[2][2]) - ((*initial_matrix).dizi[1][2] * (*initial_matrix).dizi[2][0])));
	(*inverted_matrix).dizi[0][2] = (((*initial_matrix).dizi[1][0] * (*initial_matrix).dizi[2][1]) - ((*initial_matrix).dizi[1][1] * (*initial_matrix).dizi[2][0]));
	(*inverted_matrix).dizi[1][0] = (-1)*((((*initial_matrix).dizi[0][1] * (*initial_matrix).dizi[2][2]) - ((*initial_matrix).dizi[0][2] *(*initial_matrix).dizi[2][1])));
	(*inverted_matrix).dizi[1][1] = (((*initial_matrix).dizi[0][0] * (*initial_matrix).dizi[2][2]) - ((*initial_matrix).dizi[0][2] *(*initial_matrix).dizi[2][0]));
	(*inverted_matrix).dizi[1][2] = (-1)*((((*initial_matrix).dizi[0][0] * (*initial_matrix).dizi[2][1]) - ((*initial_matrix).dizi[0][1] *(*initial_matrix).dizi[2][0])));
	(*inverted_matrix).dizi[2][0] = (((*initial_matrix).dizi[0][1] * (*initial_matrix).dizi[1][2]) - ((*initial_matrix).dizi[0][2] *(*initial_matrix).dizi[1][1]));
	(*inverted_matrix).dizi[2][1] = (-1)*((((*initial_matrix).dizi[0][0] * (*initial_matrix).dizi[1][2]) - ((*initial_matrix).dizi[0][2] *(*initial_matrix).dizi[1][0])));
	(*inverted_matrix).dizi[2][2] = (((*initial_matrix).dizi[0][0] * (*initial_matrix).dizi[1][1]) - ((*initial_matrix).dizi[0][1] *(*initial_matrix).dizi[1][0]));

	temp = (*inverted_matrix).dizi[0][1];
	(*inverted_matrix).dizi[0][1] = (*inverted_matrix).dizi[1][0];
	(*inverted_matrix).dizi[1][0] = temp;
	temp = (*inverted_matrix).dizi[1][2];
	(*inverted_matrix).dizi[1][2] = (*inverted_matrix).dizi[2][1];
	(*inverted_matrix).dizi[2][1] = temp;
	temp = (*inverted_matrix).dizi[0][2];
	(*inverted_matrix).dizi[0][2] = (*inverted_matrix).dizi[2][0];
	(*inverted_matrix).dizi[2][0] = temp;

	while(i<3)
	{
		while(j<3)
		{
			(*inverted_matrix).dizi[i][j] /= (*initial_matrix).determinant;
			j++;
		}
		i++;
		j= 0;

	}
} 	

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b)
{
	polynomial integral= {2};
	polynomial sonuc;
	double ust_sonuc;
	double alt_sonuc;
	sonuc.x6 = p1.x3 * p2.x3;
	sonuc.x5 = (p1.x2* p2.x3) + (p1.x3 * p2.x2);
	sonuc.x4 = (p1.x2 * p2.x2) + (p1.x1 * p2.x3) + (p1.x3 * p2.x1);
	sonuc.x3 = (p1.x3 * (p2.sabit-48)) + ((p1.sabit-48) *p2.x3) + (p1.x1 * p2.x2) + (p1.x2 * p2.x1);
	sonuc.x2 = (p1.x2 *(p2.sabit-48)) + (p1.x1 * p2.x1) + ((p1.sabit-48) *p2.x2);
	sonuc.x1 = (p1.x1 *(p2.sabit-48)) + ((p1.sabit-48) * p2.x1);
	sonuc.sabit = ((p1.sabit-48) * (p2.sabit-48));
	printf("%lfx^6+ %lf^x5 + %lf^4 + %lf^3 + %lf^2 + %lf^1 + %c\n",sonuc.x6,sonuc.x5,sonuc.x4,sonuc.x3,sonuc.x2,sonuc.x1,sonuc.sabit);
	sonuc.x6 /= 7;
	sonuc.x5 /= 6;
	sonuc.x4 /= 5;
	sonuc.x3 /= 4;
	sonuc.x2 /= 3;
	sonuc.x1 /= 2;
	
	ust_sonuc = ust(sonuc,a);
	alt_sonuc=ust(sonuc,b);
	printf(" üst sınır = %lf\n",ust_sonuc);
	printf(" alt sınır = %lf\n",alt_sonuc);
	integral.x6 = ust_sonuc - alt_sonuc;
	return integral;
}
double ust(polynomial p1,int a)
{
	double sonuc;
	int i;
	int times;
	sonuc = 0;
	times = 1;
	for(i = 0 ; i<7;i++)
	{	
		times *= a;
	}
	sonuc  += (p1.x6 * times);
	times = 1;
	for(i = 0 ; i<6;i++)
	{	
		times *= a;
	}
	sonuc  += (p1.x5 * times);
	times =1;

	for(i = 0 ; i<5;i++)
	{	
		times *= a;
	}
	sonuc  += (p1.x4 * times);
	times = 1;

	for(i = 0 ; i<4;i++)
	{	
		times *= a;
	}
	sonuc  += (p1.x3 * times);
	times = 1;
	for(i = 0 ; i<3;i++)
	{	
		times *= a;
	}
	sonuc  += (p1.x2 * times);	
	times=1;
	for(i = 0 ; i<2;i++)
	{	
		times *= a;
	}
	sonuc  += (p1.x1 * times);
	times = 1;
	for(i = 0 ; i<1;i++)
	{	
		times *= a;
	}
	sonuc  += (((int)(p1.sabit)) * times);

	return sonuc;
}
double find_orthogonal(vector vec_1, vector vec_2, vector* output_vec)
{
	double result;
	double aci;
	double ust;
	double alt;
	alt = sqrt(pow(vec_1.x,2) + pow(vec_1.y,2) + pow(vec_1.z,2)) + sqrt(pow(vec_2.x,2) + pow(vec_2.y,2) + pow(vec_2.z,2));
	ust  = vec_1.x + vec_2.x + vec_1.y + vec_2.y +vec_1.z + vec_2.z ;
	result = ust / alt;
	aci = acos(result);
	aci /= 3.14159;
	aci *=180;

	(*output_vec).x = (vec_1.y * vec_2.y) - (vec_1.z * vec_2.y);
	(*output_vec).y = -1*(vec_1.x * vec_2.z) - (vec_1.z * vec_2.x);
	output_vec->z = (vec_1.x * vec_2.y) - (vec_1.y * vec_2.x);
	return aci;
}