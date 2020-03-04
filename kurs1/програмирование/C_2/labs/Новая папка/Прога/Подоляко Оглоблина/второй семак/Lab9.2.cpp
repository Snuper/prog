#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
typedef struct st
	{ 
		char fam[20];
		int marks[4];
		struct st *next;
		struct st *prev;
	} spis;
	 
void list(spis *head); 
spis * dellete(spis *head); 
main(){ 
spis *head; 
spis *p, *pred; 
head=pred=new spis;
pred->prev=NULL;
		
printf ("Vvedite familii and 4 ocenki\n");
int i;
do {
p=new spis;
scanf("%s",p->fam);
for(i=0;i<4;i++)
scanf("%d",&p->marks[i]);
pred->next=p;
p->prev=pred;
pred=p;
}
while(strcmp(p->fam,"."));
p->next=NULL;
head=dellete(head);
list (head);
spis *q;
q=p=head;
while (p!=NULL)
	{
	p=q->next;
	delete q;
	q=p;
	}
	head=NULL;
	getch(); 
}
 
void list(spis *head){
	spis *p;
	p=head;
	while (p!=NULL) 
	{
		printf("\n %s",p->fam);
		for (int i=0;i<4;i++)	printf(" %d ",p->marks[i]);
		p=p->next; 
	}
}  
spis * dellete(spis *head){
	spis *p,*t;
	p=t=head; 
	while (p!=NULL){
	for (int i=0;i<4;i++){
	if(p->marks[i]<3){
	if (p->prev==NULL){
	if(p->next==NULL){
	free(p);
	return NULL;}	
	head=head->next;
	free(p);
	head->prev=NULL;
	p=head;
}
	else{
	if(p->next==NULL){
	t=p->prev;
	free(p);
	p=t;
	p->next=NULL;
	}
	else{
	t=p->prev;
    t->next=p->next;
	t=p->next;
	t->prev=p->prev;
	free(p);
	p=t;
	}
	}
	}
	}
	p=p->next;
	}
	return head;
	
}

