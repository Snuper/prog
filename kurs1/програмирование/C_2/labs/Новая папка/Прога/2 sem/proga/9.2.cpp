#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st
     { char data[20]; int a; int b; int c; int d;
       struct st *next;} spis;
spis * create(void); //������� �������� ������
void list(spis *head); // ������� ��������� ������
void free_spis(spis *head); //������� ������������ ������
spis * swap(spis *head);
main()
{ system ("CLS");
  spis *head; // ����� ������ ������
  head= create();
  head=swap(head);
   list (head);
   free_spis (head);
   getch(); 
} 
 spis * create(void)
{  spis *p, *pred, *h; 
   // pred - ��������� �� ���������� ���������
  // h- ��������� �� ������ ���������
   h=pred=new spis; //��������� ������ ��� ������ ���������
   printf("  fam: "); scanf("%s%d%d%d%d", pred->data,&pred->a,&pred->b,&pred->c,&pred->d);
   do { p=new spis;
        printf("\n  fam: "); scanf("%s%d%d%d%d", p->data,&p->a,&p->b,&p->c,&p->d);
        pred->next=p; //������ �� ���������� �� �������
        pred=p; // ���������� ������ ������� 
        printf(" Finish? y/n  ");
       } while (getch()!='y');
   p->next=NULL; 
   return h;
}

spis * swap(spis *head)
{  spis *p,*q;
   p=head;
   q=new spis;
   
   while (p!=NULL) // ���� �� ����� ������
   {  
	//if(p->a < 3 or p->b < 3 or p->c < 3 or p->d < 3)
	//{
	printf("\n  chek: %s ", p->data);
		q->next=p;
	    q=p;
		//printf("darova");
		//}
	p=p->next;
   }
   return q;
} 

void list(spis *head)
{  spis *p;
   p=head;
   
   while (p!=NULL) // ���� �� ����� ������
   {  printf("\n  fio: %s %d %d %d %d ", p->data,p->a,p->b,p->c,p->d);
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

