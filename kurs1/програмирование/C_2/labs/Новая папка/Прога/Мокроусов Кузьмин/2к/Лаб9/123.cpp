#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct st
     { char data[20]; int a;
       struct st *next;
	   struct st *prev;} spis;
spis * create(void); //функция создания списка
void list(spis *head); // функция просмотра списка
void free_spis(spis *head); //функция освобождения памяти
spis * swap(spis *head);
main()
{ system ("CLS");

 	spis *head, *hea; // адрес головы списка
  	head = create();
  	head = swap(head);
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
   pred->prev=NULL;
   do { p=new spis;
   		
        printf("\n  fam: "); scanf("%s%d", p->data,&p->a);
        pred->next=p; //ссылка из предыдущей на текущую
        p->prev=pred;
		pred=p; // сохранение адреса текущей 
        printf(" Finish? y/n  ");
       } while (getch()!='y');
   p->next=NULL; 
   return h;
}

spis * swap(spis *head)
{  spis *p,*q;
   p=q=head;
   while (p!=NULL) // пока не конец списка
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


