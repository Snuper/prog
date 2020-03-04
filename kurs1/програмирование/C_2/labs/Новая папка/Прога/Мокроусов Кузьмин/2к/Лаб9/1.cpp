#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st
     { char data[20]; int a;
       struct st *next;} spis;
spis * create(void); //функция создания списка
void list(spis *head); // функция просмотра списка
void free_spis(spis *head); //функция освобождения памяти
spis * swap(spis *head);
main()
{ system ("CLS");
  spis *head, *hea; // адрес головы списка
  head= create();
swap(head);
   list (head);
   free_spis (head);

   getch(); 
} 
 spis * create(void)
{  spis *p, *pred, *h; 
   // pred - указатель на предыдущую структуру
  // h- указатель на первую структуру
   h=pred=new spis; //выделение памяти для первой структуры
   printf("  fam: "); scanf("%s%d", pred->data,&pred->a);
   do { p=new spis;
        printf("\n  fam: "); scanf("%s%d", p->data,&p->a);
        pred->next=p; //ссылка из предыдущей на текущую
        pred=p; // сохранение адреса текущей 
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
   
   while (p!=NULL) // пока не конец списка
   {  printf("\n  fio: %s %d ", p->data,p->a);
      p=p->next; // продвижение по списку 
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


