#include <stdlib.h>
#include <stdio.h>

struct INFO
{
	char name[20];
	int marks[4];
	struct INFO *next;
	struct INFO *prev;
};
INFO *head;

int AddList()
{
	int n;
	printf("Input the number of students: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		INFO *node = new INFO;
		if(node == NULL)
		{
			printf("Out of memory!");
			return 0;
		}
		
		printf("\nSecond name: ");
		scanf("%s", node->name);
		printf("Input student`s marks: ");
		for(int j = 0; j < 4; j++)
			scanf("%d", node->marks+j);
		
		if(head == NULL)
		{
			node->next = node;
			node->prev = node;
			head = node;
		}
		else
		{
			INFO *p = head;
			p->prev->next = node;
			node->prev = p->prev;
			node->next = p;
			p->prev = node;
		}
	}
	return n;
}

int DeleteList(int n)
{
	INFO *p = head;
	for(int j = 0; j < n; j++)
	{
		if (head == NULL)
		{
			printf("\nStudents list clear.\n");
			return 0;
		}
		if (head == head->next)
		{
			for(int i = 0; i < 4; i++)
			{
				if(head->marks[i] < 3)
				{
					delete head;
					head = NULL;
					return 0;
				}
			}
		}
		else
		{
			INFO *a = p;
			for(int i = 0; i < 4; i++)
			{
				if(a->marks[i] < 3)
				{
					if(a == head) head = a->next;
	 				a->prev->next = a->next;
					a->next->prev = a->prev;
					delete a;
					break;
				}
			}
				p = p->next;
		}
	}
}

void PrintList(int n)
{
	printf("\n");
	if(head == NULL)
		printf("All students expelled\n");
	else
	{
		INFO *a = head;
		do
		{
			printf("%s ", a->name);
			for(int i = 0; i < 4; i++)
				printf("%d ", a->marks[i]);
			printf("\n");
			a = a->next;
		}while (a != head);
	}
}

int main()
{
	int n;
	n = AddList();
	PrintList(n);
	printf("\nAfter\n");
	DeleteList(n);
	PrintList(n);
	
	system("PAUSE");
	return 0;
}
