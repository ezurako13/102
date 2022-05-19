#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *CREATEmatris(int row, int column);
float average_finder(int *array, int row, int column);
void intervew (const char s1, const char s2, char * s3);
char *CombineString(char *string1, char *string2);



int main()
{
    int *matris3, *matris4;
    short int secenek, cIk=0;

    while (cIk!=1)
    {
        printf("\e[1;1H\e[2J");
        secenek=0;
        printf("\n\nChoose a Task to Perform\n"
            "\n1. Find Average of Values in Elements that Sum of it's Index Numbers are Even Number"
            "\n2. Combine Strings"
            "\n6. Exit\n\n");
        scanf("%hd",&secenek);

        if(secenek==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
        if(secenek==6) cIk=1;
        if(secenek==1)
        {    
            printf("\n\nCreating 3x5 and 4x9 2D Array...\n\n");
            printf("Matrix:\n");
            matris3= CREATEmatris(3, 5);
            printf("\nResult= %.1f\n\n", average_finder(matris3, 3, 5));
            printf("\n");
            printf("Matrix:\n");
            matris4= CREATEmatris(4, 9);
            printf("\nResult= %.1f\n", average_finder(matris4, 4, 9));
        }
        if(secenek==2)
        {
            printf("\nEnter a String\n");
            char *buffer= (char *)calloc(50, sizeof(char));
            scanf("%s",buffer);
            
            char *string1= (char *)calloc(strlen(buffer), sizeof(char));
            strcpy(string1, buffer);

            printf("\nEnter Another String, which has different lenght, to Merge with First One\n");        
            scanf("%s",buffer);
            char *string2= (char *)calloc(strlen(buffer), sizeof(char));
            strcpy(string2, buffer);          
            free(buffer);

            int len1= strlen(string1);
            int len2= strlen(string2);
            short int say1=0, say2=0;
            char *combinedString= (char *)calloc( len1+len2+1, sizeof(char) );
            int i;

            for(i=0; i< (len1+len2); )
            {
                intervew(string1[say1], string2[say2], combinedString+i);
                if(say1<len1)
                {    
                    say1++;
                    i++;
                }
                if(say2<len2)
                {    
                    say2++;
                    i++;
                }    
            }
            
            printf("\nCombined String is %s\n", combinedString);
            free(string1);
            free(string2);
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



int *CREATEmatris(int row, int column)
{
    int i, o;
    int *matris= calloc(row*column, sizeof(int));
    for(i=0; i<column; i++) 
    {
        for(o=0; o<row; o++)
        {
            matris[i*row+o]= (2* (i*row+o+1) * (i*row+o+1) )-3;
            printf("%d\t", matris[i*row+o]);
        }
        printf("\n");
    }

    return matris;
}

float average_finder(int *array, int row, int column)
{
    int i, o, sayac=0;
    float result=0.0f;
    for(i=0; i<column; i++) 
    {
        for(o=0; o<row; o++)
        {
            if((i+o)%2==0) 
            {
                result+= array[i*row+o];
                printf("%d ", i+o);
                sayac++;
            }
        }
    }

    return (result/sayac);
}



char *CombineString(char *string1, char *string2)
{
    int len1= strlen(string1);
    int len2= strlen(string2);
    short int say1=0, say2=0;
    char *combinedString= (char *)calloc( len1+len2, sizeof(char) );

    for(int i=0; i< (len1+len2); )
    {
        if(len1>say1)
        {    
            *(combinedString+i)= *(string1+say1);
            say1++;
            i++;
        }
        if(len2>say2)
        {    
            *(combinedString+i)= *(string2+say2);
            say2++;
            i++;
        }    
    }    
    
    return combinedString;
}

void intervew (const char s1, const char s2, char * s3)
{
    if(s1!=0) *s3=s1;
    if(s2!=0) 
    {
        if(s1==0) *(s3)=s2;
        else *(s3+1)=s2;
    }
}