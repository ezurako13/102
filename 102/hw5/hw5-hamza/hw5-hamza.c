#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder}Shapes;

typedef enum{Area=1,Perimeter,Volume}Calculators;

int select_shape ();

int select_calc ();

int calculate (int(* f)(), int(* p)());

int calc_triangle(int calc);

int calc_quadrilateral(int calc);

int calc_circle(int calc);

int calc_pyramid(int calc);

int calc_cylinder(int calc);

int find_big(int num1,int num2);

int find_small(int num1,int num2);

int main()
{
calculate(select_shape,select_calc);
    return 0;

}

int select_shape ()

{
    int chose=-1;
        printf("Select a shape the calculation\n"
                    "\t1.Triangle\n"
                    "\t2.Quadrilateral\n"
                    "\t3.Circle\n"
                    "\t4.Pyramid\n"
                    "\t5.Cylinder\n"
                    "\t0.EXIT\n");
        scanf("%d",&chose);
        while(getchar()!=10);
        return chose;

}

int select_calc ()
{
    int chose=-1;
        printf("Select calculator\n"
                    "\t1.Area\n"
                    "\t2.Perimeter\n"
                    "\t3.Volume\n"
                    "\t0.EXIT\n");
        scanf("%d",&chose);
        while(getchar()!=10);
        return chose;
}

int calculate (int(* f)(), int(* p)())
{
    Shapes chose_s=-1;
    Calculators chose_c=-1;
    int control=1;
    int control_3=1;
    printf("Welcome to the geometric calculator!\n");
    while(control)
    {
        chose_s=f();
        if(chose_s==0)
            control=chose_s;
        else if(chose_s>0&&chose_s<6)
        {
            int control_2=1; 
            while(control_2)
            {
                chose_c=p();
                if(chose_c==0)
                    control_2=chose_c;
                else if  (chose_c>0&&chose_c<4) 
                {
                    switch (chose_s)
                    {
                        case Triangle:
                                
                                while(control_3)
                                {
                                    control_3=calc_triangle(chose_c);
                                    if(control_3==1)
                                        printf("ERROR!! Invalid entry for Triangle sides\n");
                                }
                                control_3=1;
                            break;
                        case Quadrilateral:
                                while(control_3)
                                {
                                    control_3=calc_quadrilateral(chose_c);
                                    if(control_3==1)
                                        printf("ERROR!! Invalid entry for Quadrilateral sides\n");
                                }
                                control_3=1;
                            break;
                        case Circle:
                                while(control_3)
                                {
                                    control_3=calc_circle(chose_c);
                                    if(control_3==1)
                                        printf("ERROR!! Invalid entry for Circle radius\n");
                                }
                                control_3=1;
                                break;
                        case Pyramid:
                            while(control_3)
                            {
                                control_3=calc_pyramid(chose_c);
                                if(control_3==1)
                                printf("ERROR!! Invalid entry for Pyramid's base side\n");
                                if(control_3==2)
                                printf("ERROR!! Invalid entry for Pyramid's slant heigt \n");
                                if(control_3==3)
                                printf("ERROR!! Invalid entry for Pyramid's height \n");
                            }
                            control_3=1;
                            break;
                        case Cylinder:
                          while(control_3)
                            {
                                control_3=calc_cylinder(chose_c);
                                if(control_3==1)
                                printf("ERROR!! Invalid entry for Cylinder radıus\n");
                                if(control_3==2)
                                printf("ERROR!! Invalid entry for Cylınder's heigt \n");
                            }
                            control_3=1;
                            break;
                    }
                }  
                else   
                    printf("ERROR!! Invalid value for chosing ,try again!!\n");      
            }
        }
        else   
            printf("ERROR!! Invalid value for chosing ,try again!!\n");
    }
    
  

}

int calc_triangle(int calc)
{
    Calculators chose_c1;
    chose_c1=calc;
    float edge1=-1,edge2=-1,edge3=-1;
    char c;
    int control=1;
    float sum;
    switch (chose_c1)
    {
        case Area:
                printf("Enter 3 sides of triangles:");
                scanf("%f",&edge1);
                while(getchar()!=10);
                if(edge1>0)
                {
                    scanf("%f",&edge2);
                    while(getchar()!=10);
                    if(edge2>0)
                    {
                        scanf("%f",&edge3);
                        while(getchar()!=10);
                        if(edge3>0)
                        {
                            if(((abs(edge1-edge2))<(abs(edge3)))&&(edge3<(abs(edge1+edge2))))
                            {
                                control=0;
                                float s;
                                s=(float)(edge1+edge2+edge3)/2;
                                sum=sqrt(s*(s-edge1)*(s-edge2)*(s-edge3));
                                printf("area of TRIANGLE %.2f\n",sum);
                            return 0;

                            }
                            else
                                return 1;
                        }
                        else
                            return 1;
                    }
                    else
                        return 1;
                }
                else
                    return 1;
            break;
        case Perimeter:
            printf("Enter 3 sides of triangles:\n");
            scanf("%f",&edge1);
            while(getchar()!=10);
            if(edge1>0)
            {
                scanf("%f",&edge2);
                while(getchar()!=10);
                if(edge2>0)
                {
                    scanf("%f",&edge3);
                    while(getchar()!=10);
                    if(edge3>0)
                    {
                        if(((abs(edge1-edge2))<(abs(edge3)))&&(edge3<(abs(edge1+edge2))))
                        {
                            control=0;
                            sum=edge1+edge2+edge3;
                            printf("perimeter of TRIANGLE %.2f\n",sum);
                            return 0;
                        }
                        else
                            return 1;
                    }
                    else
                        return 1;
                }
                else
                    return 1;
            }
            else
                return 1;
        case Volume:
            printf("ERROR!! you cannot calculate the Triangle volume!!\n");
            return 0;
        break;
    }
    
    return 0;
}

int calc_quadrilateral(int calc)
{
    Calculators chose_c1;
    chose_c1=calc;
    float edge1=-1,edge2=-1,edge3=-1,edge4=-1;
    char c;
    int control=1;
    float sum;
    switch (chose_c1)
    {
         case Area:
       
            printf("Enter 4 sides of quadrilateral:\n");
            printf("a=>");
            scanf("%f",&edge1);
            while(getchar()!=10);
            if(edge1>0)
            {
                printf("b=>");
                scanf("%f",&edge2);
                while(getchar()!=10);
                if(edge2>0)
                {
                    printf("c=>");
                    scanf("%f",&edge3);
                    while(getchar()!=10);
                    if(edge3>0)
                    {
                        printf("d=>");
                        scanf("%f",&edge4);
                        while(getchar()!=10);
                        if(edge4>0)
                        {
                            int sum1=abs(edge1-edge3),sum2=abs(edge2-edge4);
                            int big,small;
                            big=find_big(sum1,sum2);
                            small=find_small(edge1+edge3,edge2+edge4);
                            if(big<small)
                            {
                                float s;
                                s=(edge1+edge2+edge3+edge4)/2;
                                sum=sqrt((s-edge1)*(s-edge2)*(s-edge3)*(s-edge4));
                                printf("area of Quadrilateral %.2f\n",sum);
                                return 0;
                            }
                            else
                                 return 1;
                        }
                        else
                            return 1;
                    }
                    else
                        return 1;
                }
                else
                    return 1;
            }
            else
                return 1;        
            break;
        case Perimeter:
            printf("Enter 4 sides of quadrilateral:\n");
            printf("a=>");
            scanf("%f",&edge1);
            while(getchar()!=10);
            if(edge1>0)
            {
                printf("b=>");
                scanf("%f",&edge2);
                while(getchar()!=10);
                if(edge2>0)
                {
                    printf("c=>");
                    scanf("%f",&edge3);
                    while(getchar()!=10);
                    if(edge3>0)
                    {
                        printf("d=>");
                        scanf("%f",&edge4);
                        while(getchar()!=10);
                        if(edge4>0)
                        {
                            int sum1=abs(edge1-edge3),sum2=abs(edge2-edge4);
                            int big,small;
                            big=find_big(sum1,sum2);
                            small=find_small(edge1+edge3,edge2+edge4);
                            if(big<small)
                            {
                                sum=edge1+edge2+edge3+edge4;
                                printf("perimeter of Quadrilateral %.2f\n",sum);
                                return 0;
                            }
                            else
                                 return 1;
                        }
                        else
                            return 1;
                    }
                    else
                        return 1;
                }
                else
                    return 1;
            }
            else
                return 1;  
            break;
        case Volume:
            printf("ERROR!! you cannot calculate the Quadrilateral volume!!\n"); 
            return 0;
    }
}

int calc_circle(int calc)
{
     Calculators chose_c1;
    chose_c1=calc;
    float radius=-1;
    int control=1;
    switch (chose_c1)
    {
    case Area:
            printf("Enter circle radius:\n");
            scanf("%f",&radius);
            while(getchar()!=10);
            if(radius>0)
            {   
                printf("area of Circle %.2f\n",3.14*radius*radius);
                return 0;
            }
            else    
                return 1;
    case Perimeter:
            printf("Enter circle radius:\n");
            scanf("%f",&radius);
            while(getchar()!=10);
            if(radius>0)
            {   
                printf("perimeter of circle %.2f\n",3.14*radius*2);
                    return 0;
            }
            else
                return 1;
    case Volume:
        printf("ERROR!! you cannot calculate the Circle volume!!\n"); 
        return 0;
    }
  
}

int calc_pyramid(int calc)
{
    Calculators chose_c1;
    chose_c1=calc;
    float slant_h=-1,base_s=-1,height=-1;
    int control=1;
    switch (chose_c1)
    {
        case Area:
            printf("Please enter base side of pyramid\n");
            scanf("%f",&base_s);
            while(getchar()!=10);
            if(base_s>0)
            {   
                printf("Please enter slant hight of pyramid\n");
                scanf("%f",&slant_h);
                while(getchar()!=10);
                if(slant_h>0)
                {
                    printf("BASE SURFACE of Pyramid:%.2f\n",base_s*base_s);
                    printf("LATERAL SURFACE of pyramid:%.2f\n",2*base_s*slant_h);
                    printf("AREA of Pyramid %.2f\n",(base_s*base_s)+(2*base_s*slant_h));
                    return 0;
                }
                else
                    return 2;
            }
            else    
                return 1;
        
    case Perimeter:
        printf("Pyramid's perimeter cannot calculate\n");
            return 0 ;
    case Volume:
            printf("Please enter base side of pyramid\n");
            scanf("%f",&base_s);
            while(getchar()!=10);
            if(base_s>0)
            {   
                printf("Please enter  height of pyramid\n");
                scanf("%f",&height);
                while(getchar()!=10);
                if(height>0)
                {
                    printf("VOLUME of PYRAMIDE %.2f\n",(base_s*base_s*height)/3); 
                    return 0;
                }
                else
                    return 3;
            }
            else    
                return 1;
       
    }
}   

int calc_cylinder(int calc)
{
      Calculators chose_c1;
    chose_c1=calc;
    float radius=-1,height=-1;
    int control=1;
    switch (chose_c1)
    {
    case Area:
        
            printf("Please enter radius of cylinder\n");
            scanf("%f",&radius);
            while(getchar()!=10);
            if(radius>0)
            {   
                printf("Please enter height of cylinder\n");
                scanf("%f",&height);
                while(getchar()!=10);
                if(height>0)
                {
                    printf("BASE SURFACE area of Cylinder:%.2f\n",2*3.14*radius*radius);
                    printf("LATERAL SURFACE of Cylinder:%.2f\n",2*3.14*radius*height); 
                    printf("AREA of CYLINDER %.2f\n",(2*3.14*radius*height)+(2*3.14*radius*radius));
                    return 0;
                }
                else
                return 2;
            }
            else    
                return 1;        
    case Perimeter:
        printf("Cylinder's perimeter cannot calculate\n");
            return 0 ;
    case Volume:
            printf("Please enter radius cylinder\n");
            scanf("%f",&radius);
            while(getchar()!=10);
            if(radius>0)
            {   
                printf("Please enter hight of cylinder\n");
                scanf("%f",&height);
                while(getchar()!=10);
                if(radius>0)
                {
                    printf("VOLUME of CYLINDER %.2f\n",3.14*radius*radius*height);
                    return 0;
                } 
                else
                    return 2;
            }
            else    
                return 1;
    }
}

int find_big(int num1,int num2)
{
    if(num1>num2)
        return num1;
    else
        return num2;
}

int find_small(int num1,int num2)
{
     if(num1<num2)
        return num1;
    else
        return num2;
}