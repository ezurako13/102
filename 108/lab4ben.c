#include <stdio.h>

void russian_multiplication(unsigned int* multiplicand, unsigned int* multiplier);
void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double b0);

int main()
{
    short int secim=0, cIk=0;

    while (cIk!=1)
    {
        printf("\e[1;1H\e[2J");
        secim=0;
        printf("\n\nSelect the Task You Have to Do Right Now\n"
            "1. Russian Peasant(Koylu) Multiplication\n"
            "2. Polynomial Multiplication\n"
            "6. Exit\n\n");
        scanf("%hd",&secim);

        if(secim==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        if(secim==6) cIk=1;
        if(secim==1)
        {    
            unsigned int multiplicand=0, multiplier=0;
            printf("\n\nEnter the Multiplicand and Multiplier\n");
            printf("\nMultiplicand= ");
            scanf("%u",&multiplicand);
            printf("\nMultiplier= ");
            scanf("%u",&multiplier);
            
            printf("\n%u x %u= ", multiplicand, multiplier);
            russian_multiplication(&multiplicand, &multiplier);
            printf("%u", multiplicand);
            printf("\n\nThe Latest Multiplicand= %u\n"
                   "The Latest Multiplier= %u\n", multiplicand, multiplier);
        }
        if(secim==2)
        {
            double a[4]= {1.0,  1.0,    1.0,    1.0};
            double b[4]= {2.0,  2.0,    2.0,    2.0};
            printf("\n(a3+a2+a1+a1+a0)*(b3+b2+b1+b0)\n"
                   "\nIn Order to Make This Calculation, Write Polinomials "
                   "You Want to Mutiply by Using This Pattern\n"
                   "\na3+a2+a1+a0+b3+b2+b1+b0\n");
            //scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a[3],&a[2],&a[1],&a[0],&b[3],&b[2],&b[1],&b[0]);
            
            multiply_polynomials(&a[3],&a[2],&a[1],&a[0],&b[3],&b[2],&b[1],b[0]);
            printf("\nThe Result is %.1lfx^6 + %.1lfx^5 + %.1lfx^4 + %.1lfx^3 + %.1lfx^2 + %.1lfx + %.1lf"
                   ,a[3], a[2], a[1], a[0], b[3], b[2], b[1]);
        }
        
        if(cIk!=1)
        {    
            printf("\n\nPress ENTER to continue... \n");
            while(getchar() != '\n');
            while(getchar() != '\n') /* nothing happens */;
        }
    }
    
    return 0;
}


void russian_multiplication(unsigned int* multiplicand, unsigned int* multiplier)
{
    short int cIk=0;
    int i;
    unsigned int result=0;

    for (i=0; cIk!=1; i++)
    {
        if(*multiplier%2 != 0)result+=*multiplicand;
        *multiplicand *=2, *multiplier/=2;
        if(*multiplier==1) cIk=1;
    }

    *multiplicand+= result;

    return;   
}

void multiply_polynomials (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double b0)
{
    double x[7]={};
    double a[4]={*a0, *a1, *a2, *a3}, b[4]={b0, *b1, *b2, *b3};
    
    int i, o;

    for(i=0; i<4; i++)
    {
        for(o=0; o<4; o++)
        {
            x[i+o]+= (a[i]) * (b[o]) ;
        }
    }
    
    *a3= x[6];
    *a2= x[5];
    *a1= x[4]; 
    *a0= x[3];
    *b3= x[2];
    *b2= x[1];
    *b1= x[0];

    return;
}
