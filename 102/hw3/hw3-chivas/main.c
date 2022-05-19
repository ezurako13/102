#include <stdio.h>
#include <math.h>

int firsttask(void);
int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);
int writefile(int num);
int prime(int num);
int secondtask(void);

int main()
{
    int secim;

    printf("Select operation\n");
    printf("1. Calculate sum/multiplication between two numbers\n");
    printf("2. Calculate prime numbers\n");
    printf("3. Show number sequance in file\n");
    printf("4. Sort number sequance in file\n");
    printf("-----------------------------------");
    scanf("%d",&secim);
    
    if(secim==1)
    //sum-multip fonc.
        firsttask();
    else if(secim==2)
        secondtask();
    //prime numbers
    else if(secim==3);
    //show number
    else if(secim==4);
    //sort number
}
int firsttask(void)
{
    int op,n1,n2,evenodd;
    printf("Select operation\n");
    printf("Please enter '0' for sum, '1' for multiplication\n");
    scanf("%d",&op);
    printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
    scanf("%d",&evenodd);
    printf("Please enter two different number:\n");
    printf("Number 1:");
    scanf("%d",&n1);
    printf("Number 2:");
    scanf("%d",&n2);
    if (n2-n1>2|| n2-n1==2&&n1%2!=evenodd)
    {
        switch(op)
        {
            int a;
            case 0:
        
                a=sum(n1,n2,evenodd);  
                writefile(a);
                printf("The result is written to the result.txt file.");
                break;
            case 1:

                a=multi(n1,n2,evenodd);
                writefile(a);
                printf("The result is written to the result.txt file.");

        }
    }
    else
        printf("error");

}
int sum(int n1, int n2, int flag)
{
    int pluscnt=1;
    int sonuc=0;
    int kontrol;
    if(n1%2==flag)
        kontrol= n1+2;
    else 
        kontrol= n1+1;
    while(kontrol<n2)
    {
        printf("%d", kontrol);
        if(pluscnt!=(n2-n1)/2)
            printf("+");
        sonuc=sonuc+kontrol;
        kontrol+=2;
        pluscnt++;
    }
    printf("=%d\n",sonuc);
    return (sonuc);

}
int multi(int n1, int n2, int flag)
{
    int pluscnt=1;
    int sonuc=1;
    int kontrol;
    if(n1%2==flag)
        kontrol= n1+2;
    else 
        kontrol= n1+1;
    while(kontrol<n2)
    {
        printf("%d", kontrol);
        if(pluscnt!=(n2-n1)/2)
            printf("*");
        sonuc=sonuc*kontrol;
        kontrol+=2;
        pluscnt++;
    }
    printf("=%d\n",sonuc);
    return (sonuc);

}
int writefile(int num)
{
    FILE *fp=fopen("result.txt","a");
    fprintf(fp," %d",num);
    fclose(fp);
}
int prime(int num)
{   
    int i=2;
    while(i<num)
    {
        if(num%i==0)
            return(i);
        i++;
    }    
    return 0;
}
int secondtask(void)
{
    int num;
    int i=2;
    printf("Please enter an integer:");
    scanf("%d",&num);
    while(i<num)
    {   
        if(prime(i)==0)
            printf("%d is a prime number.\n",i);
        else 
            printf("%d is not a prime number, it is dividible by %d.\n",i,prime(i));
        i++;
    }

}