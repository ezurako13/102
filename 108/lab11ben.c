#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	int tamsayi;
	float reel;
	char *yazi;
	struct node *link;
} node;


void insert_end(node **head, int val, float num, char* name_);
void printList_withLoop(node *head);
void printList_withRecursive(node *list) ;
void sortedInsert(node** head_ref, node* new_node);
node* newNode(int new_data, float num, char* name_);
bool search(node* head, int x);



int main()
{
	int NeZamandirSendeyim, cIk=0;

	node *head= NULL, *new_node= NULL;

	while (cIk!=1)
	{
		//printf("\e[1;1H\e[2J");
		NeZamandirSendeyim=0;
		printf("\n\nChoose an operation below to perform\n"	//
			   "--------------------------------\n"			//
			   "1. Initialize list\n"						//	Menu
			   "2. Print with loop\n"						//	Menu
			   "3. Print with recursive\n"					//
			   "4. Sorted insert\n"							//
			   "5. Search\n"								//
			   "6. Exit\n"									//
			   "--------------------------------\n"			//
			   "Enter your choice: ");						//
		
		scanf("%d", &NeZamandirSendeyim);
		while(getchar() != '\n');

		if(NeZamandirSendeyim == 0) printf("\nWhy are you so insistent about entering zeros\n\n");
		else if(NeZamandirSendeyim == 6) cIk=1;

		else if(NeZamandirSendeyim == 1)
		{
			insert_end(&head,10,5.5,"hello1");
			insert_end(&head,20,5.5,"hello2");
			insert_end(&head,30,5.5,"hello3");

		}
		else if(NeZamandirSendeyim == 2)
		{
			printf("\nPrint List with Loop: \n");
			printList_withLoop(head);

		}
		else if(NeZamandirSendeyim == 3)
		{
			printf("\nPrint List with Recursive: \n");
			printList_withRecursive(head);

		}
		else if(NeZamandirSendeyim == 4)
		{
			new_node = newNode(1,5.5, "a");
			printf("\nxd\n");
			sortedInsert(&head, new_node);

			new_node = newNode(3,5.5, "c");
			sortedInsert(&head, new_node);

			new_node = newNode(2,5.5, "d");
			sortedInsert(&head, new_node);

			new_node = newNode(2,5.5, "b");
			sortedInsert(&head, new_node);

		}
		else if(NeZamandirSendeyim == 5)
		{
			printf("\nIs 20 belong this linked list?: " );
			printf(search(head, 20) ? "YES \n" : "NO \n");
			
			printf("\nIs 18 belong this linked list?: " );
			printf(search(head, 18) ? "YES \n" : "NO \n");

		}
		else	printf("\nNe halt yiyon lan\n");
		
		if(cIk!=1)
		{
			printf("\n\nPress ENTER to continue.... \n");
			//while(getchar() != '\n');
			while(getchar() != '\n') /* nothing happens */;
		}
	}


	return 0;
}


void insert_end(struct node **head, int val, float num, char* name_)
{
	//create a new node
	struct node *newNode = malloc(sizeof(struct node));
	newNode->tamsayi = val;
	newNode->reel = num;
	newNode->yazi = name_;
	newNode->link = NULL;

	//if head is NULL, it is an empty list
	if(*head == NULL)
		 *head = newNode;
	//Otherwise, find the last node and add the newNode
	else
	{
		struct node *lastNode = *head;

		//last node's next address will be NULL.
		while(lastNode->link != NULL)
		{
			lastNode = lastNode->link;
		}

		//add the newNode at the end of the linked list
		lastNode->link = newNode;
	}

}

void printList_withLoop(node *head)
{
	printf("\nPrint list with loop:\n");
	while(head != NULL)
	{
		printf("tamsayi: %3d\treel: %.2f\tyazi: %s,\n", head->tamsayi, head->reel, head->yazi);
		head= head->link;
	}
	printf("NULL\n");
}

void printList_withRecursive(node *list) 
{  
	printf("tamsayi: %d\treel: %f\tyazi: %s,\n", list->tamsayi, list->reel, list->yazi);
	if(list->link != NULL)
		printList_withRecursive(list->link);
}

void sortedInsert(node** head_ref, node* new_node)
{
	int i= 0;
	node *prev= NULL, *now= *head_ref;

	printf("\ni= %d n_n->yazi= %s now->yazi= %s", i, new_node->yazi, now->yazi);

	while(now->link != NULL &&strcmp(new_node->yazi, now->yazi) <= 0)
	{
		i++;
		printf("\n%d", i);
		now= now->link;
	}

	if(now == NULL)
		*head_ref= new_node;
	else
	{
		prev= now->link;
		now->link= new_node;
		new_node->link= prev;
	}

	//printf("\n(sortedInsert): \n\n");
	
}
 
/* A utility function to create a new node */
node* newNode(int new_data, float num, char* name_)
{
	node *yepyeniNode= (node *)malloc(1 *sizeof(node));

	yepyeniNode->tamsayi= new_data;
	yepyeniNode->reel= num;
	yepyeniNode->yazi= name_;
	yepyeniNode->link= NULL; 

	printf("\n(newNode): \n");
	return yepyeniNode;
}

bool search(node* head, int x)
{
	//printf("\nx= %d", x);
	while(head != NULL)
	{
		//printf("\nhead->tamsayi= %d", head->tamsayi);
		if(head->tamsayi == x)	return true;
		head= head->link;
	}

	//printf("\n\n");

	return false;
}

