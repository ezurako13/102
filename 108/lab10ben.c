#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
char title[50];
char author[50];
char subject[50];
int year;
}book;

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
			for(int i=0;i<count-1;i++)	books[i]=arr2[i];	
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
int choose,m=1,compare,control=0;
char comp_arr[50];
book **temp=(book **)calloc(sizeof(book*),1);
book **fake_adress=(book **)calloc(size,sizeof(book *));
	
	for(int i=0;i<size;i++)
		fake_adress[i]=&array[i];
	while(m)
	{
		printf("SUBMENU\n"
				"\t1.Get bt Title\n"
				"\t2.Get by author\n"
				"\t3.Get by subject\n"
				"\t4.Sorted List by Year\n"
				"\t5.List All Books\n"
				"\t6.EXIT\n");
		scanf("%d%*c",&choose);
		if(choose==1)
		{
			printf("Enter book's title\n");
			scanf("%[^\n]%*c",comp_arr);
			for(int i=0;i<size;i++)
			{
				compare=strcmp(comp_arr,array[i].title);
				if(compare==0)
				{
					printf("Book Found\n");
					printf("Title => %s\n",array[i].title);
					printf("Author => %s\n",array[i].author);
					printf("Subject => %s\n",array[i].subject);
					printf("Yeaar => %d\n",array[i].year);
				control++;
				}
			}
			if(control==0)
				printf("Book couldn't found, try again\n");
		}
		if(choose==2)
		{
			printf("Enter book's Author\n");
			scanf("%[^\n]%*c",comp_arr);
			for(int i=0;i<size;i++)
			{
				compare=strcmp(comp_arr,array[i].author);
				if(compare==0)
				{
					printf("Book Found\n");
					printf("Title => %s\n",array[i].title);
					printf("Author => %s\n",array[i].author);
					printf("Subject => %s\n",array[i].subject);
					printf("Yeaar => %d\n",array[i].year);
				control++;
				}
			}
			if(control==0)
				printf("Book couldn't found, try again\n");

		}
		if(choose==3)
		{
			printf("Enter book's subject\n");
			scanf("%[^\n]%*c",comp_arr);
			for(int i=0;i<size;i++)
			{
				compare=strcmp(comp_arr,array[i].subject);
				if(compare==0)
				{
					printf("Book Found\n");
					printf("Title => %s\n",array[i].title);
					printf("Author => %s\n",array[i].author);
					printf("Subject => %s\n",array[i].subject);
					printf("Yeaar => %d\n",array[i].year);
				control++;
				}
			}
			if(control==0)
				printf("Book couldn't found, try again");

		}
		if(choose==4)
		{
			for(int i=0;i<=size;i++)
			{
				for(int j=0;j<size-1;j++)
						{
					if(fake_adress[j]->year>fake_adress[j+1]->year)
					{
						temp[0]=fake_adress[j];
						fake_adress[j]=fake_adress[j+1];
						fake_adress[j+1]=temp[0];
		
					}
				}
			}
			for(int i=size;i>0;i--)
			{
					printf("Title => %s\n",fake_adress[i-1]->title);
					printf("Author => %s\n",fake_adress[i-1]->author);
					printf("Subject => %s\n",fake_adress[i-1]->subject);
					printf("Yeaar => %d\n",fake_adress[i-1]->year);
			}
		}
		if(choose==5)
		{
			for(int i=0;i<size;i++)
			{
					printf("Book Found\n");
					printf("Title => %s\n",array[i].title);
					printf("Author => %s\n",array[i].author);
					printf("Subject => %s\n",array[i].subject);
					printf("Yeaar => %d\n",array[i].year);
			}
		}
		if(choose==6) m=0;
	
	}
free(fake_adress);
free(temp);
}
