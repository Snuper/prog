#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st{
	char name[20];int mark[4]; struct st *next;
}spis;

spis *create();
void list(spis *head);
void sort(spis *head);
void nulling(spis *head);
int main(){
	spis *head;
	head = create();
	sort(head);
	list(head);
	nulling(head);
	getch();
}
spis *create(){
	spis *p, *h, *prev;
	int n;
	printf("How many persons: ");
	scanf("%d",&n);
	h=prev= new spis;
		printf("\nFamily name: ");
		scanf("%s",&prev->name);
		printf("\n1: ");
			scanf("%d",&prev->mark[1]);
		printf("\n2: ");
		scanf("%d",&prev->mark[2]);
		printf("\n3: ");
		scanf("%d",&prev->mark[3]);
		printf("\n4: ");
		scanf("%d",&prev->mark[4]);
		n--;
	 do{
		p=new spis;
		printf("\nFamily name: ");
		scanf("%s",&p->name);
		printf("\n1: ");
		scanf("%d",&p->mark[1]);
		printf("\n2: ");
		scanf("%d",&p->mark[2]);
		printf("\n3: ");
		scanf("%d",&p->mark[3]);
		printf("\n4: ");
		scanf("%d",&p->mark[4]);
		n--;
		prev->next=p;
        prev=p;
	}while(n!=0);
	p->next=NULL;
	return h;
	
}
void sort(spis *head)
{
	spis *p = NULL;
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
void list(spis *head)
{
	spis *p;
	p = head;
	while(p != NULL)
	{
		printf("\nFamily name: %s. Marks: ", p -> name);
		for(int i = 0; i < 4; i++)
			printf("%d ", p -> mark[i]);
		p = p -> next;
		
	}
}
void nulling(spis *head)
{
	spis *p, *q;
	q = p = head;
	while(p != NULL)
	{
		p = q -> next;
		delete q;
		q = p;
	}
	head = NULL;
}
