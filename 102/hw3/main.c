#include <stdio.h>
#include <math.h>

void gorev1();
void gorev2();
void gorev3();
void gorev4();
int sum (int n1, int n2, int flag);
int multi (int n1, int n2, int flag);
int isprime (int a);
void write_file (int number);
void sort_file ();
void print_file ();
void sil(int once, int sonra, FILE *dosya);


int main()
{
	short int secme, cIk=0;
	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		secme=0;														//				
		printf("\n\nSelect operation\n"									//									
			" 1. Calculate sum/multiplication between two numbers\n"	//	Menu																
			" 2. Calculate prime numbers\n"								//										
			" 3. Show number sequence in file\n"						//												
			" 4. Sort number sequence in file\n"						//												
			" 6. Exit\n"																		
			" ---------------------------------------------------\n\n ");
		scanf("%hd",&secme);

		if(secme==0) printf("\nbilerek 0 yazmadIysan scanf bozuk\n\n");
		if(secme==6) cIk=1;
		if(secme==1)									//
		{												//								
			gorev1();									//											
		}												//								
		if(secme==2)									//											
		{												//								
			gorev2();									//											
														//						
		}												//								
		if(secme==3)									//	Task Selection										
		{												//								
			gorev3();									//											
														//						
		}												//								
		if(secme==4)									//											
		{												//								
			//int xd[5];								//												
			//printf("\n(main:) xd= %lld\n", xd);		//																		
			//deney(xd);								//												
			gorev4();									//											
		}
	}


	return 0;
}

void gorev1()
{
	int N1= 0, N2= 0, optype= 0, tekcift= 0, result= 0;

	// Look below

	printf("Select operation"
		   "\nPlease enter '0' for sum, '1' for multiplication.\n");
	scanf("%d", &optype);
	if(optype != 1 && optype != 0)	
	{
		printf("\nHatali tuslama yaptiniz\n");
		return;
	}

	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
	scanf("%d", &tekcift);
	if(tekcift != 1 && tekcift != 0)	
	{
		printf("\nHatali tuslama yaptiniz\n");
		return;
	}

	printf("Please enter two different number:"
		   "\nNumber 1: ");
	scanf("%d", &N1);

	printf("Number 2: ");
	scanf("%d", &N2);

	printf("Result\n ");

	//		All the information so far in this task can be anderstood by looking
	//	  printfs above

	if(N1 > N2)								//
	{										//		Reversing number if they are 
		int d1;								// 	  ordered in decreasing order.
		d1= N2;								//
		N2= N1;								//
		N1= d1;
	}												//
	if(N2 -N1 == 2)	optype= 2;						//	Handling extreme cases
	if(N2 -N1 < 2)	optype= 3;						//
	
	if(tekcift == 0 && N1 %2 == 0)	N1++;		//	 This part is for bug fixing and 
												//	it's not much about task
	switch(optype)
	{
	case 0:
															//
		printf("%d", N1 +N1%2 +tekcift);					//	Printing appropriate numbers 
		for(int a= N1 +N1%2 +2 +tekcift; a < N2; a += 2)	// between N1 and N2 with + sign
			printf(" + %d", a);								//
															//
		result= sum(N1, N2, tekcift);
		printf(" = %d", result);
		
		break;

	case 1:
															//
		printf("%d", N1 +N1%2 +tekcift);					//	Printing appropriate numbers 
		for(int a= N1 +N1%2 +2 +tekcift; a < N2; a += 2)	// between N1 and N2 with + sign
			printf(" * %d", a);								//
		
		result= multi(N1, N2, tekcift);
		printf(" = %d", result);
		
		break;

	case 2:
		if(N1 %2 ==0 && tekcift == 1)				//
		{											//
			result= (N1 +N2) /2;					//	Correcting output if N1 and N2 
			printf("%d = %d", result, result);		// has difference of 2 and considering 
		}											// odd and even numbers
		if(N1 %2 ==1 && tekcift == 0)				//
		{											//
			result= (N1 +N2) /2;					//
			printf("%d = %d", result, result);		//
		}											
		else							//
			printf("0 = 0");			//
		break;							//	if there isn't any number between them																	
										//	
	default:							//				
		printf("0 = 0");				//							
		break;							//				
	}

	write_file(result);
	printf("\nThe results has written to the results.txt file.");

}

void gorev2()
{
	int i= 0, asalmi= 0, a= 0;

	printf("\nPlease enter an integer: ");	//
	scanf("%d", &a);						//	Asking for upper limit
											//
	for(i= 2; i < a; i++)
	{
		//	Starting from 2 and searching next prime
		asalmi= isprime(i);
		if(asalmi == 1)	printf("%d is a prime number.\n", i);
		else	printf("%d is not a prime number, it is divisible by %d.\n", i, asalmi);

	}
}

void gorev3()
{								//
	printf("Result :\n");		//	No need to explain
	print_file();				//
}

void gorev4()
{							//
	sort_file();			//		Explanation			
	printf("Result :\n");	//
	print_file();			//				
}							//

int sum (int n1, int n2, int flag)
{
	int toplam= 0;

	for(int a= n1 +n1%2 +flag; a < n2; a += 2)		//															
	{												//	Summing numbers between N1 and N2				
		toplam += a;								//									
	}												//					

	return toplam;
}

int multi (int n1, int n2, int flag)
{
	int toplam= 1;

	for(int a= n1 -n1%2 +2 -flag; a < n2; a += 2)	//												
	{												//	Multiplying numbers between N1 and N2
		toplam *= a;								//					
	}												//	

	return toplam;
}

int isprime (int a)
{
	int i= 0, akok= (int)sqrt(a);	//									
	for(i= 2 ;i <= akok; i++)		//	Checking whether a is prime or not by 								
	{								// looking for any divisible
		if(a %i == 0)	return i;	//									
	}								//		
	return 1;
}

void write_file(int yaz)
{
	FILE *dosya= fopen("results.txt", "a+");	//												
												//	Write file
	fprintf(dosya, "%d ", yaz);					//								
												//	
	fclose(dosya);								//					
}

void print_file()
{																
	FILE *dosya= fopen("results.txt", "r+");	//															
												//				
	int oku= 0;									//							
												//				
	while(feof(dosya) == 0)						//	Print all the numbers in results.txt										
	{											//					
		fscanf(dosya, "%d ", &oku);				//												
		printf("%d ", oku);						//										
	}											//					
												//				
	fclose(dosya);								//								
}

void sort_file ()
{			
	//	void sil(int once, int sonra, FILE *dosya) is needed in order this part to work. 

	FILE *dosya= fopen("results.txt", "r+");
	FILE *reg= fopen("temporary_file.txt", "a+");
	int min1= 0x7fffffff, min2= 0x7fffffff, min3= 0x7fffffff;
	int kactane= 0, temp, once= 0, sonra= 0, oku;

	while(feof(dosya) == 0)				//						
	{									// Counting numbers in results.txt	
		fscanf(dosya, "%d ", &temp);	//									
		kactane++;						//				
	}										
	//printf("\n(zort_file:) kactane= %d\n", kactane);

	while(kactane > 0)
	{	
		min1= 0x7fffffff;
		min2= 0x7fffffff;
		min3= 0x7fffffff;

		rewind(dosya);							//
		if(kactane > 0)							//
		{										//	
			while(feof(dosya) == 0)				//							
			{									//	Finding min and removing it 
				temp= ftell(dosya);				// from results.txt
				fscanf(dosya, "%d ", &oku);		//									
				if(min1 > oku)					//	Finding place of cursor in order 	
				{								// to delete it
					once= temp;					//						
					min1= oku;					//						
					sonra= ftell(dosya);		//									
				}								//			
			}									//		
			sil(once, sonra, dosya);			//								
			kactane--;							//				
		}										//	
	
		rewind(dosya);							//				
		if(kactane > 0)							//				
		{										//	Finding min and removing it 
			while(feof(dosya) == 0)				// from results.txt
			{									//		
				temp= ftell(dosya);				//	Finding place of cursor in order 		
				fscanf(dosya, "%d ", &oku);		// to delete it
				if(min2 >= oku)					//						
				{								//			
					once= temp;					//						
					min2= oku;					//						
					sonra= ftell(dosya);		//									
				}								//			
			}									//		
			sil(once, sonra, dosya);			//								
			kactane--;							//				
		}										//	
	
		rewind(dosya);							//				
		if(kactane > 0)							//				
		{										//	Finding min and removing it 
			while(feof(dosya) == 0)				// from results.txt
			{									//		
				temp= ftell(dosya);				//	Finding place of cursor in order 		
				fscanf(dosya, "%d ", &oku);		// to delete it
				if(min3 >= oku)					//	
				{								//			
					once= temp;					//						
					min3= oku;					//						
					sonra= ftell(dosya);		//									
				}								//			
			}									//		
			sil(once, sonra, dosya);			//								
			kactane--;							//				
		}										//	

		fprintf(reg, "%d ", min1);
		fprintf(reg, "%d ", min2);
		fprintf(reg, "%d ", min3);
	}


	rewind(reg);						//					
	rewind(dosya);						//					
	while(feof(reg) == 0)				//							
	{									//		Copying temporary file back into 		
		fscanf(reg, "%d ", &temp);		//	  results.txt
		fprintf(dosya, "%d ", temp);	//										
	}									//		

	fclose(dosya);
	fclose(reg);
}

void sil(int once, int sonra, FILE *dosya)
{										//
	fseek(dosya, once, SEEK_SET);		//		Placing spaces from once to						
	for(int x= once; x < sonra; x++)	//	  sonra in results.txt file in
		fprintf(dosya, "%c", ' ');		//	  order to remove desired number
}										//
