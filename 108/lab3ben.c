#include <stdio.h>

int find_max_distance(int num_inputs);
void find_odd_average();


int main()
{
    int num_inputs=0, i, maXdistance, sel=0, cIk=0;
    
    while(cIk!=1)
    {
        printf("\nSelect Task will Have been Done\n"
            "1. Find the Max Distance\n"
            "2. Find Average of Odd Numbers\n"
            "6. Exit\n\n");
        scanf("%d",&sel);
        
        if(sel==6) cIk=1;
        if(sel==1)
        {    
            printf("\n\nEnter 5 Numbers\n");
            maXdistance= find_max_distance(num_inputs);
        }
        if(sel==2)
        {
            printf("\n\nEnter Positive Numers and Enter (-1) to Start Calculation\n");
            find_odd_average();
        }
    }


return 0;
}


int find_max_distance(int num_inputs)
{
    int distance=0, i, maXdistance=0, previous=0;
    
    for(i=0; i<5; i++)
    {   
        printf("%d: ", (i+1));
        scanf("%d",&num_inputs);
        if(i==0) previous= num_inputs;
        if( (distance= previous-num_inputs) < 0) distance*=(-1);
        if(distance > maXdistance) maXdistance= distance;
        previous= num_inputs;
    }
    printf("\n\nMax Dstance is %d\n", maXdistance);

    return maXdistance;
}


void find_odd_average()
{
    int girdi=0, i, sayac=0;
    short int cIk=0;
    long int toplam=0;

    while(cIk!=1)
    {
        printf("%d: ", (i+1));
        scanf("%d",&girdi);
        if(girdi > (-1) )
        {
            if(girdi%2 == 1) 
            {
                toplam+= girdi;
                sayac++;
            }
            i++;
        }
        else if(girdi== (-1) ) cIk=1;
        else printf("\n\nPozitif SayI Yaz\n");
    }

    printf("\n\nAverage of Odd Numbers is %ld\n\n", (toplam/sayac));
}