#include <stdio.h>
#include <math.h>
#define complex 31
#define integer 13
#define reel 0
#define karmasik 1
#define pi 3.1415926535897932384626433832795
#define ucgen 3
#define kare 4
#define cember 5 
#define fahrenheit 6
#define kelvin 7

void Standart();
void AreaVePerimeter();
void Temperature();
void Addition(short int numberType);
void Multiplication(short int numberType);
void TOPLA(long long int *toplanan1, long long int *toplanan2, long long int *sonuc);
void CARP(long long int *carpan, long long int *carpIlan, long long int *sonuc);
void Triangle();
void Ractangle();
void Circle();
void AlanCevreHesapla(int *olculer, short int sekil, double *cevre, double *alan);
void FahToKelvin();
void KelvinToFah();
void donustur(double *temperature, short int birim);
void pressEnter();


int main()
{
    short int selection=0;
    short int cIk=0;
  
    while(cIk!=2)
    {
        printf("\e[1;1H\e[2J");
        selection=0;
        printf("\n\t\tSELECT CALCULATOR TYPE\n\n"
               "1.Multi Calculator\n"
               "2.Area&Perimeter Calcualtor\n"
               "3.Temperature Calculator\n"
               "6.Exit\n");
        scanf("%1hd",&selection);

        if     (selection==1) Standart();
        else if(selection==2) AreaVePerimeter();
        else if(selection==3) Temperature();
        else if(selection==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        else if(selection==6) 
        {    
            cIk++;
            if(cIk==1) 
            {   
                printf("\e[1;1H\e[2J");
                printf("\ncIkmak mI istiyon(eger oyleyse bi daha 6'ya bas)\n\n");
                selection=0;
                scanf("%1hd",&selection);
                if(selection==6) cIk++;
                printf("\e[1;1H\e[2J");
            }    
        }
        else printf("\ntrolleme duzgun yaz\n\n");
        if(selection!=1 && selection!=2 && selection!=3 && selection!=6) pressEnter();
        
    }
    
    

return 0;
}



void Standart()
{
    short int selection=0;
    short int numberType=0;
    short int cIk=0;
    
    while(cIk!=1)
    {
        selection=0;
        printf("\e[1;1H\e[2J");
        
        while(numberType!=13 && numberType!=31)
        {
            printf("\e[1;1H\e[2J");
            printf("\n\t\tSelect The Number Type You Want to Deal with\n"
                   "13= Integeer Numbers\n"
                   "31= Complex Numbers \n");
            scanf("%2hd",&numberType);
            if(numberType!=13 && numberType!=31) 
            {
                printf("duzgun yaz\n");
                pressEnter();
            }    
        }
        
        printf("\n\t\tChoose What You Want to Do\n"
               "1. Addition\n"
               "2. Multiplication\n"
               "3. Change Number Type\n"
               "6. Exit\n");
        scanf("%1hd",&selection);

        if(selection==1) Addition(numberType);
        else if(selection==2) Multiplication(numberType);
        else if(selection==3) numberType=0;
        else if(selection==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        else if(selection==6) cIk++;
        else printf("\ntrolleme duzgun yaz\n\n");
        if(selection!=6) pressEnter();
    }
}

void Addition(short int numberType)
{
    long long int toplanan1[2]={};
    long long int toplanan2[2]={};
    long long int sonuc[2]={};
    
    if(numberType==complex)
    {
        printf("\n(a+bi)+(c+di)\n"
               "In Order to Make This Calculation, Write Numbers "
               "You Want to Add by Using This Pattern\n"
               "a+b+c+d\n");
        scanf("%lld%lld%lld%lld", &toplanan1[reel], &toplanan1[karmasik], &toplanan2[reel], &toplanan2[karmasik]);
        TOPLA(toplanan1, toplanan2, sonuc);
        printf("\nsonuc= %lld + %lldi\n",sonuc[reel], sonuc[karmasik]);
    }

    if (numberType==integer)
    {
        printf("\nWrite Numbers You Want to Add by Using This Pattern\n"
               "a+b\n");
        scanf("%lld%lld", &toplanan1[reel], &toplanan2[reel]);
        TOPLA(toplanan1, toplanan2, sonuc);
        printf("\nsonuc= %lld\n",sonuc[reel]);
    }
}

void Multiplication(short int numberType)
{
    long long int carpan[2]={};
    long long int carpIlan[2]={};
    long long int sonuc[2]={};
    
    if(numberType==complex)
    {
        printf("\n(a+bi)*(c+di)\n"
               "In Order to Make This Calculation, Write Numbers "
               "You Want to Multiply by Using This Pattern\n"
               "a+b+c+d\n");
        scanf("%lld%lld%lld%lld", &carpan[reel], &carpan[karmasik], &carpIlan[reel], &carpIlan[karmasik]);
        CARP(carpan, carpIlan, sonuc);
        printf("\nsonuc= %lld + %lldi\n",sonuc[reel], sonuc[karmasik]);
    }

    if (numberType==integer)
    {
        printf("\nWrite Numbers You Want to Multiply by Using This Pattern\n"
               "a+b\n");
        scanf("%lld%lld", &carpan[reel], &carpIlan[reel]);
        CARP(carpan, carpIlan, sonuc);
        printf("\nsonuc= %lld\n",sonuc[reel]);
    }
}

void TOPLA(long long int *toplanan1, long long int *toplanan2, long long int *sonuc)
{
    sonuc[reel]= toplanan1[reel] + toplanan2[reel];
    sonuc[karmasik]= toplanan1[karmasik] + toplanan2[karmasik];
}

void CARP(long long int *carpan, long long int *carpIlan, long long int *sonuc)


{
    sonuc[reel]= (carpan[reel] * carpIlan[reel]) + (carpan[karmasik] * carpIlan[karmasik] * (-1));
    sonuc[karmasik]= (carpan[karmasik] * carpIlan[reel]) + (carpIlan[karmasik] * carpan[reel]);
}



void AreaVePerimeter()
{
    short int selection=0;
    short int cIk=0;
    
    while(cIk!=1)
    {
        selection=0;
        printf("\e[1;1H\e[2J");
        
        printf("\n\tChoose The Shape You Want to Know it's Area and Perimeter\n"
               "1. Triangle\n"
               "2. Ractangle\n"
               "3. Circle\n"
               "6. Exit\n");
        scanf("%1hd",&selection);

        if(selection==1) Triangle();
        else if(selection==2) Ractangle();
        else if(selection==3) Circle();
        else if(selection==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        else if(selection==6) cIk++;
        else printf("\ntrolleme duzgun yaz\n\n");
        if(selection!=6) pressEnter();
    }
}

void Triangle()
{
    int olculer[3]={};
    double cevre;
    double alan;

    printf("\nEnter Sizes of the Triangle\n\n");
    for(int i=0; i<=3; i++)
    {
        printf("    \t    /\\     \n"
               "  %d\t   /  \\ %d \n"
               "    \t  /    \\   \n"
               "    \t ________   \n"
               "    \t    %d      \n", olculer[0], olculer[1], olculer[2]);
        if(i!=3) printf("\033[20D\033[6A        \b\b\b\b\b\b\b\b");
        if(i!=3) scanf("%d", &olculer[i]);
    }

    AlanCevreHesapla(olculer, ucgen, &cevre, &alan);
    printf("\nPerimeter of the Triangle= \t%lf\n"
           "Area of the Triangle= \t%lf\n", cevre, alan);
}

void Ractangle()
{
    int olculer[2]={};
    double cevre;
    double alan;

    printf("\nEnter Sizes of the Ractangle\n\n");
    for(int i=0; i<=2; i++)
    {
        printf("    \t     %d     \n"
               "    \t  ________  \n"
               "    \t |        | \n"
               "    \t |        | %d \n"
               "    \t |        | \n"
               "    \t  ________  \n"
               "    \t            \n", olculer[0], olculer[1]);
        if(i!=2) printf("\033[20D\033[8A        \b\b\b\b\b\b\b\b");
        if(i!=2) scanf("%d", &olculer[i]);
    }

    AlanCevreHesapla(olculer, kare, &cevre, &alan);
    printf("\nPerimeter of the Ractangle= \t%lf\n"
           "Area of the Ractangle= \t%lf\n", cevre, alan);
}

void Circle()
{
    int olculer[1]={};
    double cevre;
    double alan;

    printf("\nEnter Radius of the Circle\n");
    scanf("%d", &olculer[0]);

    AlanCevreHesapla(olculer, cember, &cevre, &alan);
    printf("\nPerimeter of the Circle= \t%lf\n"
           "Area of the Circle= \t%lf\n", cevre, alan);
}

void AlanCevreHesapla(int *olculer, short int sekil, double *cevre, double *alan)
{
    if(sekil==ucgen)
    {
        for(int i=0; i<3; i++) *cevre+= olculer[i];
        double s= (*cevre)/2;
        *alan= sqrt( s* (s-olculer[0]) * (s-olculer[1]) * (s-olculer[2]) );
    }
    if(sekil==kare)
    {
        *cevre= 2*(olculer[0]+olculer[1]);
        *alan= olculer[0]*olculer[1];
    }
    if(sekil==cember)
    {
        *cevre= 2*olculer[0]*pi;
        *alan= olculer[0]*olculer[0]*pi;
    }
}



void Temperature()
{
    short int selection=0;
    short int cIk=0;
    
    while(cIk!=1)
    {
        selection=0;
        printf("\e[1;1H\e[2J");
        
        printf("\n\t\tChoose The Converion Type\n"
               "1. Fahrenheit to Kelvin\n"
               "2. Kelvin to Fahrenheit\n"
               "6. Exit\n");
        scanf("%1hd",&selection);

        if(selection==1) FahToKelvin();
        else if(selection==2) KelvinToFah();
        else if(selection==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        else if(selection==6) cIk++;
        else printf("\nhala trolluk yapIyon mu cidden\n\n");
        if(selection!=6) pressEnter();
    }
}

void FahToKelvin()
{
    double temperature;
    printf("\nEnter the Temperature\n");
    scanf("%lf", &temperature);
    printf("%lf degrees Fahrenheit is ", temperature);
    donustur(&temperature, fahrenheit);
    printf("%lf degrees Kelvin\n", temperature);
}

void KelvinToFah()
{
    double temperature;
    printf("\nEnter the Temperature\n");
    scanf("%lf", &temperature);
    printf("%lf degrees Kelvin is ", temperature);
    donustur(&temperature, kelvin);
    printf("%lf degrees Fahrenheit\n", temperature);
}

void donustur(double *temperature, short int birim)
{
    if(birim==fahrenheit) *temperature= ((*temperature-32)*((double)5/9))+273.15;
    if(birim==kelvin) *temperature= ((*temperature-273.15)*((double)9/5))+32;
}



void pressEnter()
{
    //Press ENTER to continue... is enough explain i think
    printf("\n\nPress ENTER to continue... \n");
    while(getchar() != '\n');
    while(getchar() != '\n') /* nothing happens */;  
}