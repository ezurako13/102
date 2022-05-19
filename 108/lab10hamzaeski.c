#include <stdio.h>
#include <stdlib.h>

typedef struct
{
char title[50];
char author[50];
char subject[50];
int year;
}	book;

void submenu(book *array,int size);

int main()
{
	int count=1,chose,m=1;
	book *books= NULL, *arr2= NULL;
		while(m)
		{
			printf("MENU\n"
					"\t1.Add new book\n"
					"\t2.List books\n"
					"\t3.Exit\n");
					scanf("%d%*c",&chose);
			if(chose==1)
			{
				books=calloc(count,sizeof(book));
				printf("Please write tour book title\n");
				scanf("%[^\n]%*c",books[count-1].title);
				printf("Please write tour book author\n");
				scanf("%[^\n]%*c",books[count-1].author);
				printf("Please write tour book subject\n");
				scanf("%[^\n]%*c",books[count-1].subject);
				printf("write your bookŝ public date\n");
				scanf("%d%*c",&books[count-1].year);	
			for(int i=0;i<count-1;i++)	arr2[i]=books[i];	
			if(arr2!=NULL) free(arr2);
			arr2=books;
			count++;
			}
			if(chose==2) submenu(books,count -1);
			if(chose==3) m=0;
		}
	return 0;
}
	
void submenu(book *array,int size)
{
printf("hamza");
}