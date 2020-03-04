#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>

typedef struct INFO
{
	char name[20];
	int mark[4];
	struct INFO *next;
}info;

info *create(void); //создание списка

void sort(info *head);

void list(info *head);

void free_info(info *head);

int main()
{
	setlocale(0,"");
	
	info *head;
	head = create();
	
	sort(head);
	
	list(head);
	
	free_info(head);
	
	system("PAUSE");
	return 0;
}

info *create(void)
{
	int n, i = 1;
	printf("¬ведите количество учеников: "); scanf("%d",&n);
	
	info *p, *pred, *h;
	h = pred = new info;
	printf("¬ведите фамилию: "); scanf("%s", pred -> name);
	printf("¬ведите оценки: ");
	for(int i = 0; i < 4;i++)
		scanf("%d", pred -> mark+i);
	
	do
	{
		i++;
		p = new info;
		printf("¬ведите фамилию: "); scanf("%s", p -> name);	
		printf("¬ведите оценки: "); 
		for(int i = 0; i < 4;i++)
			scanf("%d", p -> mark+i);
		pred -> next = p;
		pred = p;
	} while(i < n);
	p -> next = NULL;
	return h;
}

void sort(info *head)
{
	info *p = NULL;
	char tmp[20];
	int temp[4];
	if(head != NULL)
	{
		while(head -> next != NULL)
		{
			p = head -> next;
			
			do
			{
				if(strcmp(p -> name, head -> name) < 0)
				{
					strcpy(tmp,p -> name);
					strcpy(p -> name, head -> name);
					strcpy(head -> name, tmp);
					for(int i = 0; i < 4; i++)
					{
						temp[i] = p -> mark[i];
						p -> mark[i] = head -> mark[i];
						head -> mark[i] = temp[i];
					}
				}
				
				p = p -> next;
			}while(p != NULL);
			
			head = head -> next;
		}
	}
}

void list(info *head)
{
	info *p;
	p = head;
	while(p != NULL)
	{
		printf("\n‘амили€: %s. ќценки: ", p -> name);
		for(int i = 0; i < 4; i++)
			printf("%d ", p -> mark[i]);
		p = p -> next;
		
	}
}

void free_info(info *head)
{
	info *p, *q;
	q = p = head;
	while(p != NULL)
	{
		p = q -> next;
		delete q;
		q = p;
	}
	head = NULL;
}
