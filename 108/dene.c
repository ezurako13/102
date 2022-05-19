#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tavuk(int *x, int *a, int i); 

int main()
{
    printf("\e[1;1H\e[2J");
    //printf("\033[5A");
    //printf("\033[eJ");
    //printf("\033[8;5Hxd");
    //system("cls");
    
    /*
    unsigned int a=(365*24*60*60)*99;
    unsigned long long int x=256*256*256*256;
    printf("Size of a=\t%d\nSize of x=\t%d\n", sizeof(a), sizeof(x));
    printf("int= %u\nunsigned long= %llu", a, x);
    */
    //
    // int i;
    // (i*i)=ikare;
    // int x= i*i;

    // printf("%d\n",x);
    //int x=0;
    //scanf("%d",&x);
    //printf("%d", x);

    int a[2]={3,2};
    int x= 0xa;
    int i=256*256*256*127;
    float op= 3;
    double oop= 2;

    printf("\nx= %x\n", x);


    //char array[10];
    //printf("\nsizeof array= %dbytes\n", sizeof(array));

    //int size= ((&array)+1) - (&array);
    //printf("\nthere is %d elements in this array\n\n", size);
    //for(int occ=0; array[occ]; occ++)

    //printf("&array=\t\t%d\n", (&array));
    //printf("&array+1=\t%d\n", (&array+1));
    //printf("array=\t\t%d\n", array);
    //printf("array+1=\t%d\n", (array+1));


    x= 25^7;
    //printf("\n%d\n", x);

    oop= pow(2,3);
    //printf("\n%lf\n", oop);
   
    
    
    
    
    //tavuk(&x, a, i);
    //printf("%*d %*d \n\n",31, *(&x), 11, i);
  
    //char *H="313331";
    //printf(H);
  
    //printf("\n\n%.2f %.2lf\n\n", op, oop);
  
    //for(int xp=10; xp<63; xp++) printf("%d", xp);
    //
    //char *buffer= (char *)calloc(51, sizeof(char));
    ////scanf("%s",buffer);
    //printf("\ns= %s", buffer);
    //free(buffer);

    //int d=9;    
    //int e=5;
    //double c= e/(double)9;
    //printf("\nc= %lf\n", c);

    //int *xz;
    //xz=a;
    //printf("%d",xz[1]);


return 0;
}

void tavuk(int *x, int *a, int i)
{
    *x= (a[i]) * (a[i]);
}

// Burası hatalı kullanım(Pointerları gör)
//void tavuk(int *x, int *a, int i)
//{
//    *x= (*a[i]) * (*a[i]);
//}
//