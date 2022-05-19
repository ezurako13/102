#include<stdio.h>
int find_max_distance(int *num_inputs);
void find_odd_average();
int main() {
 int num[5],max;;
 for(int i=0;i<5;i++) 
 {
 printf("write your value:");
 scanf("%d",&num[i]);
 
 }
 max=find_max_distance(&num);
printf(" max dist is %d\n",max);
find_odd_average();


}
int find_max_distance(int *num_inputs)
{
int a=0,b=0,c,d;
	for(int i=0;i<4;i++)
	{ 
	
	if((num_inputs[i]-num_inputs[i+1])>0 && a<(num_inputs[i]-num_inputs[i+1]) ) 
	{
	a=(num_inputs[i]-num_inputs[i+1]);
	//printf("%d\n",a);
	}	
          if((num_inputs[i]-num_inputs[i+1])<0 && b>(num_inputs[i]-num_inputs[i+1]) ) b=(num_inputs[i]-num_inputs[i+1]);
         // printf("%d\n",b);
	}
	d=(-b);
	if(a>d) return a;
	if(d>a) return d;
	//return d;

}
void find_odd_average()
{
int *p,sum=1,c=0,i=0,av=0,a=0,m=1;
 p=&a;
	while(m)
	{  
		
		scanf("%d",p);
		if(*p%2==1) 
		{
		sum+=*(p);
		c++;
		}
		//sum+=*(p);
		
			if(*(p)<0) 
			{
				av=sum/(c);
				printf("%d",av);
				m=0;
			}
       }
}