#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
     { char data[20]; int a;
       struct st *next;} spis;
spis * create(void); //������� �������� ������
void list(spis *head); // ������� ��������� ������
void free_spis(spis *head); //������� ������������ ������
spis * swap(spis *head);
main()
{ system ("CLS");
  spis *head, *hea; // ����� ������ ������
  head= create();
swap(head);
   list (head);
   free_spis (head);

   getch(); 
} 
 spis * create(void)
{  spis *p, *pred, *h; 
   // pred - ��������� �� ���������� ���������
  // h- ��������� �� ������ ���������
   h=pred=new spis; //��������� ������ ��� ������ ���������
   printf("  fam: "); scanf("%s%d", pred->data,&pred->a);
   do { p=new spis;
        printf("\n  fam: "); scanf("%s%d", p->data,&p->a);
        pred->next=p; //������ �� ���������� �� �������
        pred=p; // ���������� ������ ������� 
        printf(" Finish? y/n  ");
       } while (getch()!='y');
   p->next=NULL; 
   return h;
}

spis * swap(spis *head)
{  spis *p,*q;
	char temp[20];
	int min,t;
	q=p=head;
	while(p->next!=NULL){
		min=0;
		q=p->next;
		while(q!=NULL){
			if(min<strcmp(p->data,q->data)){
				min=strcmp(p->data,q->data);
				strcpy(temp,p->data);
				strcpy(p->data,q->data);
				strcpy(q->data,temp);
				t=p->a;
				p->a=q->a;
				q->a=t;				
			}
			q=q->next;
		}
		p=p->next;
	}
} 

void list(spis *head)
{  spis *p;
   p=head;
   
   while (p!=NULL) // ���� �� ����� ������
   {  printf("\n  fio: %s %d ", p->data,p->a);
      p=p->next; // ����������� �� ������ 
   }
} 

 void free_spis(spis *head)
 { spis *p,*q;
   q=p=head;
   while (p!=NULL)
   {
     p=q->next;
     delete q; 
     q=p;
   }   
  head=NULL;
 }


