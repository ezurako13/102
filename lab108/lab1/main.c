#include <stdio.h>

#define pi 3.1415926535897932384626433832795

int main()
{
	int x1= 0, x2= 0, y1= 0, y2= 0;
	printf("\e[1;1H\e[2J");

	printf("\nx1: ");
	scanf("%d",&x1);
	printf("y1: ");
	scanf("%d",&y1);
	printf("x2: ");
	scanf("%d",&x2);
	printf("y2: ");
	scanf("%d",&y2);
	
	printf("\nMidpoint: M(x,y) = "
	"(%.1lf, %.1lf)\n", (x1 + x2)/2.0, (y1 + y2)/2.0 );
	
	printf("\nSlope: m = "
	"(%.1lf)\n", (y2 - y1)/(double)(x2 - x1) );
	
	printf("\nArea: A = "
	"(%.1lf)\n", pi *((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))/4.0 );
	
	printf("\n\nPress ENTER to continue.... \n");
	while(getchar() != '\n');
	while(getchar() != '\n') /* nothing happens */;
	printf("\e[1;1H\e[2J");
	
	return 0;
}