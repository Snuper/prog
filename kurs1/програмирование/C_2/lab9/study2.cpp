#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct st
     { char data[20];
       struct st *next;} spis;
spis * create(void); //������� �������� ������
void list(spis *head); // ������� ��������� ������
void free_spis(spis *head); //������� ������������ ������
main()
{ system ("CLS");
  spis *head; // ����� ������ ������
  head= create();
   list (head);
   free_spis (head);
   getch(); 
} 
 spis * create(void)
{  spis *p, *pred, *h; 
   // pred � ��������� �� ���������� ���������
  // h- ��������� �� ������ ���������
   h=pred=new spis; //��������� ������ ��� ������ ���������
   printf("  fam: "); scanf("%s", pred->data);
   do { p=new spis;
        printf("\n  fam: "); scanf("%s", p->data);
        pred->next=p; //������ �� ���������� �� �������
        pred=p; // ���������� ������ ������� 
        printf(" ���������? y/n  ");
       } while (getch()=='y');
   p->next=NULL; 
   return h;
}
void list(spis *head)
{  spis *p;
   p=head;
   while (p!=NULL) // ���� �� ����� ������
   {  printf("\n  fio: %s",p->data);
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
