#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st
     { char data[20]; int a;
       struct st *next;
	   struct st *prev;} spis;
spis * create(void); //������� �������� ������
void list(spis *head); // ������� ��������� ������
void free_spis(spis *head); //������� ������������ ������
spis * swap(spis *head);
main()
{ system ("CLS");

 	spis *head, *hea; // ����� ������ ������
  	head = create();
  	head = swap(head);
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
   pred->prev=NULL;
   do { p=new spis;
   		
        printf("\n  fam: "); scanf("%s%d", p->data,&p->a);
        pred->next=p; //������ �� ���������� �� �������
        p->prev=pred;
		pred=p; // ���������� ������ ������� 
        printf(" Finish? y/n  ");
       } while (getch()!='y');
   p->next=NULL; 
   return h;
}

spis * swap(spis *head)
{  spis *p,*q;
   p=q=head;
   while (p!=NULL) // ���� �� ����� ������
   {  
   if(p->a<3){
   		if(p->prev==NULL){
			if(p->next==NULL){
					free(p);
					return NULL;
				}	
				head=head->next;
				free(p);
				head->prev=NULL;
				p=head;}
   		else{
			if(p->next==NULL){
				q=p->prev;
				free(p);
				p=q;
				p->next=NULL;
				}
			else{
				q=p->prev;
				q->next=p->next;
				q=p->next;
				q->prev=p->prev;
				free(p);
				p=q;
				}
			}
   		}
	p=p->next;
   }
return head;
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


