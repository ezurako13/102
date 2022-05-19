#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 31

int check_palindrome(int a[], int n);
int search_element(int arr[], int input_number, int n);
float cosx(int n, float x );


int main()
{
    short int cIk=0, secmek=0;
    srand(time(0));
    while (cIk!=1)
    {
        printf("\e[1;1H\e[2J");
        secmek=0;
        printf("\n\nChoose One of the Tasks Below\n"
            "1. Check Palindrome\n"
            "2. Search Element\n"
            "3. Implementing Cos\n"
            "6. Exit\n\n");
        scanf("%1hd",&secmek);

        if(secmek==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        if(secmek==6) cIk=1;
        if(secmek==1)
        {
            int palindrome=31;
            char *string= (char *)calloc(51, sizeof(char));
            printf("\n\nEnter a Number You Want to Check If It is Palindrome or not\n");
            scanf("%50s",string);
            short int lenS= strlen(string), lenI=0;
            int *buffer= (int *)calloc(lenS, sizeof(int));
            
            for(int i=0; i<lenS; i++)
            {
                if(string[i]<='9' && string[i]>='0')
                {
                    buffer[lenI]= ((int)string[i])-48;
                    lenI++;
                }
            }
            free(string);
            
            int *a= (int *)calloc(lenI, sizeof(int));
            for(int i=0; i<lenI; i++) 
            {
                a[i]= buffer[i];
                printf("%d ", a[i]);
            }
            printf("\n");
            free(buffer);
            
            palindrome= check_palindrome(a, lenI);
            printf("\n");
            if(palindrome==31) printf("\n\nFonksiyon bozuk...\n\n");
            if(palindrome==1) printf("\nYour input is a palindrome\n");
            if(palindrome==0) printf("\nYour input is not a palindrome\n");

        }
        if(secmek==2)
        {
            int arr[20];
            printf("\nArray:\n");
            for(int o=0; o<20; o++)
            {
                arr[o]= rand()%100;
                printf("%d ", arr[o]);
            }
            int input_number=rand()%100;
            printf("\n\nInput Number= %d\n", input_number);
            int icindEvar=52;
            icindEvar= search_element(arr, input_number, 20);
            if(icindEvar==52) printf("\n\nFonksiyon bozuk...\n\n");
            if(icindEvar==1) printf("\nInput Number is in the Arrya\n");
            if(icindEvar==0) printf("\nOtherwise\n");
        }
        if(secmek==3)
        {

            printf("\n%f\n", cosx(4,5));
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



int check_palindrome(int a[], int n)
{
    printf("\n*a= %d  n= %d  *(a+n-1)= %d", *a, n, *(a+n-1));
    if(*a!=(*(a+n-1))) return 0;
    if(a>=(a+n)) return 1;
    
    check_palindrome(a+1, n-2);
}



int search_element(int arr[], int input_number, int n)
{
    if(*(arr+n-1)==input_number) return 1;
    if(n==0) return 0;

    search_element(arr, input_number, n-1);
}



float cosx(int n, float x )
{
    if(n==MAX+1) return 1.0f;
    return 1.0f - ( (x*x)/((float)(2*n-1)*(2*n)) ) * (cosx(n+1, x));
}
