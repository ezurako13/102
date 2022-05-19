#include <stdio.h>

void drawGraph();
int checkExs(char *name);

int main()
{
	short int yapma, cIk=0, dosyavar= 0;
	while (cIk!=1)
	{
		printf("\e[1;1H\e[2J");
		yapma=0;											//
		printf("\n\nSelect an operation...\n"				//
			"1 -> Enter the coefficents.\n"					//
			"2 -> Draw the graph.\n"						//
			"3 -> Print the graph into a .txt file. \n"		//	Menu
			"4 -> Exit.\n\n"								//
			"Choice: ");									//
		scanf("%hd",&yapma);								//
	//	fflush(stdin);
		
		dosyavar= checkExs("coefficients.txt");													//
		if(dosyavar == 0 && (yapma == 2 || yapma == 3))											//
		{																						//
			printf("\ncoefficients.txt file does not exist. Please create one in option 1\n");	//	Checkes existance of file and 
			yapma= 9;																			// giving feedback
		}																						//
		else if(yapma == 0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		else if(yapma == 6 || yapma == 4) cIk=1;
		else if(yapma == 1)																			//
		{																							//
			int a= 0, b=0, c= 0;																	//
			printf("\nPlease enter coefficents for following equation: x=a*(y*y) + b*y +c\n");		//
			printf("\na: ");																		//
			scanf("%d", &a);																		//
			printf("b: ");																			//
			scanf("%d", &b);																		//	Taking coefficcents and saving 
			printf("c: ");																			// them into the file
			scanf("%d", &c);																		//
																									//
			FILE *dosya= fopen("coefficients.txt", "w");											//
			fprintf(dosya, "%d\n%d\n%d\n", a, b, c);												//
			fclose(dosya);																			//
																									//
			printf("\ncoefficients.txt file has been created.\n");									//
																									//
																									//
		}																							//
		else if(yapma == 2)
		{
			int a= 0, b= 0, c= 0;
																						//
			FILE *dosya= fopen("coefficients.txt", "r");								//
			fscanf(dosya, "%d\n%d\n%d\n", &a, &b, &c);									//
			fclose(dosya);																//	Taking values of coefficents from file
																						//
			printf("\nCoefficents has been read from coefficients.txt file.");			//
			printf("\nPrinting the graph of x=%d*(y*y) + %d*y +%d.\n\n", a, b, c);		//
			
			drawGraph();

			printf("\033[33A\033[111D");				//
			for(int y= 16; y >= -16; y--)				//
			{											//
				for(int x= -55; x <= 55; x++)			//
				{										//	Moving back to initial point that graph started and 
					if(x == a*(y*y) + b*y +c)			// placing '#' to where graph should be
					{									// while moving cursor on graph
						printf("\033[1;34m");			//
						printf("#");					//
						printf("\033[0m");				//
					}									//
					printf("\033[1C");					//
				}										//
				printf("\033[1B\033[112D");				//

			}

		}
		else if(yapma == 3)
		{
			int a= 0, b= 0, c= 0;
																					//
			FILE *dosya= fopen("coefficients.txt", "r");							//
			fscanf(dosya, "%d\n%d\n%d\n", &a, &b, &c);								//	Taking values of coefficents from file
			fclose(dosya);															//
																					//
			printf("\nCoefficents has been read from coefficients.txt file.");		//


			FILE *graph= fopen("graph.txt", "w");
			
			int y, x;													//
																		//
			for(y= 16; y >= -16; y--)									//
			{															//
				for(x= -55; x <=55; x++)								//
				{														//
					if(x == a*(y*y) + b*y +c)	fprintf(graph, "#");	//
					else if(y == -16 && x == 0)	fprintf(graph, "v");	//
					else if(x == 0 && y == 16)	fprintf(graph, "^");	//	Writing graph to file by putting spesific signes to lines or 
					else if(y == 0 && x == -55)	fprintf(graph, "<");	// places that aquires given formulas while moving in ractangular
					else if(y == 0 && x == 55)	fprintf(graph, ">");	//
					else if(x == 0)	fprintf(graph, "|");				//
					else if(y == 0)	fprintf(graph, "-");				//
																		//
					else	fprintf(graph, " ");						//
				}														//
				fprintf(graph, "\n");									//
			}															//
			fclose(graph);												//

			printf("\nThe graph of x=%d*(y*y) + %d*y +%d has been written to graph.txt file.\n", a, b, c);
		}
		else	printf("\nHatali tuslama yaptiniz.\n");

		if(cIk!=1)
		{    
			printf("\n\nPress ENTER to continue.... \n");
			while(getchar() != '\n') /* nothing happens */;
			while(getchar() != '\n');
		}
	}
	if(yapma == 6)	printf("\nThis is a secret way to exit.\n");

	return 0;
}

void drawGraph()
{
	for(int y= 16; y >= -16; y--)
	{
		for(int x= -55; x <=55; x++)
		{														//
			if(x == 0 && y == 16)	printf("^");				//
			else if(y == 0 && x == -55)	printf("<");			//
			else if(y == 0 && x == 55)	printf(">");			//
			else if(y == -16 && x == 0)	printf("v");			//
			else if(x == 0)	printf("|");						//	Drawing graph with axix labels by putting spesific signes 
			else if(y == 0)	printf("-");						// to lines or places that aquires given formulas  while moving 
			else if(y == -1 && (x %10 == 9 || (-x) %10 == 1))	// in ractangular
			{													//
				printf("\b\b");									//
				printf("\033[1;31m");							//
				printf("\033[1;33m");							//
				printf("%3d", x+1);								//
				printf("\033[0m");								//
			}
			else if(x == -1 && (y %5 == 0 || (-y) %5 == 0))														
			{
				printf("\b\b");
				printf("\033[1;31m");
				printf("\033[1;33m");
				printf("%3d", y);
				printf("\033[0m");
			}

			else	printf(" ");
		}
		printf("\n");
	}
}

int checkExs(char *name)
{
	FILE *dosya= fopen(name, "r");
	
	if(dosya == 0)	return 0;

	fclose(dosya);
	return 1;
}
